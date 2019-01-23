#include "Iterador.h"
#include <stdlib.h>

#define VERDADERO 1
#define FALSO 0


void crear_iterador(t_iterador* it, t_arbol *pa){
    it->pl = it->act = pa;
    it->fin_it = FALSO;
}
void primero( t_iterador *it, t_dato *d){

    if(*(it->pl) == NULL){
        it->fin_it = VERDADERO;
        return;
    }

    it->act = arbol_nodo_menor(it->pl);
    *d = (*(it->act))->info;
    return;
}
/*
void siguiente( t_iterador *it, t_dato *d);
int fin_it( const t_iterador *it);
*/
