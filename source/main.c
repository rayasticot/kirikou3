#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"


#include "define.h"
#include "structs.h"

pos kirikou;
pos cam;
map* curmap;
u16_f timer;

bool checkCollision(int x1, int y1, int sx1, int sy1, int x2, int y2, int sx2, int sy2){
	bool bouf = false;
	if(x1+sx1 > x2 && x1 < x2+sx2){
		if(y1+sy1 > y2 && y1 < y2+sy2){
			bouf = true;
		}
	}
	return bouf;
}

#include "functions.h"
#include "map_benin.h"

int main(int argc, char **argv){

	NF_Set2D(0, 0);
	NF_Set2D(1, 0);
	NF_SetRootFolder("NITROFS");
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);
	NF_InitSpriteSys(1);
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);
	NF_InitTiledBgSys(1);
	soundEnable();
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_BAISE);
	mmStart(MOD_BAISE, MM_PLAY_LOOP);
	NF_InitRawSoundBuffers();
	NF_InitCmapBuffers();

	NF_LoadSpriteGfx("spr/nada", 0, 16, 32);
	NF_LoadSpritePal("spr/nada", 0);
	NF_VramSpriteGfx(1, 0, 0, false);
	NF_VramSpritePal(1, 0, 0);

	curmap = &be;

	LoadMap(curmap);
	kirikouStart();

	while(1){
		NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		scanKeys();
		kirikouUpdate();
		UpdateObj();
		if(timer != 0) timer--;
	}
	return 0;
}
