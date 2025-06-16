#include <stdio.h>
#include <stdlib.h>

/*1 y 2- Ingresar por teclado dos números, determinar cuál es el mayor y visualizarlo en
pantalla. Informar también si los números son iguales.*/
int main()
{

    int num1;
    int num2;
    int acumulador;

    do
    {
        printf("Ingrese el 1er numero: ");
        scanf("%d", &num1);
        printf("Ingrese el 2do numero: ");
        scanf("%d", &num2);
        if (num1 > num2)
        {
            printf("El numero mayor es :%d", num1);
        }
        else if (num2 > num1)
        {

            printf("El numero mayor es :%d", num2);
        }
        else
        {
            printf("Ambos numeros son iguales. ");
        }

        printf("\nSi desea salir del programa ingrese 0, de lo contrario ingrese cualquier otro numero: ");
        scanf("%d", &acumulador);
    } while (acumulador != 0);

    return 0;
}