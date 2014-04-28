[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=DIVX / fast - 2-pass (using XVID codec)
tpl_com=Basic 2-pass DIVX example using libxvid codec.The xvid codec can be often used instead of mpeg4 and offers betterquality at low bitrates.You can freely adapt bitrate, frame rate, frame size, aspect ratio etc.Use one of the latest FFmpeg versions.
tpl_v_cdbe=avi,---,mp4, EV   ,libxvid,xvid (lib),Y,libxvidcore MPEG-4 part 2
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=640x480
v_bitrate=800
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=4000
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-qmax 10 -g 300
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
c2=80
c3=22050
c4=2
c5=Disabled
c6=XviD (Lib)
c7=25.000 fps
c8=4:3
c9=Default
c10=DIVX
c11=Source
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
 