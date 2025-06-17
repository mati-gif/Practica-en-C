#include <stdio.h>
#include <stdlib.h>

/*5. Se tiene el dni de un alumno y una nota correspondiente a su parcial.
Requerir al usuario ingresar el dni del alumno. Evaluar si el dni ingresado es
igual al que se tiene almacenado. Permitir ingresar un dni incorrecto hasta 3
veces como máximo. Si el usuario ingresa el dni de manera correcta, mostrar
en la consola la nota del alumno.
Trabajar con las siguientes variables:
int dni = 38632584;
float nota = 7;
int dniIngresado = 0;
int intentos = 1;
int ingresaCorrectamente = 0;
*/

int main()
{

    int dni = 386;
    float nota = 7;
    int dniIngresado = 0;
    int intentos = 1;
    int ingresaCorrectamente = 0;

    while (intentos <= 3)
    {
        printf("Ingrese el dni del alumno ");
        scanf("%d", &dniIngresado);
        if (dniIngresado != dni)
        {
            printf("El dni ingresado es invalido , intente nuevamente\n");
            intentos++;
        } else {
            printf("La nota del alumno es %f\n", nota);
            intentos += 4;
        }
    }

    return 0;
}
