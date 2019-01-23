#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#define ERROR 0
#define EXITO 1

//LAS SIGUIENTES FUNCIONES RETORNAN SI LA EJECUCION DE UNA FUNCION FUE
//UN EXITO O ERROR, ADEMAS EL USUARIO DEBE SABER QUE LA PRIM
//ERA POSICION ES 0. SI EL VECTOR ESTA LLENO NO REALIZA
//INSERCION Y DESPLAZAMIENTO.

int insertar(int *ce, int tam, int * vec, int data);
int insertar_pos(int *ce, int tam, int * vec, int data, int pos);
int insertar_ord_asc(int *ce, int tam, int * vec, int data);
int insertar_ord_asc_no_duplicados(int *ce, int tam, int * vec, int data);
int eliminar_elemento(int *ce, int tam, int * vec, int data);
int buscar(int ce, int tam, int * vec, int data);
int eliminar_todos_element(int *ce, int tam, int * vec, int data);
int eliminar_pos(int *ce, int tam, int * vec, int pos);
void mostrar_vec(int *vec,int ce);

int mi_bsearch(const int * vec, int ce, int num);
void ord_seleccion(int * vec, int ce);
int *buscar_menor(int *pi, int *pf);
void intercambiar(int *a, int*b);

#endif // VECTORES_H_INCLUDED
