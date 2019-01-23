#ifndef LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED
#define LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED

typedef int t_dato;

typedef struct s_nodo{

    struct s_nodo * pDer;
    struct s_nodo * pIzq;
    t_dato info;

}t_nodo;

typedef t_nodo* t_lista;


typedef int (*t_cmp) (const void *a, const void *b);
typedef void (*t_accion) (void * info, void * datos_accion);
typedef void (*t_actualizar) (void *actualizar, const void *actualizador);



void crear_lista(t_lista *pl);
int lista_insertar_ord_asc(t_lista *pl, const t_dato *pd, t_cmp cmp);
int lista_insertar_ord_asc_dup(t_lista *pl, const t_dato *pd, t_cmp cmp);
int lista_insertar_actualizar_ord_asc(t_lista *pl, const t_dato *pd, t_cmp cmp, t_actualizar actualizar);
int lista_buscar(const t_lista *pl, t_dato *pd, t_cmp cmp);
int lista_eliminar(t_lista *pl, t_dato *pd, t_cmp cmp);
void lista_vaciar(t_lista *pl);
void lista_recorrer(t_lista *pl, t_accion accion, void * datos_accion);

int lista_vacia(const t_lista *pl);

int lista_llena(const t_lista *pl);

int lista_sacar_primero(t_lista *pl, const t_dato *pd, t_cmp cmp);



/*** utilitarias******/

void mostrar(void * info, void * datos_accion);
int comp_num(const void *a, const void *b);
#endif // LISTA_DOBLEMENTE_ENLAZADA_H_INCLUDED
