[PARMS]
tpl_ver=0.5.2
tpl_id=UNI
tpl_desc=METADATA / Dump source clip metadata/chapters to text file
tpl_com=This template dumps the metadata and chapter info from the source clipto a FFmpeg compatible text file.It is saved at the destination path as a "destination name.ffmeta" text fileand can be opened and modified in a simple text editor like Wordpad.To include a metadata text file when encoding, add the following to the"user VIDEO options" command line or at the [infile] section if you alreadyuse [infile] redirection. -i "full_path_to_text_file" < [optional commands]IMPORTANT: In both cases, you have to disable the "Metadata Manager" option.
tpl_v_cdbe=ffmeta,---,---,DEV D ,ffmetadata,Metadata Dump,Y,Dump FFmpeg metadata
tpl_a_cdbe=ad,---,---,D A   ,copy,copy audio,N,Avanti System (do not remove)
avs_mode=AUTO
src2avs1=0
src2avs2=0
a_check=-an
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
v_userOpt=-an -vn -sn -f ffmetadata
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
c2=80
c3=22050
c4=2
c5=Disabled
c6=Metadata Dump
c7=Source
c8=Source
c9=Default
c10=Default
c11=Source
c12=Source

[#EVENT/#THIS/ID_COMBOEDIT]
 
 