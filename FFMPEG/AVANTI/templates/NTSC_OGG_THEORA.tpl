[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=THEORA video with VORBIS audio
tpl_com=Example of ogg theora encoding. With the theora codec, FFmpeg accepts onlyvorbis as audio stream and the the -f ogg output format. This is addedto the 'User VIDEO options >'.You can freely adapt bitrate, frame rate, frame size, aspect ratio etc.Media Player Classic suggests that the 'ogg' extension is for vorbis audioand the 'ogm' (ogg media file) extension for ogg theora video.In general this container also includes audio (one or more streams) andcan contain subtitle streams.Current FFmpeg versions don't support any command line tweaking for Theora.
tpl_v_cdbe=ogm,---,---, EV   ,libtheora,theora (lib),N,libtheora Theora
tpl_a_cdbe=ogg,---,---, EA   ,libvorbis,vorbis (lib),Y,libvorbis Vorbis
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=640x480
v_bitrate=1200
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-f ogg
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
c1=vorbis (Lib)
c2=128
c3=44100
c4=2
c5=Disabled
c6=theora (lib)
c7=23.976 fps
c8=4:3
c9=Default
c10=Default
c11=Source
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
 