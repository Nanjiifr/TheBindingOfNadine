#ifndef DYN_ARRAYS_H
#define DYN_ARRAYS_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include <stdio.h>
#include "tab_chaines.h"

typedef list cases ;
typedef struct dyn_dico_s dA ;


/// Constructeurs
dA* create() ;
dA* create_from_d(int len, cases* a) ;
/// Accesseurs
element get(dA* t, int i, int j) ;
/// Transformateurs
void append(dA* t, int i, int j, void* value) ;
void remove_dico(dA* t, int i, int j) ;
/// Libération Mémoire
void free_dA(dA* t) ;
int h(int x, int y) ;

#endif