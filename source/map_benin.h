#ifndef MAP_BENIN_H
#define MAP_BENIN_H
evil be_evil1 ={
  .x = 224,
  .y = 160,
  .id = 3,
  .type = false
};
evil be_evil2 ={
  .x = 96,
  .y = 64,
  .id = 4,
  .type = false,
  .next = &be_evil1
};
evil be_evil3 ={
  .x = 64,
  .y = 32,
  .id = 5,
  .type = false,
  .next = &be_evil2
};
evil be_evil4 ={
  .x = 32,
  .y = 320,
  .id = 6,
  .type = true,
  .next = &be_evil3
};
evil be_evil5 ={
  .x = 160,
  .y = 352,
  .id = 9,
  .type = false,
  .next = &be_evil4
};
evil be_evil6 ={
  .x = 96,
  .y = 448,
  .id = 10,
  .type = false,
  .next = &be_evil5
};
evil be_evil7 ={
  .x = 192,
  .y = 544,
  .id = 11,
  .type = false,
  .next = &be_evil6
};
evil be_evil8 ={
  .x = 192,
  .y = 608,
  .id = 12,
  .type = false,
  .next = &be_evil7
};
evil be_evil9 ={
  .x = 224,
  .y = 672,
  .id = 13,
  .type = true,
  .next = &be_evil8
};
evil be_evil10 ={
  .x = 576,
  .y = 576,
  .id = 14,
  .type = false,
  .next = &be_evil9
};
evil be_evil11 ={
  .x = 544,
  .y = 608,
  .id = 15,
  .type = false,
  .next = &be_evil10
};
evil be_evil12 ={
  .x = 448,
  .y = 704,
  .id = 16,
  .type = false,
  .next = &be_evil11
};
evil be_evil13 ={
  .x = 640,
  .y = 544,
  .id = 17,
  .type = true,
  .next = &be_evil12
};
evil be_evil14 ={
  .x = 672,
  .y = 544,
  .id = 18,
  .type = true,
  .next = &be_evil13
};
evil be_evil15 ={
  .x = 608,
  .y = 288,
  .id = 19,
  .type = false,
  .next = &be_evil14
};
evil be_evil16 ={
  .x = 704,
  .y = 128,
  .id = 20,
  .type = true,
  .next = &be_evil15
};
evil be_evil17 ={
  .x = 544,
  .y = 320,
  .id = 21,
  .type = true,
  .next = &be_evil16
};
evil be_evil18 ={
  .x = 512,
  .y = 320,
  .id = 23,
  .type = true,
  .next = &be_evil17
};
evil be_evil19 ={
  .x = 64,
  .y = 224,
  .id = 24,
  .type = true,
  .next = &be_evil18
};
evil be_evil20 ={
  .x = 416,
  .y = 448,
  .id = 25,
  .type = true,
  .next = &be_evil19
};
evil be_evil21 ={
  .x = 448,
  .y = 448,
  .id = 26,
  .type = true,
  .next = &be_evil20
};
evil be_evil22 ={
  .x = 352,
  .y = 480,
  .id = 27,
  .type = false,
  .next = &be_evil21
};
evil be_evil23 ={
  .x = 384,
  .y = 512,
  .id = 28,
  .type = false,
  .next = &be_evil22
};
evil be_evil24 ={
  .x = 384,
  .y = 256,
  .id = 29,
  .type = false,
  .next = &be_evil23
};
evil be_evil25 ={
  .x = 384,
  .y = 288,
  .id = 30,
  .type = false,
  .next = &be_evil24
};
evil be_evil26 ={
  .x = 416,
  .y = 288,
  .id = 31,
  .type = false,
  .next = &be_evil25
};
cave cavebe ={
  .bg = "bg/cavebe",
  .cmap = "col/cavebecol",
  .song = MOD_ATTAQUE,
  .firstevil = &be_evil26
};
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
  .song = MOD_BAISE,
  .firstobj = &npc0
};
#endif