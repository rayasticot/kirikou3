#ifndef MAP_BENIN_H
#define MAP_BENIN_H
char* be_sprite = "spr/npc/be%u";
obj npc3 ={
  .id = 4,
  .type = 1,
  .defx = 104,
  .defy = 260,
  .state = 0,
  .sound = {SFX_BE31, SFX_BE32, SFX_BE33, SFX_BE34, SFX_BE35},
  .bg = "bg/tueur",
  .radius = 8
};
obj npc2 ={
  .id = 3,
  .type = 1,
  .defx = 574,
  .defy = 92,
  .state = 0,
  .sound = {SFX_BE21, SFX_BE22, SFX_BE23, SFX_BE24, SFX_BE23},
  .bg = "bg/ps3",
  .radius = 0,
  .next = &npc3
};
obj npc1 ={
  .id = 2,
  .type = 1,
  .defx = 56,
  .defy = 630,
  .state = 0,
  .sound = {SFX_BE11, SFX_BE12, SFX_BE13, SFX_BE14, SFX_BE13},
  .bg = "bg/dodji",
  .radius = 16,
  .next = &npc2
};
obj npc0 ={
  .id = 1,
  .type = 1,
  .defx = 576,
  .defy = 432,
  .state = 0,
  .radius = 32,
  .sound = {SFX_BE01, SFX_BE02, SFX_BE03, SFX_BE04, SFX_BE05},
  .bg = "bg/richesse",
  .next = &npc1
};
map be ={
  .bg_map = "bg/benin_map",
  .bg_obj = "bg/benin_obj",
  .bg_mini = "bg/minibenin",
  .cmap = "col/colbe",
  .npc_link = &be_sprite,
  .firstobj = &npc0
};
#endif