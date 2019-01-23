#include "Iterador.h"
#include <stdlib.h>

void crear_iterador(t_iterador* it, t_lista *pl){

    if(*pl){
        while((*pl)->pIzq)
            pl = &(*pl)->pIzq;
    }

    it->pl = pl;
    it->act = pl;
    it->fin_it = FALSO;
}

void primero( t_iterador *it, t_dato *d){

    if(it->pl == NULL){
        it->fin_it = VERDADERO;
        return;
    }

    it->act = it->pl;
    *d = (*(it->act))->info;
    return;
}

void siguiente( t_iterador *it, t_dato *d){

    if((*(it->act))->pDer == NULL){
        it->fin_it = VERDADERO;
        return;
    }

    it->act = &(*(it->act))->pDer;
    *d = (*(it->act))->info;
    return;
}

int fin_it( const t_iterador *it){
    return it->fin_it;
}
