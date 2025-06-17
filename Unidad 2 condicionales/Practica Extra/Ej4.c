#include <stdio.h>
#include <math.h>

/*Problemas Condicionales Selectivos Simples
1. Determinar si un alumno aprueba a reprueba un curso, sabiendo que
aprobara si su promedio de tres calificaciones es mayor o igual a 7; reprueba
en caso contrario*/

int main(){

    int nota1;
    int nota2;
    int nota3;

    int promedio;
    printf("Ingrese la primera nota: ");
    scanf("%d", &nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%d", &nota2);
    printf("Ingrese la tercera nota: ");
    scanf("%d", &nota3);
    promedio = (nota1 + nota2 + nota3) / 3;
    if(promedio >= 7 ){
        printf("El alumno aprueba el curso con un promedio de %d\n", promedio);
    } else {
        printf("El alumno reprueba el curso con un promedio de %d\n", promedio);
    }

    return 0 ; 
}