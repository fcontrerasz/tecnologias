[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=MPEG-2 / PAL progressive to NTSC 23.976 progressive
tpl_com=Example template to convert PAL progressive source to NTSC 23.976 progressive."AV conversion", "Frame size" and "Frame rate" are fixed. All other settingscan be changed according to the stream type you wish to encode.This example uses "variable bitrate" settins and B frames. Initial bitrateis set for HQ encode (DVD quality).After you finished the 23.976 progressive encoding use soft flag 2:3 pulldownavailable at the "MPEG/AVI tools" button to create a 29.970 DVD compliant stream.
tpl_v_cdbe=mpg,m2v,mpg,DEVSDT,mpeg2video,mpeg2,Y,MPEG-2 video
tpl_a_cdbe=ac3,---,---,DEA   ,ac3,ac3,Y,ATSC A/52 / AC-3
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=720x480
v_bitrate=5000
v_qscale=
v_minrate=0
v_maxrate=9200
v_bufsize=1835
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-mbd 2 -trellis 1
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
c1=ac3
c2=192
c3=48000
c4=2
c5=P/N 23.976
c6=mpeg2
c7=23.976 fps
c8=4:3
c9=ES
c10=Default
c11=Source
c12=720x480

[#EVENT/#THIS/ID_COMBOEDIT]
 