#ifndef NORMALIZADOR_H_INCLUDED
#define NORMALIZADOR_H_INCLUDED

#include <string.h>

typedef struct{
    char * pini;
    char * pfin;
    char * cursor;
    int termino;
}t_procesador;

void normalizar(char * cad);

void init_proce(t_procesador *proce, char *cad, char *aux);
int leer_palabra(t_procesador *proce);
int escribir_palabra(t_procesador *proce);
int escribir_caracter(t_procesador *proce,char c);
int fin_de_proceso(t_procesador *proce);
void cerrar_linea(t_procesador *proce);
int es_letra(char c);
void mover_cursor(t_procesador *proce, int cant);
void trim(char * cad);
void agregar_coma(char *cad);
int coma_finder(t_procesador * proce);

char to_lower(char c);
char to_upper(char c);


#endif // NORMALIZADOR_H_INCLUDED
