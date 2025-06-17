#include <stdio.h>

/*3. Pedir al usuario que ingrese 10 números reales, validar que los mismos sean
valores positivos, si el usuario ingresa un número negativo o nulo, pedir
reingresar el número (repetir el ingreso de dicho número mientras el número
no sea correcto). Informar al usuario la suma de los 10 números ingresados.*/

int main(){

    int numero = 0;
    int contador = 0;
    int suma = 0;
    
    while(contador < 10){
        printf("Ingrese un numero positivo: ");
        scanf("%d",&numero);
        if(numero <= 0){
            printf("El numero ingresado no es positivo, por favor reingrese el numero.\n");
        } else {
            printf("El numero ingresado es: %d\n", numero);
            suma += numero;
            printf("la suma de todos los 10 numeros son : %d\n", suma);
            contador++;
        }
    }
    return 0 ;
}