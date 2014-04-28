[PARMS]
tpl_ver=0.6.0
tpl_id=UNI
tpl_desc=AAC (libvo) audio / registers - libvo_aacenc - codec
tpl_com=Template adds "libvo_aacenc" encoder to FFmpeg codecs database andaudio "Codec" dropdown list.This AAC encoder may be limited to max 2 channels (just try).When you double-click on the audio "Codec" field you can re-arrangethe dropdown list (also applicable on other dropdown lists).
tpl_v_cdbe=vd,vde,---,D V   ,copy,Demux video,N,Avanti System (do not remove)
tpl_a_cdbe=aac,---,---, EA   ,libvo_aacenc,aac (libvo),N,---
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
c1=aac (Libvo)
c2=256
c3=48000
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
 