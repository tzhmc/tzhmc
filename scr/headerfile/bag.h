int bagwait;
inline void bag(){
	int x=363,y=85;
	if(openbag){
		for(int i=0;i<875;i+=2){
			for(int j=0;j<830;j+=2){
				window[(x+i)/2][(y+j)/2]=getpixel(i/5,j/5,ima[ima_name["bag"]]);
			}
		}
	}
}
