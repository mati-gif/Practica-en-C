#include <stdio.h>
#include <string.h>

/*3. Crea una función llamada esPar que reciba un número entero como parámetro y
devuelva 1 si el número es par, o 0 si es impar. Después, crea un programa que
utilice esta función y muestre los mensajes en consola “El número ingresado es
par” o “El número ingresado es impar”, según el valor retornado. */

int esPar(int number);
int main(){

    int numero;
    printf("Ingrese un numero para saber si es par o no \n");
    scanf("%d",&numero);

    int resultado = esPar(numero);
    if(resultado == 1){
        printf("El numero es par \n");
    }else{
        printf("El numero es impar \n");
    }
    return 0;
}

int esPar(int number){

    if(number % 2 == 0){

        return  1;
    }

    return 0;

}