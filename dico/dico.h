#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct element_s element ;
typedef struct dico_s dico ;

dico create () ;
bool is_empty(dico d) ;
void add (dico d, element a, element b) ;
void remove(dico d, element a) ;
bool mem(dico d, element elt) ;
element* find(dico d, element elt) ;

void free_dico(dico d) ;