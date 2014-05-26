#robot14
Code for the new 2014 FIRST Robotics Competition.

##Setting up WPILibExtensions

To get a complete codebase of WPILibExtensions run the batch file `GetWPILibExtensions.bat` in the git power shell available from [here](https://windows.github.com).

##RobotBuilder
To download the version of Robot Builder that we are using for WPILibExtensions, click [here](http://evinugur.com/RobotBuilderWPILibExtensions.jar). Currently this is not supported until RobotBuilderWPILibExtensions adds support for the new `SmartVictor` class.

##Preferences
When switching robot hardware, or reflashing Atlas' cRio, it is import to take the file `wpilibpreferences.ini` to the root of the robot's FTP site. These are preferences we've saved at runtime, and the robot needs them to function properly.

###JFrame Madness 
RobotBuilder will save your preferences to the registry (if your'e on Windows), two of these preferences are the x and y locations of the window. If you exit the program while it is minimized, `JFrame.getLocationOnScreen()` will return coordinates of `(-32000, -32000)`. RobotBuilder blindly writes those values to the registry, and Team 1073 will patch this so it doesn't happen. In the meantime, run `RobotBuilderRegistryFix.reg` as an administrator to set those values back to 0.

##Sublime Text
If you want to compile the code from within Sublime Text, copy the file called `robot14.sublime-build` to `%appdata%\Sublime Text 3\Packages\User\`. I would avise against this because as it stands `make.bat` has no way of updating the projects `Makefile`, so you'll have to compile through WindRiver before running code through Sublime Text.

##Trello
We collaborate and track our progress on <a href = "https://Trello.com">Trello</a>. Check it out <a href = "https://trello.com/b/HWx0Nqct/1073-software">here</a>.