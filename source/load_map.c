#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "include.h"

void LoadSprites(char* link){
  char* out = "d";
  for(u8_f i = 0; i <= curmap->spritenum; i++){
    sprintf(out, link, i);
    NF_LoadSpriteGfx(out, i+1, 16, 32);
	  NF_VramSpriteGfx(1, i+1, i+1, false);
  }
  sprintf(out, link, 4);
	NF_LoadSpritePal(out, 1);
	NF_VramSpritePal(1, 1, 1);
}

void UnLoadSprites(){
  NF_UnloadSpritePal(1);
  for(u8_f i = 0; i <= curmap->spritenum; i++){
    NF_UnloadSpriteGfx(i+1);
    NF_FreeSpriteGfx(1, i+1);
  }
}

void LoadMap(map* mape, bool unload){
  curmap = mape;
  obj* objbuf;
  NF_ResetCmapBuffers();
  NF_ResetTiledBgBuffers();
  //NF_ResetSpriteBuffers();
  NF_LoadTiledBg(mape->bg_map, "bgmap", 768, 768);
  if(mape->bg_obj != NULL) NF_LoadTiledBg(mape->bg_obj, "bgobj", 768, 768);
  //NF_LoadTiledBg(mape->bg_mini, "bgmin", 768, 768);
  NF_CreateTiledBg(1, 3, "bgmap");
  if(mape->bg_obj != NULL) NF_CreateTiledBg(1, 2, "bgobj");
  else NF_DeleteTiledBg(1, 2);
  //NF_CreateTiledBg(0, 3, "bgmin");
  NF_LoadColisionBg(mape->cmap, 0, 768, 768);

  if(*mape->npc_link != NULL) LoadSprites(*mape->npc_link);
  objbuf = mape->firstobj;
	mmLoad(mape->song);
  while(1){
    objbuf->x = objbuf->defx;
    objbuf->y = objbuf->defy;
    switch(objbuf->type){
      case 1:
        NF_CreateSprite(1, objbuf->id, objbuf->id, 1, objbuf->x, objbuf->y);
        break;
      case 3:
      case 4:
        NF_CreateSprite(1, 2, 2, 1, objbuf->x, objbuf->y);
        break;
    }
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
	mmStart(mape->song, MM_PLAY_LOOP);
  if(mape->type == true){
    mmLoadEffect(SFX_RIP);
    mmLoadEffect(SFX_OS);
    mmLoadEffect(SFX_GUN);
    NF_CreateSprite(1, 32, 1, 1, 256, 192);
    iscave = true;
  }
}

/*void LoadCave(cave* cav, map* mapbuf){
  iscave = true;
  curcave = cav;
  kirikou.x = 384;
  kirikou.y = 64;
  evil* evilbuf;
  NF_ResetCmapBuffers();
  NF_ResetTiledBgBuffers();
  NF_DeleteTiledBg(1, 2);
  NF_LoadTiledBg(cav->bg, "bg", 768, 768);
  NF_CreateTiledBg(1, 3, "bg");
  NF_LoadColisionBg(cav->cmap, 0, 768, 768);
  obj* objbuf = mapbuf->firstobj;
  while(1){
    NF_DeleteSprite(1, objbuf->id);
    if(objbuf->next == NULL) break;
    objbuf = objbuf->next;
  }
  NF_UnloadSpritePal(1);
	NF_LoadSpritePal("spr/cave", 1);
	NF_SpriteUpdatePalette(1, 1);
	NF_UnloadSpriteGfx(1);
	NF_UnloadSpriteGfx(2);
  NF_LoadSpriteGfx("spr/balle", 1, 8, 8);
  NF_LoadSpriteGfx("spr/skull", 2, 32, 32);
  NF_FreeSpriteGfx(1, 1);
  NF_FreeSpriteGfx(1, 2);
	NF_VramSpriteGfx(1, 1, 1, false);
	NF_VramSpriteGfx(1, 2, 2, false);
  evilbuf = cav->firstevil;
  while(1){
    NF_CreateSprite(1, evilbuf->id, 2, 1, evilbuf->x, evilbuf->y);
    evilbuf->life = true;
    if(evilbuf->next == NULL) break;
    evilbuf = evilbuf->next;
  }
	mmLoad(cav->song);
  mmLoadEffect(SFX_RIP);
  mmLoadEffect(SFX_OS);
  mmLoadEffect(SFX_GUN);
	mmStart(cav->song, MM_PLAY_LOOP);
  NF_CreateSprite(1, 32, 1, 1, 256, 192);
}*/