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
cave* curcave;
u16_f timer;
bool iscave = false;
balle bal;
u8_f cur_song = MOD_BAISE;

bool checkCollision(int x1, int y1, int sx1, int sy1, int x2, int y2, int sx2, int sy2){
	if(x1+sx1 > x2 && x1 < x2+sx2){
		if(y1+sy1 > y2 && y1 < y2+sy2){
			return true;
		}
	}
	return false;
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
  	NF_LoadTiledBg("bg/loading", "load", 256, 256);
  	NF_CreateTiledBg(0, 3, "load");
	mmInitDefault("nitro:/soundbank.bin"); // CREDIT A MATHISZER HAHAHAHAHA C4EST LUI QUI A ECRIT CE CODE HAHAHAHAHHAHAHA LE GOAT
	//mmInitDefaultMem((mm_addr)soundbank_bin); // J'ABANDONNE
	NF_InitCmapBuffers();

	NF_LoadSpriteGfx("spr/nada", 0, 16, 32);
	NF_LoadSpritePal("spr/nada", 0);
	NF_VramSpriteGfx(1, 0, 0, false);
	NF_VramSpritePal(1, 0, 0);

	/*NF_LoadSpriteGfx("spr/mini", 15, 8, 8);
	NF_LoadSpritePal("spr/mini", 15);
	NF_VramSpriteGfx(0, 15, 15, false);
	NF_VramSpritePal(0, 15, 15);*/

	curmap = &be;

	LoadMap(curmap);
	kirikouStart();
	NF_DeleteTiledBg(0, 3);

	while(1){
		NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		scanKeys();
		kirikouUpdate();
		UpdateObj();
		if(iscave == true){
			EvilUpdate();
			kirikouGunUpdate();
		}
		if(KEY_Y & keysDown() && iscave == false){
			LoadCave(&cavebe, &be);
		}
		if(timer != 0) timer--;
	}
	return 0;
}
