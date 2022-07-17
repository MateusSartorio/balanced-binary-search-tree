#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char key;
typedef int value;
#define null_key 0
#define null_value -1

typedef struct bst_t {
    key k;
    int sz;
    struct bst_t* l;
    struct bst_t* r;
} bst;

bst* bst_init(key k);
bst* bst_get(bst* t, key k);
void bst_put(bst* t, key k);
// key bst_floor(bst* t, key k);
int bst_height(bst* t);
void bst_print(bst* t);
void bst_delete(bst* t);

#endif