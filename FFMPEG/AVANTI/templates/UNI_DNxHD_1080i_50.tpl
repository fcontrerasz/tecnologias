[PARMS]
tpl_ver=0.4.2
tpl_id=UNI
tpl_desc=DNxHD / 1080i 50 (example template + table for adaption)
tpl_com=Example template for PAL DNxHD 1080i 50 and 1080p 25.Use table to adapt this template to your needs.Project Format Resolution Frame Size Bits FPS  <bitrate>---------------------------------------------------------1080i / 59.94   DNxHD 220  1920x1080  8  29.97   220 Mb1080i / 59.94   DNxHD 145  1920x1080  8  29.97   145 Mb1080i / 50      DNxHD 185  1920x1080  8  25      185 Mb1080i / 50      DNxHD 120  1920x1080  8  25      120 Mb1080p / 25      DNxHD 185  1920x1080  8  25      185 Mb1080p / 25      DNxHD 120  1920x1080  8  25      120 Mb1080p / 25      DNxHD  36  1920x1080  8  25       36 Mb1080p / 24      DNxHD 175  1920x1080  8  24      175 Mb1080p / 24      DNxHD 115  1920x1080  8  24      115 Mb1080p / 24      DNxHD  36  1920x1080  8  24       36 Mb1080p / 23.976  DNxHD 175  1920x1080  8  23.976  175 Mb1080p / 23.976  DNxHD 115  1920x1080  8  23.976  115 Mb1080p / 23.976  DNxHD  36  1920x1080  8  23.976   36 Mb1080p / 29.7    DNxHD  45  1920x1080  8  29.97    45 Mb 720p / 59.94   DNxHD 220  1280x720   8  59.94   220 Mb 720p / 59.94   DNxHD 145  1280x720   8  59.94   145 Mb 720p / 50      DNxHD 175  1280x720   8  50      175 Mb 720p / 50      DNxHD 115  1280x720   8  50      115 Mb 720p / 23.976  DNxHD  90  1280x720   8  23.976   90 Mb 720p / 23.976  DNxHD  60  1280x720   8  23.976   60 Mb---------------------------------------------------------
tpl_v_cdbe=mov,---,---,DEV D ,dnxhd,DNxHD,N,VC3/DNxHD
tpl_a_cdbe=wav,---,---,DEA   ,pcm_s16le,wav,Y,PCM signed 16-bit little-endian
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=1920x1080
v_bitrate=185000
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
c6=DNxHD
c7=Source
c8=16:9
c9=Default
c10=DIVX
c11=Source
c12=1920x1080

[#EVENT/#THIS/ID_COMBOEDIT]
 