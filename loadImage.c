#include "BMP.h"


int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=loadBMP("my.bmp",&bm);
	if(bmm==NULL){
		puts("error bitmap not a 24 bit color compativel");
		return 0;
	}
	clears(&bm,bmm,255,0,0);
	x=8;
	ball(&bm,bmm,31,31,5,255,255,255);

	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
