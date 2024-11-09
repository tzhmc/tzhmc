color_t window[900][600];
class Point2D{
	public:
	double x;
	double y;
	Point2D(double _x=0,double _y=0){
		x=_x;
		y=_y;
	}
};
typedef Point2D TWODAPI;
TWODAPI getplace(Point a){
	a.y=-a.y;a.x+=xp;a.y-=yp;a.z+=zp;
	double x,y,z;
	x=a.x;y=a.y;a.x=x*cos(txy)-y*sin(txy);a.y=x*sin(txy)+y*cos(txy);
	x=a.x;z=a.z;a.x=x*cos(txz)-z*sin(txz);a.z=x*sin(txz)+z*cos(txz);
	y=a.y;z=a.z;a.y=y*cos(tyz)-z*sin(tyz);a.z=y*sin(tyz)+z*cos(tyz);
	Point2D res;
	if(a.y<=0||a.y>=looksize) return res;
	res.x=a.x/a.y*800*camerasize+800;
	res.y=500-a.z/a.y*800*camerasize;
	return res;
}
inline TWODAPI getpartofAB(Point2D start,Point2D end,int all,int part){
	Point2D res;
	res=start;
	res.x+=(end.x-start.x)/all*part;
	res.y+=(end.y-start.y)/all*part;
	return res;
}
