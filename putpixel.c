#include "BMP.h"
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,64,64);
	for(y=0;y<64;y++){
		for(x=0;x<64;x++){
			setPixel(&bm,bmm,x,y,255,y*4,y*4);
		}
	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
