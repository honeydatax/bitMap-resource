#include "BMP.h"


int main(int argc,char *argv[]){
	struct headerBMP bm;
	char *bmm;
	int y;
	int x;
	bmm=loadMapArray("my.Marray",&bm);
	if(bmm==NULL){
		puts("error bitmap not a 24 bit color compativel");
		return 0;
	}
	saveBMP("my.bmp",&bm,bmm);
	if(bmm!=NULL)free(bmm);
	return 0;
}
