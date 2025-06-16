#include <stdio.h>

/*2. En un almacén se hace un 20% de descuento a los clientes cuya compra
supere los $5000 ¿Cuál será la cantidad que pagara una persona por su
compra?
*/

int main(){

    float descuento = 0.20;
    float importeCompra;

    printf("Ingrese el importe de la compra: ");
    scanf("%f",&importeCompra);
    if(importeCompra > 5000){
        float total = importeCompra -  (importeCompra * descuento);
        printf("El total a pagar es : %f\n", total);
    }else {

        printf("No se aplica descuento, el total a pagar es : %f\n", importeCompra);
    }
    return 0;
}