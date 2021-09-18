/**
 * @file: map.h
 * @author: Anonyman637
 * @date: 9/16/2021; 2:29 PM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_MAP_H
#define DATASTRUCTURESCOURSE_INTERNAL_MAP_H

#include <dscommon.h>
#include <map.h>
#include <internals/interfaces/list/list.h>

/* ============================== Map Item ========================= */

Type *t_map_item;

struct MapItemData {
	Any *key;
	Any *value;
};

typedef struct MapItemData MapItemData;

Any *MapItem(Any *key, Any *value);

int map_item_data_compare(Any *this, Any *other);

void map_item_data_print(Any *this);

void map_item_data_destroy(Any *this);

/* ============================== Struct Data ========================= */

struct MapData {
	Any *list;
};

typedef struct MapData MapData;

MapData *map_data_new(Any *iList);

void map_data_destroy(Any *this);

/* ============================== Helper Functions ========================= */

MapItemData *map_getItem(MapData *map, Any *key);

#endif // DATASTRUCTURESCOURSE_INTERNAL_MAP_H

