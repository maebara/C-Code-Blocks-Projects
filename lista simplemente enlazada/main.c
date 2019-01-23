#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    t_lista lista;
    init_lista(&lista);
    int a = 1;
    int b = 2;
    int c = 3;

    insertar_al_final(&lista, &a);
    insertar_al_final(&lista, &b);
    insertar_al_final(&lista, &c);

    int elm = 1;
    eliminar_de_lista(&lista,&elm,comp_num);
    recorrer_lista(&lista,mostrar,"%d ");

    return 0;
}
