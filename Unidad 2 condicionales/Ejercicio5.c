#include <stdio.h>


/*Ejercicio 5: Número par o impar
Descripción: Escribe un programa en C que determine si un número ingresado por el usuario 
es par o impar.*/

int main(){

    int number;
    printf("Ingrese un numero:");
    scanf("%d",&number);
    if(number % 2 == 0){
        printf("El numero ingresado: %d es par \n",number);
    }else{
        printf("El numero ingresado %d es impar \n", number);
    }
    

    return 0;
}