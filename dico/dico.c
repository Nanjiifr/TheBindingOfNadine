#include "dico.h"

struct element_s {
    int key ;
    int** value ;
} ;

typedef struct element_s element ; 

typedef element* cell ;

struct dico_s {
    int len ;
    int max_len ; 
    cell* cases ;
} ;

typedef struct dico_s dico ;

int MINLEN = 10 ;

dico create () {
    dico n_dico = {0, MINLEN, malloc(sizeof(cell)*MINLEN)} ;
    for (int i = 0 ; i < MINLEN ; i++) {
        n_dico.cases[i] = NULL ;
    }
    return n_dico ; 
}

bool is_empty(dico d) {
    return (d.len == 0) ; 
}

int pow(int x, int n) {
    //Returns 1 if n <= 0, else x^n
    int r = 1 ;
    for (int i = 1 ; i<n ; i++) {
        r*=x ;
    }
    return r ;
}

int h (int i, int j) {
    if (i >= 0) {
        if (j>=0) return pow(2, 2*i) + pow(3, 2*j) ;
        return pow(2, 2*i) + pow(3, -2*j - 1) ;
    } else {
        if (j>=0) return pow(2, -2*i - 1) + pow(3, 2*j) ;
        return pow(2, -2*i - 1) + pow(3, -2*j - 1) ;
    }
}

void add (dico d, int i, int j, int** map) {
    int id = h(i, j)%(d.max_len);
    int k = h(i, j);
    if (d.cases[id] == NULL) {
        d.cases[id] = malloc(sizeof(element)) ;
        d.cases[id]->key = k ;
        d.cases[id]->value = map ;
    }
}