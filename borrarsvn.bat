for /f "tokens=* delims=" %%i in ('dir /s /b /a:d *svn') do (
rem rd /s /q '%%i'
echo %%i
)