#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
#define ERROR -1

long int combinatorio(int n, int m);

int main()
{
    unsigned int num1,num2;
    int comb;

    printf("Ingrese ( num1 num2 ): ");
    scanf("%d %d",&num1,&num2);

    comb = combinatorio(num1,num2);

    printf("%ld",comb);

    return 0;
}

long int combinatorio(int n, int m){


    if (  m < 0 || m >  n ){
        printf("hubo un error!!\n");
        return ERROR;
    }

    return factorial_iterativo(n) / ( factorial_iterativo(n - m) * factorial_iterativo(m) );

}
