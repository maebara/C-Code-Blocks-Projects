#include "Indice.h"
#include <stdio.h>


void ind_crear (t_indice* ind){

    crear_lista(&ind->lista);
    crear_iterador(&ind->it,&ind->lista);
}

int ind_insertar (t_indice* ind, const t_reg_indice* reg_ind){

    return lista_insertar_en_orden_asc(&ind->lista,reg_ind,comp_dni);
}

int ind_eliminar (t_indice* ind, t_reg_indice* reg_ind){

    return eliminar_de_lista(&ind->lista, reg_ind, comp_dni);

}



int ind_buscar (const t_indice* ind, t_reg_indice* reg_ind){

    return buscar(&ind->lista,reg_ind,comp_dni);

}


int ind_cargar (t_indice* ind, const char* path){


    FILE *p = fopen(path,"rb");
    if(!p) return 0;

    t_reg_indice reg;

    fread(&reg, sizeof(t_reg_indice), 1, p);
    while(!feof(p)){
            ind_insertar(ind,&reg);
            fread(&reg, sizeof(t_reg_indice), 1, p);
    }

    fclose(p);
    return 1;

}

int ind_grabar ( t_indice* ind, const char* path){

    FILE *p = fopen(path,"wb");
    if(!p) return 0;

    t_reg_indice reg;
    primero(&ind->it,&reg);
    while(!fin_it(&ind->it)){
        fwrite(&reg,sizeof(t_reg_indice),1,p);
        siguiente(&ind->it, &reg);
    }

    fclose(p);


    return 1;
}


void ind_vaciar (t_indice* ind){

    vaciar_lista(&ind->lista);

}




int ind_primero (t_indice* ind, t_reg_indice* reg_ind){
    primero(&ind->it,reg_ind);
    return 1;
}

int ind_siguiente (t_indice* ind, t_reg_indice* reg_ind){
    siguiente(&ind->it, reg_ind);
    return 1;

}
int ind_fin (const t_indice* ind){

    return fin_it(&ind->it);
}




