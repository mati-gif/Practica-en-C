#include <stdio.h>



/*6. Ingresar dos valores, calcular su suma, su producto y la resta del 1ro menos
el 2do valor ingresado, imprimir los resultados.*/

int main(){

    int a;
    int b;
    int suma;
    int multiplicacion;
    int resta;

    printf("Ingrese la suma del 1er valor: ");
    scanf("%d",&a);
    printf("Ingrese la suma del 2do valor: ");
    scanf("%d",&b);
    suma = a + b;
    multiplicacion = a * b;
    resta = a - b;
    printf("La suma de los valores es : %d\n", suma);
    printf("El producto de los valores es : %d\n", multiplicacion);
    printf("La resta de los valores es : %d\n", resta);
    

    return 0;
}