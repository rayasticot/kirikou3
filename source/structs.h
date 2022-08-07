#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct pos{
	int x;
	int y;
} pos;
typedef struct balle{
	int x;
	int y;
	u8_f side;
} balle;
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
typedef struct evil{
	int x;
	int y;
	int sprx;
	int spry;
	u8_f id;
	bool side;
	bool type;
	bool life;
	struct evil* next;
} evil;
typedef struct cave{
	char* bg;
	char* cmap;
	int song;
	evil* firstevil;
} cave;
typedef struct map{
	char* bg_map;
	char* bg_obj;
	char* bg_mini;
	char* cmap;
	char** npc_link;
	int song;
	obj* firstobj;
	cave* cave;
} map;
#endif
