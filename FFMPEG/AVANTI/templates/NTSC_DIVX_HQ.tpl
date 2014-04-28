[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=DIVX / HQ - 2-pass (using mpeg4 codec)
tpl_com=Template example for hq DIVX encoding using mpeg4 codec.You can freely adapt bitrate, frame rate, frame size, aspect ratio etc.Bitrates of 1200 kbps up and 2-pass enconding is recommended for mpeg4.For low bitrates use the DIVX 2-pass template that uses the xvid codec.
tpl_v_cdbe=avi,m4v,mp4,DEVSDT,mpeg4,mpeg4,Y,MPEG-4 part 2
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=640x480
v_bitrate=1200
v_qscale=
v_minrate=
v_maxrate=2500
v_bufsize=2000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-flags +aic+mv4 -trellis 1 -mbd 2 -cmp 2 -subcmp 2 -g 250 -me_range 1023
d_userExt=
avs_rgb=N,1,1,1,1,0,0,0,0,1,1,1,1,false
avs_hsbc=N,0,1,0,1
cps_use=0
ffmp_pass=2
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
c2=112
c3=44100
c4=2
c5=Disabled
c6=mpeg4
c7=23.976 fps
c8=4:3
c9=Default
c10=DIVX
c11=Source
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
 