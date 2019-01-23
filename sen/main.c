#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
#include "potencia.h"


float seno(float x, float tol);
float absoluto ( float x);



int main()
{
    printf("%f",seno(3.14/2,0.01));
    return 0;
}


float absoluto ( float x)
{

    if( x < 0 ) return -x;

    return x;

}


float seno(float x, float tol)
{

    float output = 0, termino;

    int i = 1, j = 1;



    termino = potencia_exp_int(x,i) / factorial(i);

    while( absoluto(termino) > tol)
    {

        output += j * termino;

        j = - j;
        i = i + 2;

        termino = potencia_exp_int(x,i) / factorial(i);

    }


    return output;
}
