[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=MPEG-2 / PS (example of the -new command line option)
tpl_com=If you start the command line with the -new option, this will give you full controlover the FFmpeg command line (example is set for single A/V source at "Source 1").It uses relative paths and relative labels. These are:@source1 = label to the path at "Source 1"@source2 = label to the path at "Source 2"@destin1 = label to the path at "Destination"@destin2 = label to the path used by Avanti for ES output-das     = label to "Destination Audio settings" at the main page-dvs     = label to "Destination Video settings" at the main page-vpass   = switch that indicates you wish 2-pass encoding (do not add a pass #)-vlog    = label to path used for 2-pass log file (do not add a path)You can freely interchange these paths and labels and add your own optionsas long as they confirm to the FFmpeg conventions.
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
v_userOpt=-new -i "@source1" -dvs -vpass -vlog -das -f vob -y "@destin1"
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
 