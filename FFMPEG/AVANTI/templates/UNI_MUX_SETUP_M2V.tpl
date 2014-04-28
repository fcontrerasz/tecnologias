[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=MUX/REMUX setup 3 / for mpeg2 video (for older FFmpeg versions)
tpl_com=This template disables all undesirable options and setup the environmentfor multiplexing. All basic audio/video settings except "codec" are ignored.Do not change any other setting.Setup to 'mux/remux' separate or combined mpeg2 audio/video sources like e.g.m2v, mpv, vob, mpg, etc. and their related audio (ac3/mp2) into a vob or mpgcontainer.You need to select the desired container at the "Container" dropdown list.If the default setting is not successful (audio out-of-sync or other issues),change -f vob into -f dvd (always include one of these). Additionally you cantry to add the -async 2 command.With multiple audio streams, you can map out any desirable audio stream byusing "Input stream mapping" assistance (see chm help).
tpl_v_cdbe=vd,---,---,D A   ,copy,copy video,N,Avanti System (do not remove)
tpl_a_cdbe=ad,---,---,D A   ,copy,copy audio,N,Avanti System (do not remove)
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
v_userOpt=-f vob
d_userExt=
avs_rgb=N,1,1,1,1,0,0,0,0,1,1,1,1,false
avs_hsbc=N,0,0,0,1
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
c1=Copy Audio
c2=192
c3=48000
c4=2
c5=Disabled
c6=Copy Video
c7=Source
c8=4:3
c9=mpg
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 