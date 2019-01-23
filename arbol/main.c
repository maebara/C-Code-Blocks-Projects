#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

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

    arbol_vaciar(&arbol);
    return 0;
}
