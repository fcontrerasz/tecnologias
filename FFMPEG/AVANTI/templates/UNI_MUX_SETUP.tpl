[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=MUX (only) setup / for all formats (read comment on mpeg2)
tpl_com=This template disables all undesirable options and setup the environment formultiplexing of separate audio/video sources. All basic audio/video settingsexcept "codec" are ignored. Do not change any other setting.General setup to 'mux' separate audio/video sources like e.g. mpeg2, mpeg4, xvid,h264 and their related audio into any supported container (mpg, vob, avi, mp4,m4v, mkv etc).You need to select the desired container at the "Container" dropdown list.When you use this template to 'mux' mpeg2 into the vob or mpg container,Avanti will automatically add the -fflags genpts and -f vob commands.If you have mpeg2/ac3 or mpeg2/mp2 audio sync problems with these commands,try the dedicated mpeg2 'mux/remux' template (read comments on user adaption).
tpl_v_cdbe=vd,---,---,D V   ,copy,Mux video,N,Avanti System (do not remove)
tpl_a_cdbe=ad,---,---,D A   ,copy,Mux audio,N,Avanti System (do not remove)
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
c1=Mux Audio
c2=192
c3=48000
c4=2
c5=Disabled
c6=Mux Video
c7=Source
c8=4:3
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 