[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=PS3 / h264 720x576 (extended tweaking)
tpl_com=h264 in mp4 container for PS3 / extended tweaking.You can call up the command line by expanding the report windowand pressing 'Get user video opts'.You then can add or remove commands and restore the command lineby pressing 'Set user video opts'.
tpl_v_cdbe=avi,---,mp4, EV   ,libx264,x264 (lib),Y,libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10
tpl_a_cdbe=aac,---,---,DEA   ,libfaac,aac (lib),Y,Older FFmpeg versions
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=720x576
v_bitrate=2050
v_qscale=
v_minrate=
v_maxrate=4000
v_bufsize=4000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-me_method umh -subq 5 -coder 1 -trellis 1 -g 300 -qmin 10 -qmax 51 -qdiff 4 -level 41 -rc_eq "blurCplx^(1-qComp)"
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
c2=128
c3=48000
c4=2
c5=Disabled
c6=x264 (lib)
c7=25.000 fps
c8=4:3
c9=PS
c10=Default
c11=Source
c12=720x576

[#EVENT/#THIS/ID_COMBOEDIT]
 