#include <stdio.h>


/*Ejercicio 6: Número mayor
Descripción: Escribe un programa en C que lea tres 
números del usuario y determine cuál es el mayor.*/

int main(){

    int num1;
    int num2;
    int num3;
    printf("Ingrese el 1er numero: ");
    scanf("%d",&num1);
    printf("Ingrese el 2do numero: ");
    scanf("%d",&num2);
    printf("Ingrese el 3er numero: ");
    scanf("%d",&num3);
    if(num1 >= num2 && num1 >= num3){
        printf("El numero %d es el mayor \n", num1);
    }else if(num2 >= num1 && num2 >= num3){

        printf("El numero %d es el mayor",num2);

    }else if(num3 >= num1 && num3 >= num2){
        printf("El numero %d es el mayor \n", num3);
    }else{
        printf("Los numeros ingresados son iguales \n");
    }

    return 0;
}