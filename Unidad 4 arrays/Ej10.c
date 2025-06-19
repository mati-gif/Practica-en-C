#include <stdio.h>


/*10.Escriba un programa que lea una matriz cuadrada, la muestre en pantalla y
calcule la suma de todos los números que no están en la diagonal principal.*/

int main(){

    int matriz[3][3];
    int suma = 0;
    printf("Ingrese numeros para completar la matriz \n");

    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Ingrese el numero para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

        for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j){
                suma += matriz[i][j]; // Sumar los elementos que no están en la diagonal principal
            }
        }
    }

    // Mostrar el resultado
    printf("\nLa suma de los elementos que NO están en la diagonal principal es: %d\n", suma);


    for (int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            printf("%d ", matriz[i][j]);
        }
          printf("\n"); // Salto de línea al final de cada fila
    }

    
return 0;
}