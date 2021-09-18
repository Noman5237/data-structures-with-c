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

Any *MapItem(Any *key, Any *value) {
	MapItemData *item = malloc(sizeof(MapItemData));
	item->key = key;
	item->value = value;
	let this = any_new(item, t_map_item);
	return this;
}

void map_item_data_destroy(Any *this) {
	MapItemData *item = this->data;
	any_destroy(item->key);
	any_destroy(item->value);
	free(item);
}

int map_item_data_compare(Any *this, Any *other) {
	MapItemData *thisItem = this->data;
	MapItemData *otherItem = other->data;
	return any_compare(thisItem->key, otherItem->key);
}

void map_item_data_print(Any *this) {
	MapItemData *map = this->data;
	printf("(");
	any_print(map->key);
	printf(": ");
	any_print(map->value);
	printf(")");
}

/* ============================== Map Data ========================= */

MapData *map_data_new(Any *iList) {
	MapData *map = malloc(sizeof(MapData));
	map->list = iList;
	return map;
}

void map_data_destroy(Any *this) {
	MapData *map = this->data;
	any_destroy(map->list);
	free(map);
}

/* ============================== Core Type Functions ========================= */

Any *Map(Any *iList) {
	MapData *map = map_data_new(iList);
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
	return list_size(map->list);
}

void map_put(Any *this, Any *key, Any *value) {
	MapData *map = this->data;
	let item = MapItem(key, value);
	MapItemData *itemData = map_getItem(map, key);
	if (itemData == NULL) {
		list_append(map->list, item);
	} else {
		any_destroy(itemData->value);
		itemData->value = value;
	}
}

Any *map_get(Any *this, Any *key) {
	MapData *map = this->data;
	return map_getItem(map, key)->value;
}

Any *map_getKeys(Any *this) {
	MapData *map = this->data;
	let list = map->list;
	IListInstance *iList = map->list->data;
	let keys = iList->functions->new();
	
	for (int i = 0; i < map_size(this); i++) {
		let key = ((MapItemData *) (list_get(list, i)->data))->key;
		list_append(keys, key);
	}
	
	return keys;
}

void map_remove(Any *this, Any *key) {
	MapData *map = this->data;
	let itemToRemove = MapItem(key, NULL);
	list_removeItem(map->list, itemToRemove);
}

/* ============================== Helper Functions ========================= */

MapItemData *map_getItem(MapData *map, Any *key) {
	let itemToSearch = MapItem(key, NULL);
	let item = list_search(map->list, itemToSearch);
	if (item == NULL) {
		return NULL;
	}
	MapItemData *itemData = item->data;
	return itemData;
}
