#include "TP_Parte1.h"
#include <stdio.h>

t_alumno validar_ingresar_alu_sin_dni(t_fecha * fProceso, int dni){

    t_alumno alu;

    alu.dni = dni;

    printf("Ingrese Apellido/s y Nombre/s:\n>");
    fflush(stdin);
    gets(alu.apyn);

    validar_apyn(alu.apyn);

    printf("Ingrese sexo F o M:\n>");
    fflush(stdin);
    scanf("%c",&alu.sexo);

    while(validar_sexo(alu.sexo) == 0){
        puts("\nSEXO INVALIDO\n");
        printf("Ingrese sexo F o M:\n>");
        fflush(stdin);
        scanf("%c",&alu.sexo);

    }


    printf("Ingrese carrera:\n");
    fflush(stdin);
    gets(alu.carrera);
    while(validar_carrera(alu.carrera) == 0){
        puts("\nCARRERA INVALIDA\n");
        printf("Ingrese carrera:\n");
        fflush(stdin);
        gets(alu.carrera);
    }

    printf("Ingrese cantidad de materias aprobadas:\n>");
    fflush(stdin);
    scanf("%d",&alu.cantMatAprob);
    while(validar_cantMatAprob(alu.cantMatAprob) == 0){

        puts("\nCANTIDAD INVALIDA\n");
        printf("Ingrese cantidad de materias aprobadas:\n>");
        fflush(stdin);
        scanf("%d",&alu.cantMatAprob);
    }



    printf("Ingrese su Fecha de Nacimiento dd/mm/aaaa:\n>");
    scanf("%d/%d/%d",&alu.fNac.dia,&alu.fNac.mes,&alu.fNac.anio);

    while(validar_fNac(&alu.fNac,fProceso )== 0){
        puts("\nFECHA DE NACIMIENTO INVALIDA!!\n");
        printf("Ingrese su Fecha de Nacimiento dd/mm/aaaa:\n>");
        scanf("%d/%d/%d",&alu.fNac.dia,&alu.fNac.mes,&alu.fNac.anio);
    }


    printf("Ingrese su Fecha de Ingreso dd/mm/aaaa:\n>");
    scanf("%d/%d/%d",&alu.fIngreso.dia,&alu.fIngreso.mes,&alu.fIngreso.anio);

    while(validar_fIngreso(&alu.fIngreso,&alu.fNac,fProceso )== 0){
        puts("\nFECHA DE INGRESO INVALIDA!!\n");
        printf("Ingrese su Fecha de Ingreso dd/mm/aaaa:\n>");
        scanf("%d/%d/%d",&alu.fIngreso.dia,&alu.fIngreso.mes,&alu.fIngreso.anio);
    }

    printf("Ingrese su Fecha de aprobacion de la ultima materia dd/mm/aaaa:\n>");
    scanf("%d/%d/%d",&alu.fAprob.dia,&alu.fAprob.mes,&alu.fAprob.anio);

    while(validar_fAprob(&alu.fAprob,&alu.fIngreso,fProceso )== 0){
        puts("\nFECHA INVALIDA!!\n");
        printf("Ingrese su Fecha de aprobacion de la ultima materia dd/mm/aaaa:\n>");
        scanf("%d/%d/%d",&alu.fAprob.dia,&alu.fAprob.mes,&alu.fAprob.anio);
    }

    alu.estado = 'A';
    alu.fBaja.dia = 31;
    alu.fBaja.mes = 12;
    alu.fBaja.anio = 9999;

    return alu;

}

long validar_ingresar_dni(){

    long dni;

    printf("Ingrese DNI:\n>");
    scanf("%ld",&dni);

    while(validar_dni(dni) == 0){
        puts("\nDNI INVALIDO!!\n");
        printf("Ingrese DNI:\n>");
        scanf("%ld",&dni);
    }

    return dni;
}


void validar_alu(t_alumno * alu, t_fecha * fProceso, int * vec_errores){

    *vec_errores = !validar_dni(alu->dni);
    vec_errores++;
    *vec_errores = 0; normalizar(alu->apyn);
    vec_errores++;
    *vec_errores = !validar_fNac(&alu->fNac, fProceso);
    vec_errores++;
    *vec_errores = !validar_sexo(alu->sexo);
    vec_errores++;
    *vec_errores = !validar_fIngreso(&alu->fIngreso, &alu->fNac, fProceso);
    vec_errores++;
    *vec_errores = !validar_carrera(alu->carrera);
    vec_errores++;
    *vec_errores = !validar_cantMatAprob(alu->cantMatAprob);
    vec_errores++;
    *vec_errores = !validar_fAprob(&alu->fAprob, &alu->fIngreso, fProceso);

    /*

    vec_errores++;
    *vec_errores = !validar_fBaja(&alu->fBaja);
    vec_errores++;
    *vec_errores = !validar_estado(alu->estado);

    */
}
