[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=FLASH HQ / registers the 'Flash Video' codec
tpl_com=Flash Video template. Frame size can be set as desired.Frame rate is not applicable for FLV.Based on contribution and advice from 45tripp at VideoHelp.com
tpl_v_cdbe=flv,---,---,DEVSD ,flv,Flash Video,N,Flash Video (FLV)
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=320x240
v_bitrate=500
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-g 160 -cmp 3 -subcmp 3 -mbd 2 -flags aic+cbp+mv0+mv4+global_header -trellis 1 -sws_flags lanczos
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
c2=64
c3=22050
c4=1
c5=Disabled
c6=Flash Video
c7=Source
c8=4:3
c9=Default
c10=Default
c11=Source
c12=320x240

[#EVENT/#THIS/ID_COMBOEDIT]
 