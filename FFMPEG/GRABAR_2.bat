@echo off

SET /A COUNT=1
Set _Aux=0
Set _Height=12
Set _Width=40
Set _BHeight=100
Set _BWidth=%_Width%
Set _xPos=30
Set _yPos=20
Set _Color=1E
Set /A _BufferSize=_BHeight*0x10000+_BWidth
Set /A _WindowPos=_yPos*0x10000+_xPos
Set /A _WindowSize=_Height*0x10000+_Width
Set _Cmd=Title TERMINAL

rem Call :_OPEN %_BufferSize% %_Color% %_WindowPos% %_WindowSize% "170"

for /l %%x in (1, 1, 10) do (
	SET /A COUNT+=1
	echo "DATA %COUNT%"
	Ping 172.16.11.10%%x -n 1 -w 1000
	if errorlevel 0 Call :_DATA %COUNT%

)

Goto :EOF

:_DATA
rem	set /A sum += 1
rem	set /A _Total=sum*12
rem	Set /A _yPos=_yPos+_Height*%_Total%+40
rem	Set /A _WindowPos=_yPos*0x10000+_xPos
if %1 LEQ 10 (Call :_OPEN %_BufferSize% %_Color% %_WindowPos% %_WindowSize% "10%1")
if %1 GEQ 9 (Call :_OPEN %_BufferSize% %_Color% %_WindowPos% %_WindowSize% "1%1")


:_OPEN
Set _caja=ESTACION_%5
Reg Add "HKCU\Console\%_caja%~5" /V ScreenBufferSize /T REG_DWORD /D %1 /F
Reg Add "HKCU\Console\%_caja%~5" /V ScreenColors /T REG_DWORD /D 0x%2 /F
Reg Add "HKCU\Console\%_caja%~5" /V WindowPosition /T REG_DWORD /D %3 /F
Reg Add "HKCU\Console\%_caja%~5" /V WindowSize /T REG_DWORD /D %4 /F
start "%_caja%~5" %COMSPEC% /K cmd /c "psexec.exe -s -u mets\neutron -p Yt10p* \\172.16.11.%5 -f -c ejecutar_remoto.bat"

