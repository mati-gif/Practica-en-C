#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*4. Solicitar ingresar dos lados de un triángulo rectángulo y calcular, la
hipotenusa, el perímetro, la superficie. Imprima los resultados de las
operaciones solicitadas.*/

int main(){

int lado1;
int lado2;

int perimetro;
float superficie;
float hipotenusa;

printf("Ingrese el primer lado del triángulo rectángulo: ");
scanf("%d", &lado1);

printf("Ingrese el segundo lado del triángulo rectángulo: ");
scanf("%d", &lado2);

hipotenusa = sqrt(pow(lado1, 2) + pow(lado2, 2));
perimetro = lado1 + lado2 + hipotenusa;
superficie = (lado1 * lado2) / 2.0;

printf("La hipotenusa del triángulo rectángulo es: %.2f\n", hipotenusa);
printf("El perímetro del triángulo rectángulo es: %d\n", perimetro);
printf("La superficie del triángulo rectángulo es: %.2f\n", superficie);

    return 0;
}