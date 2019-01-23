#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int t_dato; // el tipo de dato lo suelen poner aparte en un TipoDato.h

typedef int  (*t_cmp) (const void *a, const void *b);
typedef void (*t_accion) (void * info, void * datos_accion);
typedef void (*t_actualizar) (void * actualizar, const void* actualizador);

typedef struct s_nodo{

    struct s_nodo *pSig;
    t_dato info;
}t_nodo;

typedef t_nodo *t_lista;


void init_lista(t_lista *pl);
int insertar_al_final(t_lista *pl, const t_dato *info);
void vaciar_lista(t_lista *pl);
void recorrer_lista(t_lista *pl, t_accion accion, void * datos );
int lista_vacia(const t_lista *pl);
int actualizar_insertar(t_lista *pl, const t_dato *info, t_cmp cmp, t_actualizar actualizar);
int lista_sacar_primero(t_lista* plista, t_dato* info);
int lista_llena(const t_lista* pl);
int buscar(t_lista *pl, t_dato *info, t_cmp cmp);
int eliminar_de_lista(t_lista* plista, t_dato* pd, t_cmp cmp);

int lista_insertar_en_orden_asc(t_lista* plista, const t_dato* pd, t_cmp cmp);
void lista_ordenar_asc(t_lista* plista, t_cmp cmp);



#endif // LISTA_H_INCLUDED
