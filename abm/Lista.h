#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "TipoRegInd.h"

typedef struct s_nodo{

    t_dato info;
    struct s_nodo *pSig;

}t_nodo;

typedef t_nodo *t_lista;


typedef int  (*t_cmp) (const void *a, const void *b);
int comp_dni(const void *a, const void *b);


void crear_lista(t_lista *pl);
void vaciar_lista(t_lista *pl);
int lista_vacia(const t_lista *pl);
int lista_sacar_primero(t_lista* plista, t_dato* info);
int buscar(const t_lista *pl, t_dato *info, t_cmp cmp);
int eliminar_de_lista(t_lista* plista, t_dato* pd, t_cmp cmp);
int lista_insertar_en_orden_asc(t_lista* plista, const t_dato* pd, t_cmp cmp);


#endif // LISTA_H_INCLUDED
