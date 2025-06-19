#include <stdio.h>
#include <string.h>

/*8. Leer 10 números por teclado: 5 para un array y 5 para otro array distinto.
Mostrar los 10 números juntos en pantalla utilizando un solo array.*/

int main(){

    int array1[5] = {};
    int array2[5] = {};
    int arrayTotal[10] = {};


    // Leer los primeros 5 números
    printf("Ingrese 5 números para el primer array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    // Leer los segundos 5 números
    printf("\nIngrese 5 números para el segundo array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array2[i]);
    }


        for(int i = 0; i < 5;i++){

        arrayTotal[i] = array1[i];
        arrayTotal[i + 5] = array2[i];
    }
    printf("Los numeros ingresados son: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arrayTotal[i]);
    }
    return 0;
}