#include <stdio.h>
#include <string.h>

/*13.Ingresar por consola 10 nombres de alumnos en un array y sus apellidos en
otro, concatenarlos de la forma "nombre apellido" para cada uno y mostrarlos
por consola.
*/

int main(){

    char nombres[5][100];
    char apellidos[5][100];
    char nombreCompleto[5][100];
    for(int i = 0; i < 5; i++){

        printf("Nombre %d : ", i + 1);
        fgets(nombres[i],100,stdin);
         nombres[i][strcspn(nombres[i], "\n")] = '\0'; // 

        printf("Apellido %d : ",i + 1);
        fgets(apellidos[i],100,stdin);
        apellidos[i][strcspn(apellidos[i], "\n")] = '\0'; // Eliminar \n
    }

    for(int i = 0; i < 5; i++){

        strcpy(nombreCompleto[i], nombres[i]);     // Copiar nombre
        strcat(nombreCompleto[i], " ");            // Agregar espacio
        strcat(nombreCompleto[i], apellidos[i]);   // Agregar apellido

        printf("Nombre completo %d: %s\n", i + 1, nombreCompleto[i]);
    }
    return 0;
}