#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "Lista.h"
#include "Iterador.h"

typedef struct{
    t_lista lista;
    t_iterador it;
}t_indice;

void ind_crear (t_indice* ind);
int ind_insertar (t_indice* ind, const t_reg_indice* reg_ind);
int ind_eliminar (t_indice* ind, t_reg_indice* reg_ind);
int ind_buscar (const t_indice* ind, t_reg_indice* reg_ind);
int ind_cargar (t_indice* ind, const char* path);
int ind_grabar ( t_indice* ind, const char* path);
void ind_vaciar (t_indice* ind);
int ind_primero (t_indice* ind, t_reg_indice* reg_ind);
int ind_siguiente (t_indice*, t_reg_indice*);
int ind_fin ( const t_indice*);
void ind_liberar(t_indice*);


#endif // INDICE_H_INCLUDED
