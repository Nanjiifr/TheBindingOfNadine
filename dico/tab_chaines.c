#include "tab_chaines.h"

struct element_s {
    int key ; //utilisé que pour les sentinelles et l'identification des salles (hashage des coordonnées)
    void* value ; //On pourra tout mettre dans un struct à part les coordonnées, comme ca tout est stocké au même endroit.
} ;
typedef struct element_s element ;

struct cell_s {
    element elt ;
    struct cell_s* next ;
} ;
typedef struct cell_s cell ;

typedef cell* list ;


list empty_list () {
    list head = malloc(sizeof(cell)) ;
    cell* tail = malloc(sizeof(cell)) ;
    head->elt.key = -1  ;
    tail->elt.key = -1 ;
    head->next = tail ;
    tail->next = NULL ;
    return head ;
}

int len(list l) {
    cell* last = l->next;
    int length = 0 ;
    while (last->elt.key != -1) {
        last = last->next ;
        l = l->next ;
        length ++ ;
    }
    return length ;
}

void add_in_last (list l, element e) {
    cell* last = l;
    cell* n_cell = malloc(sizeof(cell)) ;
    n_cell->elt = e ;
    n_cell->next = last->next ;
    last->next = n_cell ;
}

void removev1 (list l, element e) {
    cell* last = l->next;
    while (last->elt.key != -1 && last->elt.key != e.key) {
        last = last->next ;
        l = l->next ;
    }
    if (l->elt.key != -1) {
        l->next = last->next ;
        free(last) ;
    }
}


/**
 * Returns the element corresponding to the id provided
 * 
 * @param l List to search in
 * @param id The id to search
 * 
 * @returns The value element corresponding to the id. Returns {-1, NULL} if the element is not found in the list
 */
element find(list l, int id) {
    cell* last = l->next;
    while (last->elt.key != -1 && last->elt.key != id) {
        last = last->next ;
        l = l->next ;
    }
    /*if (last->elt.key == -1) {
        printf("Element not found ...") ;
    }*/
    return last->elt ;
}

void destroy (list l) {
    if (l->next == NULL) {
        free(l) ;
    } else {
        destroy(l->next) ;
        free(l) ;
    }
}

element* to_tab(list l) {
    int length = len(l) ;
    element* n_tab = malloc(sizeof(element)*length) ;
    for (int i = 0; i<length ; i++) {
        n_tab[i] = l->next->elt ;
        l = l->next ;
    }
    return n_tab ;
}