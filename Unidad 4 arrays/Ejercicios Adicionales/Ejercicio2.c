#include <stdio.h>
#include <string.h>


/*2. Cargar N elementos e imprimir el número que se repite más veces dentro del
arreglo*/

int main(){

    int cantidad;
    int numeros[100];
    int contador = 0;

    printf("Ingrese la cantidad de numeros que va a contener el array(no mas de 100): \n");
    scanf("%d",&cantidad);
        if (cantidad > 100 || cantidad <= 0) {
        printf("Cantidad inválida. Debe ser entre 1 y 100.\n");
        return 1;
    }

    for(int i = 0; i < cantidad ;i++){
        printf("Ingrese el numero %d : \n ",i + 1);
        scanf("%d",&numeros);

    }

     // Contar repeticiones
    int maxRepeticiones = 0;
    int numeroMasRepetido = numeros[0];

    for (int i = 0; i < cantidad; i++) {
        int contador = 1;

        for (int j = i + 1; j < cantidad; j++) {
            if (numeros[i] == numeros[j]) {
                contador++;
            }
        }

        if (contador > maxRepeticiones) {
            maxRepeticiones = contador;
            numeroMasRepetido = numeros[i];
        }
    }

    printf("\nEl número que más se repite es: %d (se repite %d veces)\n", numeroMasRepetido, maxRepeticiones);


    return 0;
}

