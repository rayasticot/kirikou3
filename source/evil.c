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
  evil* evilbuf = curcave->firstevil;
  while(1){
    evilbuf->life = true;
    if(evilbuf->next == NULL) break;
    evilbuf = evilbuf->next;
  }
  mmStart(MOD_CAVE, MM_PLAY_LOOP);
}

void EvilUpdate(){
  evil* evilbuf = curcave->firstevil;
  while(1){
    if(evilbuf->life == true){
      if(evilbuf->x > cam.x-32 && evilbuf->x - cam.x < 256){
        evilbuf->sprx = evilbuf->x - cam.x;
      }
      else{
        evilbuf->sprx = 256;
      }
      if(evilbuf->y > cam.y-32 && evilbuf->y - cam.y < 192){
        evilbuf->spry = evilbuf->y - cam.y;
      }
      else{
        evilbuf->spry = 192;
      }
      if(evilbuf->type == false){
        if(evilbuf->side == false){
          if(NF_GetTile(0, evilbuf->x+33, evilbuf->y) == 0){
            evilbuf->x+=2;
            NF_HflipSprite(1, evilbuf->id, false);
          }
          else{
            evilbuf->side = true;
          }
        }
        if(evilbuf->side == true){
          if(NF_GetTile(0, evilbuf->x-1, evilbuf->y) == 0){
            evilbuf->x-=2;
            NF_HflipSprite(1, evilbuf->id, true);
          }
          else{
            evilbuf->side = false;
          }
        }
      }
      if(evilbuf->type == true){
        if(evilbuf->side == false){
          if(NF_GetTile(0, evilbuf->x, evilbuf->y+1) == 0){
            evilbuf->y+=2;
          }
          else{
            evilbuf->side = true;
          }
        }
        if(evilbuf->side == true){
          if(NF_GetTile(0, evilbuf->x, evilbuf->y-1) == 0){
            evilbuf->y-=2;
          }
          else{
            evilbuf->side = false;
          }
        }
      }
      if(checkCollision(evilbuf->x, evilbuf->y, 32, 32, bal.x, bal.y, 8, 8) == true){
        mmEffect(SFX_OS);
        evilbuf->life = false;
        evilbuf->sprx = 256;
        evilbuf->spry = 192;
        bal.side = 0;
        bal.x = 768;
        bal.y = 768;
      }
      if(checkCollision(evilbuf->x, evilbuf->y, 32, 32, kirikou.x, kirikou.y, 16, 32) == true){
        Gameover();
      }
      NF_MoveSprite(1, evilbuf->id, evilbuf->sprx, evilbuf->spry);
    }
    if(evilbuf->next == NULL) break;
    evilbuf = evilbuf->next;
  }
}