#include <stdio.h>
#include <string.h>

/*1. Cargar en un arreglo las marcas obtenidas por 10 corredores en una carrera e
imprimir cuántos tienen una marca mayor, cuántos tienen una marca menor que
el promedio y el promedio.*/

#include <stdio.h>

int main() {
    float marcas[10];
    float suma = 0;
    float promedio;
    int mayores = 0;
    int menores = 0;

    // Ingreso de datos
    for (int i = 0; i < 10; i++) {
        printf("Ingrese la marca del corredor %d: ", i + 1);
        scanf("%f", &marcas[i]);
        suma += marcas[i];  // acumulamos para el promedio
    }

    // Cálculo del promedio
    promedio = suma / 10.0;

    // Contar mayores y menores que el promedio
    for (int i = 0; i < 10; i++) {
        if (marcas[i] > promedio) {
            mayores++;
        } else if (marcas[i] < promedio) {
            menores++;
        }
    }

    // Resultados
    printf("\nPromedio de marcas: %.2f\n", promedio);
    printf("Cantidad de marcas mayores que el promedio: %d\n", mayores);
    printf("Cantidad de marcas menores que el promedio: %d\n", menores);

    return 0;
}
