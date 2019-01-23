#include <stdio.h>
#include <stdlib.h>
#include "fechFormal.h"



int main()
{
    t_fecha fech;

    scanf("%d %d %d",&fech.dia,&fech.mes,&fech.anio);

    printf("%d",es_fechFormal(fech));

    return 0;
}
