
setlocal

set PATH=%PATH%;C:\WindRiver\gnu\3.4.4-vxworks-6.3\x86-win32\bin;C:\WindRiver\utilities-1.0\x86-win32\bin;C:\WindRiver\setup\x86-win32\bin
set WIND_BASE=C:\WindRiver\vxworks-6.3

cd PPC603gnu

make --no-print-directory BUILD_SPEC=PPC603gnu DEBUG_MODE=1 TRACE=1