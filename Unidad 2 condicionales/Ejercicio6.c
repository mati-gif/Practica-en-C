#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*6- Leer una nota de un alumno por consola e informar la condición del mismo.
(menor que 4: Reprobado, menor que 6: Regular, mayor o igual que 6:
Promocionado). Validar que la nota ingresada se encuentre entre el 0 y el 10, de
lo contrario informar “Nota inválida”.
*/

int main()
{

    int contador = 1;
    while (contador != 0)
    {

        float nota;

        printf("Ingresar la nota del alumno: ");
        scanf("%f", &nota);
        if (nota <= 0 || nota > 10)
        {
            printf("Nota invalida \n");
        }
        else if (nota < 4)
        {
            printf("Reprobado \n");
        }
        else if (nota < 6)
        {
            printf("Regular \n");
        }
        else if (nota >= 6)
        {
            printf("Promocionado \n");
        }
        printf("Desea continuar? (1: Si, 0: No): ");
        scanf("%d", &contador);
    }

    return 0;
}