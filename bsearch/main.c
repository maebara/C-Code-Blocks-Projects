#include <stdio.h>
#include <stdlib.h>

int mi_bsearch(const int * vec, int ce, int num);

int main()
{
    int vec[10] = {1,2,3,-4,5,6,7,8};
    int ce = 8;
    int num = 3;
    int pos = mi_bsearch(vec, ce, a);
  
    printf("posicion del elemento 3: %d", pos);
  
    return 0;
}

int mi_bsearch(const int * vec, int ce, int num){

    const int *pi = vec;
    const int *pf = vec + ce - 1;
    const int *pm = NULL;

    while(pi <= pf){

        pm = pi + (pf - pi)/2;

        if (*pm < num){
            pi = pm + 1;

        }
        else{

            if(*pm > num){
                pf = pm - 1;

            }
            else{

                return pm - vec;
            }
        }

    }

    return -1;
}
