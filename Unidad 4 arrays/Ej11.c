#include <stdio.h>
#include <string.h>

/*11.Escribe un programa que pida tres cadenas al usuario y muestre sus longitudes
(cantidad de caracteres).*/

int main(){

    char cad1[50];
    char cad2[50];
    char cad3[50];

    printf("Ingrese la primera cadena: \n");
    fgets(cad1,50,stdin);
    printf("%lu \n",strlen(cad1));

    printf("Ingrese la segunda cadena: \n");
    fgets(cad2,50,stdin);
    printf("%lu \n",strlen(cad2));


    printf("Ingrese la tercer cadena: \n");
    fgets(cad3,50,stdin);
    printf("%lu \n",strlen(cad3));


    char cadena[3][50];

    for(int i = 0; i < 3;i++){

        printf("Ingrese el string %d \n",i + 1);
        fgets(cadena[i],50,stdin);
        printf("%lu \n",strlen(cadena[i]));
    }

    /* for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3;j++){
            
            for(int k = 0 ; k > 3; k++){
                    printf("Ingrese la primera cadena: \n");
    fgets(50,cad1,stdin);

    printf("Ingrese la segunda cadena: \n");
    printf(50,cad2,stdin);

    printf("Ingrese la tercer cadena: \n");
    fgets(50,cad3,stdin);
            }
        }
    } */
    
    char palabra[] = "hola";//Esto es un string en C .
    printf("%s \n",palabra);
    char saludo[50];
    scanf("%s",saludo);
    printf("%s",saludo);
    char saludo2[] = "Bienvenido a la argentina";
    printf("%s",saludo2);
    char nombres[3][10] = {"mati","juan","pepe"};// esto es un arregolo de string
    for(int i = 0; i < 3; i++){
        printf("%s \n",nombres[i]);
    }



    return 0;
}