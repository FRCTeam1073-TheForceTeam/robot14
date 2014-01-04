@echo off
echo this will run through everything you need to pull down the latest version of WPILibExtensions or update your local copy

rem there is no harm in running through this file as many times as you'd like

rem clone the submodule - only has to happen once
git submodule add https://github.com/FRCTeam1073-TheForceTeam/WPILibExtensions.git
rem initialize it - only has to happen once
git submodule init
rem and if you already have it, get the latest and greatest
git submodule update