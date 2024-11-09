#pragma GCC optimize(2,"Ofast","inline")
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
double vz;
int fbl=16;
const int looksize=14;
bool openbag=0;
bool opentext=0;
double tx,ty,tz;
double x,y,z;
#include"headerfile/math.h" 
#include"headerfile/threeD.h"
#include"headerfile/twoD.h"
#include"headerfile/noise.h"
#include"headerfile/blocks.h"
#include"headerfile/bag.h"
#include"headerfile/mouse.h"
#include"headerfile/key.h"
#include"headerfile/screen.h"
#include"headerfile/text.h" 
int main(){
	initgraph(800,500,INIT_RENDERMANUAL);
	setcaption("Minecraft bate 2.1 (µ¥ÈËÓÎÏ·)");
	_load();
	PIMAGE start=newimage();
	getimage(start, "..//ima//first//start.png");
	putimage(0,0,start);
	delay_ms(0);
	mousepos(&lx,&ly);
	while(!(lx>251&&ly>278&&lx<548&&ly<366&&GetAsyncKeyState(VK_LBUTTON))){
		mousepos(&lx,&ly);
	}
	setcamerasize(90); 
	for(;;){
		x=0;y=0;
		tx=0;ty=0;
		if(bagwait)bagwait--;
		if(textwait)textwait--;
		get_mouse();
		get_key();
		x=tx;
		y=ty;
		tx=x*cos(txy)-y*sin(txy);ty=x*sin(txy)+y*cos(txy);
		if(chu.m_block[int_(-xp-tx+0.35)][int_(-yp+0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp-tx+0.35)][int_(-yp-0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp-tx-0.35)][int_(-yp+0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp-tx-0.35)][int_(-yp-0.35)][int(-zp-1.5)].m_name==0
		)xp+=tx;
		if(chu.m_block[int_(-xp+0.35)][int_(-yp-ty-0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp+0.35)][int_(-yp-ty+0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp-0.35)][int_(-yp-ty-0.35)][int(-zp-1.5)].m_name==0&&
		   chu.m_block[int_(-xp-0.35)][int_(-yp-ty+0.35)][int(-zp-1.5)].m_name==0
		)yp+=ty;
		
		
		if((chu.m_block[int_(-xp+0.35)][int_(-yp-0.35)][(int)(-zp-1.5-tz)].m_name==0&&
		    chu.m_block[int_(-xp+0.35)][int_(-yp+0.35)][int(-zp-1.5-tz)].m_name==0&&
		    chu.m_block[int_(-xp-0.35)][int_(-yp-0.35)][int(-zp-1.5-tz)].m_name==0&&
		    chu.m_block[int_(-xp-0.35)][int_(-yp+0.35)][int(-zp-1.5-tz)].m_name==0)||tz<=0){
			zp+=tz/2;
			tz+=0.05;
		}
		else if(chu.m_block[int_(-xp+0.35)][int_(-yp-0.35)][(int)(-zp-1.5)].m_name!=0||
		        chu.m_block[int_(-xp+0.35)][int_(-yp+0.35)][int(-zp-1.5)].m_name!=0||
		        chu.m_block[int_(-xp-0.35)][int_(-yp-0.35)][int(-zp-1.5)].m_name!=0||
		        chu.m_block[int_(-xp-0.35)][int_(-yp+0.35)][int(-zp-1.5)].m_name!=0){
			zp-=0.5;
		}
		else tz=0;
		delay_ms(0);
		setfillcolor(EGERGB(101,236,255));
		bar(0,0,1600,1000);
		load_chu();
		chu._draw();
		xr();
		bag();
		draw_screen();
		draw_text();
		register char str[10];
		sprintf(str,"fps:%.3f",getfps());
		xyprintf(0,0,str);
		setfillcolor(BLACK);
		bar(798/2,480/2,802/2,520/2);
		bar(780/2,498/2,820/2,502/2);
	}
}
