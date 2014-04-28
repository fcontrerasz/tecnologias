[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=INFO / considerations before you start encoding
tpl_com=This info is applicable on all conversions.Depending on the used settings and in conjunction with the source quality,FFmpeg needs to vary the quantizer scale or the required bitrate.For sources with a inferior quality this can lead to bad encode quality orundesirable high bitrates. In such case it is recommended to use Avisynthpre-processing with the excelent hqdn3d noise filter.Ensure that the hqdn3d.dll is in your Avisynth plugins folder, copy nextlines to the Avanti Avisynth editior and enable the Avisynth USER mode:   DirectShowSource("@source1_path")   ConvertToYV12()   hqdn3d(x)Practical values for x are in the range 2-6 depending on the source quality.
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
c1=Copy Audio
c2=64
c3=11025
c4=2
c5=Disabled
c6=Copy Video
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 