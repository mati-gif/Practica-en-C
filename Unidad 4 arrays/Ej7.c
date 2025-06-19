#include <stdio.h>
#include <string.h>

/*7. Declarar un array de tipo float. El usuario debe ingresar la cantidad de notas a
cargar. Leer las notas por consola, luego mostrar la suma total y el promedio.. */



int main() {
    int cantidad;
    float notas[100];  // Tamaño máximo permitido
    float suma = 0.0, promedio;

    printf("Ingrese la cantidad de notas a cargar (máximo 100): ");
    scanf("%d", &cantidad);

    if (cantidad > 100 || cantidad <= 0) {
        printf("Cantidad inválida. Debe ser entre 1 y 100.\n");
        return 1;
    }

    // Ingreso de notas y cálculo de la suma
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese la nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        suma += notas[i];
    }

    promedio = suma / cantidad;

    // Mostrar resultados
    printf("\nSuma total de notas: %.2f\n", suma);
    printf("Promedio de notas: %.2f\n", promedio);
    return 0;
}
