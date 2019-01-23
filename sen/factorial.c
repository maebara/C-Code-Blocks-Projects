#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

 long int factorial(unsigned int num){

        if( !num ) return 1;

        return num * factorial(num - 1);

}

 long int factorial_v2(unsigned int num){

    unsigned int i;

    long long int fact = 1;

    for(i = 1; i <= num ; i++){

        fact *= i ;


    }

    return fact;
}


