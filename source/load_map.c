#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

void LoadSprites(char* link){
  char* out = "d";
  for(u8_f i = 0; i < 4; i++){
    sprintf(out, link, i);
    NF_LoadSpriteGfx(out, i+1, 16, 32);
	  NF_VramSpriteGfx(1, i+1, i+1, false);
  }
  sprintf(out, link, 4);
	NF_LoadSpritePal(out, 1);
	NF_VramSpritePal(1, 1, 1);
}

void LoadMap(map* mape){
  obj* objbuf;
  NF_ResetCmapBuffers();
  NF_ResetTiledBgBuffers();
  NF_LoadTiledBg(mape->bg_map, "bgmap", 768, 768);
  NF_LoadTiledBg(mape->bg_obj, "bgobj", 768, 768);
  //NF_LoadTiledBg(mape->bg_mini, "bgmin", 768, 768);
  NF_CreateTiledBg(1, 3, "bgmap");
  NF_CreateTiledBg(1, 2, "bgobj");
  //NF_CreateTiledBg(0, 3, "bgmin");
  NF_LoadColisionBg(mape->cmap, 0, 768, 768);
  LoadSprites(*mape->npc_link);
  objbuf = mape->firstobj;
  while(1){
    objbuf->x = objbuf->defx;
    objbuf->y = objbuf->defy;
    NF_CreateSprite(1, objbuf->id, objbuf->id, 1, objbuf->x, objbuf->y);
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
}

void LoadCave(cave* cav){
  evil* evilbuf;
  NF_ResetCmapBuffers();
  NF_ResetTiledBgBuffers();
  NF_LoadTiledBg(cav->bg, "bg", 768, 768);
  NF_CreateTiledBg(1, 3, "bg");
  NF_LoadColisionBg(cav->cmap, 0, 768, 768);
  evilbuf = cav->firstevil;
  while(1){
    NF_CreateSprite(1, evilbuf->id, 1, 1, evilbuf->x, evilbuf->y);
    if(evilbuf->next == NULL) break;
    evilbuf = evilbuf->next;
  }
}