#include "Alumno.h"


int validar_dni(long dni){

    return dni>10000 && dni<100000000;

}

int validar_sexo(char sexo){

    return sexo=='M' || sexo=='F';
}


int validar_fIngreso(t_fecha *fIngreso,t_fecha *fNac, t_fecha *fProceso){

    if(es_fecha_valida(*fIngreso) == 0) return 0;

    int bool1 = comp_fechas(*fIngreso,*fProceso) <= 0;
    int bool2 = comp_fechas(*fIngreso,*fNac) > 0;
    return bool1 && bool2;
}


int validar_carrera(char *carrera){

    static char carreras[][4] = {"INF","ELE","IND","ECO","DER","ADM","MED","EDF","FIL","SAD","AA5"};

    int i = 0, tam = sizeof(carreras)/4;
    while(i < tam){
            if(strcmp(carrera,carreras[i]) == 0){
                return 1;
            }
            i++;
    }
    return 0;
}

void validar_apyn(char *apyn){

    normalizar(apyn);

}

int validar_fNac(t_fecha *fNac, t_fecha *fProceso){

    if(es_fecha_valida(*fNac) == 0) return 0;

    int dias = dif_entre_dias(*fNac,*fProceso);

    return dias > 3650;

}

int validar_cantMatAprob(int cant){
    return cant >= 0;
}

int validar_fAprob(t_fecha *fAprob, t_fecha *fIngreso,t_fecha *fProceso){

    if(es_fecha_valida(*fAprob) == 0) return 0;

    int bool1 = comp_fechas(*fAprob, *fIngreso) > 0;

    if(bool1 == 0) return 1;

    int bool2 = comp_fechas(*fAprob, *fProceso) <= 0;

    return bool1 && bool2;

}
int validar_estado(char estado){

    return estado == 'A' || estado == 'B';

}

int validar_fBaja(t_fecha *fBaja){

    return es_fecha_valida(*fBaja);
}


