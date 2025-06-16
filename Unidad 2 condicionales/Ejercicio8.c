#include <stdio.h>
#include <math.h>

/*8- Actualizar el saldo de una cuenta bancaria, a partir de un retiro. Verificar que el
saldo sea mayor o igual que el importe a retirar.*/

int main()
{

    float saldoCuenta = 150000; // Saldo inicial de la cuenta
    float importeRetiro;
    int resultado;
    while (saldoCuenta > 0 && resultado != 0)
    {
        printf("Ingrese el importe a retirar : ");
        scanf("%f", &importeRetiro);

        if (importeRetiro > saldoCuenta)
        {
            printf("Saldo insuficiente para realizar el retiro.\n");
        }
        else
        {

            saldoCuenta = saldoCuenta - importeRetiro;
            printf("Retiro realizado con exito.\n");
            printf("El importe retirado es : %f\n", importeRetiro);
            printf("El saldo de la cuenta ahora es : %f\n", saldoCuenta);
        }
        printf("Desea continuar retirando? (1: Si, 0: No): ");
        scanf("%d", &resultado);
        if(saldoCuenta <= 0){
            printf("Saldo insuficiente para continuar con los retiros.\n");
            break;
        }
    }


    return 0;
}