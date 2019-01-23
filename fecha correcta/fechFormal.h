#ifndef FECHFORMAL_H_INCLUDED
#define FECHFORMAL_H_INCLUDED

typedef struct{
                        int dia,
                            mes,
                            anio;
}t_fecha;


int es_bisiesto(int anio);
int es_fechFormal(t_fecha fech);
int dia_del_mes(t_fecha fech);

#endif // FECHFORMAL_H_INCLUDED
