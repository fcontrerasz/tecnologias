[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=AUDIO (only) conversion from NTSC to PAL (with pitch corr.)
tpl_com=Audio conversion from NTSC to PAL with pitch correction.This can be used for lossless conversion from NTSC DivX to PAL.1. Demux the NTSC video to a separate AVI stream and overwrite   the "frame rate" with 25.000 fps.2. Demux the audio stream and use this template to convert the audio.3. Remux both streams to a new AVI and write the DIVX fourcc to it.
tpl_v_cdbe=vd,vde,---,D V   ,copy,Demux video,N,Avanti System (do not remove)
tpl_a_cdbe=mp3,---,---, EA   ,libmp3lame,mp3 (Lib),Y,libmp3lame MP3 (MPEG audio layer 3)
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
c1=mp3 (Lib)
c2=128
c3=44100
c4=2
c5=N/P 23.976
c6=Demux Video
c7=25.000 fps
c8=4:3
c9=Default
c10=DIVX
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 