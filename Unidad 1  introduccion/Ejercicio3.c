#include <stdio.h>

/*3. Ingresar los lados de un triángulo calcular su perímetro e imprimirlo.*/
int main(){

    int lado1;
    int lado2;
    int lado3;
    int perimetro;
    printf("ingrese el primer lado del triangulo: ");
    scanf("%d",&lado1);

    printf("Ingrese el segundo lado: ");
    scanf("%d",&lado2);

    printf("Ingrese el 3er lado: ");
    scanf("%d",&lado3);

    perimetro = lado1 + lado2 + lado3;
    printf("El perimetro del triangulo es: %d\n",perimetro);

    return 0;
}