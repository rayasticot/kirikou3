#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "include.h"

void LoadMap(map* mape){
  obj* objbuf;
  NF_ResetTiledBgBuffers();
  NF_LoadTiledBg(mape->bg, "bg", 768, 768);
  NF_CreateTiledBg(1, 3, "bg");
  objbuf = mape->firstobj;
  while(objbuf->next != NULL){
    NF_CreateSprite(1, objbuf->id, 0, 0, objbuf->x, objbuf->y);
    objbuf = objbuf->next;
  }
}
