







			$SP,"<1>",BI=1$









I64 global_r[4][4];

U0 DrawIt(CTask *,CDC *dc)
{
	I64 *old_r=dc->r;
	dc->x=200;
	dc->y=200;
	dc->z=GR_Z_ALL;
	dc->flags|=DCF_TRANSFORMATION;
	DCDepthBufAlloc(dc);
	DCMat4x4Set(dc,global_r); //This assigns to dc->r and sets r_norm.
	DCDepthBufReset(dc);
	Sprite3(dc,0,0,0,$IB,"<1>",BI=1$);
	dc->r=old_r;
}

U0 SpritePlot3D()
{
	F64 �=0,�=0;

	SettingsPush; //See $LK,"SettingsPush",A="MN:SettingsPush"$
	Fs->draw_it=&DrawIt;
	while (!CharScan) {
		Mat4x4IdentEqu(global_r);
		Mat4x4RotX(global_r,�);
		Mat4x4RotZ(global_r,�);

		Sleep(40);
		�+=2*�/100;
		�+=2*�/130;
	}
	SettingsPop;
}

SpritePlot3D;
        �            ��������    2   ����        2       2   ����2   ��������2       2   2                                                                                                       