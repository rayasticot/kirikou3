#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

/*void CaveUpdate(){
    NF_SpriteOamSet(0);
    NF_SpriteOamSet(1);

    swiWaitForVBlank();

    oamUpdate(&oamMain);
    oamUpdate(&oamSub);

    scanKeys();
    kirikouUpdate();
    EvilUpdate();
}

void OverworldUpdate(){
    while(1){
        NF_SpriteOamSet(0);
        NF_SpriteOamSet(1);

        swiWaitForVBlank();

        oamUpdate(&oamMain);
        oamUpdate(&oamSub);

        scanKeys();
        kirikouUpdate();
        UpdateObj();
        if(KEY_Y & keysDown()){
			LoadCave(&cavebe, &be);
		}
        if(timer != 0) timer--;
        if(iscave == true) CaveUpdate();
    }
}*/