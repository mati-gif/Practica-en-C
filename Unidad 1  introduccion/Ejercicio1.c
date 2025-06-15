#include <stdio.h>

/*DATOS Y OPERADORES*/

int main(){

    int num1;
    int num2;
    int resultado;

    printf("Introduce el primer numero: ");
    scanf("%d",&num1);
    printf("Introduce el segundo numero: ");
    scanf("%d",&num2);

    resultado = num1 + num2;
    printf("El resultado de la suma es: %i\n", resultado);
    return 0;
}