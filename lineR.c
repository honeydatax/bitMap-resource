#include "BMP.h"
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,64,64);
	clears(&bm,bmm,255,0,0);
	line(&bm,bmm,0,0,63,63,255,255,255);
	line(&bm,bmm,63,0,0,63,255,255,255);
	for(x=0;x<63;x=x+16)line(&bm,bmm,x,0,x,63,255,255,255);
	for(y=0;y<63;y=y+16)line(&bm,bmm,0,y,63,y,255,255,255);
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
