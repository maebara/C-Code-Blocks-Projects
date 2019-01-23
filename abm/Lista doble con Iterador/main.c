#include <stdio.h>
#include <stdlib.h>
#include "Lista Doblemente Enlazada.h"
#include "Iterador.h"

int main()
{
    t_lista lista;
    crear_lista(&lista);
    int a = 20;
    int b = 30;
    int c = 40;
    int d = 29;
    int e = -23;

    lista_insertar_ord_asc_dup(&lista,&a,comp_num);
    lista_insertar_ord_asc_dup(&lista,&b,comp_num);
    lista_insertar_ord_asc_dup(&lista,&c,comp_num);
    lista_insertar_ord_asc_dup(&lista,&d,comp_num);
    lista_insertar_ord_asc_dup(&lista,&e,comp_num);
    lista_insertar_ord_asc_dup(&lista,&a,comp_num);

    t_iterador it;
    crear_iterador(&it,&lista);

    int aux;
    primero(&it,&aux);
    while(!fin_it(&it)){
        printf("%d ",aux);
        siguiente(&it,&aux);
    }

    return 0;
}
