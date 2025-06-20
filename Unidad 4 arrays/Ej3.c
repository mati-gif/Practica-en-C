#include <stdio.h>
#include <string.h>

/*3. Declarar un array de tipo entero de 5 componentes, ingresar los valores por
consola y mostrar cuántas veces se repite el número 5.*/

int main(){

    int array[5] = {};
    int contador = 0;
    for(int i = 0; i < 5; i++){

        printf("Vuelta %d , ingrese un numero: \n",i);
        scanf("%d",&array[i]);
        if(array[i] == 5){
            contador++;
        }
    }
    printf("El numero 5 se repite : %d veces \n",contador);
    // Mostrar el contenido del array correctamente
    printf("El array está compuesto por los siguientes elementos: ");
    
    for(int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    printf("\n"); // Nueva línea para mejorar la presentación


    return 0;
}