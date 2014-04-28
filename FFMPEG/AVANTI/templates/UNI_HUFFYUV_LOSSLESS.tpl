[PARMS]
tpl_ver=0.4.9
tpl_id=UNI
tpl_desc=HUFFYUV (intermediar format for NLE editing)
tpl_com=Huffyuv lossless format is mainly of interest as intermediar for source formatsthat are not supported by NLE programs. It uses a large amount of diskspaceand is intended to convert to a final more compressed format after editing.Frame size, frame rate and aspect ratio are set to "Source" and may needadaption, depending on the source and desired destination.
tpl_v_cdbe=avi,---,---,DEVSD ,huffyuv,Huffyuv,Y,Huffyuv / HuffYUV
tpl_a_cdbe=wav,---,---,DEA   ,pcm_s16le,wav,Y,PCM signed 16-bit little-endian
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
c1=wav
c2=1536
c3=48000
c4=2
c5=Disabled
c6=huffyuv
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 
 