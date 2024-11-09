#include<string>
#include<map>
#define mi(a,b) ((a)<(b)?a:b)
#define ma(a,b) ((a)>(b)?a:b)
map<string,int> ima_name;
map<int,string> block_name;
PIMAGE ima[100];
bool xface[2][2][2];
inline void _load(){
	PIMAGE logo=newimage();
	getimage(logo, "..//ima//first//logo.png");
	putimage(0,0,logo);
	delay_ms(0);
	for(int i=0;i<800;i++){
		for(int j=0;j<500;j++){
			window[i][j]=BLACK;
		}
	}
	xp=-100;
	yp=-100;
	zp=-(int((1.0*(PerlinNoise(1.0*80/168,1.0*80/168)+1)/2+1)*120+8)-20);
	block_name[0]="none";
	block_name[1]="grass";
	block_name[2]="soil";
	block_name[3]="rock";
	block_name[4]="tree";
	block_name[5]="leave";
	block_name[6]="dirt";
	ima_name["grasstop"]=0;
	ima[0]=newimage();
	getimage(ima[0], "..//ima//block//grass//1.png");
	ima_name["grassside"]=1;
	ima[1]=newimage();
	getimage(ima[1], "..//ima//block//grass//2.png");
	ima_name["grassbotton"]=2;
	ima[2]=newimage();
	getimage(ima[2], "..//ima//block//grass//3.png");
	
	ima_name["treetop"]=3;
	ima[3]=newimage();
	getimage(ima[3], "..//ima//block//tree//1.png");
	ima_name["treeside"]=4;
	ima[4]=newimage();
	getimage(ima[4], "..//ima//block//tree//2.png");
	ima_name["treebotton"]=5;
	ima[5]=newimage();
	getimage(ima[5], "..//ima//block//tree//3.png");
	
	ima_name["rocktop"]=6;
	ima[6]=newimage();
	getimage(ima[6], "..//ima//block//rock//1.png");
	ima_name["rockside"]=7;
	ima[7]=newimage();
	getimage(ima[7], "..//ima//block//rock//2.png");
	ima_name["rockbotton"]=8;
	ima[8]=newimage();
	getimage(ima[8], "..//ima//block//rock//3.png");
	
	ima_name["leavetop"]=9;
	ima[9]=newimage();
	getimage(ima[9], "..//ima//block//leave//1.png");
	ima_name["leaveside"]=10;
	ima[10]=newimage();
	getimage(ima[10], "..//ima//block//leave//2.png");
	ima_name["leavebotton"]=11;
	ima[11]=newimage();
	getimage(ima[11], "..//ima//block//leave//3.png");
	
	ima_name["dirttop"]=12;
	ima[12]=newimage();
	getimage(ima[12], "..//ima//block//dirt//1.png");
	ima_name["dirtside"]=13;
	ima[13]=newimage();
	getimage(ima[13], "..//ima//block//dirt//2.png");
	ima_name["dirtbotton"]=14;
	ima[14]=newimage();
	getimage(ima[14], "..//ima//block//dirt//3.png");
	
	ima_name["bag"]=50;
	ima[50]=newimage();
	getimage(ima[50], "..//ima//gui//bag//bag.png");
}
class BLOCK{
	public:
	int m_name=0,x,y,z;
	Point p[8];
	float d;
	inline void _load();
	inline void _draw(BLOCK *y0,BLOCK *y1,BLOCK *x0,BLOCK *x1,BLOCK *z0,BLOCK *z1);
};
int dig[6];

