[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=MP3 audio (only) with variable bitrate
tpl_com=Example template to encode to VBR mp3 audio stream ...The "User AUDIO options >" command line contains the -aq x command where xis the VBR level that can be set from 1-9. 9 gives the highest compression.Bitrate setting at the "Destination Audio settings" is ignored.You can also use the -aq option for the mp3 audio stream of a video clip.
tpl_v_cdbe=vd,vde,---,D V   ,copy,Demux video,N,Avanti System (do not remove)
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=-vn
v_size=Source
v_bitrate=
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=-aq 5
v_userOpt=
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
c2=32
c3=44100
c4=2
c5=Disabled
c6=Demux Video
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 