#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void seleccion(void * vec, int ce ,size_t tam);
void *buscar_menor(void *ini,void *fin,int (*comp)(const void *,const void*),size_t tam);
int comp(const void* a, const void *b);
void intercambiar(void *min,void *ini, size_t bytes);

int main()
{
    int vec[5] = {2,3,3,2,1};
    int ce = 5;
    size_t tam = sizeof(int);

    seleccion(vec,ce,tam);
    int i;
    for(i= 0; i < ce; i++){

        printf("%d ",vec[i]);
    }
    return 0;
}


void seleccion(void * vec, int ce,size_t tam){

    void * ini;
    void * fin = vec + (ce-1)*tam;
    void * min;

    for(ini = vec; ini < fin; ini+= tam){

        min = buscar_menor(ini,fin,comp,tam);

        if(min != ini){
            intercambiar(min,ini,tam);
        }

    }
}

void *buscar_menor(void *ini,void *fin,int (*comp)(const void *,const void*),size_t tam){

    void *min = ini;
    for( ini+=tam ; ini <= fin; ini+= tam){

        if(comp(ini,min) < 0){
            min = ini;
        }
    }
    return min;
}

int comp(const void* a, const void *b){
    int * num = (int *)a;
    int * num2 = (int *)b;
    return *num - *num2;

}

void intercambiar(void *min,void *ini, size_t bytes){

    void * aux = malloc(bytes);
    if (!aux) {
        fprintf(stderr, "malloc failed\n");
        exit(-1);
    }
    memcpy(aux,min,bytes);
    memcpy(min,ini,bytes);
    memcpy(ini,aux,bytes);
    free(aux);
}
