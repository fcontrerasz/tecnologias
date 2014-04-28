[PARMS]
tpl_ver=0.4.5
tpl_id=UNI
tpl_desc=FLAC audio in original flac format
tpl_com=FLAC (free lossless audio codec) in original flac format.Reduces file size dramatically compared to 16 bit PCM (ms wave).Bitrate setting is not applicable (like with PCM) and the by FFmpegreported bitrate at process log can be ignored.Sample frequency can be changed within the flac specs.Needs flac decoder (e.g. FFdshow audio decoder) and Haali mediasplitter (aka Matroska splitter).
tpl_v_cdbe=vd,vde,---,D V   ,copy,Demux video,N,Avanti System (do not remove)
tpl_a_cdbe=flac,---,---,DEA   ,flac,Flac Audio,Y,FLAC (Free Lossless Audio Codec)
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
d_userExt=.flac
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
c1=Flac Audio
c2=128
c3=44100
c4=2
c5=Disabled
c6=Demux Video
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 