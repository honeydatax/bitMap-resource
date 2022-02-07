#include "BMP.h"
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,64,64);
	for(y=0;y<63;y=y+16)box(&bm,bmm,0,y,63,16,255,y*4,y*4);
	
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
