#include <stdio.h>
#include <stdlib.h>
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
char *setBMPHead(struct headerBMP *hb,int w,int h){
	int ajust=0;
	int ajust2=0;
	char *strings;
	//bmp -------
	hb->size=54+(w*3)*h;
	hb->application=0;
	hb->pos=54;
	//dib -------
	hb->sizes=40;
	hb->w=w;
	hb->h=h;
	hb->nPlanes1=1;
	hb->nPlanes2=0;
	hb->nPixel1=24;
	hb->nPixel2=0;
	hb->compressions=0;
	hb->rawSize=(w*3)*h;
	hb->rw=2835;
	hb->rh=2835;
	hb->colors=0;
	hb->importColors=0;
	strings=malloc(hb->rawSize+10);
	return strings;
}
void saveBMP(char *files,struct headerBMP *hb, char *bm){
	char *bmid="BM";	
	FILE *f1;
	if(files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
				fseek(f1,0,SEEK_SET);
				fwrite(bmid,2,1,f1);
				fwrite(hb,hb->pos-2,1,f1);
				fwrite(bm,hb->rawSize,1,f1);
				fclose(f1);
		}
	}
}
void setPixel(struct headerBMP *hb, void *bm,int x,int y,int b,int g,int r){
	struct lines{
	struct pixel px[hb->w];
	};
	struct BM{
	struct lines liness[hb->h];
	};
	struct BM *bmms=bm;
	if(x<hb->w && y<hb->h && y>-1 && x>-1){
		bmms->liness[hb->h-y-1].px[hb->w-x-1].b=b;
		bmms->liness[hb->h-y-1].px[hb->w-x-1].g=g;
		bmms->liness[hb->h-y-1].px[hb->w-x-1].r=r;
	}

}
