#include "TP_Parte2.h"
#include <stdio.h>
#include <stdlib.h>
#include "Indice.h"
#include "Lista.h"

#define CANT_CAMPOS 8

void generar_binario_alum(char * pathAlumTxt, char *pathAlum, char *pathError, t_fecha * fProceso){

    FILE *pTxt = fopen(pathAlumTxt,"rt");
    FILE *pAlu = fopen(pathAlum, "wb");
    FILE *pErr = fopen(pathError,"wt");
    FILE *pInd = fopen("indiceAlumnos.idx","wb");

    if(!pTxt || !pAlu || !pErr) return;

    t_alumno alu;
    char linea[100];
    int nro_reg = 1;
    t_reg_indice reg;
    t_indice indice;
    ind_crear(&indice);


    fgets(linea,100,pTxt);

    while(!feof(pTxt)){

        alu = procesar_linea(linea);
        if(grabar_alu(&alu,pAlu,pErr,fProceso) == 1 ){

            reg.dni = alu.dni;
            reg.nro_reg = nro_reg;
            ind_insertar(&indice,&reg);

            nro_reg++;
        }
        fgets(linea, 100, pTxt);
    }


    ind_grabar(&indice,"indiceAlumnos.idx");


    fclose(pInd);
    fclose(pErr);
    fclose(pAlu);
    fclose(pTxt);
}


int grabar_alu(t_alumno *alu, FILE *pAlu,FILE *pErr, t_fecha *fProceso){

    int vec[CANT_CAMPOS] = {0};

    validar_alu(alu,fProceso,vec);

    int i = 0;

    while(i < CANT_CAMPOS && vec[i] == 0) i++;

    if( i < CANT_CAMPOS){
        grabar_reg_invalido(pErr, alu, vec);
        return 0;
    }else{
        fwrite(alu, sizeof(t_alumno), 1, pAlu);
        return 1;
    }

}


void grabar_reg_invalido(FILE *pErr, t_alumno *alu, int *vec){

    char msg[600];
    static char campos[][60] = {"Dni ","Nombre ","Fecha de Nacimiento ","Sexo ","Fecha de Ingreso ","Carrera ", "Cantidad de Materias Aprobadas ", "Fecha de aprobacion de ultima materias "};
    int i;

    for(i = 0; i< CANT_CAMPOS; i++){

        if(vec[i] == 1){
            strcat(msg,campos[i]);
        }

    }


    fprintf(pErr,"%ld\t%-41s\t%d/%d/%d\t%c\t%d/%d/%d\t%-5s\t%d\t%d/%d/%d    Descripcion: %s Invalido\n",alu->dni,alu->apyn,alu->fNac.dia,alu->fNac.mes,alu->fNac.anio,alu->sexo,alu->fIngreso.dia,alu->fIngreso.mes,alu->fIngreso.anio,alu->carrera,alu->cantMatAprob,alu->fAprob.dia,alu->fAprob.mes,alu->fAprob.anio, msg);

}



t_alumno procesar_linea(char *linea){

    t_alumno alu;

    char *pFin = strchr(linea,'\n');
    *pFin = '\0';

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    alu.fAprob = procesar_linea_fecha(pFin);

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    alu.cantMatAprob = atoi(pFin);

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    strcpy(alu.carrera,pFin);

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    alu.fIngreso = procesar_linea_fecha(pFin);

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    alu.sexo = *pFin;

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    alu.fNac = procesar_linea_fecha(pFin);

    pFin = strrchr(linea,'|');
    *pFin = '\0';
    pFin++;

    strcpy(alu.apyn,pFin);

    //fin de ciclo

    alu.dni = atol(linea);

    alu.estado = 'R';
    alu.fBaja.dia = 31;
    alu.fBaja.mes = 12;
    alu.fBaja.anio = 9999;

    return alu;

}


t_fecha procesar_linea_fecha(char *linea){

    t_fecha fecha;

    char *pFin = strrchr(linea,'/');
    *pFin = '\0';
    pFin++;

    fecha.anio = atoi(pFin);

    pFin = strrchr(linea,'/');
    *pFin = '\0';
    pFin++;

    fecha.mes = atoi(pFin);

    fecha.dia = atoi(linea);

    return fecha;
}



void mostrar_archivos(const char * pathAlumnosTxt, const char *pathAlumosDat, const char *pathInd, const char *pathErr){

    FILE *aluTxt = fopen(pathAlumnosTxt, "rt");
    FILE *aluDat = fopen(pathAlumosDat, "rb");
    FILE *aluInd = fopen(pathInd, "rb");
    FILE *aluErr = fopen(pathErr, "rt");

    if(!aluDat || !aluTxt || !aluInd || !aluErr) return;

    puts("********** ALUMNOS DE ENTRADA **********");

    t_alumno alu;
    char buff[100];

    fgets(buff, 100, aluTxt);

    while(!feof(aluTxt)){

        alu = procesar_linea(buff);
        printf("%ld\t%-41s\t%d/%d/%d\t%c\t%d/%d/%d\t%-5s\t%d\t%d/%d/%d\n",alu.dni,alu.apyn,alu.fNac.dia,alu.fNac.mes,alu.fNac.anio,alu.sexo,alu.fIngreso.dia,alu.fIngreso.mes,alu.fIngreso.anio,alu.carrera,alu.cantMatAprob,alu.fAprob.dia,alu.fAprob.mes,alu.fAprob.anio);
        fgets(buff, 100, aluTxt);
    }

    printf("\n\n\n");

    puts("********** ALUMNOS DE LA BASE DE DATOS **********");

    fread(&alu,sizeof(t_alumno),1,aluDat);

    while(!feof(aluDat)){
        printf("%ld\t%-41s\t%d/%d/%d\t%c\t%d/%d/%d\t%-5s\t%d\t%d/%d/%d\n",alu.dni,alu.apyn,alu.fNac.dia,alu.fNac.mes,alu.fNac.anio,alu.sexo,alu.fIngreso.dia,alu.fIngreso.mes,alu.fIngreso.anio,alu.carrera,alu.cantMatAprob,alu.fAprob.dia,alu.fAprob.mes,alu.fAprob.anio);
        fread(&alu,sizeof(t_alumno),1,aluDat);
    }

    printf("\n\n\n");

    puts("********** INDICE **********");

    t_reg_indice reg;

    fread(&reg,sizeof(t_reg_indice),1,aluInd);

    while(!feof(aluInd)){

        printf("%ld\t%u\n",reg.dni,reg.nro_reg);

        fread(&reg,sizeof(t_reg_indice),1,aluInd);
    }


    puts("\n\n");

    puts("************** ALU ERROR **********");

    char buffer[1000];
    fgets(buffer,1000,aluErr);
    while(!feof(aluErr)){
        printf("%s",buffer);
        fgets(buffer,1000,aluErr);
    }

    fclose(aluErr);
    fclose(aluDat);
    fclose(aluInd);
    fclose(aluTxt);

}
