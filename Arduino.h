#ifndef ARDUINO_H
#define ARDUINO_H

/* These work because Wait multiplies the requested delay time by
 * the number of ticks per second of the system clock and calls
 * taskDelay(ticks) after casting back to int. See WPILib's timer.cpp.
 */

#define delay(x) Wait((x) / 1000.0f)
#define delayMicroseconds(x) Wait((x) / 1000000.0f)
#endif
