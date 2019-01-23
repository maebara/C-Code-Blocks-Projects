#include "Vectores.h"
#include <stdio.h>

//Inserta al final
int insertar(int *ce, int tam, int * vec, int data){

    if(*ce == tam) return ERROR;

    *(vec + *ce) = data;

    (*ce)++;

    return EXITO;
}

//Insertar y corre los valores para no alterar el orden
int insertar_pos(int *ce, int tam, int * vec, int data, int pos){

    if(*ce == tam || pos > *ce) return ERROR;

    int i;

    for(i = *ce; i > pos; i--){

        *(vec + i) = *(vec + i - 1);
    }

    *(vec + i) = data;

    (*ce)++;

    return EXITO;

}

//Inserta ordenado ascendentemente, no considera repeticiones
int insertar_ord_asc(int *ce, int tam, int * vec, int data){

    if(*ce == tam) return ERROR;

    int pos = 0, i;

    while( pos < *ce && *(vec + pos) < data){

        pos++;
    }

    for(i = *ce; i > pos; i--){

        *(vec + i) = *(vec + i - 1);
    }

    *(vec + i) = data;
    (*ce)++;

    return EXITO;
}


int insertar_ord_asc_no_duplicados(int *ce, int tam, int * vec, int data){

    if(*ce == tam) return ERROR;

    int pos = 0, i;

    while( pos < *ce && *(vec + pos) < data){

        pos++;
    }

    if(*(vec + pos) == data) return ERROR;

    for(i = *ce; i > pos; i--){

        *(vec + i) = *(vec + i - 1);
    }

    *(vec + i) = data;
    (*ce)++;

    return EXITO;

}


int eliminar_elemento(int *ce, int tam, int * vec, int data){

    if(*ce == 0) return ERROR;

    int pos = 0;

    while( pos < *ce &&  *(vec + pos) != data){

        pos++;
    }

    if(pos == *ce) return ERROR;

    int i;
    int condicion = *ce - 1;

    for(i = pos; i < condicion; i++){

        *(vec + i) = *(vec + i + 1);

    }

    (*ce)--;

    return EXITO;

}
//retorna la pos
int buscar(int ce, int tam, int * vec, int data){

    int pos = 0;

    while(pos < ce && *(vec + pos) != data){
        pos++;
    }

    if( pos == ce) return -1;

    return pos;

}

int eliminar_todos_element(int *ce, int tam, int * vec, int data){

    if(*ce == 0) return ERROR;

    int pos = 0;

    while( pos < *ce &&  *(vec + pos) != data){

        pos++;
    }

    int i;
    int condicion;

    while(pos != *ce){

        condicion = *ce - 1;

        for(i = pos; i < condicion; i++){

            *(vec + i) = *(vec + i + 1);

        }

        (*ce)--;

        while( pos < *ce &&  *(vec + pos) != data){

            pos++;

        }
    }

    return EXITO;

}

int eliminar_pos(int *ce, int tam, int * vec, int pos){

    if(*ce == 0 || pos >= *ce) return ERROR;

    int i;
    int condicion = *ce - 1;

    for(i = pos; i < condicion; i++){

        *(vec + i) = *(vec + i + 1);

    }
    (*ce)--;

    return EXITO;
}

void mostrar_vec(int *vec,int ce){

    int i;
    printf("\n[");
    ce--;
    for ( i = 0; i < ce ; i++){

        printf("%d, ",*(vec + i));

    }

    printf("%d]\n",*(vec + i));

}

int mi_bsearch(const int * vec, int ce, int num){

    const int *pi = vec;
    const int *pf = vec + ce - 1;
    const int *pm = NULL;

    while(pi <= pf){

        pm = pi + (pf - pi)/2;

        if (*pm < num){
            pi = pm + 1;

        }
        else{

            if(*pm > num){
                pf = pm - 1;

            }
            else{

                return pm - vec;
            }
        }

    }

    return -1;
}

void ord_seleccion(int * vec, int ce){

    int * pf = vec + ce - 1;
    int * i;
    int * pm;

    for(i = vec; i < pf; i++ ){

        pm = buscar_menor(i,pf);

        if(i != pm)
            intercambiar(i,pm);

    }
}


int *buscar_menor(int *pi, int *pf){

    int * pm = pi;
    int * i;

    for(i = pi + 1; i <= pf; i++){

        if( *i < *pm)
            pm = i;

    }

    return pm;

}
void intercambiar(int *a, int*b){

    int aux = *a;
    *a = *b;
    *b = aux;
}
