#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "structs.h"

obj kirikou;

#include "functions.h"

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
	NF_InitRawSoundBuffers();
	NF_InitCmapBuffers();

	NF_LoadSpriteGfx("spr/nada", 0, 16, 32);
	NF_LoadSpritePal("spr/nada", 0);
	NF_VramSpriteGfx(1, 0, 0, false);
	NF_VramSpritePal(1, 0, 0);

	NF_LoadTiledBg("bg/benin", "be", 768, 768);
	NF_CreateTiledBg(1, 3, "be");

	while(1){
		NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		scanKeys();
		kirikouUpdate();
	}

	return 0;
}
