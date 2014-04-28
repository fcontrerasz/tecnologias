[PARMS]
tpl_ver=0.5.3
tpl_id=UNI
tpl_desc=D10 / Sony IMX (includes adaption info)
tpl_com=Example template for PAL D10 (aka Sony IMX) Encoding (Final Cut Pro compliant).You can adapt this template to other PAL/NTSC variants. After you made yourchanges, enter the related vtag (see list below) at the "Force FourCC to" fieldon the main page and press enter to store it permanently.Notes :- Change bitrate, minrate and maxrate values to 30000k / 40000k / 50000k  in order to produce 30/40/50 Mbps D10 essence.- Set bufsize and rc_init_occupancy values to 1200000 / 1600000 / 2000000  for 30/40/50 Mbps D10 essence (call up "user video opts").- Set qmax value to 8 / 3 / 3 for 30/40/50 Mbps D10 essence.- Add "-vfin scale=0:0,pad=720:608:0:32" option if you want to produce  a 720x608 D10 image size from a 720x576 source.- Set -vtag to mx3p / mx4p / mx5p for D10 30/40/50 PAL  or  -vtag  mx3n / mx4n / mx5n for D10 30/40/50 NTSC. vtag  MPEG2 IMX profile--------------------------------'mx5n, MPEG2 IMX NTSC 525/60 50mb/s'mx5p, MPEG2 IMX PAL 625/50 50mb/s'mx4n, MPEG2 IMX NTSC 525/60 40mb/s'mx4p, MPEG2 IMX PAL 625/50 40mb/s'mx3n, MPEG2 IMX NTSC 525/60 30mb/s'mx3p, MPEG2 IMX PAL 625/50 30mb/s
tpl_v_cdbe=mpg,m2v,mpg,DEVSDT,mpeg2video,mpeg2,Y,MPEG-2 video
tpl_a_cdbe=wav,---,---,DEA   ,pcm_s16le,wav,Y,PCM signed 16-bit little-endian
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=
v_check=
v_size=720x576
v_bitrate=50000
v_qscale=
v_minrate=50000
v_maxrate=50000
v_bufsize=
v_deint=
vf_hqdn3d=0
vf_unsharp=0
v_expandLum=0
a_userOpt=
v_userOpt=-pix_fmt yuv422p -intra -flags +ildct+low_delay -dc 10 -non_linear_quant 1 -intra_vlc 1 -ps 1 -qmin 1 -qmax 3 -top 1 -bufsize 2000000 -rc_init_occupancy 2000000 -rc_buf_aggressivity 0.25
d_userExt=
avs_rgb=N,1,1,1,1,-39,18,50,0,1.5,1.5,1.5,1.5,false
avs_hsbc=N,0,0,0,1
cps_use=0
ffmp_pass=1
post_proc=No post process scheduled
av_pitch=1

[PARMS2]
cps_po=csp
c_lrtb=0,0,0,0
p_lrtb=0,0,72,72,0/0/0
d_width=720
d_height=576
sc_algo_0=Lanczos
sc_algo_1=Lanczos4
cps_sys=0
cps_calc_scr=
cps_colspc=0

[DROPSELECT]
c1=wav
c2=1536
c3=48000
c4=2
c5=Disabled
c6=mpeg2
c7=25.000 fps
c8=4:3
c9=mov
c10=mx5p
c11=Source
c12=720x576

[#EVENT/#THIS/ID_COMBOEDIT]
 
 