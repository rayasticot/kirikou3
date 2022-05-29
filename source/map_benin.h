#ifndef MAP_BENIN_H
#define MAP_BENIN_H
obj npc1 ={
  .id = 2,
  .x = 384,
  .y = 384
};
obj npc0 ={
  .id = 1,
  .x = 454,
  .y = 128,
  .next = &npc1
};
map be ={
  .bg = "bg/benin",
  .firstobj = &npc0
};
#endif
