#include <stdio.h>
#include <stdlib.h>

int buscar_char_izq(char letra, char vec[]);
int es_palindromo(char vec[]);
int char_length(char vec[]);
int char_length_nospace(char vec[]);
int to_lower_case(char c);

int main()
{
    char vec[]="   a n   i t a lav a l a ti n a ";

    printf("%d",es_palindromo(vec));

    return 0;
}
fgets

int es_palindromo(char vec[]){

    int i = 0;
    int j = char_length(vec) - 2;

    while ( i < j  && vec[i] ){

        while(vec[i] == ' ') i++;

        while ( vec[j] == ' ' && j > 0) j--;

        if ( vec[i] != vec[j] && to_lower_case(vec[i]) != to_lower_case(vec[j]) )  return 0;

        i++;  j--;

    }

    return char_length_nospace(vec) != 0;

}


int buscar_char_izq(char letra, char vec[]){

    int i = 0;

    while( vec[i] && vec[i] != letra) i++;

    return (vec[i] == letra)? i: -1;
}



int char_length(char vec[]){

    int  i = 0;

    while( vec[i++] ) ;

    return i;
}


int char_length_nospace(char vec[]){

    int i = 0, ce = 0;

    while(vec[i]){

        if( vec[i++] != ' ' ) ce++;

    }

    return ce;
}

int to_lower_case(char c){

    int letra = (int)c;

    return ( letra < 65 || letra > 90 )? letra : letra+32;
}
