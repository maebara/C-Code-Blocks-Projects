#ifndef TP_PARTE4_H_INCLUDED
#define TP_PARTE4_H_INCLUDED
#include "TP_Parte1.h"
#include "Indice.h"

char mostrar_menu();
char mantenimiento_menu();
void mantenimiento(const char *pathAlu, t_indice *ind, t_fecha * fProceso);

void dar_alta(const char *pathAlu, t_indice *ind, t_fecha * fProceso);
void dar_baja(const char *pathAlu, t_indice *ind, t_fecha * fProceso);

void listar_baja(const char *pathAlu);
void listar_alta(const char *pathAlu, t_indice *ind);

#endif // TP_PARTE4_H_INCLUDED
