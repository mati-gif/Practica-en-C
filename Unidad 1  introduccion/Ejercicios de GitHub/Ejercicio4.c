#include <stdio.h>

#include <ctype.h>

/*Ejercicio 4: Factorial de un número
Descripción: Escribe un programa en C que calcule el factorial 
de un número ingresado por el usuario.*/

int main(){

    int number;
    long factorial = 1;
    printf("Ingrese un numero: ");
    scanf("%d",&number);

    if(number < 0 ){
        printf("No se puede hacer un factorial de numeros negativos \n");

    }else{
        for(int i = number; i > 0; i--){
            factorial *= i;
        }

        printf("El factorial de %d es %ld \n", number, factorial);
        
    }
    return 0;

}