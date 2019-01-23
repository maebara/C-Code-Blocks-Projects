#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED

#include "Lista Doblemente Enlazada.h"


#define VERDADERO 1
#define FALSO 0

typedef struct{
    t_lista* pl;
    t_nodo** act;
    int fin_it;

}t_iterador;

void crear_iterador(t_iterador* it, t_lista *pl);
void primero( t_iterador *it, t_dato *d);
void siguiente( t_iterador *it, t_dato *d);
int fin_it( const t_iterador *it);


#endif // ITERADOR_H_INCLUDED
