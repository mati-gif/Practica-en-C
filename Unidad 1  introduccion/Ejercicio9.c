#include <stdio.h>
#include <ctype.h>

/*3. Pedir al usuario que ingrese un carácter en mayúscula y luego imprimir su
equivalente en minúscula. */

int main(){

    char letra;
    printf("Ingrese una letra en mayuscula: ");
    scanf("%c", &letra);
    printf("La letra en minuscula es: %c\n", tolower(letra));
    return 0;
}