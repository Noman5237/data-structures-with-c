/**
 * @file: map.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:04 PM
 */

#include <internals/map.h>

/* ============================== Runtime Registry ========================= */

void t_map_register() {
	if (t_map != NULL) {
		return;
	}
	
	t_map = type_new("Map");
	t_map->print = map_print;
	t_map->destroyData = map_data_destroy;
	
	t_map_item = type_new("MapItem");
	t_map_item->print = map_item_data_print;
	t_map_item->compare = map_item_data_compare;
	t_map_item->destroyData = map_item_data_destroy;
}

void t_map_deregister() {
	if (t_map == NULL) {
		return;
	}
	
	type_destroy(t_map);
	t_map = NULL;
	
	type_destroy(t_map_item);
	t_map_item = NULL;
}

/* ============================== Map Item ========================= */

Any *MapItem(Any *key, Any *value, Any *hash) {
	MapItemData *item = malloc(sizeof(MapItemData));
	item->key = key;
	item->value = value;
	item->hash = hash;
	let this = any_new(item, t_map_item);
	return this;
}

void map_item_data_destroy(Any *this) {
	MapItemData *item = this->data;
	any_destroy(item->key);
	any_destroy(item->value);
	any_destroy(item->hash);
	free(item);
}

int map_item_data_compare(Any *this, Any *other) {
	MapItemData *thisMap = this->data;
	MapItemData *otherMap = other->data;
	return any_compare(thisMap->hash, otherMap->hash);
}

void map_item_data_print(Any *this) {
	MapItemData *map = this->data;
	printf("(");
	any_print(map->key);
	printf(", ");
	any_print(map->value);
	printf(")");
}

/* ============================== Map Data ========================= */

MapData *map_data_new(Any *iList, Any *(*hashFunction)(Any *key)) {
	MapData *map = malloc(sizeof(MapData));
	map->list = iList;
	map->computeHash = hashFunction;
	map->size = 0;
	return map;
}

void map_data_destroy(Any *this) {
	MapData *map = this->data;
	any_destroy(map->list);
	free(map);
}

/* ============================== Core Type Functions ========================= */

Any *Map(Any *iList, Any *(*hashFunction)(Any *key)) {
	MapData *map = map_data_new(iList, hashFunction);
	let this = any_new(map, t_map);
	return this;
}

void map_print(Any *this) {
	MapData *map = this->data;
	any_print(map->list);
}

/* ============================== Advanced Type Functions ========================= */

int map_size(Any *this) {
	MapData *map = this->data;
	return map->size;
}

void map_set(Any *this, Any *key, Any *value) {
	MapData *map = this->data;
	let item = MapItem(key, value, map->computeHash(key));
	list_append(map->list, item);
}

Any *map_get(Any *this, Any *key) {
	MapData *map = this->data;
	let itemToSearch = MapItem(key, NULL, map->computeHash(key));
	let item = list_search(map->list, itemToSearch);
	if (item == NULL) {
		return NULL;
	}
	MapItemData *itemData = item->data;
	return itemData->value;
}

void map_remove(Any *this, Any *key) {
	MapData *map = this->data;
	let itemToRemove = MapItem(key, NULL, map->computeHash(key));
	list_removeItem(map->list, itemToRemove);
}
