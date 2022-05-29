#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct pos{
	s16 x;
	s16 y;
} pos;
typedef struct obj{
	s16 x;
	s16 y;
	s16 sprx;
	s16 spry;
	s16 radius;
	u8 id;
	u8 type;
	u8 state;
	struct obj* next;
} obj;
typedef struct map{
	char* bg;
	obj* firstobj;
} map;
#endif
