

	AVANTI - Version 0.7.0 - FFmpeg/Avisynth GUI
	============================================


	By default, Avanti looks for the FFmpeg executable at this directory.
	You can copy a valid "ffmpeg.exe" here or set the path to another location
	at the "Start process" button pop-up menu (right-click to open it).

	Always use a generic FFmpeg Win32 (static) build. FFmpeg versions included
	in other applications may be modified for specific use and may not work.
	When Avanti hangs at startup and/or you get the message "ffmp_avanti.exe
	stopped working", you most likely use a special or invalid version.

	You only need to copy the "ffmpeg.exe" executable to this directory and
	in case it is included (older versions) the "pthreadGC2.dll".
	Avanti doesn't need "ffplay.exe" and the related "SDL.dll".  

	You can keep more then one FFmpeg version available in this directory
	by renaming them following this naming convention; 
	
	They can have any name as long as it starts of with "ffmpeg". E.g.;

		ffmpeg.exe
		ffmpeg_32153.exe
		ffmpeg_divx3_demux.exe

	This are all valid names and you can select which one to use as default
	at the "Start Process" button pop-up menu.

	The first time you run Avanti or when you deleted the "Avanti.ini" file
	for some reason, it will use the first file copied to this directory.
	
	Also read the "Avanti-help.chm" on FFmpeg version limitations (Appendix).


	September 2012 - Chris Kevany
	