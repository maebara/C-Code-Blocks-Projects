#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#define COL 99
#define FIL 99

void mostrar_matriz(int mat[][COL],int fil, int col);

void recorrer_encima_diagonal_pri(int mat[][COL],int fil, int col);
void recorrer_encima_diagonal_sec(int mat[][COL],int fil, int col);
void recorrer_encima_con_diagonal_pri(int mat[][COL],int fil, int col);
void recorrer_encima_con_diagonal_sec(int mat[][COL],int fil, int col);

void recorrer_debajo_diagonal_pri(int mat[][COL],int fil, int col);
void recorrer_debajo_diagonal_sec(int mat[][COL],int fil, int col);
void recorrer_debajo_con_diagonal_pri(int mat[][COL],int fil, int col);
void recorrer_debajo_con_diagonal_sec(int mat[][COL],int fil, int col);

int traza_matriz(int mat[][COL],int fil, int col);
int es_diagonal(int mat[][COL],int fil, int col);
int es_identidad(int mat[][COL],int fil, int col);
int es_simetrica(int mat[][COL],int fil, int col);

void traspuesta_cuadrada(int mat[][COL],int fil, int col);
void copiar_mat(int *m1, int fil, int col, int *m2);

#endif // MATRICES_H_INCLUDED
