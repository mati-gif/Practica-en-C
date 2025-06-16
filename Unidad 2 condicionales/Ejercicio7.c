#include <stdio.h>
#include <math.h>

/*7- Ingresar el valor de una venta y aplicar el 15% de descuento si el valor es >=
100000 y un 10% si es menor. Validar que la venta sea mayor que 0, caso
contrario informar dicha situación.*/

int main()
{

    float valorVenta;
    float descuento;
    float resultado;
    printf("Ingrese el valor de la venta: ");
    scanf("%f", &valorVenta);
    if (valorVenta <= 0)
    {
        printf("Valor de venta invalido\n");
    }
    else if (valorVenta >= 100000)
    {
        descuento = valorVenta * 0.15;
        resultado = valorVenta - descuento;
    }
    else
    {
        descuento = valorVenta * 0.10;
        resultado = valorVenta - descuento;
    }
    printf("El valor de la venta con el descuento es : %f", resultado);
    return 0;
}