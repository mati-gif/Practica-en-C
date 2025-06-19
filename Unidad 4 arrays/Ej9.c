#include <stdio.h>

/*9. Escriba un programa que lea 5 números por teclado, los copie a otro array
multiplicados por 2 y muestre el segundo array.*/

int main(){
int array[5] = {};
int nuevoArray[5] = {};
printf("Ingrese 5 numeros \n");
for(int i = 0; i < 5;i++){

    printf("Numero %d : ",i + 1);
    scanf("%d",&array[i]);

    nuevoArray[i] = array[i] * 2;

}
for(int i = 0; i<5;i++){

    printf("-%d",nuevoArray[i]);
}

    return 0;
}