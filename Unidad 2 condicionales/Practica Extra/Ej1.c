#include <stdio.h>
#include <math.h>

/*oblemas Secuenciales
1. Suponga que un individuo desea invertir su capital en un banco y desea
saber cuánto dinero ganará después de un mes si el banco paga a razón de
2% mensual.
*/

int main(){

    int capital;
    int resultado;
    printf("Ingrese su capital : ");
    scanf("%d", &capital);
    if (capital < 0) {
        printf("El capital no puede ser negativo.\n");
    }else{
        resultado = ( capital * 0.02 ) + capital;
        printf("El capital despues de un mes es: %d\n", resultado); 
    }

    return 0 ;
}