#include <stdio.h>
#include <stdlib.h>
#include "fechFormal.h"

int es_bisiesto(int anio){

    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}


int dia_del_mes(t_fecha fech){

    if ( fech.mes == 4||fech.mes==6||fech.mes==9||fech.mes==11)

        return 30;

    if ( fech.mes == 2 )

        return 28 + es_bisiesto(fech.anio);

    return 31;

}

int es_fechFormal(t_fecha fech){

    if (fech.anio <1601)

        return 0;

    if( fech.mes <= 0|| fech.mes >12)

        return 0;

    return fech.dia > 0 && fech.dia <= dia_del_mes(fech);

}



