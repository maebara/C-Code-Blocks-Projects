#include <stdio.h>
#include <stdlib.h>
char* ej_7(int num);

int main()
{
    char *msg;
    msg = ej_7(12);

    printf("\n%s",msg);
    return 0;
}


char* ej_7(int num)
{

    int i, sum = 0;
    char * calif;

    for ( i = 1 ; i < num ; i++)
    {

        if ( num%i == 0)
        {
            printf("%d\n",i);
            sum += i;
        }
    }


    if ( sum < num)
    {

        calif = "deficiente";

    }
    else if ( sum == num)
    {

        calif = "perfecto";
    }
    else
    {

        calif = "abundante";
    }


    return calif;


}
