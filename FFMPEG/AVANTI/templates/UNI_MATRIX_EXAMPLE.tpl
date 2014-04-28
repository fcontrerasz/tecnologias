[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=MATRIX / example shows use of quantizer matrices
tpl_com=This example shows how user matrix commands are handled.Select "Get user VIDEO opts" to call up the commands for editing.You can load/insert cqm and xcm matrices at the expanded report windowwhich will be formatted for direct transfer to the command line.Also see the Avanti Help (Appendix) on this subject.
tpl_v_cdbe=mpg,m2v,mpg,DEVSDT,mpeg2video,mpeg2,Y,MPEG-2 video
tpl_a_cdbe=ac3,---,---,DEA   ,ac3,ac3,Y,ATSC A/52 / AC-3
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=Source
v_bitrate=4000
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-mbd 2 -cmp 10 -subcmp 3 -precmp 0 -me_range 1023 -intra_matrix 8,16,19,22,26,27,29,34,16,16,22,24,27,29,34,37,19,22,26,27,29,34,34,38,22,22,26,27,29,34,37,40,22,26,27,29,32,35,40,48,26,27,29,32,35,40,48,58,26,27,29,34,38,46,56,69,27,29,35,38,46,56,69,83 -inter_matrix 16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16
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
c5=Disabled
c6=mpeg2
c7=Source
c8=4:3
c9=PS
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 