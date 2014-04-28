@echo off
setLocal EnableDelayedExpansion

set FILE_LIST=(69 70 73 79 80 81 82 86 87 88 89 93 95 96 97 94)
rem set FILE_LIST=(87 88 89 93 95 96 97 94)

Set /A maximo=5
Set _Height=2
Set _Width=25
Set _BHeight=100
Set _BWidth=%_Width%
Set _xPos=10
Set _yPos=10
Set _Color=1E
Set /A _BufferSize=_BHeight*0x10000+_BWidth
Set /A _WindowPos=_yPos*0x10000+_xPos
Set /A _WindowSize=_Height*0x10000+_Width
Set _Cmd=Title TERMINAL




for %%i in %FILE_LIST% do (
	
		set /a counter += 1

		ping 172.16.11.%%i -n 1 -w 1000
	
		if errorlevel 0 (

		Call :_OPEN %_BufferSize% %_Color% !_WindowPos! %_WindowSize% %%i

		set /a divi = !counter! * 12
		
		Set /A _yPos=_yPos+_Height * 12 + 40

		Set /A _WindowPos=!_yPos!*0x10000+!_xPos!

		
			if !counter! == !maximo! (
				Goto :EOF
			)

		)
)

Goto :EOF

:_OPEN
Set _caja=ESTACION_%5
Reg Add "HKCU\Console\%_caja%~5" /V ScreenBufferSize /T REG_DWORD /D %1 /F
Reg Add "HKCU\Console\%_caja%~5" /V ScreenColors /T REG_DWORD /D 0x%2 /F
Reg Add "HKCU\Console\%_caja%~5" /V WindowPosition /T REG_DWORD /D %3 /F
Reg Add "HKCU\Console\%_caja%~5" /V WindowSize /T REG_DWORD /D %4 /F

start "%_caja%~5" %COMSPEC% /K cmd /c "psexec.exe -s -u mets\neutron -p Yt10p* \\172.16.11.%5 -f -c ejecutar_remoto.bat"

