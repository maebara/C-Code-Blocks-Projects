#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"


int main()
{
    unsigned int num;

    scanf("%d",&num);

    printf("factorial de %d es %ld \n",num,factorial_recursivo(num));

    printf("factorial_v2 de %d es %ld",num,factorial_iterativo(num));

    return 0;
}


