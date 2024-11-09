inline void draw_screen(){
	for(int i=0;i<800;i++){
		for(int j=0;j<500;j++){
			if(window[i][j])putpixel_f(i,j,window[i][j]);
		}
	}
	for(int i=0;i<800;i++){
		for(int j=0;j<500;j++){
			window[i][j]=BLACK;
		}
	}
}
