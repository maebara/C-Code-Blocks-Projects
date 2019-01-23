#include "Lista Doblemente Enlazada.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(t_lista *pl){
    *pl = NULL;

}

int lista_insertar_ord_asc(t_lista *pl, const t_dato *pd, t_cmp cmp){

    t_nodo *pAnt = NULL,
           *pSig = NULL,
           *act  = *pl;

    if(act){
        while(act->pIzq && cmp(&act->info,pd) > 0)
            act = act->pIzq;

        while(act->pDer && cmp(&act->info,pd) < 0)
            act = act->pDer;

        int comp = cmp(&act->info,pd);

        if(comp == 0) return 0; //DUPLICADO

        if(comp > 0){

            pAnt = act->pIzq;
            pSig = act;

        }else{
            pAnt = act;
            pSig = act->pDer;
        }

    }

    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(nue == NULL) return 0; //SIN_MEM

    nue->info = *pd;
    nue->pDer = pSig;
    nue->pIzq = pAnt;

    if(pAnt) pAnt->pDer = nue;

    if(pSig) pSig->pIzq = nue;

    *pl = nue;

    return 1; //TODO_OK
}


int lista_insertar_ord_asc_dup(t_lista *pl, const t_dato *pd, t_cmp cmp){

    t_nodo *pAnt = NULL,
           *pSig = NULL,
           *act  = *pl;

    if(act){
        while(act->pIzq && cmp(&act->info,pd) > 0)
            act = act->pIzq;

        while(act->pDer && cmp(&act->info,pd) < 0)
            act = act->pDer;

        int comp = cmp(&act->info,pd);


        if(comp > 0){

            pAnt = act->pIzq;
            pSig = act;

        }else{
            pAnt = act;
            pSig = act->pDer;
        }

    }

    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(nue == NULL) return 0; //SIN_MEM

    nue->info = *pd;
    nue->pDer = pSig;
    nue->pIzq = pAnt;

    if(pAnt) pAnt->pDer = nue;

    if(pSig) pSig->pIzq = nue;

    *pl = nue;

    return 1; //TODO_OK
}

void lista_recorrer(t_lista *pl, t_accion accion, void * datos_accion){

    if(*pl == NULL) return;

    t_nodo * act = *pl;

    while(act->pIzq)
        act = act->pIzq;


    while(act){
        accion(&act->info, datos_accion);
        act = act->pDer;
    }
}


int lista_buscar(const t_lista *pl, t_dato *pd, t_cmp cmp){

    if(*pl == NULL) return 0;//FALSO

    while((*pl)->pIzq && cmp(&(*pl)->info,pd) > 0)
        pl = &(*pl)->pIzq;

    while((*pl)->pDer && cmp(&(*pl)->info,pd) < 0)
        pl = &(*pl)->pDer;

    int comp = cmp(&(*pl)->info,pd);

    if(comp != 0) return 0; //FALSO

     *pd = (*pl)->info;

    return 1;
}


int lista_eliminar(t_lista *pl, t_dato *pd, t_cmp cmp){

    t_nodo *act  = *pl;

    if(act == NULL) return 0;

    while(act->pIzq && cmp(&act->info,pd) > 0)
       act = act->pIzq;

    while(act->pDer && cmp(&act->info,pd) < 0)
        act = act->pDer;

    int comp = cmp(&act->info,pd);

    if(comp != 0) return 0; //FALSO

    if(act->pIzq){
        act->pIzq->pDer = act->pDer;

        if(*pl == act)
            *pl = act->pIzq;
        else
            *pl = act->pDer;
    }

    if(act->pDer)
        act->pDer->pIzq = act->pIzq;

    free(act);

    return 1;
}
void lista_vaciar(t_lista *pl){

    if(*pl == NULL) return;

    t_nodo * act = *pl;

    while(act->pIzq)
        act = act->pIzq;


    t_nodo *nae;
    while(act){
        nae = act;
        act = act->pDer;
        free(nae);
    }


    *pl = NULL;
}


int lista_insertar_actualizar_ord_asc(t_lista *pl, const t_dato *pd, t_cmp cmp, t_actualizar actualizar){

     t_nodo *pAnt = NULL,
            *pSig = NULL,
            *act  = *pl;

    if(act){
        while(act->pIzq && cmp(&act->info,pd) > 0)
            act = act->pIzq;

        while(act->pDer && cmp(&act->info,pd) < 0)
            act = act->pDer;

        int comp = cmp(&act->info,pd);

        if(comp == 0){
            actualizar(&act->info,pd);
            return 1;
        }

        if(comp > 0){

            pAnt = act->pIzq;
            pSig = act;

        }else{
            pAnt = act;
            pSig = act->pDer;
        }

    }

    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(nue == NULL) return 0; //SIN_MEM

    nue->info = *pd;
    nue->pDer = pSig;
    nue->pIzq = pAnt;

    if(pAnt) pAnt->pDer = nue;

    if(pSig) pSig->pIzq = nue;

    *pl = nue;

    return 1; //TODO_OK

}

/***utilitarias****/

void mostrar(void * info, void * datos_accion){

    int * d = (int*)info;

    printf("%d ",*d);
}

int comp_num(const void *a, const void *b){

    return *(int*)a - *(int*)b;
}
