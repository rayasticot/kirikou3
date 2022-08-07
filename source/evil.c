#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

static void EvilMove(evil* evilbuf, bool type, bool side){
}

void EvilUpdate(){
  evil* evilbuf = curcave->firstevil;
    while(1){
    if(evilbuf->x > cam.x-16 && evilbuf->x - cam.x < 256){
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
        if(NF_GetTile(0, evilbuf->x+1, evilbuf->y) == 0){
          evilbuf->x++;
        }
      }
      if(evilbuf->side == true){
        if(NF_GetTile(0, evilbuf->x-1, evilbuf->y) == 0){
          evilbuf->x--;
        }
      }
    }
    if(evilbuf->type == true){
      if(evilbuf->side == false){
        if(NF_GetTile(0, evilbuf->x, evilbuf->y+1) == 0){
          evilbuf->y++;
        }
      }
      if(evilbuf->side == true){
        if(NF_GetTile(0, evilbuf->x, evilbuf->y-1) == 0){
          evilbuf->y--;
        }
      }
    }
    NF_MoveSprite(1, evilbuf->id, evilbuf->sprx, evilbuf->spry);
    if(evilbuf->next == NULL) break;
    evilbuf = evilbuf->next;
  }
}