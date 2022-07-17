#include "../h/bst.h"

#define max(a, b) (a > b ? a : b)
#define compare(a, b) (a - b)

bst* bst_init(key k) {
    bst* t = (bst*) malloc(sizeof(bst));
    
    t->k = k;
    t->l = NULL;
    t->r = NULL;

    return t;
}

bst* bst_get(bst* t, key k) {
    if(!t)
        return NULL;

    int cmp = compare(k, t->k);
    if(cmp < 0)
        return bst_get(t->l, k);
    else if(cmp > 0)
        return bst_get(t->r, k);
    else
        return t;
}

static bst* rotate_right(bst* t) {
    
}

static bst* rec_put(bst* t, key k) {
    if(!t)
        return bst_init(k);

    int cmp = compare(k, t->k);
    if(cmp < 0)
        t->l = rec_put(t->l, k);
    else if(cmp > 0)
        t->r = rec_put(t->r, k);
    else
        t->k = k;

    return t;
}

void bst_put(bst* t, key k) {
    rec_put(t, k);
}

// key bst_floor(bst* t, key k) {

// }

static int rec_height(bst* t) {
    if(!t)
        return 0;
    
    return 1 + max(rec_height(t->l), rec_height(t->r));
}

int bst_height(bst* t) {
    return rec_height(t) - 1;
}

// static void rec_print(bst* t) {
//     if(!t) {
//         printf("<>");
//         return;
//     }

//     printf("<%d", t->k);
//     rec_print(t->l);
//     rec_print(t->r);
//     printf(">");
// }

// void bst_print(bst* t) {
//     rec_print(t);
//     printf("\n");
// }

static void rec_print(bst* t, int level) {
    if(t) {
        rec_print(t->r, level + 1);
        for(int i = 0; i < level; i++)
            printf("    ");
        printf("<%d>\n", t->k);
        rec_print(t->l, level + 1);
    }
}

void bst_print(bst* t) {
    rec_print(t, 0);
}

void bst_delete(bst* t) {
    if(!t)
        return;
    
    if(!t->l && !t->r) {
        free(t);
        return;
    }

    bst_delete(t->l);
    bst_delete(t->r);
    free(t);
}
