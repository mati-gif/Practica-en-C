#include <stdio.h>

/*8. Escriba un programa que lea un número n1, y escriba la tabla de multiplicar
del número.*/

int main(){

    int number;
    printf("Ingrese un numero entero: \n");
    scanf("%d",&number);
    for(int i = 1; i <= 10;i++){
        int multiplicacion = number * i;
        printf("%d x %d = %d  \n" ,number,i,multiplicacion);
    }
    return 0;
}