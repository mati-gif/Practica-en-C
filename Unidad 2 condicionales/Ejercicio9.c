#include <stdio.h>

/*9- Se desea escribir un algoritmo que pida la altura de una persona, si la altura es
menor o igual a 150 cm envíe el mensaje: “Persona de altura por debajo de la
media”; si la altura está entre 151 y 170 escriba el mensaje: “Persona de altura
media” y si la altura es mayor al 171 escriba el mensaje: “Persona de altura por
arriba de la media”*/

int main(){

    int altura;

    printf("Ingrese su altura: ");
    scanf("%d",&altura);
    if(altura <= 150){
        printf("Persona de altura por debajo de la media");
    }else if(altura > 150 && altura <= 170)
    {
        printf("Persona de altura media");

    }else{
        printf("Persona de altura por arriba de la media");
    }
    return 0;
}