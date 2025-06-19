#include <stdio.h>
#include <string.h>


/*15.Dada la siguiente lista de corredores de karting y el resultado de cada uno:
Corredor Posición final
Pedro Gomez 7
Martín Ceres 6
Ernestina Diaz 1
Gastón Bautista 2
Dalma Alvarez 8
Patricio Fernandez 3
Faustina Martinez 10
Andrea Perez 9
Hilda Lopez 4
León García 5
Realizar un programa que muestre la siguiente opción de menú al usuario:
1 - Mostrar lista de corredores
2 - Mostrar los tres mejores
3 - Mostrar lista completa de resultados 4 - Salir
La opción 1 se llevará a cabo mediante una función llamada ListaCorredores
que mostrará al usuario los nombres y apellidos de los corredores.
La opción 2 llama a otra función llamada ListaMejores que mostrará a los
corredores que salieron en las primeras 3 posiciones.
La opción 3 llamará a una función llamada ListaPosiciones que mostrará la lista
de corredores con sus posiciones.
La opción 4 es la salida del sistema.
Nota: La lista de corredores y los resultados de la carrera se guardarán en un
arreglo.
El sistema debe volver a mostrar el menú de opciones una vez que se complete
cada solicitud del usuario, y hasta tanto el usuario ingrese la opción de salida.*/


int main(){

    int bandera = 1;
    int opcion;
        int cantidad;
    char nombreCorredores[100][100];
    char apellidoCorredores[100][100];
    int posicion[100];
    char nombreApellido[100][100];
    


void listaCorredores(char array[][100], int cantidad);

    while (cantidad > 100 || cantidad <= 0)
    {
            printf("Ingrese la cantidad de corredores (no mas de 100) \n");
            scanf("%d",&cantidad);
            getchar();  // Limpia el '\n' después del scanf
            if(cantidad > 100 || cantidad <= 0){

            printf("La cantidad no puede ser menor a 0 ni mayora 100  \n");
            }
    }
    
    for(int i = 0; i < cantidad; i++){

        printf("Ingrese el nombre del corredor %d : \n",i + 1);
        fgets(nombreCorredores[i],100,stdin);
        nombreCorredores[i][strcspn(nombreCorredores[i], "\n")] = '\0'; // Limpia el salto 
        // getchar();  // <- limpiar el búfer

        printf("Ingrese el apellido del corredor %d : \n",i + 1);
        fgets(apellidoCorredores[i],100,stdin);
        apellidoCorredores[i][strcspn(apellidoCorredores[i], "\n")] = '\0';

    }

        for(int i = 0; i < cantidad; i++){

        printf("Ingrese la posicion del corredor %d : \n",i + 1);
        scanf("%d",&posicion[i]);
        getchar();  // <- limpiar el búfer
        //   while (getchar() != '\n'); // Limpiamos el búfer después del scanf
    }

    for(int i = 0; i < cantidad ; i++){

        strcpy(nombreApellido[i],nombreCorredores[i]);
        strcat(nombreApellido[i]," ");
        strcat(nombreApellido[i],apellidoCorredores[i]);
        printf("\n");

        printf("Nombre completo %d: %s\n", i + 1, nombreApellido[i]);
    }

    

    while(bandera != 0){

        printf("----MENU ELIJA UNA OPCION---- \n");
        printf("1 - Mostrar lista de corredores \n");
        printf("2 - Mostrar los tres mejores \n");
        printf("3 - Mostrar lista completa de resultados \n");
        printf("4 - Salir \n");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            // char listaCorredores[10][100];
            printf("Lista corredores");
            listaCorredores(nombreApellido,cantidad);

            bandera = 1;
            break;
            case 4:
            printf("Saliendo del programa...");
            bandera = 0;
            break;
        default:
            break;
        }
    };
    return 0;
}

void listaCorredores(char array[][100], int cantidad) {
    printf("\n--- Lista de Corredores ---\n");
    for(int i = 0; i < cantidad; i++) {
        printf("%d. %s\n", i + 1, array[i]);
    }
}
