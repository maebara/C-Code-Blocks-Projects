#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED




///**** UTILITARIAS ***///

typedef int  (*t_cmp) (const void *a, const void *b);
typedef void (*t_accion) (void * info, void * datos_accion);
typedef void (*t_actualizar) (void * actualizar, const void* actualizador);

int comp_num(const void *a, const void *b);
void mostrar_num(void * num, void *datos_accion);


int comp_char(const void *a, const void *b);
void mostrar_char(void * num, void *datos_accion);
///********************///
typedef int t_dato;


typedef struct s_nodo_arb{

    struct s_nodo_arb *hDer;
    struct s_nodo_arb *hIzq;
    t_dato info;
}t_nodo_arb;

typedef t_nodo_arb* t_arbol;

void crear_arbol(t_arbol *pa);
int arbol_insertar_ord_asc_no_dup(t_arbol *pa,const t_dato * d, t_cmp cmp);

void arbol_vaciar(t_arbol *pa);
int arbol_vacio(const t_arbol *pa);
int arbol_lleno(const t_arbol *pa);


void arbol_recorrer_pos(t_arbol *pa, t_accion accion,  void* datos_accion);
void arbol_recorrer_arbol_pre(t_arbol *pa, t_accion accion,  void* datos_accion);
void arbol_recorrer_arbol_ord(t_arbol *pa, t_accion accion,  void* datos_accion);

int arbol_altura(const t_arbol *pa);
int arbol_buscar(const t_arbol* pa, t_dato *d, t_cmp cmp);

int arbol_insertar_actualizar(t_arbol *pa, const t_dato * d, t_cmp cmp, t_actualizar actualizar);
int arbol_profundidad(const t_arbol *pa);
int arbol_cantidad_hojas(const t_arbol *pa);


int arbol_eliminar(t_arbol* pa, t_dato* pd, t_cmp cmp);
t_nodo_arb **arbol_buscar_nodo( t_arbol *pa,const t_dato *pd,t_cmp cmp);
void arbol_eliminar_nodo_rec(t_nodo_arb ** nae);
t_nodo_arb** arbol_nodo_mayor( t_arbol *pa);
t_nodo_arb** arbol_nodo_menor( t_arbol *pa);

void graficar_arbol(t_arbol *pa);

int arbol_es_AVL(const t_arbol *p);
int arbol_es_balanceado(const t_arbol *p);
int arbol_balanceado(const t_arbol *p, int h);
int arbol_es_completo(const t_arbol *p);
int arbol_completo(const t_arbol *p, int h);
void arbol_podar(t_arbol *p, int h);
void arbol_que_arbol_es(const t_arbol *p);


#endif // ARBOL_H_INCLUDED
