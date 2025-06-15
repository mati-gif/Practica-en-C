#include <stdio.h>

/*2. Ingresar tres valores, sumarlos e imprimir esa suma.*/
int main(){

    int num1, num2, num3, suma;

    printf("Introduce el primer numero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero: ");
    scanf("%d", &num2);
    printf("Introduce el tercer numero: ");
    scanf("%d", &num3);

    suma = num1 + num2 + num3;
    printf("La suma de los tres numeros es: %d\n", suma);

    return 0;
}