[PARMS]
tpl_ver=0.4.2
tpl_id=PAL
tpl_desc=MPEG-2 / 1-pass HQ constant quality
tpl_com=Example to convert source clip to "Elementary" mpeg2video streams which can beused in DVD authoring programs. Often these programs expect elementary streamselse they have to first seperate them at the expense of time and extra disk space.(Set ES to PS if your authoring program expects "mpg" program streams).This example uses CQ (constant quality) variable bitrate settings.To keep the resulting clip DVD compliant (max rate), FFmpeg may still need toincrease the fixed qscale setting occasionally.Depending on the quality of the source (much noise), FFmpeg may need to use veryhigh bitrates to preserve the desired quality. It then is highly recommendedto use some kind of noise reduction (e.g. by using a small Avisynth script).
tpl_v_cdbe=mpg,m2v,mpg,DEVSDT,mpeg2video,mpeg2,Y,MPEG-2 video
tpl_a_cdbe=mp2,---,---,DEA   ,mp2,mp2,Y,MP2 (MPEG audio layer 2)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=720x576
v_bitrate=
v_qscale=2
v_minrate=
v_maxrate=9000
v_bufsize=1835
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-g 12 -trellis 1 -mbd 2 -lmin 1 -muxrate 10080k
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
c1=mp2
c2=192
c3=48000
c4=2
c5=Disabled
c6=mpeg2
c7=25.000 fps
c8=4:3
c9=ES
c10=Default
c11=Source
c12=720x576

[#EVENT/#THIS/ID_COMBOEDIT]
 