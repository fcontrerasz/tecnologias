[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=H264 in AVI container (basic example)
tpl_com=h264 in AVI container / general example using FFmpeg defaults.You can change 'Bitrate', 'Frame rate' and "Frame size' as desired.You can call up the command line by expanding the report windowand pressing 'Get user video opts'.You then can add or remove commands and restore the command lineby pressing 'Set user video opts'.
tpl_v_cdbe=avi,---,mp4, EV   ,libx264,x264 (lib),Y,libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=320x240
v_bitrate=750
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-coder 1 -flags +loop -cmp +chroma -partitions +parti8x8+parti4x4+partp8x8+partb8x8 -me_method hex -subq 6 -me_range 16 -g 250 -keyint_min 25 -sc_threshold 40 -i_qfactor 0.71 -b_strategy 1 -qcomp 0.6 -qmin 10 -qmax 51 -qdiff 4 -direct-pred 1 -fast-pskip 1
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
c2=128
c3=44100
c4=2
c5=Disabled
c6=x264 (lib)
c7=30.000 fps
c8=4:3
c9=avi
c10=Default
c11=Source
c12=320x240

[#EVENT/#THIS/ID_COMBOEDIT]
 
 