#include <stdio.h>
#include <string.h>


/*1. Declarar un array de tipo entero de 5 elementos, asignarles un valor y mostrar la
información de la siguiente forma: “Índice: X, Valor: Y”*/

int main(){
    int array[5] = {1,2,3,4,5};
    
    for(int i = 0; i < 5;i++){
        printf("Indice: %d , Valor: %d \n",i,array[i]);
    }
    return 0;
}