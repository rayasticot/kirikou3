#ifndef MAP_BENIN_H
#define MAP_BENIN_H
char* be_sprite = "spr/npc/be%u";
obj npc1 ={
  .id = 2,
  .type = 1,
  .defx = 328,
  .defy = 456,
  .state = 0,
  .radius = 32
};
obj npc0 ={
  .id = 1,
  .type = 1,
  .defx = 576,
  .defy = 432,
  .state = 0,
  .radius = 32,
  .sound = {SFX_BE01, SFX_BE02, SFX_BE03, SFX_BE04, SFX_BE05},
  .next = &npc1
};
map be ={
  .bg_map = "bg/benin_map",
  .bg_obj = "bg/benin_obj",
  .npc_link = &be_sprite,
  .firstobj = &npc0
};
#endif