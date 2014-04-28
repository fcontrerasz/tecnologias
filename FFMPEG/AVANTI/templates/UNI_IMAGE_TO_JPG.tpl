[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=JPG Image conversion (any supported input to jpg image).
tpl_com=Converts any by FFmpeg supported input format to jpeg image.Input: BMP, PNG, GIF, JPEG, TIF ... output JPG.Frame size can be set to any desired format or kept as source size.If you remove -sameq from the command line, default quality is used.You can use the "Job Control Manager" for batch processing.
tpl_v_cdbe=jpg,---,---,DEV D ,mjpeg,JPEG Image,Y,JPEG Image (any supported input)
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=-an
v_check=
v_size=Source
v_bitrate=
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-sameq  -f image2
d_userExt=
avs_rgb=N,1,1,1,1,0,0,0,0,1,1,1,1,false
avs_hsbc=N,0,1,0,1
cps_use=0
ffmp_pass=1
post_proc=No post process scheduled

[PARMS2]
cps_po=csp
c_lrtb=0,0,0,0
p_lrtb=0,0,0,0,0/0/0
d_width=0
d_height=0
sc_algo_0=Bicubic
sc_algo_1=Bicubic
cps_sys=0
cps_calc_scr=
cps_colspc=0

[DROPSELECT]
c1=mp3 (Lib)
c2=128
c3=44100
c4=2
c5=Disabled
c6=JPEG Image
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 