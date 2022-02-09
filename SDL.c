//g++ door.c  -o door -lSDL
#include <SDL/SDL.h>
#include "BMP.h"
int main(int argc,char *argv[]){
	int n;
	int nn;
	struct headerBMP bm;
	void *bmm;
	SDL_Surface *sss;
	SDL_Event event;
	if(argc<2)exit(0);
	SDL_Rect rrr[1]={0,0,640,480};
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	bmm=loadBMP(argv[1],&bm);
	struct lines{
		struct pixel px[bm.w];
	};
	struct BM{
		struct lines liness[bm.h];
	};
	struct BM *bmms;
	bmms=bmm;
	if(bmm==NULL)exit(0);
	sss=SDL_SetVideoMode(bm.w,bm.h,16,0);
	SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,0,0,255));
	SDL_UpdateRects(sss,1,rrr);
	short int *pixels=(short int*) sss->pixels;
	for(n=0;n<bm.h;n++){
		for(nn=0;nn<bm.w;nn++){
			pixels[n*sss->w+nn]=(bmms->liness[n].px[nn].b/8)|((bmms->liness[n].px[nn].g/8)<<6)|((bmms->liness[n].px[nn].r/8)<<11);
		}
	}
	SDL_Flip(sss);
	SDL_WM_SetCaption("SDL...",NULL);
	while(1){
		if(SDL_PollEvent(&event)){
			if(event.type==SDL_KEYDOWN){
				if(event.key.keysym.sym==SDLK_ESCAPE)break;

			}
			else if (event.type==SDL_QUIT){
				break;
				
			}
			
		}
	}
		if(bmm!=NULL)free(bmm);
	return 0;
}
