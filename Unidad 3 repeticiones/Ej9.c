#include <stdio.h>
#include <stdlib.h>

/*9. Realizar un programa que permita ver información a un cliente de un banco.
Para ello el cliente deberá ingresar su usuario (número de DNI) y contraseña
(número entero), validar que los datos ingresados sean correctos, se
permitirá al cliente 3 intentos de ingreso de contraseña. Al loguarse
correctamente presentar un menú con las siguientes opciones:
1- Consultar saldo
2- Consultar CBU
3- 3- Salir
Trabajar con las siguientes variables:
int dni = 35654123;
int pass = 1234;
int saldo = 150000;
int cbu = 986323456;
int dniIngresado = 0;
int passIngresado = 0;
int intentos = 1;
int ingresaCorrectamente = 0;
 */

int main()
{
    int intentos = 1;
    int dni = 356;
    int pass = 1234;
    int opcion;
    int saldo = 150000;
    int cbu = 986323456;
    while (intentos <= 3)
    {

        int dniIngresado = 0;
        int passIngresado = 0;
        printf("Ingrese el dni: ");
        scanf("%d", &dniIngresado);
        printf("Ingresa la contraseña : ");
        scanf("%d", &passIngresado);
        if (passIngresado != pass)
        {
            printf("Contraseña incorrecta.");
            intentos++;
        }
        else
        {
            do
            {
                printf("Ingrese una opcion");
                printf("------MENU-----\n");
                printf("1- Consultar saldo\n");
                printf("2- Consultar CBU\n");
                printf("3- Salir\n");
                scanf("%d",&opcion);
                switch (opcion)
                {
                case 1:
                    printf("su saldo es %d: \n", saldo);
                    break;
                case 2:
                    printf("su cbu es %d: \n", cbu);
                    break;
                case 3:
                    printf("Saliendo del programa...");
                    intentos = 4;
                    break;
                default:
                    printf("Opcion invalida , intente otra vez");
                }
            }while (opcion != 3);
        }
    }

    return 0;
}