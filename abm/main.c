#include <stdio.h>
#include <stdlib.h>
#include "TP_Parte4.h"
#include "TP_Parte2.h"

int main()
{
    /*
    t_fecha f = {30,6,2018};

    generar_binario_alum("Alumnos.txt","Alumnos.dat","Alumnos_errores.txt",&f);

    mostrar_archivos("Alumnos.txt", "Alumnos.dat","indiceAlumnos.idx", "Alumnos_errores.txt");
    */

    char * pathAlu = "Alumnos.dat";
    char * pathInd = "indiceAlumnos.idx";
    //verificar paths

    t_fecha fProceso = {12,7,2018};
    t_indice ind;

    ind_crear(&ind);
    ind_cargar(&ind, pathInd);

    char res = mostrar_menu();

    while(res != 'D'){

        switch(res){
            case 'A':
                    mantenimiento(pathAlu,&ind,&fProceso);
                    break;
            case 'B':
                    listar_baja(pathAlu);
                    break;
            case 'C':
                    listar_alta(pathAlu, &ind);
                    break;

        }

        system("cls");

        res = mostrar_menu();

    }

    ind_grabar(&ind,pathInd);
    ind_vaciar(&ind);

    return 0;
}

