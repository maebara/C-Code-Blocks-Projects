#include <stdio.h>
#include <stdlib.h>
float absoluto(float x);
float raiz_cuadrada(float x, float tol);

int main()
{
    printf("\n%f",raiz_cuadrada(4.0,1));
    return 0;
}



float raiz_cuadrada(float x, float tol){

    float output, termino1 = 1, termino2,dif;


    if(x<0){
        printf("hubo un error!");
        return -1;
    }

    termino2 = 1.0/2  * ( termino1 + x/termino1) ;

    dif = absoluto(termino2 - termino1);

    while(dif >= tol){

        termino1 = 1.0/2 * (termino2 + x/termino2);

        termino2 = 1.0/2 * (termino1 + x/termino1);

        dif = abs(termino2 - termino1);
    }

    output = termino2;

    return output;

}



float absoluto(float x){

    if ( x < 0) return -x;

    return x;

}
