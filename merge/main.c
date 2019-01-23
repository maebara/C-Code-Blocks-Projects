#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int dni;
    char apyn[100];
    char sexo;

}t_persona;

void merge(FILE *a, FILE *b, FILE *c,size_t bytes,int (*comp) (const void*,const void*));
int comp(const void *a, const void *b);

int main()
{
    FILE *a;
    FILE *b;
    FILE *c;

    a = fopen("lotesA.dat", "rb");
    b = fopen("lotesB.dat", "rb");
    c = fopen("fileC.dat", "wb");

    merge(a, b, c, sizeof(t_persona), comp);


    fclose(a);
    fclose(b);
    fclose(c);


    return 0;
}


void merge(FILE *a, FILE *b, FILE *c, size_t bytes, int (*comp) (const void*,const void*)){

    void * numA = malloc(bytes);
    void * numB = malloc(bytes);

    fread(numA, bytes, 1, a);
    fread(numB, bytes, 1, b);
    int cmp;

    while(!feof(a) && !feof(b)){

        cmp = comp(numA,numB);

        if( cmp < 0){

            fwrite(numA, bytes, 1 ,c);
            fread(numA, bytes, 1, a);
        }
        else{

            if( cmp > 0){
                fwrite(numB, bytes, 1, c);
                fread(numB, bytes, 1, b);
            }
            else{
                fwrite(numA, bytes, 1, c);
                fread(numA, bytes, 1, a);
                fread(numB, bytes, 1, b);
 
            }

        }
    }

    if(!feof(a)){

        fwrite(numA, bytes, 1, c);
        fread(numA, bytes, 1, a);
        while(!feof(a)){
            fwrite(numA, bytes, 1, c);
            fread(numA, bytes, 1, a);
        }
    }

    if(!feof(b)){
        fwrite(numB,bytes,1,c);
        fread(numB,bytes,1,b);
        while(!feof(b)){
            fwrite(numB,bytes,1,c);
            fread(numB,bytes,1,b);
        }

    }

    free(numA);
    free(numB);
}

int comp(const void *a, const void *b){

    t_persona *p1 = (t_persona*)a;
    t_persona *p2 = (t_persona*)b;

    return p1->dni - p2->dni;
}
