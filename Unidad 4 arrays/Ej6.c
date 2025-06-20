#include <stdio.h>
#include <string.h>

/*6. Ingrese por teclado las facturaciónes de los últimos 6 meses del año. Informar:
a. La facturación total
b. El promedio de facturación
c. La facturación máxima
d. La facturación mínima*/

#include <stdio.h>

int main() {
    int facturacion[6];
    int suma = 0;
    int max, min;
    float promedio;

    // Ingreso de datos
    for (int i = 0; i < 6; i++) {
        printf("Ingrese la facturación del mes %d: ", i + 1);
        scanf("%d", &facturacion[i]);
    }

    // Inicializar max y min con el primer valor ingresado
    max = facturacion[0];
    min = facturacion[0];

    // Calcular suma, max y min
    for (int i = 0; i < 6; i++) {
        suma += facturacion[i];

        if (facturacion[i] > max) {
            max = facturacion[i];
        }

        if (facturacion[i] < min) {
            min = facturacion[i];
        }
    }

    // Calcular promedio (notar el uso de 6.0 para float)
    promedio = suma / 6.0;

    // Mostrar resultados
    printf("a. Facturación total: %d\n", suma);
    printf("b. Promedio de facturación: %.2f\n", promedio);
    printf("c. Facturación máxima: %d\n", max);
    printf("d. Facturación mínima: %d\n", min);

    return 0;
}
