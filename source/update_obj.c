#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "include.h"

#define up 1
#define down 2
#define right 3
#define left 4


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
  if(checkCollision(objbuf->x, objbuf->y, 32, 16, kirikou.x, kirikou.y, 32, 16) == true){
    
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