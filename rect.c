#include "BMP.h"
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,64,64);
	clears(&bm,bmm,255,0,0);
	x=63;
	for(y=0;y<32;y++){
		rectangle(&bm,bmm,y,y,x,x,255,y*4,y*4);
		x--;
	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
