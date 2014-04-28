@ECHO OFF

SET /A data=%RANDOM% * 100 / 32768 + 1
net use "\\greco\STREAM" Yt10p* /USER:mets\neutron

if exist c:\windows\system32\UScreenCapture.msi (
    rem existe
) else (
    copy /Y \\greco\STREAM\UScreenCapture.msi c:\windows\system32\
    c:\windows\system32\UScreenCapture.msi /quiet
)

if exist c:\ffmpeg.exe (
    rem existe
) else (
    copy /Y \\greco\STREAM\ffmpeg.exe c:\
)

taskkill /F /IM  ffmpeg.exe

c:\ffmpeg -f dshow -i video="UScreenCapture" -s vga -r 5 "\\greco\STREAM\%COMPUTERNAME%_%date:~10,4%-%date:~4,2%-%date:~7,2%_%data%_ou.mkv"
