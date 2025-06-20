#include <stdio.h>

/*9. Escriba un programa que escriba la tabla de multiplicar del 1, 2,....,9.*/

int main(){

    for(int i = 1; i <= 9;i++){

        int resultado = i * i;
        printf("%d * %d = %d \n",i,i,resultado);
    }
    return 0;
}