[PARMS]
tpl_ver=0.6.1
tpl_id=UNI
tpl_desc=WEBM VP8 for FFmpeg SVN-r23642 and higher
tpl_com="webm vp8" basic template. Uses the preferred libvpx, libvorbis combinationfor video/audio. Most settings can be adapted to fit your needs.-quality can be changed to "good" (slow) and "best" (very slow).
tpl_v_cdbe=webm,---,---,D V D ,libvpx,webm vp8,Y,webm vp8
tpl_a_cdbe=ogg,---,---, EA   ,libvorbis,vorbis (lib),Y,libvorbis Vorbis
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=640x480
v_bitrate=700
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=2000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-g 120 -rc_lookahead 16 -profile 1 -qmax 51 -qmin 11 -slices 4 -quality realtime
d_userExt=
avs_rgb=N,1,1,1,1,0,0,0,0,1,1,1,1,false
avs_hsbc=N,0,1,0,1
cps_use=0
ffmp_pass=1
post_proc=No post process scheduled
av_pitch=1

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
c2=64
c3=22050
c4=2
c5=Disabled
c6=webm vp8
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
 
 