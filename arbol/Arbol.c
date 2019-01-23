#include "Arbol.h"
#include <stdio.h>
#include <stdlib.h>

void crear_arbol(t_arbol *pa){
    *pa =NULL;
}

int arbol_insertar_ord_asc_no_dup(t_arbol *pa,const t_dato * d, t_cmp cmp){

    if(*pa == NULL){
        t_nodo_arb *nue = (t_nodo_arb*)malloc(sizeof(t_nodo_arb));
        if(nue == NULL) return 0;

        nue->info = *d;
        nue->hDer = NULL;
        nue->hIzq = NULL;
        *pa = nue;

        return 1;
    }

    int comp = cmp(d, &(*pa)->info);

    if(comp == 0) return 0;

    if(comp < 0){
        return arbol_insertar_ord_asc_no_dup(&(*pa)->hIzq,d,cmp);
    }else{

        return arbol_insertar_ord_asc_no_dup(&(*pa)->hDer,d,cmp);
    }
}

int arbol_buscar(const t_arbol* pa, t_dato *d, t_cmp cmp){

    if(*pa == NULL) return 0;

    int comp = cmp(d, &(*pa)->info);

    if(comp == 0){
        *d = (*pa)->info;
        return 1;
    }

    if(comp > 0){
        return arbol_buscar(&(*pa)->hDer,d,cmp);
    }else{
        return arbol_buscar(&(*pa)->hIzq,d,cmp);
    }

}

void arbol_recorrer_pos(t_arbol *pa, t_accion accion,  void* datos_accion){

    if(*pa == NULL) return;

    arbol_recorrer_pos(&(*pa)->hIzq,accion,datos_accion);
    arbol_recorrer_pos(&(*pa)->hDer,accion,datos_accion);
    accion(*pa,datos_accion);

    return;
}

void arbol_recorrer_pre(t_arbol *pa, t_accion accion,  void* datos_accion){

    if(*pa == NULL) return;

    accion(*pa,datos_accion);
    arbol_recorrer_pre(&(*pa)->hIzq,accion,datos_accion);
    arbol_recorrer_pre(&(*pa)->hDer,accion,datos_accion);

    return;
}
void arbol_recorrer_ord(t_arbol *pa, t_accion accion,  void* datos_accion){

    if(*pa == NULL) return;

    arbol_recorrer_ord(&(*pa)->hIzq,accion,datos_accion);
    accion(*pa,datos_accion);
    arbol_recorrer_ord(&(*pa)->hDer,accion,datos_accion);

    return;
}




void arbol_vaciar(t_arbol *pa){


    if(*pa == NULL) return;

    arbol_vaciar(&(*pa)->hIzq);
    arbol_vaciar(&(*pa)->hDer);
    free(*pa);
    *pa = NULL;
    return;

}


int arbol_vacio(const t_arbol *pa){

    return *pa == NULL;
}

int arbol_lleno(const t_arbol *pa){

    t_nodo_arb * aux = (t_nodo_arb*) malloc(sizeof(t_nodo_arb));
    free(aux);
    return aux == NULL;
}


int arbol_altura(const t_arbol *pa){

    if(*pa == NULL) return 0;

    int hIzq =  arbol_altura(&(*pa)->hIzq);
    int hDer =  arbol_altura(&(*pa)->hDer);

    return (hIzq > hDer)?(hIzq + 1):(hDer + 1);

}


int arbol_profundidad(const t_arbol *pa){

    if(*pa == NULL) return -1;

    int profIzq =  arbol_profundidad(&(*pa)->hIzq);
    int profDer =  arbol_profundidad(&(*pa)->hDer);


    return (profIzq > profDer)?(profIzq + 1):(profDer + 1) ;

}


int arbol_cantidad_hojas(const t_arbol *pa){

    if(*pa == NULL) return 0;

    int hIzq =  arbol_cantidad_hojas(&(*pa)->hIzq);
    int hDer =  arbol_cantidad_hojas(&(*pa)->hDer);

    return hIzq + hDer + 1;

}



int arbol_eliminar(t_arbol* pa, t_dato* pd, t_cmp cmp)
{
    t_nodo_arb ** nae = arbol_buscar_nodo(pa,pd,cmp);

    if(!nae) return 0;
    *pd = (*nae)->info;

    arbol_eliminar_nodo_rec(nae);
    return 1;
}

