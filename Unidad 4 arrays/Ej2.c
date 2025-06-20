#include <stdio.h>
#include <string.h>

/*2. Declarar un array de tipo entero de 5 componentes, asignarles un valor, calcular
y mostrar la suma de sus componentes y el promedio.*/

int main(){

    int array[5] = {1,2,3,4,5};
    int suma = 0;
    for(int i = 0; i <= 5; i++){
        suma += i;
    }
    int promedio = suma / 5;
    printf(" La suma es: %d \n",suma);
    printf("El promedio es: %d" ,promedio);
    return 0;
}