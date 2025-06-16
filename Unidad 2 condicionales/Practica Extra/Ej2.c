#include <stdio.h>

/*2. Una tienda ofrece un descuento del 15% sobre el total de la compra y un
cliente desea saber cuánto deberá pagar finalmente por su compra.*/

int main()
{

    int totalCompra;
    int resultadoFinal;
    printf("Ingrese el total de la compra ");
    scanf("%d", &totalCompra);
    resultadoFinal = totalCompra - (totalCompra * 0.15);
    printf("El total a pagar es : %d\n", resultadoFinal);

    return 0;
}
