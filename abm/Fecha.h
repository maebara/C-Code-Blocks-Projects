#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}t_fecha;

int es_fecha_valida(t_fecha f);
int cant_dias_mes(int mes, int anio);
int cant_dias_mes_v2(int mes, int anio);
int es_bisiesto(int anio);
t_fecha sumar_dias(t_fecha f, int dias);
t_fecha restar_dias(t_fecha f, int dias);
int dia_de_la_semana(t_fecha f); // 0 = lunes, 6 = domingo
int dif_entre_dias(t_fecha f1, t_fecha f2);
int comp_fechas(t_fecha f1, t_fecha f2);

#endif // FECHA_H_INCLUDED
