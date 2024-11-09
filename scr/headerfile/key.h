string buffer;
string textlist[100];
int text_used;
int textwait;
void get_key(){
	if(!openbag&&!opentext){
		if(GetAsyncKeyState('W')) ty=0.2;
		if(GetAsyncKeyState('S')) ty=-0.15;
		if(GetAsyncKeyState(' ')&&(chu.m_block[int_(-xp+0.35)][int_(-yp-0.35)][int(-zp-2)].m_name!=0||
		        				   chu.m_block[int_(-xp+0.35)][int_(-yp+0.35)][int(-zp-2)].m_name!=0||
		        				   chu.m_block[int_(-xp-0.35)][int_(-yp-0.35)][int(-zp-2)].m_name!=0||
		        				   chu.m_block[int_(-xp-0.35)][int_(-yp+0.35)][int(-zp-2)].m_name!=0
		)) tz=-0.4;
		if(GetAsyncKeyState('A')) tx=0.15;
		if(GetAsyncKeyState('D')) tx=-0.15;
	}
	if(GetAsyncKeyState('E')&&bagwait==0&&!opentext){
		openbag=!openbag;
		bagwait=3;
	}
	if(GetAsyncKeyState('T')&&!openbag&&!opentext){
		opentext=1;
		textwait=3;
	}
	if(GetAsyncKeyState(VK_OEM_2)&&!openbag&&!opentext){
		opentext=1;
		textwait=3;
		buffer="/";
	}
	if(opentext){
		if(GetAsyncKeyState(VK_RETURN)){
			if(buffer[0]!='/'){
				textlist[text_used]=buffer;
			}
			buffer="";
			opentext=0;
			text_used++;
		}
		if(!textwait){
			for(char k='A';k<='Z';k++){
				if(GetAsyncKeyState(k)&&!textwait){
					buffer+=(k-'A'+'a');
					textwait=2;
				}
			}
			for(char k='0';k<='9';k++){
				if(GetAsyncKeyState(k)&&!textwait){
					buffer+=(k);
					textwait=2;
				}
			}
			for(int k=0;k<=9;k++){
				
				if(GetAsyncKeyState(k+0x60)&&!textwait){
					buffer+=(char(k+'0'));
					textwait=2;
				}
			}
			if(GetAsyncKeyState(' ')&&!textwait){
				buffer+=' ';
				textwait=2;
			}
			if(GetAsyncKeyState(VK_BACK)&&!textwait&&buffer.length()>=1){
				string tmp;
				for(int i=0;i<buffer.length()-1;i++){
					tmp+=buffer[i];
				}
				buffer=tmp;
				textwait=2;
			}
			if((GetAsyncKeyState(VK_DECIMAL)||GetAsyncKeyState(VK_OEM_PERIOD))&&!textwait){
				buffer+='.';
				textwait=2;
			}
			if(GetAsyncKeyState(VK_OEM_COMMA)&&!textwait){
				buffer+=',';
				textwait=2;
			}
		}
	}
}
