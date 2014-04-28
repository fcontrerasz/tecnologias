[PARMS]
tpl_ver=0.6.1
tpl_id=NTSC
tpl_desc=MPEG-1 - low bitrate / highest possible quality
tpl_com=MPEG-1 template example that follows the VCD specs as close as possible.VCD requires CBR but FFmpeg is not able to encode this properly with MPEG-1.Tries to achieve the highest posible quality for this codec.You can increase the bitrate if VCD compliance is not required.If you're looking for a format that will play on any (old) Windows install,without additional codecs, this is the one.With noisy sources, use the "Denoise" option (30-60).With interlaced sources, use the "Deinterlace" option.
tpl_v_cdbe=mpg,m1v,mpg,DEVSDT,mpeg1video,mpeg1,Y,mpeg1 video
tpl_a_cdbe=mp2,---,---,DEA   ,mp2,mp2,Y,MP2 (MPEG audio layer 2)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_sync=0
v_pts=0
a_check=
v_check=
v_size=352x240
v_bitrate=1150
v_qscale=
v_minrate=1150
v_maxrate=
v_bufsize=
v_deint=
v_deintFld= AUTO
vf_hqdn3d=0
vf_unsharp=0
v_expandLum=0
a_userOpt=
v_userOpt=-trellis 2 -mbd 2 -cmp 2 -subcmp 2 -g 15 -bf 2 -flags2 sgop -flags cgop -sc_threshold 1000000000
d_userExt=
avs_rgb=N,1,1,1,1,0,0,0,0,1,1,1,1,false
avs_hsbc=N,0,1,0,1
cps_use=0
ffmp_pass=1
post_proc=No post process scheduled
av_pitch=1
userComState=0

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
c2=224
c3=44100
c4=2
c5=Disabled
c6=mpeg1
c7=23.976 fps
c8=4:3
c9=Default
c10=Default
c11=Source
c12=352x240

[#EVENT/#THIS/ID_COMBOEDIT]
 
 