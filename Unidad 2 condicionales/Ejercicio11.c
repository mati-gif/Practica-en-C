#include <stdio.h>
#include <stdlib.h>

/*11- Pedir al usuario que ingrese dos números (permitir ingresar número con
decimales).
Luego presentar el siguiente menú:
1. Informar su suma
2. Informar su resta
3. Informar su multiplicación
4. Informar su división
5. Salir
Seleccione una operación: Mostrar el resultado de la operación seleccionada. Si
el usuario ingresa la opción 5 el programa debe terminar.
*/

int main()
{

    float num1;
    float num2;
    int opcion;
    float resultado;
    int acumulador = 0; // Variable para controlar el bucle

    do
    {
        printf("Ingrese el 1er numero :");
        scanf("%f", &num1);
        printf("Ingrese el 2do numero: ");
        scanf("%f", &num2);

        printf("------ Seleccione una operacion: ------\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");

        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            resultado = num1 + num2;
            printf("El resultado de la suma es : %f\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("El resultado de la resta es : %f\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("El resultado de la multiplicacion es : %f\n", resultado);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("No se puede dividir por cero.\n");
            }
            else
            {
                resultado = num1 / num2;
                printf("El resultado de la division es : %f\n", resultado);
            }
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Por favor, seleccione una opcion del 1 al 5.\n");
            break;
        }

    } while (opcion != 5);

    return 0;
}