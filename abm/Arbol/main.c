#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "Iterador.h"

int main()
{
    t_arbol arbol;
    crear_arbol(&arbol);
    int a = 2;
    int b = 6;
    int c = 4;
    arbol_insertar_ord_asc_no_dup(&arbol,&a,comp_num);
    arbol_insertar_ord_asc_no_dup(&arbol,&b,comp_num);
    arbol_insertar_ord_asc_no_dup(&arbol,&c,comp_num);


    t_iterador it;
    crear_iterador(&it,&arbol);

    int aux;
    primero(&it,&aux);

    printf("%d",aux);


    arbol_vaciar(&arbol);
    return 0;
}
