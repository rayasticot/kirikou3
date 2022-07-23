#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

#define up 1
#define down 2
#define right 3
#define left 4



void Dialog(obj* objbuf){
  NF_LoadTiledBg(objbuf->bg, objbuf->bg, 256, 256);
  NF_CreateTiledBg(0, 3, objbuf->bg);
  mmSetModuleVolume(128);
  mmLoadEffect(objbuf->sound[objbuf->dialog]);
  mm_sfxhand snd = mmEffect(objbuf->sound[objbuf->dialog]);
  mmEffectVolume(snd, 255);
  while(KEY_A ^ keysDown()){
    NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

		scanKeys();
  }
  mmEffectCancel(snd);
  mmUnloadEffect(objbuf->sound[objbuf->dialog]);
  NF_DeleteTiledBg(0, 3);
  NF_UnloadTiledBg(objbuf->bg);
  mmSetModuleVolume(1024);
  if(objbuf->dialog++ == 4) objbuf->dialog = 0;
}

void UpdateNpc(obj* objbuf){
  int randnum;
    switch(objbuf->state){
      case 0:
        randnum = rand() % 200 + 1;
        if(randnum < 4){
          objbuf->state = randnum;
        }
        break;
      case up:
        if(objbuf->y > objbuf->defy - objbuf->radius && objbuf->y < objbuf->defy + objbuf->radius){
          if(rand() % 40 + 1 == 1){
            objbuf->state = 0;
            break;
          }
          objbuf->y++;
        }
        else{
          objbuf->y--;
          objbuf->state = 0;
        }
        break;
      case down:
        if(objbuf->y > objbuf->defy - objbuf->radius && objbuf->y < objbuf->defy + objbuf->radius){
          objbuf->y--;
        }
        else{
          objbuf->y++;
          objbuf->state = 0;
        }
        break;
      case left:
        if(objbuf->x > objbuf->defx - objbuf->radius && objbuf->x < objbuf->defx + objbuf->radius){
          objbuf->x++;
        }
        else{
          objbuf->x--;
          objbuf->state = 0;
        }
        break;
      case right:
        if(objbuf->x > objbuf->defx - objbuf->radius && objbuf->x < objbuf->defx + objbuf->radius){
          objbuf->x--;
        }
        else{
          objbuf->x++;
          objbuf->state = 0;
        }
        break;
    }
  if(checkCollision(objbuf->x, objbuf->y, 16, 32, kirikou.x, kirikou.y, 16, 32) == true && timer == 0){
    Dialog(objbuf);
    timer = 180;
  }
}

void UpdateObj(){
  obj* objbuf = curmap->firstobj;
  while(1){
    if(objbuf->x > cam.x-16 && objbuf->x - cam.x < 256){
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
    }
    NF_MoveSprite(1, objbuf->id, objbuf->sprx, objbuf->spry);
    switch(objbuf->type){
      case 1:
        UpdateNpc(objbuf);
        break;
    }
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
}