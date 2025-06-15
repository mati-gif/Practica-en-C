#include <stdio.h>
#include <stdlib.h>

/*8. Ingresar el tiempo trabajado por un contador y considerando que el valor de
la hora es de 800 pesos, calcular su sueldo e imprimirlo.*/

int main(){


    int tiempoTrabajado;
    float valorHora = 800;
    float sueldo;
    printf("Ingrese el tiempo trabajado:");
    scanf("%d",&tiempoTrabajado);

    sueldo = valorHora * tiempoTrabajado;
    printf("El sueldo es: %f \n", sueldo);
    return 0;
}