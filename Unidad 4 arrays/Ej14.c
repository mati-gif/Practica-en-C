#include <stdio.h>
#include <string.h>

/*14.Escribe un programa que solicite al usuario una cadena de caracteres y luego
cuente el número de vocales que contiene.*/
int main(){

    char nombre[100];
    int contador = 0;
    
    printf("Ingrese un nombre: \n");
    fgets(nombre,100,stdin);

    for(int i = 0; nombre[i] != '\0';i++){

        char c = tolower(nombre[i]);  // pasar a minúscula
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
 printf("La cantidad de vocales es: %d\n", contador);

    return 0;
}