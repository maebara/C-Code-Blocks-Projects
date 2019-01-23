#ifndef TP_PARTE2_H_INCLUDED
#define TP_PARTE2_H_INCLUDED

#include "TP_Parte1.h"
#include <stdio.h>


void generar_binario_alum(char * pathAlumTxt, char *pathAlum, char *pathError, t_fecha *fProceso);

t_fecha procesar_linea_fecha(char *linea);
t_alumno procesar_linea(char *linea);
int grabar_alu(t_alumno *alu, FILE *pAlu,FILE *pErr, t_fecha *fProceso);
void grabar_reg_invalido(FILE *pErr, t_alumno *alu, int *vec);


void mostrar_archivos(const char * pathAlumnosTxt, const char *pathAlumosDat, const char *pathInd, const char *pathErr);
#endif // TP_PARTE2_H_INCLUDED
