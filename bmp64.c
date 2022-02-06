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
struct lines{
	struct pixel px[64];
};
struct BM{
	struct lines liness[64];
};
void setBMPHead(FILE *f1,int w,int h){
	int ajust=0;
	int ajust2=0;
	char *bmid="BM";
	struct headerBMP hb;
	//bmp -------
//	hb->ID[0]='B';
//	hb->ID[1]='M';
	ajust=w/8;
	if(ajust*8==w){
		ajust2=0;
	printf("%d\n",ajust2);	
	}else{
		ajust2=(ajust+1*8)-(ajust*8);
		printf("%d\n",ajust2);	
	}
	hb.size=54+(w*3+ajust2)*h;
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
	hb.rawSize=(w*3+ajust2)*h;
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
			setBMPHead(f1,64,64);
			for(i=0;i<64;i++){
				for(ii=0;ii<64;ii++){
						bm.liness[i].px[ii].b=255;
						bm.liness[i].px[ii].g=i*4;
						bm.liness[i].px[ii].r=i*4;
				}
			}
			fwrite(&bm,sizeof(bm),1,f1);
			fclose(f1);
		}
}
