int mx,my,lx,ly;
inline void get_mouse(){
	mousepos(&mx,&my);
	if(openbag){
		
	}
	else if(opentext);
	else{
		txy-=asin(1)*2/200*(1.0*(lx-mx)/2)*2;
		tyz-=asin(1)*2/200*(1.0*(ly-my)/2)*2;
		mousepos(&lx,&ly);
		if(GetAsyncKeyState(VK_LBUTTON)){
			chu.m_block[dig[0]][dig[1]][dig[2]].m_name=0;
		}
		if(GetAsyncKeyState(VK_RBUTTON)&&
		((dig[3]!=-(int)ceil(xp)||dig[4]!=-(int)ceil(yp))&&
		 (dig[3]!=-(int)floor(xp)||dig[4]!=-(int)ceil(yp))&&
		 (dig[3]!=-(int)floor(xp)||dig[4]!=-(int)floor(yp))&&
		 (dig[3]!=-(int)ceil(xp)||dig[4]!=-(int)floor(yp))||
		 (dig[5]!=int(-zp-1.5)&&dig[5]!=int(-zp-1.5)+1))){
			chu.m_block[dig[3]][dig[4]][dig[5]].m_name=4;
		}
	}
}
