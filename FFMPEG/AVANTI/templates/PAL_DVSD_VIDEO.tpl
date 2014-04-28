[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=DV standard definition
tpl_com=Note that DV video has a fast fixed bitrate (approx 30 Mbit/s) and consumesa large amount of diskspace. The bitrate reported by FFmpeg can be ignored.It can be useful to convert other formats to this standard if you have toprovide (near) broadcast quality on tape.
tpl_v_cdbe=avi,---,---,DEV D ,dvvideo,DV Video,N,DV (Digital Video)
tpl_a_cdbe=wav,---,---,DEA   ,pcm_s16le,wav,Y,PCM signed 16-bit little-endian
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=720x576
v_bitrate=
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
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
c1=wav
c2=1536
c3=48000
c4=2
c5=Disabled
c6=DV video
c7=25.000 fps
c8=4:3
c9=Default
c10=Default
c11=Source
c12=720x576

[#EVENT/#THIS/ID_COMBOEDIT]
 