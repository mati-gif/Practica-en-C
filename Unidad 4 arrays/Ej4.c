#include <stdio.h>
#include <string.h>


/*4. Dado el vector {10, 20, 5, 15, 30, 20}, realizar lo siguiente:
a. Informar el vector de la forma: "Índice: X, Valor: Y".
b. Calcular e informar el total del vector.
c. Mostrar los valores que se encuentran en posiciones impares.
d. Mostrar las posiciones (índices) que contienen números impares.
e. Informar el mayor número del vector.
f. Informar cuántas veces aparece el número 20*/

int main(){

    int array[6] = {10,20,5,15,30,20};
    int suma = 0;
    int contador = 0;
    int acumulador = 0;

    for(int i = 0; i < 6;i++){
        printf("Indice : %d , Valor : %d \n ",i,array[i]);
        suma += array[i];
    }
    printf("El total del vector es : %d \n",suma);
    for(int i = 0; i < 6;i++){
        if(i % 2 != 0){
            printf("los valores que se encuentran en posiciones impares son : %d \n",array[i]);
        }
    }
    for(int i = 0; i < 6;i++){
        if(i % 2 != 0){
            printf("Índice %d (valor: %d)\n", i, array[i]);
        }
    }

        for(int i = 0; i < 6; i++){
            if(array[i] > contador){
                contador = array[i];
            }
    }
    printf("El valor mayor es : %d \n",contador);

            for(int i = 0; i < 6; i++){
            if(array[i] == 20){
                acumulador++;
            }
    }
    printf("dentro del array el 20 se repite : %d  veces \n",acumulador);
    
    return 0;
}