/**
 * @file: map.h
 * @author: Anonyman637
 * @date: 8/26/2021; 3:04 PM
 */

#ifndef DATASTRUCTURESCOURSE_MAP_H
#define DATASTRUCTURESCOURSE_MAP_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_map;

void t_map_register();

void t_map_deregister();

/* ============================== Core Type Functions ========================= */

Any *Map(Any *iList, Any *(*hashFunction)(Any *key));

void map_print(Any *map);

/* ============================== Advanced Type Functions ========================= */

int map_size(Any *this);

void map_set(Any *this, Any *key, Any *value);

Any *map_get(Any *this, Any *key);

void map_remove(Any *this, Any *key);

#endif //DATASTRUCTURESCOURSE_MAP_H
