#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "include.h"

void UpdateObj(){
  obj* objbuf = curmap->firstobj;
  while(objbuf->next != NULL){
    if(objbuf->x > cam.x && objbuf->x - cam.x < 256){
      objbuf->sprx = objbuf->x - cam.x;
    }
    else{
      objbuf->sprx = 256;
    }
    if(objbuf->y > cam.y && objbuf->y - cam.y < 192){
      objbuf->spry = objbuf->y - cam.y;
    }
    else{
      objbuf->spry = 192;
    }
    NF_MoveSprite(1, objbuf->id, objbuf->sprx, objbuf->spry);
    objbuf = objbuf->next;
  }
}
