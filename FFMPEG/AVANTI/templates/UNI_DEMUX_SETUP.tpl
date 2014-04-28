[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=DEMUX setup (disables all undesirable settings)
tpl_com=This template disables all undesirable options and setup the environmentfor de-multiplexing of combined audio/video sources at "Source 1".For this option, "Source 2" must be empty. All basic audio/video settingsexcept "codec" are ignored. Do not change any other setting.Audio and video must be processed separtately. By default the audio sectionis disabled to demux the video stream. Reverse this setting fo the audio stream.
tpl_v_cdbe=vd,vde,---,D V   ,copy,Demux video,N,Avanti System (do not remove)
tpl_a_cdbe=ad,ade,---,D A   ,copy,Demux audio,N,Avanti System (do not remove)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
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
c1=Demux Audio
c2=192
c3=48000
c4=2
c5=Disabled
c6=Demux Video
c7=Source
c8=Source
c9=ES
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 
 