struct FACE{
	int x,y,z;
	int x0,y0,z0;
	Point point[4];
	double d;
	string name;
}_face[looksize*looksize*256*6];
int used;
inline FACE getd(FACE a){
	a.d=getdis(getmidle(a.point[0],a.point[1],a.point[2],a.point[3]));
	return a;
}
inline bool face_cmp(FACE a,FACE b){
	return a.d>b.d;
}
inline void BLOCK::_load(){
	register int t=0;
	for(register double i=x-0.5;i<=x+0.5;++i){
		for(register double j=y-0.5;j<=y+0.5;++j){
			for(register double k=z-0.5;k<=z+0.5;++k){
				p[t].x=i;
				p[t].y=j;
				p[t++].z=k;
			}
		}
	}
}
inline void BLOCK::_draw(BLOCK *y0,BLOCK *y1,BLOCK *x0,BLOCK *x1,BLOCK *z0,BLOCK *z1){
	if(y0->m_name==0&&-yp<y){
		_face[used].point[0]=p[1];
		_face[used].point[1]=p[0];
		_face[used].point[2]=p[5];
		_face[used].point[3]=p[4];
		_face[used].name=block_name[m_name]+"side";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=y0->x;
		_face[used].y0=y0->y;
		_face[used].z0=y0->z;
		++used;
	}
	//y-
	if(x0->m_name==0&&-xp<x){
		_face[used].point[0]=p[3];
		_face[used].point[1]=p[2];
		_face[used].point[2]=p[1];
		_face[used].point[3]=p[0];
		_face[used].name=block_name[m_name]+"side";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=x0->x;
		_face[used].y0=x0->y;
		_face[used].z0=x0->z;
		++used;
	}
	//x-
	if(y1->m_name==0&&-yp>y){
		_face[used].point[0]=p[7];
		_face[used].point[1]=p[6];
		_face[used].point[2]=p[3];
		_face[used].point[3]=p[2];
		_face[used].name=block_name[m_name]+"side";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=y1->x;
		_face[used].y0=y1->y;
		_face[used].z0=y1->z;
		++used;
	}
	//y+ 
	if(x1->m_name==0&&-xp>x){
		_face[used].point[0]=p[5];
		_face[used].point[1]=p[4];
		_face[used].point[2]=p[7];
		_face[used].point[3]=p[6];
		_face[used].name=block_name[m_name]+"side";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=x1->x;
		_face[used].y0=x1->y;
		_face[used].z0=x1->z;
		++used;
	}
	//x+
	if(z0->m_name==0&&-zp<z){
		_face[used].point[0]=p[0];
		_face[used].point[1]=p[2];
		_face[used].point[2]=p[4];
		_face[used].point[3]=p[6];
		_face[used].name=block_name[m_name]+"botton";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=z0->x;
		_face[used].y0=z0->y;
		_face[used].z0=z0->z;
		++used;	
	}
	if(z1->m_name==0&&-zp>z){
		_face[used].point[0]=p[1];
		_face[used].point[1]=p[3];
		_face[used].point[2]=p[5];
		_face[used].point[3]=p[7];
		_face[used].name=block_name[m_name]+"top";
		_face[used]=getd(_face[used]);
		_face[used].x=x;
		_face[used].y=y;
		_face[used].z=z;
		_face[used].x0=z1->x;
		_face[used].y0=z1->y;
		_face[used].z0=z1->z;
		++used;
	}
}
inline void _fill_(Point2D p1, Point2D p2, Point2D p3, Point2D p4,color_t color,int x,int y,int z,int x0,int y0,int z0) {  
    register int minX = mi(mi(mi(p1.x, p2.x), p3.x), p4.x);  
    register int maxX = ma(ma(ma(p1.x, p2.x), p3.x), p4.x);  
    register int minY = mi(mi(mi(p1.y, p2.y), p3.y), p4.y);  
    register int maxY = ma(ma(ma(p1.y, p2.y), p3.y), p4.y);
	if(maxX<0||minX>1600||maxY<0||minY>1000)return;
    minX=ma(0,minX);
    maxX=mi(1600,maxX); 
    minY=ma(0,minY); 
    maxY=mi(1000,maxY); 
	if(minX<=810&&minY<=510&&maxX>=790&maxY>=490){
		dig[0]=x;
		dig[1]=y;
		dig[2]=z;
		dig[3]=x0;
		dig[4]=y0;
		dig[5]=z0;
	}
    for(register int i=minX/2;i<maxX/2;++i){
    	for(register int j=minY/2;j<maxY/2;++j){
    		window[i][j]=color;
		}
	}
}  
inline void xr(){
	sort(_face,_face+used,face_cmp);
	register Point2D plist[fbl+1][fbl+1];
	register bool con=0;
	register Point2D p1,p2;
	for(register int k=0;k<used;k++){
		con=0;
		for(register int ti=0;ti<=fbl;++ti){
			p1=getpartofAB(getplace(_face[k].point[0]),getplace(_face[k].point[2]),fbl,ti);
			p2=getpartofAB(getplace(_face[k].point[1]),getplace(_face[k].point[3]),fbl,ti);
			if(p1.x==0&&p1.y==0)con=1;
			if(p2.x==0&&p2.y==0)con=1;
			if(p1.x==0&&p1.y==0)break;
			if(p2.x==0&&p2.y==0)break;
			for(register int tj=0;tj<=fbl;++tj){
				plist[ti][tj]=getpartofAB(p1,p2,fbl,tj);
			}
		}
		if(con)continue;
		for(register int i=0;i<fbl;i++){
			for(register int j=0;j<fbl;j++){
				_fill_(plist[i][j],plist[i][j+1],plist[i+1][j+1],plist[i+1][j],getpixel(1.0*i*16/fbl,1.0*j*16/fbl,ima[ima_name[_face[k].name]]),_face[k].x,_face[k].y,_face[k].z,_face[k].x0,_face[k].y0,_face[k].z0);
			}
		}
	}
	used=0;
}
bool tree[205][205];
inline void load_tree(int x,int y,int z);
class CHUNKS{
	public:
	BLOCK m_block[205][205][258];
	bool is_load[13][13];
	int _x=0,_y=0;
	inline void _fill(int x,int y,int z,int val){
		if(x<0||y<0||x>=200||y>=200||z<0||z>256)return;
		m_block[x][y][z].m_name=val;
	}
	inline void _load(int x,int y){
		if(x<0||y<0||x>=200/16||y>=200/16) return;
		if(is_load[x][y])return;
		is_load[x][y]=1;
		for(register int i=16*x;i<16*x+16;i++){
			for(register int j=16*y;j<16*y+16;j++){
				for(register int k=0;k<256;k++){
					m_block[i][j][k].x=i;
					m_block[i][j][k].y=j;
					m_block[i][j][k].z=k;
					m_block[i][j][k]._load();
				}
			}
		}
		for(register int i=16*x;i<16*x+16;i++){
			for(register int j=16*y;j<16*y+16;j++){
				for(register int k=0;k<int((1.0*(PerlinNoise(1.0*i/168,1.0*j/168)+1)/2+1)*120+8)-20;k++){
					_fill(i,j,k,1);
					if(k<int((1.0*(PerlinNoise(1.0*i/168,1.0*j/168)+1)/2+1)*120+8)-20-4)_fill(i,j,k,3);
					else if(k<int((1.0*(PerlinNoise(1.0*i/168,1.0*j/168)+1)/2+1)*120+8)-20-1)_fill(i,j,k,6);
				}
				if(rand()%26==0)load_tree(i,j,int((1.0*(PerlinNoise(1.0*i/168,1.0*j/168)+1)/2+1)*120+8)-20);
			}
		}
	}
	inline void _draw(){
		for(register int i=-xp-looksize;i<-xp+looksize;++i){
			for(register int j=-yp-looksize;j<=-yp+looksize;++j){
				for(register int k=-zp-looksize;k<-zp+looksize;++k){
					if(!m_block[i][j][k].m_name) continue;
					//if(!is_look2(i,j,k)) continue;
					m_block[i][j][k]._draw(&m_block[i][j-1][k],&m_block[i][j+1][k],&m_block[i-1][j][k],&m_block[i+1][j][k],&m_block[i][j][k-1],&m_block[i][j][k+1]);
					
				}
			}
		}
	}
};
CHUNKS chu;
inline void load_tree(int x,int y,int z){
	if(tree[x][y]) return;
	for(register int i=x-6;i<x+6;i++){
		for(register int j=y-6;j<y+6;j++){
			if(i>=0&&i<200&&j>=0&&j<200)tree[i][j]=1;
		}
	}
	for(register int i=x-2;i<=x+2;i++){
		for(register int j=y-2;j<=y+2;j++){
			chu._fill(i,j,z+4,5);
			chu._fill(i,j,z+5,5);
		}
	}
	for(register int i=x-1;i<=x+1;i++){
		for(register int j=y-1;j<=y+1;j++){
			chu._fill(i,j,z+6,5);
			chu._fill(i,j,z+7,5);
		}
	}
	for(register int i=z;i<z+6;i++){
		chu._fill(x,y,i,4);
	}
}
inline void load_chu(){
	chu._load(-int(xp)/16,-int(yp)/16);
	chu._load(-int(xp)/16+1,-int(yp)/16);
	chu._load(-int(xp)/16-1,-int(yp)/16);
	chu._load(-int(xp)/16,-int(yp)/16+1);
	chu._load(-int(xp)/16,-int(yp)/16-1);
	chu._load(-int(xp)/16+1,-int(yp)/16+1);
	chu._load(-int(xp)/16+1,-int(yp)/16-1);
	chu._load(-int(xp)/16-1,-int(yp)/16+1);
	chu._load(-int(xp)/16-1,-int(yp)/16-1);
}
