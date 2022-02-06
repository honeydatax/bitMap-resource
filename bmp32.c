#include <stdio.h>
#include <stdlib.h>
#define pixess 32
#define divss 256/pixess
struct headerBMP{
	int size;
	int application;
	int pos;
	//dib
	int sizes;
	int w;
	int h;
	char nPlanes1;
	char nPlanes2;
	char nPixel1;
	char nPixel2;
	int compressions;
	int rawSize;
	int rw;
	int rh;
	int colors;
	int importColors;
};
struct pixel{
	char b;
	char g;
	char r;
};
struct lpixel {
	char aa;
	char bb;
};
struct lines{
	struct pixel px[pixess];
};
struct BM{
	struct lines liness[pixess];
};
void setBMPHead(FILE *f1,int w,int h){
	int ajust=0;
	int ajust2=0;
	char *bmid="BM";
	struct headerBMP hb;
	//bmp -------
//	hb->ID[0]='B';
//	hb->ID[1]='M';8
	hb.size=54+(w*3)*h;
	hb.application=0;
	hb.pos=54;
	//dib -------
	hb.sizes=40;
	hb.w=w;
	hb.h=h;
	hb.nPlanes1=1;
	hb.nPlanes2=0;
	hb.nPixel1=24;
	hb.nPixel2=0;
	hb.compressions=0;
	hb.rawSize=(w*3)*h;
	hb.rw=2835;
	hb.rh=2835;
	hb.colors=0;
	hb.importColors=0;
	if(f1!=NULL){
			fseek(f1,0,SEEK_SET);
			fwrite(bmid,2,1,f1);
			fwrite(&hb,sizeof(hb),1,f1);
	}
}
int main(int argc,char *argv[]){
	char *files="my.bmp";
	struct lines ln;
	struct BM bm;
	FILE *f1;
	int i;
	int ii;
	printf("\ec\e[44;36m\n\a\n");
	f1=fopen(files,"w");
	
		if(f1!=NULL){
			setBMPHead(f1,pixess,pixess);
			for(i=0;i<pixess;i++){
				for(ii=0;ii<pixess;ii++){
						bm.liness[i].px[ii].b=255;
						bm.liness[i].px[ii].g=i*divss;
						bm.liness[i].px[ii].r=i*divss;
				}
			}
			fwrite(&bm,sizeof(bm),1,f1);
			fclose(f1);
		}
}
