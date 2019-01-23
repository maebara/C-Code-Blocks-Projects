#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Fecha.h"
#include "Normalizador.h"

typedef struct{

    long dni;
    char apyn[40];
    t_fecha fNac;
    char sexo;
    t_fecha fIngreso;
    char carrera[4];
    int cantMatAprob;
    t_fecha fAprob;
    char estado;
    t_fecha fBaja;
}t_alumno;

int validar_alumno(t_alumno * alum);
int validar_dni(long dni);
int validar_sexo(char sexo);
int validar_fIngreso(t_fecha *fIngreso,t_fecha *fNac, t_fecha *fProceso);
int validar_carrera(char *carrera);
void validar_apyn(char *apyn);
int validar_fNac(t_fecha *fNac, t_fecha *fProceso);
int validar_cantMatAprob(int cant);
int validar_fAprob(t_fecha *fAprob, t_fecha *fIngreso,t_fecha *fProceso);
int validar_estado(char estado);
int validar_fBaja(t_fecha *fBaja);
char *normalizar_apyn(char * apyn);

#endif // ALUMNO_H_INCLUDED
