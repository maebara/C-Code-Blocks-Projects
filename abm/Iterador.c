#include "Iterador.h"

#define VERDADERO 1
#define FALSO 0


#include <stdlib.h>

void crear_iterador(t_iterador* it, t_lista *pl){

    it->pl = it->act = pl;
    it->fin_it = FALSO;
}

void primero( t_iterador *it, t_dato *d){

    it->act = it->pl;

    if( (*(it->act)) == NULL){
        it->fin_it = VERDADERO;
        return;
    }

    *d = (*(it->act))->info;
     it->fin_it = FALSO;
}

void siguiente( t_iterador *it, t_dato *d){

    it->act = &(*(it->act))->pSig;
    if((*(it->act)) == NULL){
        it->fin_it = VERDADERO;
        return;
    }
    *d = (*(it->act))->info;

}

int fin_it(const t_iterador *it){
    return it->fin_it;
}
