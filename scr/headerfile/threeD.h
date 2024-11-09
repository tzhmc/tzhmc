
#ifndef _EGE_THREED_H_
#define _EGE_THREED_H_
#endif

#ifndef _EGE_H_
#error include "threeD.h" must after include "ege.h" or "graphics.h"
#endif
double camerasize=0;
double txy,txz,tyz;
double xp,yp,zp;
inline void setcamerasize(int angle){
	camerasize=1/tan(asin(1)*2/(360.0/angle));
}
struct Point{
	float x,y,z;
};
typedef Point THREEDAPI;
inline THREEDAPI getmidle(Point a,Point b,Point c,Point d){
	Point res;
	res.x=(a.x+b.x+c.x+d.x)/4;
	res.y=(a.y+b.y+c.y+d.y)/4;
	res.z=(a.z+b.z+c.z+d.z)/4;
	return res;
}
inline double getdis(Point a){
	return sqrt((a.x+xp)*(a.x+xp)+(a.y+yp)*(a.y+yp)+(a.z+zp)*(a.z+zp));
}
bool is_look(Point a){
	a.y=-a.y;a.x+=xp;a.y-=yp;a.z+=zp;
	double x,y,z;
	x=a.x;y=a.y;a.x=x*cos(txy)-y*sin(txy);a.y=x*sin(txy)+y*cos(txy);
	x=a.x;z=a.z;a.x=x*cos(txz)-z*sin(txz);a.z=x*sin(txz)+z*cos(txz);
	y=a.y;z=a.z;a.y=y*cos(tyz)-z*sin(tyz);a.z=y*sin(tyz)+z*cos(tyz);
	if(a.y<=-1.5||a.y>=looksize) return 0;
	return 1;
}
bool is_look2(double x,double y,double z){
	Point a;
	a.x=x;
	a.y=y;
	a.z=z;
	return is_look(a);
}
