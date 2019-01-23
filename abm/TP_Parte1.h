#ifndef TP_PARTE1_H_INCLUDED
#define TP_PARTE1_H_INCLUDED


#include "Alumno.h"

t_alumno validar_ingresar_alu_sin_dni(t_fecha * fProceso, int dni);
void validar_alu(t_alumno * alu, t_fecha * fProceso, int * vec_errores);
long validar_ingresar_dni();




#endif // TP_PARTE1_H_INCLUDED
