#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
#include "potencia.h"

float e_elevado_a(int x , float tol);

int main()
{

    float f;

    f = e_elevado_a(2,0.0001);

    printf("%f",f);

    return 0;
}


float e_elevado_a(int x , float tol){

    float output = 0, termino;
    int i = 0;


    termino = potencia_exp_int(x,i)/factorial(i);

    while(termino >= tol){

        output += termino;

        i++;

        termino = potencia_exp_int(x,i)/factorial(i);

    }

    return output;
}

