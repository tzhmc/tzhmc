void draw_text(){
	for(int i=0;i<text_used;i++){
		char info[100];
		for(int t=0;t<textlist[text_used-i-1].length();t++){
			info[t]=textlist[text_used-i-1][t];
		}
		info[textlist[text_used-i-1].length()]='\0';
		outtextxy(0,400-i*20, info);
	}
	char info[100];
	for(int t=0;t<buffer.length();t++){
		info[t]=buffer[t];
	}
	info[buffer.length()]='\0';
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	outtextxy(0,420, info);
}
