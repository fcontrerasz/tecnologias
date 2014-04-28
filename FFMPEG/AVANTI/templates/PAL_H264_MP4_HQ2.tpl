[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=H264 HQ 2-pass in MP4 (uses FFmpeg presets and dual cmd lin)
tpl_com=h264 in mp4 container / hq example.Needs FFmpeg SVN-r15625 or higher which supports the -vpre (preset) option.Uses the Avanti dual command line option with a fast FFmpeg preset for pass 1and a hq preset for pass 2.Dual command line syntax examples:-@pass1 -vpre "your_pass1.ffpreset"  -@pass2 -vpre "your_pass2.ffpreset" or-@pass1 -your -encoder -commands  -@pass2 -your -encoder -commands
tpl_v_cdbe=avi,---,mp4, EV   ,libx264,x264 (lib),Y,libx264 H.264 / AVC / MPEG-4 AVC / MPEG-4 part 10
tpl_a_cdbe=aac,---,---,DEA   ,libfaac,aac (lib),Y,Older FFmpeg versions
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
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-@pass1 -vpre libx264-fast-pass1 -@pass2 -vpre libx264-hq-pass2
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
c12=640x480

[#EVENT/#THIS/ID_COMBOEDIT]
 