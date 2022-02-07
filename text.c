#include "BMP.h"
int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=setBMPHead(&bm,64,64);
	clears(&bm,bmm,255,0,0);
	x=8;
//	for(x=8;x>3;x--){
		gputs(&bm,bmm,20,20,255,255,255,"hello");
		
//	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
