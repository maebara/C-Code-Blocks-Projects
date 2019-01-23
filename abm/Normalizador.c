#include "Normalizador.h"

void normalizar(char * cad){


    char aux[100];

    if(!strchr(cad,','))
        agregar_coma(cad);


    t_procesador proce;

    init_proce(&proce,cad,aux);

    leer_palabra(&proce);

    while(!fin_de_proceso(&proce)){

        escribir_palabra(&proce);

        if(coma_finder(&proce))
            escribir_caracter(&proce,',');

        escribir_caracter(&proce,' ');
        leer_palabra(&proce);

    }
    cerrar_linea(&proce);
    trim(aux);

    strcpy(cad,aux);
}



void init_proce(t_procesador *proce, char *cad, char *aux){
    proce->pfin = proce->pini = cad;
    proce->cursor = aux;
    proce->termino = 0;
}


int leer_palabra(t_procesador *proce){

    proce->pini = proce->pfin;

    while( *proce->pini && !es_letra(*proce->pini)){
        proce->pini++;
    }

    if(*proce->pini == '\0'){
        proce->termino = 1;
        return 0;
    }

    proce->pfin = proce->pini;

    while( *proce->pfin && es_letra(*proce->pfin)){
        proce->pfin++;
    }
    return 1;
}

int escribir_palabra(t_procesador *proce){

    *proce->cursor = to_upper(*proce->pini);
    proce->cursor++;
    proce->pini++;


    while(proce->pini < proce->pfin){
        *proce->cursor = to_lower(*proce->pini);
        proce->cursor++;
        proce->pini++;
    }
    return 1;

}


int escribir_caracter(t_procesador *proce,char c){

    *proce->cursor = c;
    proce->cursor++;
    return 1;
}

int fin_de_proceso(t_procesador *proce){
    return proce->termino == 1;
}

void cerrar_linea(t_procesador *proce){
    *proce->cursor = '\0';
}


int es_letra(char c){

    return (c >='a' && c<='z') || (c >= 'A' && c<='Z');
}

void trim(char * cad){

    char * pfin = strchr(cad,'\0') - 1;

    while(*pfin == ' '){
        pfin--;
    }

    pfin++;
    *pfin = '\0';
}

char to_lower(char c){
    return (c < 'A' || c > 'Z')?(c):(c + 32);

}
char to_upper(char c){
     return (c < 'a' || c > 'z')?(c):(c - 32);
}

void agregar_coma(char *cad){

    while(es_letra(*cad) == 0) cad++;
    while(es_letra(*cad)) cad++;
    *cad = ',';
}

int coma_finder(t_procesador * proce){

    proce->pini = proce->pfin;

    while(*proce->pini != '\0' && *proce->pini != ',' && es_letra(*proce->pini) == 0)
        proce->pini++;

    return *proce->pini == ',';
}