t_nodo_arb **arbol_buscar_nodo( t_arbol *pa,const t_dato *pd,t_cmp cmp){

    if(*pa == NULL) return NULL;

    int comp = cmp(&(*pa)->info, pd);

    if(comp == 0) return pa;

    if(comp < 0){
        return arbol_buscar_nodo(&(*pa)->hDer,pd,cmp);
    }else{
        return arbol_buscar_nodo(&(*pa)->hIzq,pd,cmp);
    }

}

void arbol_eliminar_nodo_rec(t_nodo_arb ** nae){

    if( (*nae)->hDer == NULL && (*nae)->hIzq == NULL){
        free(*nae);
        *nae = NULL;
        return;
    }


    int hd = arbol_altura(&(*nae)->hDer);
    int hi = arbol_altura(&(*nae)->hIzq);

    t_nodo_arb ** nreem = hi>hd? arbol_nodo_mayor(&(*nae)->hIzq) : arbol_nodo_menor(&(*nae)->hDer);
    (*nae)->info = (*nreem)->info;
    arbol_eliminar_nodo_rec(nreem);
}


t_nodo_arb** arbol_nodo_mayor(t_arbol *pa){

    if(*pa == NULL) return NULL;

    while((*pa)->hDer != NULL){
        pa = &(*pa)->hDer;
    }

    return pa;
}

t_nodo_arb** arbol_nodo_menor(t_arbol *pa){

    if(*pa == NULL) return NULL;

    while((*pa)->hIzq != NULL){
        pa = &(*pa)->hIzq;
    }

    return pa;

}


int arbol_insertar_actualizar(t_arbol *pa, const t_dato * d, t_cmp cmp, t_actualizar actualizar){


    if(*pa == NULL){
        t_nodo_arb *nue = (t_nodo_arb*)malloc(sizeof(t_nodo_arb));
        if(nue == NULL) return 0;

        nue->info = *d;
        nue->hDer = NULL;
        nue->hIzq = NULL;
        *pa = nue;

        return 1;
    }

    int comp = cmp(d, &(*pa)->info);

    if(comp == 0) {
         actualizar(&(*pa)->info,d);
         return 1;
    }

    if(comp < 0){
        return arbol_insertar_actualizar(&(*pa)->hIzq,d,cmp,actualizar);
    }else{

        return arbol_insertar_actualizar(&(*pa)->hDer,d,cmp,actualizar);
    }

}

void arbol_que_arbol_es(const t_arbol *p)
{
    if(arbol_es_completo(p))
        puts("Arbol Completo");
    else
        if(arbol_es_balanceado(p))
            puts("Arbol Balanceado");
        else
            if(arbol_es_AVL(p))
                puts("Arbol AVL");
            else
                puts("Desbalanceado");
}

void arbol_podar(t_arbol *p, int h){

    if(*p){

        if(h == 0)
            arbol_vaciar(p);
        else{
            arbol_podar(&(*p)->hIzq, --h);
            arbol_podar(&(*p)->hDer, h);
        }
    }
}


int arbol_completo(const t_arbol *p, int h){
    if(*p)
        return arbol_completo(&(*p)->hIzq, --h) && arbol_completo(&(*p)->hDer, h);
    return h == 0;
}


int arbol_es_completo(const t_arbol *p)
{
    return arbol_completo(p, arbol_altura(p));
}



int arbol_balanceado(const t_arbol *p, int h)
{
    if(*p)
        return arbol_balanceado(&(*p)->hIzq, --h) && arbol_balanceado(&(*p)->hDer, h);
    return h <= 1;
}


int arbol_es_balanceado(const t_arbol *p)
{
    return arbol_balanceado(p, arbol_altura(p));
}


int arbol_es_AVL(const t_arbol *p)
{
    if(*p){
        int h = arbol_altura(&(*p)->hIzq) - arbol_altura(&(*p)->hDer);

        if(h > 1 || h < -1)
            return 0;

        return arbol_es_AVL(&(*p)->hIzq) && arbol_es_AVL(&(*p)->hDer);
    }

    return 1;
}

/***utilitarias para testear***/

void mostrar_num(void * num, void *datos_accion){

    printf((char*)datos_accion,((t_nodo_arb*)num)->info);
}

int comp_num(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int comp_char(const void *a, const void *b){

    return *(char*)a - *(char*)b;

}
void mostrar_char(void * dato, void *datos_accion){

    printf((char*)datos_accion,((t_nodo_arb*)dato)->info);

}
