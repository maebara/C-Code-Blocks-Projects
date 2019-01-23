#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int es_fibonacci(int n);

int main()
{

    printf("%d",es_fibonacci(2));


    return 0;
}

int fibonacci(int n){

    if ( n == 0) return 0;
    if ( n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);

}

int es_fibonacci(int n){

     int i=0;

     while ( n > fibonacci(i)){
        i++;
     }

     return n == fibonacci(i);

}
