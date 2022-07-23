#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct pos{
	int x;
	int y;
} pos;
typedef struct obj{
	char* bg;
	int x;
	int y;
	int sprx;
	int spry;
	int defx;
	int defy;
	int radius;
	u8_f id;
	u8_f type;
	u8_f state;
	u8_f sound[5];
	u8_f dialog;
	struct obj* next;
} obj;
typedef struct map{
	char* bg_map;
	char* bg_obj;
	char** npc_link;
	obj* firstobj;
} map;
#endif
