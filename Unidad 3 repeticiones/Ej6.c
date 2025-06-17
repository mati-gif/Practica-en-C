#include <stdio.h>

/*6. Leer por consola notas hasta que el usuario lo indique e informar su suma y
promedio*/

int main(){

    int notas;
    int sumaNotas = 0;
    int promedio;
    int contador;
    int acumulador = 0;

    while(contador != 0){
    printf("Ingrese una nota : ");
    scanf("%d",&notas);
    sumaNotas += notas;
    acumulador++;
    printf("Desea continuar ingresando notas? (1 para continuar, 0 para salir): ");
    scanf("%d",&contador);


    }

    promedio = sumaNotas / acumulador;
    printf("La suma de las notas es: %d\n", sumaNotas);
    printf("El promedio de las notas es: %d\n", promedio);

    return 0;
}