#include "BMP.h"
#define xxx 640
#define yyy 480
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,xxx,yyy);
	clears(&bm,bmm,255,0,0);
	x=8;
	for(x=60;x>3;x=x-6){
		ball(&bm,bmm,320,240,x,255,x*4,x*4);
	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
