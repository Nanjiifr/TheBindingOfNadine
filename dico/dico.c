/// DYNAMIC ARRAYS

#include "dico.h" // contains all includes

int MINLEN = 100 ;
int LENMULT = 2 ;
int RATIO = 3 ;

struct element_s {
    int key ;
    void* value ;
} ;
typedef struct element_s element ;

struct cell_s {
    element elt ;
    struct cell_s* next ;
} ;
typedef struct cell_s cell ;

typedef cell* list ;

struct dyn_dico_s {
  cases* elt ;
  int len ;
  int memlen ;
} ;

typedef struct dyn_dico_s dA ;

// Fonctions auxiliaires
int max_len(int a, int b) {
    while (a > b) {
        b *= LENMULT ;
    }
    return b ;
}

int min_len(int a, int b) {
    while(a<b) {
        b /= LENMULT ;
    }
    return b;
}

int pow_int(int x, int n) {
    //Returns 1 if n <= 0, else x^n
    int r = 1 ;
    for (int i = 1 ; i<n ; i++) {
        r*=x ;
    }
    return r ;
}

void resize(dA* t, int newlen) {
    if (newlen < MINLEN) {
        printf("Error : Minimum lenght exeeded\n") ;
        assert(false) ;
    }
    else {
        if ((float)newlen / (float)t->memlen > 3) {
            int length = max_len(newlen, t->memlen) ;
            cases* n_t = malloc(sizeof(cases)*length) ;
            for (int i = 0; i<t->memlen; i++) {
                element* elts = to_tab(t->elt[i]) ;
                for (int j = 0; j<(len(t->elt[i])); j++) {
                    add_in_last(n_t[(elts[j].key)%length], elts[j]) ;
                }
            }
            free(t->elt) ;
            t->elt = n_t ;
            t->memlen = length ;
        }
    }
}

/**
 * Calculates the hashing value of a couple of integers
 * 
 * @param i First value of the couple
 * @param j Second value of the couple
 * 
 * @returns The value of the unique corresponding integer to the couple
 */
/*int h (int i, int j) {
    if (i >= 0) {
        if (j>=0) return pow_int(2, 2*i) + pow_int(3, 2*j) ;
        return pow_int(2, 2*i) + pow_int(3, -2*j - 1) ;
    } else {
        if (j>=0) return pow_int(2, -2*i - 1) + pow_int(3, 2*j) ;
        return pow_int(2, -2*i - 1) + pow_int(3, -2*j - 1) ;
    }
}*/
int h(int i, int j) {
    return i * 31 + j * 37;
}

//Fonctions interfaces

//Constructeurs
dA* create () {
    dA* dyn_list = malloc(sizeof(dA)) ;
    dyn_list->elt = malloc(sizeof(cases) * MINLEN) ;
    for (int i = 0 ; i<MINLEN ; i++) {
        dyn_list->elt[i] = empty_list() ;
    }
    dyn_list->len = 0 ;
    dyn_list->memlen = MINLEN ;
    return dyn_list ;
}

dA* create_from_d(int len, cases* a) {
    dA* dyn_list = create() ;
    resize(dyn_list, len) ;
    for (int i = 0; i < len; i++) {
        dyn_list->elt[i] = a[i] ;
    }
    dyn_list->len = len ;
    return dyn_list ;
}

//Accesseurs
/**
 * @brief Accesses the element from the specified index
 * 
 * @param t Pointer to the dynamic array
 * @param i The index of the element to get
 */
element get(dA* t, int i, int j) {
    int id = h(i, j) ;
    return find(t->elt[id%(t->memlen)], id) ;
}

//Transformateurs

/**
 * @brief Appends an element to the dynamic array.
 *
 * This function adds the specified element to the end of the dynamic array.
 *
 * @param t Pointer to the dynamic array.
 * @param i First value of coordinates
 * @param j Second value of coordinates
 * @param value The struct containing data for the rooms
 */
void append(dA* t, int i, int j, void* value) {
    if (t->len >= MINLEN) 
        resize(t, t->len + 1) ;
    int id = h(i, j) ;
    element e = {id, value} ;
    add_in_last(t->elt[id%(t->memlen)], e) ;
    t->len += 1;
}

//Destructeurs
void free_dA(dA* t) {
    for (int i = 0; i<t->len; i++) {
        destroy(t->elt[i]) ;
    }
    free(t->elt) ;
    free(t) ;
}

void remove_dico(dA* t, int i, int j) {
    element e = get(t, i, j) ;
    int id = h(i, j) ;
    removev1(t->elt[id%(t->memlen)], e) ;
}