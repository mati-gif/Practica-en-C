#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*12- Realizar un programa que permita registrar los datos para una venta de
$4600. Para ello, se le pedirá al usuario que ingrese su DNI, validar que dicho
número no sea menor que 1000000 ni mayor que 99999999. Luego, requerir al
usuario que seleccione el medio de pago: 1-Efectivo, 2-Tarjeta de crédito, si
selecciona tarjeta, pedir que ingrese una opción de las siguientes: 1-Visa, 2-
American Express, 3-Mercado Pago, 4-Cabal.
Además, requerir la cantidad de cuotas en las que abonará (1, 3, 6 o 12). El
interés por pagar en cuotas será de: 0 interés para efectivo o 1 cuota, 4% para 3
cuotas y 8% para 6 y 12 cuotas. Validar que todos los datos ingresados por el
usuario sean correctos, en caso contrario informar la situación y finalizar
programa. Por último, presentar un resumen de la operación, por ejemplo:
DNI: 38.456.123
Medio de pago: Tarjeta de crédito
Tarjeta: Cabal
Cuotas: 3
Total: $4784*/

int main()
{

    float venta = 4600;
    float Dni;
    int opcion;
    int cuotas;
    float totalVenta;
    char tipoTarjeta[50];
    int resultado;

    while (opcion != 3 )
    {
        printf("Ingresa su DNI : ");
        scanf("%f", &Dni);
        if (Dni < 1000000 || Dni > 99999999)
        {
            printf("Dni invalido , pruebe nuevamente \n");
        }
        printf("Seleccione el medio de pago:\n");
        printf("1. Efectivo\n");
        printf("2. Tarjeta de credito\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Puedes pagar en 0 o 1 cuota sin interes.\n");
            printf("Ingrese la cantidad de cuotas (0 o 1): ");
            scanf("%d", &cuotas);
            if (cuotas == 0 || cuotas == 1)
            {
                printf("DNI: %f\n", Dni);
                printf("Medio de Pago: Efectivo\n");
                printf("Cuotas: %d\n", cuotas);
                printf("Total a pagar: %f\n", venta);
            }
            break;
        case 2:
            printf("Selecciona alguna de las siguientes tarjetas:\n");
            printf("1. Visa\n");
            printf("2. American Express\n");
            printf("3. Mercado Pago\n");
            printf("4. Cabal\n");
            scanf("%s", tipoTarjeta);
            printf("Ingrese la cantidad de cuotas (3 ,6 o 12): ");
            scanf("%d", &cuotas);
            if (cuotas == 3)
            {
                totalVenta = (venta * 0.04) + venta;
                printf("DNI: %f\n", Dni);
                printf("Medio de Pago: Tarjeta de Credito\n");
                printf("Cuotas: %d\n", cuotas);
                printf("Tarjeta: %s\n", tipoTarjeta);
                printf("Total a pagar: %f\n", totalVenta);
            }
            else if (cuotas == 6 || cuotas == 12)
            {
                totalVenta = (venta * 0.08) + venta;
                printf("DNI: %f\n", Dni);
                printf("Medio de Pago: Tarjeta de Credito\n");
                printf("Cuotas: %d\n", cuotas);
                printf("Tarjeta: %c\n", tipoTarjeta);
                printf("Total a pagar: %f\n", totalVenta);
            }
            else
            {
                printf("Cantidad de cuotas invalida, pruebe nuevamente.\n");
            }
            break;
            case 3:
            printf("esta a punto de salir...\n");
            break;
        default:
            printf("Opcion invalida, pruebe nuevamente.\n");
            break;
        }
    }

    return 0;
}