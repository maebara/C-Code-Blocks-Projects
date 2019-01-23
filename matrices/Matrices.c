#include  "Matrices.h"
#include <stdio.h>


void mostrar_matriz(int mat[][COL],int fil, int col){

    unsigned int i , j;

    for( i = 0; i < fil; i++){

        for( j = 0; j < col; j++) printf("%d\t", mat[i][j]);

        printf("\n");
    }
}


void recorrer_encima_diagonal_pri(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for(i = 0; i < fil  ; i++){

        for ( j = i + 1; j < col ; j++ ) printf("%d\t", mat[i][j]);

        printf("\n");

    }

}

void recorrer_encima_con_diagonal_pri(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for(i = 0; i < fil; i++){

        for ( j = i; j < col; j++) printf("%d\t", mat[i][j]);

        printf("\n");

    }

}


void recorrer_encima_diagonal_sec(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for( i = 0; i < fil; i++){

        for(j = 0; j < col - i - 1; j++) printf("%d\t", mat[i][j]);

        printf("\n");
    }
}

void recorrer_encima_con_diagonal_sec(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for( i = 0; i < fil; i++){

        for(j = 0; j < col - i; j++) printf("%d\t", mat[i][j]);

        printf("\n");
    }
}


void recorrer_debajo_diagonal_pri(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for( i = 0 ; i < fil; i++){

        for( j = 0; j < i; j++) printf("%d\t",mat[i][j]);

        printf("\n");
    }
}

void recorrer_debajo_con_diagonal_pri(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for( i = 0 ; i < fil; i++){

        for( j = 0; j <= i; j++) printf("%d\t",mat[i][j]);

        printf("\n");
    }
}


void recorrer_debajo_diagonal_sec(int mat[][COL], int fil, int col){

    unsigned int i, j;

    for( i = 0; i < fil; i++){

        for(j = col - i ; j < col ; j++) printf("%d\t", mat[i][j]);

        printf("\n");

    }
}


void recorrer_debajo_con_diagonal_sec(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for( i = 0; i < fil; i++){

        for(j = col - i - 1; j < col ; j++) printf("%d\t",mat[i][j]);

        printf("\n");

    }
}


int traza_matriz(int mat[][COL],int fil, int col){

    unsigned int i;
    int sum = 0;

    for(i = 0; i< fil; i++ ) sum += mat[i][i];

    return sum;

}

int es_diagonal(int mat[][COL],int fil, int col){

    unsigned int i, j;

    for(i = 0; i < fil  ; i++){

        for ( j = i + 1; j < col ; j++ ){

            if( mat[i][j] || mat[j][i] )  return 0;

        }

    }

    return 1;
}

int es_identidad(int mat[][COL],int fil, int col){

    unsigned int i = 0;

    if ( !es_diagonal(mat,fil,col) ) return 0;

    while( i < fil){

        if ( mat[i][i] != 1) return 0;

        i++;
    }

    return 1;
}

int es_simetrica(int mat[][COL],int fil, int col){

   unsigned int i, j;

   for(i = 0; i < fil  ; i++){

        for ( j = i + 1; j < col ; j++ ){

            if(mat[i][j] != mat[j][i]) return 0;

        }

    }

    return 1;
}

void traspuesta_cuadrada(int mat[][COL],int fil, int col){

    unsigned int i, j;
    int aux;

   for(i = 0; i < fil  ; i++){

        for ( j = i + 1; j < col ; j++ ){

            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

/*
int* traspuesta(int mat[][COL],int fil, int col){

    int tras[col][fil];

    unsigned int i , j;

    for( i = 0; i < fil; i++){

        for( j = 0; j < col; j++){

            tras[j][i] = mat[i][j];
        }
    }

    return tras;
}
*/
void copiar_mat(int *m1, int fil, int col, int *m2){

    int x = fil*col;

    while(x --> 0)
    printf("%d ",*m1);


}
/*
void recorrer_vecinos(int mat[][COL],int fil, int col, int posX, int posY){
    //suponiendo q posX y posY esta dentro del ragon de la matriz

    unsigned short i;
    int add = 1;

    posX += add;
    posy += add;

    for(i = 0; i < 8; i++){

        //pregunta si pertenece

            printf("%d",mat[posX][posY]);


        add = (i == 4)()
        //donde sumo ahora

        if(i%2 == 0) flag = 1;

        if(flag){
            posY+=add;
        }
        else{
            posX+=add;
        }

}
*/
