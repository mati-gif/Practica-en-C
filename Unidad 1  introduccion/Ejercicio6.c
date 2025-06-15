#include <stdio.h>
#include <stdlib.h>

/* 7 => Ingresar el valor de la hora y el tiempo trabajado por un comerciante, calcular
su sueldo e imprimirlo.*/

int main(){


float valorHora;
int tiempoTrabajado;
float sueldo;
printf("ingrese el tiempo trabajado : ");
scanf("%d",&tiempoTrabajado);
printf("Ingrese el valor de la hora: ");
scanf("%f",&valorHora);
sueldo = tiempoTrabajado * valorHora;
printf("El sueldo del trabajador es : %f\n", sueldo);


    return 0;
}