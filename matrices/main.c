#include <stdio.h>
#include <stdlib.h>
#include "Matrices.h"

int main()
{
    int mat[FIL][COL] = {{1,2,3},{4,5,6},{7,8,9}};
    int fil = 3;
    int col = 3;
    int mat2[FIL][COL];

    mostrar_matriz(mat,fil,col);
    copiar_mat(mat,fil,col,mat2);
    puts("");
    mostrar_matriz(mat2,fil,col);
    return 0;
}
