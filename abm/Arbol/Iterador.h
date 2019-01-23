#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include "Arbol.h"

typedef struct{
    t_arbol* pl;
    t_nodo_arb** act;
    int fin_it;

}t_iterador;

void crear_iterador(t_iterador* it, t_arbol *pa);
void primero( t_iterador *it, t_dato *d);
void siguiente( t_iterador *it, t_dato *d);
int fin_it( const t_iterador *it);

#endif // ITERADOR_H_INCLUDED
