[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=3GP / basic settings for cell phones
tpl_com=This template example encodes to a 3gp stream which can be uploaded to cell phonesthat can play video and support this format.You can freely adapt bitrate, frame rate, frame size, aspect ratio etc.Valid frame sizes are 128x96, 176x144, 352x288, 704x576, and 1408x1152.
tpl_v_cdbe=3gp,---,---,DEVSDT,h263,3gp Video,N,H.263 / H.263-1996
tpl_a_cdbe=aac,---,---,DEA   ,libfaac,aac (lib),Y,Older FFmpeg versions
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=176x144
v_bitrate=350
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-flags +aic+cbp+mv0 -trellis 1 -mbd 2 -cmp 2 -subcmp 2 -g 250
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
c1=aac (Lib)
c2=32
c3=8000
c4=1
c5=Disabled
c6=3gp Video
c7=25.000 fps
c8=4:3
c9=Default
c10=Default
c11=Source
c12=176x144

[#EVENT/#THIS/ID_COMBOEDIT]
 