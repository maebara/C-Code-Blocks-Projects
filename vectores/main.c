#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"
#define TAM 10

int main()
{
    int vec[TAM] = {1,2,-3,-66,23,0,1};
    int ce = 5;
    ord_seleccion(vec,ce);
    mostrar_vec(vec,ce);

    return 0;
}
