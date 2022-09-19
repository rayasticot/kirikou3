#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4



static void Dialog(obj* objbuf){
  NF_LoadTiledBg(objbuf->bg, objbuf->bg, 256, 256);
  NF_CreateTiledBg(0, 2, objbuf->bg);
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
  NF_DeleteTiledBg(0, 2);
  NF_UnloadTiledBg(objbuf->bg);
  mmSetModuleVolume(1024);
  if(objbuf->dialog++ == 4) objbuf->dialog = 0;
}

static void moveNpc(obj* objbuf, int* check, int* def, bool aug){
  if(*check > *def - objbuf->radius && *check < *def + objbuf->radius){
    /*if(rand() % 40 + 1 == 1){
      objbuf->state = 0;
      break;
    }*/
    if(aug == true){
      (*check)++;
    }
    else{
      (*check)--;
    }
  }
  else{
    if(aug == true){
      (*check)--;
    }
    else{
      (*check)++;
    }
    objbuf->state = 0;
  }
}

static void UpdateNpc(obj* objbuf){
  int randnum;
    switch(objbuf->state){
      case 0:
        randnum = rand() % 200 + 1;
        if(randnum < 4){
          objbuf->state = randnum;
        }
        break;
      case UP:
        moveNpc(objbuf, &objbuf->y, &objbuf->defy, true);
        break;
      case DOWN:
        moveNpc(objbuf, &objbuf->y, &objbuf->defy, false);
        break;
      case LEFT:
        moveNpc(objbuf, &objbuf->x, &objbuf->defx, true);
        break;
      case RIGHT:
        moveNpc(objbuf, &objbuf->x, &objbuf->defx, false);
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
      case 3:
        EvilUpdate(objbuf);
        break;
      case 4:
        EvilUpdate(objbuf);
        break;
    }
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
}