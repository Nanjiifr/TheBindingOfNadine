#ifndef TAB_CHAINES_H
#define TAB_CHAINES_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct element_s element ;

typedef cell* list;

list empty_list() ;
int len(list l) ;
void add_in_last(list l, element e) ;
void removev1 (list l, element e) ; 
void destroy (list l) ;
element find(list l, int id) ;
element* to_tab(list l) ;

#endif // TAB_CHAINES_H