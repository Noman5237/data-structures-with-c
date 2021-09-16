/**
 * @file: binarySearchTree.h
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#ifndef DATASTRUCTURESCOURSE_BST_H
#define DATASTRUCTURESCOURSE_BST_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_bst;

void t_bst_register();

void t_bst_deregister();

/* ============================== Core Type Functions ========================= */

Any *BinarySearchTree();

void bst_print(Any *this);

/* ============================== Advanced Type Functions ========================= */

int bst_size(Any *this);

int bst_isEmpty(Any *this);

void bst_append(Any *this, Any *newDatum);

Any *bst_get(Any *this, int index);

void bst_remove(Any *this, int index);

void bst_removeItem(Any *this, Any *itemToRemove);

int bst_getIndexOf(Any *this, Any *itemToSearch);

Any *bst_search(Any *this, Any *itemToSearch);

#endif //DATASTRUCTURESCOURSE_BST_H
