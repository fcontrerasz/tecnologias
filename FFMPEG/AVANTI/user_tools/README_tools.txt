

	AVANTI - Version 0.7.0 - FFmpeg/Avisynth GUI
	============================================


	After a first-time (or clean) install, Avanti adds four predefined items
	to the "tools menu" ( 12th toolbar button on top of the main window ).

	   1. "MediaInfo @ Source 1", shows details of clip at "Source 1".
	   2. "MediaInfo @ Destination", shows details of clip at "Destination"
	   3. "MP4Box (move atom)", prepares clip for web streaming.
	   4. "DGPulldown (24-30)", sets 23.976 to 29.970 (3:2) pulldown flags. 
		
	Note that item 3 and 4 take the clip at the "Destination" path as source
	for the related tool and create a processed copy with the file extension;

	   "fielname.web.mp4"  (for MP4Box).
	   "filename.pull.m2v" (for DGPulldown).

	These intems can be used as examples to add your own tools but will be fully
	functional when you copy the related tools to this "/user_tools" folder.
	You are free to modify or delete these items if they are not useful to you.

	The for these items required tools are;

	   1. MediaInfo.exe (including all its related files).
	   2. MP4Box.exe (including the js32.dll).
	   3. DGPulldown.exe (only the executable and help text file if desired).

	If you have already one of more of these tools on your system, you can change
	the path to them at the "User tools menu manager".

	See the Avanti-help.chm at index "User tools (how to add)" for more details.


	September 2012 - Chris Kevany
	