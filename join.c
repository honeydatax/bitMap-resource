#include "BMP.h"
#define xxx 640
#define yyy 480
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,xxx,yyy);
	clears(&bm,bmm,255,150,150);
	x=8;
//	for(x=8;x>3;x--){
		circle(&bm,bmm,320,240,50,0,0,0);
//	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
