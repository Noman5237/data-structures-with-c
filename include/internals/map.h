/**
 * @file: map.h
 * @author: Anonyman637
 * @date: 9/16/2021; 2:29 PM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_MAP_H
#define DATASTRUCTURESCOURSE_INTERNAL_MAP_H

#include <dscommon.h>
#include <map.h>
#include <interfaces/list/list.h>

/* ============================== Map Item ========================= */

Type *t_map_item;

struct MapItemData {
	Any *key;
	Any *hash;
	Any *value;
};

typedef struct MapItemData MapItemData;

Any *MapItem(Any *key, Any *value, Any *hash);

int map_item_data_compare(Any *this, Any *other);

void map_item_data_print(Any *this);

void map_item_data_destroy(Any *this);

/* ============================== Struct Data ========================= */

struct MapData {
	Any *list;
	
	Any *(*computeHash)(Any *key);
	
	int size;
};

typedef struct MapData MapData;

MapData *map_data_new(Any *iList, Any *(*hashFunction)(Any *key));

void map_data_destroy(Any *this);

/* ============================== Helper Functions ========================= */

#endif // DATASTRUCTURESCOURSE_INTERNAL_MAP_H

