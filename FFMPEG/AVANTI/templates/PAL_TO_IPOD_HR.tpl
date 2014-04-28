[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=IPOD / h264 HQ (hires) 640x480
tpl_com=IPOD hires 640x480 h264 in m4v container / extended tweaking.BIT_RATE <= 1500 kbpsmax 640x480Up to 30 fps“Low-Complexity” H.264 Baseline Profile1 reference frameUp to H.264 level 3You can call up the command line by expanding the report windowand pressing 'Get user video opts'.You then can add or remove commands and restore the command lineby pressing 'Set user video opts'.
tpl_v_cdbe=avi,---,mp4, EV   ,libx264,x264 (lib),Y,libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10
tpl_a_cdbe=aac,---,---,DEA   ,libfaac,aac (lib),Y,Older FFmpeg versions
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=640x480
v_bitrate=1000
v_qscale=
v_minrate=
v_maxrate=1500
v_bufsize=10000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-f ipod -flags +loop -cmp +chroma -partitions +parti4x4+partp8x8+partb8x8 -me_method umh -subq 5 -trellis 1 -refs 1 -coder 0 -me_range 16 -g 300 -keyint_min 25 -i_qfactor 0.71 -rc_eq "blurCplx^(1-qComp)" -qcomp 0.6 -qmin 10 -qmax 51 -qdiff 4 -level 30
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
c3=44100
c4=2
c5=Disabled
c6=x264 (lib)
c7=25.000 fps
c8=4:3
c9=m4v
c10=Default
c11=Source
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
  