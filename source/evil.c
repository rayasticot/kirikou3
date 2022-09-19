#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

static void Gameover(){
  NF_LoadTiledBg("bg/gameover", "bg/gameover", 256, 256);
  NF_CreateTiledBg(0, 3, "bg/gameover");
  mmStop();
  mmEffect(SFX_RIP);
  while(KEY_A ^ keysDown()){
    NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		scanKeys();
  }
  NF_DeleteTiledBg(0, 3);
  NF_UnloadTiledBg("bg/gameover");
  kirikou.x = 384;
  kirikou.y = 64;
  obj* objbuf = curmap->firstobj;
  while(1){
    objbuf->dialog = 1;
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
  mmStart(MOD_CAVE, MM_PLAY_LOOP);
}

void EvilUpdate(obj* objbuf){
  if(objbuf->dialog > 0){
    /*if(objbuf->x > cam.x-32 && objbuf->x - cam.x < 256){
      objbuf->sprx = objbuf->x - cam.x;
    }
    else{
      objbuf->sprx = 256;
    }
    if(objbuf->y > cam.y-32 && objbuf->y - cam.y < 192){
      objbuf->spry = objbuf->y - cam.y;
    }
    else{
      objbuf->spry = 192;
    }*/
    if(objbuf->type == 3){
      if(objbuf->state == 0){
        if(NF_GetTile(0, objbuf->x+33, objbuf->y) == 0){
          objbuf->x+=2;
          NF_HflipSprite(1, objbuf->id, false);
        }
        else{
          objbuf->state = 1;
        }
      }
      if(objbuf->state == 1){
        if(NF_GetTile(0, objbuf->x-1, objbuf->y) == 0){
          objbuf->x-=2;
          NF_HflipSprite(1, objbuf->id, true);
        }
        else{
          objbuf->state = 0;
        }
      }
    }
    if(objbuf->type == 4){
      if(objbuf->state == 0){
        if(NF_GetTile(0, objbuf->x, objbuf->y+1) == 0){
          objbuf->y+=2;
        }
        else{
          objbuf->state = 1;
        }
      }
      if(objbuf->state == 1){
        if(NF_GetTile(0, objbuf->x, objbuf->y-1) == 0){
          objbuf->y-=2;
        }
        else{
          objbuf->state = 0;
        }
      }
    }
    if(checkCollision(objbuf->x, objbuf->y, 32, 32, bal.x, bal.y, 8, 8) == true){
      mmEffect(SFX_OS);
      objbuf->dialog = 0;
      objbuf->sprx = 256;
      objbuf->spry = 192;
      bal.side = 0;
      bal.x = 768;
      bal.y = 768;
    }
    if(checkCollision(objbuf->x, objbuf->y, 32, 32, kirikou.x, kirikou.y, 16, 32) == true){
      Gameover();
    }
    NF_MoveSprite(1, objbuf->id, objbuf->sprx, objbuf->spry);
  }
}