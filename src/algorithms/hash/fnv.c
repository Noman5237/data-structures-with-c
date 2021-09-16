/**
 * @file: fnv.c
 * @author: Anonyman637
 * @date: 9/16/2021; 3:22 PM
 */

#include <algorithms/hash/fnv.h>

Any *fnv_1a(Any *any) {
	int hash = 0;
	
//	TODO how to compute hash of a dynamic data
	uintptr_t *data = any->data;
	for (size_t i = 0; i < size; i++) {
		t_byte byte = (t_byte *) (data + i);
		hash = hash ^ byte;
		hash = hash * 16777619;
	}
	
	return Int(hash);
}
