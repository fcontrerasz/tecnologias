[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=PSP / h264 320x240 (extended tweaking)
tpl_com=h264 in mp4 container for PSP / extended tweaking.BIT_RATE <= 768 kbpsUp to 320×240 or up to 368×208Up to 30 fpsH.264 Main Profile up to Level 2.1Up to 2 reference framesLC AAC audio up to 48kHzYou can call up the command line by expanding the report windowand pressing 'Get user video opts'.You then can add or remove commands and restore the command lineby pressing 'Set user video opts'.
tpl_v_cdbe=avi,---,mp4, EV   ,libx264,x264 (lib),Y,libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10
tpl_a_cdbe=aac,---,---,DEA   ,libfaac,aac (lib),Y,Older FFmpeg versions
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=320x240
v_bitrate=750
v_qscale=
v_minrate=
v_maxrate=4000
v_bufsize=4000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-flags +loop -cmp +chroma -partitions +parti4x4+partp8x8+partb8x8 -me_method umh -subq 5 -trellis 1 -refs 2 -bf 1 -coder 1 -me_range 16 -g 300 -keyint_min 25 -i_qfactor 0.71 -qcomp 0.6 -qmin 10 -qmax 51 -qdiff 4 -level 21 -rc_eq "blurCplx^(1-qComp)" -f psp
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
c7=29.970 fps
c8=4:3
c9=PS
c10=Default
c11=Source
c12=320x240

[#EVENT/#THIS/ID_COMBOEDIT]
 