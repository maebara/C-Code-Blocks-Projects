#include "TP_Parte4.h"
#include <stdio.h>
#include <stdlib.h>


char mostrar_menu(){

    char res;
    printf("\t\tBASE DE DATOS ALUMNOS\n\nA. Manteminiento\nB. Listar bajas\nC. Listar altas\nD. Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c",&res);

    while(res < 'A'|| res > 'D'){
        system("cls");
        printf("\t\tBASE DE DATOS ALUMNOS\n\nA. Manteminiento\nB. Listar bajas\nC. Listar altas\nD. Salir\n");
        printf("\nOpcion incorrecta! Ingrese opcion: ");
        fflush(stdin);
        scanf("%c",&res);
    }

    return res;
}

char mantenimiento_menu(){

    char res;
    system("cls");
    printf("\tMANTENIMIENTOS\n\nA. Dar de Alta\nB. Dar de Baja\nC. Volver\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c",&res);

    while(res < 'A'|| res > 'C'){
        system("cls");
        printf("\tMANTENIMIENTOS\n\nA. Dar de Alta\nB. Dar de Baja\nC. Volver\n");
        printf("\nOpcion incorrecta! Ingrese opcion: ");
        fflush(stdin);
        scanf("%c",&res);
    }
    fflush(stdin);
    return res;
}

void mantenimiento(const char *pathAlu, t_indice *ind,  t_fecha * fProceso){

    char res = mantenimiento_menu();

    while(res != 'C'){

        switch(res){

            case 'A':
                dar_alta(pathAlu, ind, fProceso);
                break;
            case 'B':
                dar_baja(pathAlu, ind, fProceso);
                break;
        }
        system("cls");

        res = mantenimiento_menu();
    }
}


void dar_alta(const char *pathAlu, t_indice *ind,  t_fecha * fProceso){

    long dni = validar_ingresar_dni();

    t_reg_indice reg = {dni, -1};

    if( ind_buscar(ind,&reg) == 1 ){
        puts("\nALUMNO EXISTENTE EN LA BASE DE DATOS");
        puts("presione enter para continuar...");
        fflush(stdin);
        getc(stdin);
        return;
    }

    FILE * pa = fopen(pathAlu, "rb+");
    if(!pa) return;

    fseek(pa,0L,SEEK_END);
    reg.nro_reg = ftell(pa) / sizeof(t_alumno)  + 1;

    t_alumno alu = validar_ingresar_alu_sin_dni(fProceso, dni);

    fwrite(&alu,sizeof(t_alumno),1,pa);
    ind_insertar(ind, &reg);

    puts("\nREGISTRO EXITOSO!");
    puts("presiones enter para continuar...");
    fflush(stdin);
    getc(stdin);
    fclose(pa);

}


void dar_baja(const char *pathAlu, t_indice *ind, t_fecha * fProceso){

    long dni = validar_ingresar_dni();

    t_reg_indice reg = {dni, -1};

    if(ind_buscar(ind,&reg) == 0){
        puts("ALUMNO INEXISTENTE");
        puts("presiones enter para continuar...");
        fflush(stdin);
        getc(stdin);
        return;
    }


    FILE * pa = fopen(pathAlu,"rb+");
    t_alumno alu;

    fseek(pa,sizeof(t_alumno) * (reg.nro_reg - 1),SEEK_SET);
    fread(&alu,sizeof(t_alumno),1,pa);

    alu.estado = 'B';
    alu.fBaja = *fProceso;

    fseek(pa,sizeof(t_alumno) * (reg.nro_reg - 1),SEEK_SET);
    fwrite(&alu,sizeof(t_alumno),1,pa);

    ind_eliminar(ind,&reg);

    puts("BAJA EXITOSA");
    puts("presiones enter para continuar...");
    fflush(stdin);
    getc(stdin);
    fclose(pa);
}


void listar_baja(const char *pathAlu){

    FILE * pa = fopen(pathAlu, "rb");
    if(!pa) return;

    t_alumno alu;

    fread(&alu,sizeof(t_alumno),1,pa);

    while(!feof(pa)){
        if(alu.estado == 'B'){
            printf("%ld\t%-41s\t%d/%d/%d\t%c\t%d/%d/%d\t%-5s\t%d\t%d/%d/%d\n",alu.dni,alu.apyn,alu.fNac.dia,alu.fNac.mes,alu.fNac.anio,alu.sexo,alu.fIngreso.dia,alu.fIngreso.mes,alu.fIngreso.anio,alu.carrera,alu.cantMatAprob,alu.fAprob.dia,alu.fAprob.mes,alu.fAprob.anio);
        }

        fread(&alu,sizeof(t_alumno),1,pa);
    }

    puts("presiones enter para continuar...");
    fflush(stdin);
    getc(stdin);
    fclose(pa);

}

void listar_alta(const char *pathAlu, t_indice *ind){

    FILE * pa = fopen(pathAlu, "rb");
    if(!pa) return;

    t_reg_indice reg;
    t_alumno alu;

    ind_primero(ind,&reg);

    while(!ind_fin(ind)){

        fseek(pa,sizeof(t_alumno) * (reg.nro_reg - 1), SEEK_SET);
        fread(&alu,sizeof(t_alumno),1,pa);
        printf("%ld\t%-41s\t%d/%d/%d\t%c\t%d/%d/%d\t%-5s\t%d\t%d/%d/%d\n",alu.dni,alu.apyn,alu.fNac.dia,alu.fNac.mes,alu.fNac.anio,alu.sexo,alu.fIngreso.dia,alu.fIngreso.mes,alu.fIngreso.anio,alu.carrera,alu.cantMatAprob,alu.fAprob.dia,alu.fAprob.mes,alu.fAprob.anio);

        ind_siguiente(ind,&reg);
    }

    puts("presiones enter para continuar...");
    fflush(stdin);
    getc(stdin);
    fclose(pa);
}
