#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void kirikouStart();
void kirikouUpdate();
void kirikouGunUpdate();
void LoadMap(map* mape);
void UpdateObj();
bool checkCollision(int x1, int y1, int sx1, int sy1, int x2, int y2, int sx2, int sy2);
void LoadCave(cave* cav, map* mapbuf);
void EvilUpdate();
#endif
