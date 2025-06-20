#include <stdio.h>
#include <string.h>

/*12.Ingresar 2 nombres e indicar cuál de los dos precede alfabéticamente al otro o si
son iguales.*/

int main(){

    char nombre1[100];
    char nombre2[100];

    printf("Ingrese el 1er nombre: \n");
    fgets(nombre1,100,stdin);
    
    printf("Ingrese el 2do nombre: \n");
    fgets(nombre2,100,stdin);

 // Comparar alfabéticamente
    if (strcmp(nombre1, nombre2) == 0) {
        printf("Los nombres son iguales.\n");
    } else if (strcmp(nombre1, nombre2) < 0) {
        printf("%s precede alfabéticamente a %s.\n", nombre1, nombre2);
    } else {
        printf("%s precede alfabéticamente a %s.\n", nombre2, nombre1);
    }
    return 0;
}