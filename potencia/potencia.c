#include <stdio.h>
#include <stdlib.h>
#include "potencia.h"

float potencia_exp_int(float x, int y){

        float pot = 1;
        int i;

        for(i=0;i<y;i++){
            pot*= x;
        }

        return pot;
}


void potencia_exp_real(){
}
