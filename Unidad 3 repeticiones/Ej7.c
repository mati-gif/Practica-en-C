#include <stdio.h>
#include <stdlib.h>

/*7. Ingresar un conjunto de números reales distintos de cero. Para finalizar la
entrada de datos, ingresar un cero. Determinar e informar la cantidad de
números que lo forman.
*/
int main(){
    int number;
    int contador = 1;
    int acumulador = 0;

    while(contador != 0){
    printf("Ingrese numeros reales distintos de cero (0 para finalizar):\n");
    scanf("%d",&number);
    if(number != 0 ){
        acumulador++;
        printf("Desea continuar? (1 para continuar, 0 para salir): ");
        scanf("%d",&contador);
    }else{
        printf("Numero invalido ,volve a ingresar un numero distinto de cero\n");
    }

    }
    printf("La cantidad de numeros ingresados es: %d\n", acumulador);
    printf("Gracias por participar\n");


    return 0;
}