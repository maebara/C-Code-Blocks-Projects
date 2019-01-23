#include <stdio.h>
#include "Fecha.h"

int es_fecha_valida(t_fecha f){

    if(f.anio >= 1601)
        if(f.mes >= 1 && f.mes <= 12)
            return f.dia >= 1 && f.dia <= cant_dias_mes(f.mes,f.anio);

    return 0;
}

int cant_dias_mes(int mes, int anio){

    if( mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    if( mes == 2)
        return 28 + es_bisiesto(anio);

    return 31;
}

int cant_dias_mes_v2(int mes, int anio){

    static int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes == 2)
        return dias[mes - 1] + es_bisiesto(anio);

    return dias[mes - 1];
}

int es_bisiesto(int anio){

    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

t_fecha sumar_dias(t_fecha f, int dias){

    t_fecha fech = f;
    fech.dia += dias;
    while(fech.dia > cant_dias_mes(fech.mes, fech.anio)){
        fech.dia -= cant_dias_mes(fech.mes, fech.anio);
        fech.mes++;

        if(fech.mes == 13){
            fech.mes = 1;
            fech.anio++;
        }
    }

    return fech;
}

t_fecha restar_dias(t_fecha f, int dias){

    t_fecha fech = f;
    fech.dia -= dias;
    while(fech.dia <= 0){

        fech.mes--;
        if(fech.mes == 0){
            fech.mes = 12;
            fech.anio--;
        }

        fech.dia += cant_dias_mes(fech.mes, fech.anio);

    }
    return fech;
}

int dif_entre_dias(t_fecha f1, t_fecha f2){

    t_fecha fMin, fMay;
    int dias;

    if(comp_fechas(f1,f2) > 0){
        fMay = f1;
        fMin = f2;
    }
    else{
        fMay = f2;
        fMin = f1;
    }

    dias = fMay.dia - fMin.dia;

    while(fMin.mes < fMay.mes || fMin.anio < fMay.anio){

        dias += cant_dias_mes(fMin.mes,fMin.anio);

        fMin.mes++;
        if(fMin.mes == 13){
            fMin.mes = 1;
            fMin.anio++;
        }
    }

    return dias;
}

int comp_fechas(t_fecha f1, t_fecha f2){

    if( f1.anio == f2.anio){

        if(f1.mes == f2.mes){
            return f1.dia - f2.dia;

        }
        return f1.mes - f2.mes;
    }

    return f1.anio - f2.anio;
}

int dia_de_la_semana(t_fecha f){

    t_fecha fInicial = {1,1,1601};

    return dif_entre_dias(f,fInicial) % 7;

}
