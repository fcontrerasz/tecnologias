@echo off
FOR /R . %%g in (*.mkv) DO (

rem echo Nombre: %%~fg
echo Nombre: %%~nxg

ffmpeg -i %%~nxg -s 500x400 -vf "setpts=0.04*PTS" -ss 4 -vcodec msmpeg4v2 -b:v 1000k -r 5 -an -f avi Quick_%%~nxg.avi

rem pause

)