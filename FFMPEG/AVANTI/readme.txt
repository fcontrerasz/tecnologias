

	AVANTI - Version 0.7.0 - FFmpeg/Avisynth GUI
	============================================


	Avanti has its home at "http://avanti.arrozcru.org".
	
	You can post comments, questions and bug reports at the Avanti support thread at
	the VideoHelp forum ... "http://forum.videohelp.com/topic343287.html".


	For a detailed description on how to set up the Avanti environment and obtain the
	latest FFmpeg Win32 binaries, double-click on the included "Avanti-help" chm file.

	The following folders contain readme files with additional folder related notes;
 	"/ffmpeg", "/ffmpeg/ffpresets", "/user_tools" and "/avsplugins".


	Before you continue.
	====================

	Avanti doesn't offer single-click solutions for end-users. It is however highly user
	configurable and uses a powerful concept. It comes with over 200kB of compressed
	context sensitive help and we advice to read this to take advantage of all its features.
	Avanti is recommended to those who are looking for a convenient tool to learn more about
	the capabilities of FFmpeg and Avisynth. Avanti expects some basic knowledge of audio and
	video encoding but its automatic options and included templates offer a fair start point
	for less experienced users.

	
	Note for first-time users.
	==========================

	The audio and video options, available at the dropdown lists of the Avanti GUI are just
	basic FFmpeg settings. Conversion at higher quality levels and/or meant for specific
	devices like Ipod, psp, ps3, etc. need additional tweaking which can be done by loading
	a dedicated template at the top left button main menu. You are free to adapt the default
	settings to your needs and save them as a user template.


	Example Templates.
	==================

	The first time you load one of the example templates, a message box may appear showing:

		This template will add the following
		option to the related dropdown list:

	followed by a non-predefined option (e.g. Codec: Flash Video). To use the template with
	success, you need to always allow Avanti to add the option(s).     
	

	Notes for Avisynth experts.
	===========================

	-1-
	
	If you have a number of plugins in the Avisynth plugins folder, Avisynth "auto-loads"
	these plugins each time you run a avs script. Very convenient, but the drawback is that
	this procedure is rather complicated and could delay the Avisynth startup.

	There are a number of plugins (C plugins) that even increase the Avisynth startup delay
	dramatically if they are located in the Avisynth "plugins" folder.
	
	Note that these plugins can be very useful and that it only concerns a Avisynth plugin
	load problem. We advice to move all "C plugins" to a separate plugins folder and use the
	"LoadCplugin()" command if you need to use them.
	
	-2-

	When you "preview" the AUTO Avisynth scripts created by Avanti, you will notice that they
	always put the sources into the A and V variables, even if there is no necessity for it.
	This is because Avanti compiles the scripts from standard lines that can be used for both
	combined and separated AV sources.


	The on your system available codecs.
	====================================
	
	With the Avanti FFmpeg/Avisynth combination you can process a large number of audio and
	video formats. To decode/playback these formats, your system needs compatible codecs. 
	Basically the Windows OS only installs a limited number of audio/video codecs.
	Which codecs actually are registered on your system often depends on the installed video
	related software. E.g. Nero installs audio/video codecs. If you use Pinnacle soft/hardware
	a large number of codecs are installed, etc.

	To use the "Preview" and "Avisynth" options of Avanti with success you may need to install
	additional (DirectShow) codecs for the file/container formats you wish to decode or play.
	Often you need to install codecs for DivX/XviD, h264, flv, Vorbis, AAC etc. and splitters
	for mp4 and Matroska containers, if you use these formats.

	The best you can do before you install codecs is to check what's already on your system and
	works properly. You can use "Direct Show filter Manager" and "GraphEdit" (free available at
	www.videohelp.com) to manage the job.
	Drop media files on the "GraphEdit" window to see what codecs your system uses for playback.
	Use "Direct Show filter Manager" to change the "merit" (priority) of certain codecs.

	We use FFdshow with success in conjunction with the Avanti "Preview" options. Additionally
	we use "Haali Media Splitter", "FLVSplitter" and the "Ogg codecs" from "xiph.org" for
	decode/playback of ogg, aac and dts audio streams. 
	

	Recommended Video Player.
	=========================

	We prefer the built-in video player for Avisynth script preview. We experienced it plays
	often more smoothly with Avisynth options selected (color correction, crop/scale/pad,
	audio transcode, etc.). This player also allows Avanti to offer much more control over
	the available "Preview" options. 


	Known bugs and limitations.
	===========================

	In case of persistent errors, delete the "avanti.ini" file in your Avanti install directory
	and restart Avanti. This will restore the default settings.	

	Re-launching the internal video preview (without closing it first) may cause Avanti to
	crash in Windows 7 when the the "basic" or "high contrast" themes are used. To avoid
	this, use an "aero" theme or always first close the preview before you launch it again.
	
	Avanti doesn't scale its windows when you use a Windows OS system font other than the
	standard 96 dpi. 
 
	Avanti uses a lot of the standard Windows OS resources and as for every software, these are
	not free of bugs. It is known that playing a Avisynth script with the internal video preview
	disables the Avanti drag and drop functionality. Currently the only known solution to
	retrieve this feature is to exit and restart Avanti. 
		
	For the preview option of the Avisynth SuperEQ editor, Avanti creates a temporary preset and
	avs script on disk and plays this. This is a heavy job and on slower systems this might
	introduce some delay and stutter when you move the position bar or press the "move all"
	up/down buttons. 
	

	September 2012 - Chris Kevany


