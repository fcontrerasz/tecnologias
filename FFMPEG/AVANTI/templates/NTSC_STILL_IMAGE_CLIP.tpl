[PARMS]
tpl_ver=0.4.2
tpl_id=NTSC
tpl_desc=STILL IMAGE to any format (default set to mpeg2video PS)
tpl_com=This example template creates a still video clip from a image file.Supported formats: bmp, jpg, gif, pcx, tff, tga, png (use recent FFmpeg version).The image must have a 4:3 or 16:9 aspect ratio depending on you destination setting.Because a image has no duration, you MUST set "Limit encode duration" to the desiredduration. You can also use fractions for this, e.g. 0.33 for approx. 20 sec.'Destination Video settings' can be freely set to any desired output format.You can add user options to the basic command line to tweak the video settings.You can add sound to the clip by loading a audio clip at "Source 2" and using:-new -loop_input -i "@source1" -i "@source2" -dvs -das -f vob -y "@destin1"
tpl_v_cdbe=mpg,m2v,mpg,DEVSDT,mpeg2video,mpeg2,Y,MPEG-2 video
tpl_a_cdbe=ac3,---,---,DEA   ,ac3,ac3,Y,ATSC A/52 / AC-3
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=-an
v_check=
v_size=720x480
v_bitrate=2000
v_qscale=
v_minrate=
v_maxrate=
v_bufsize=
v_deint=
v_expandLum=0
a_userOpt=
v_userOpt=-new -loop_input -i "@source1" -dvs -f vob -y "@destin1"
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
c7=23.976 fps
c8=4:3
c9=PS
c10=Default
c11=Source
c12=720x480

[#EVENT/#THIS/ID_COMBOEDIT]
 