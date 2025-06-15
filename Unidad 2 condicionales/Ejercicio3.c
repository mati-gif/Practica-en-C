#include <stdio.h>

/*3- Dado un número introducido por el usuario, indicar si este es positivo, negativo
o nulo.*/

int main(){

    int numero;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    if(numero > 0){
        printf("El numero %d es positivo",numero);
    }else if(numero == 0){
        printf("El numero %d es nulo",numero);
    }else{
        printf("El numero %d es negativo",numero);
    }
    return 0;
}