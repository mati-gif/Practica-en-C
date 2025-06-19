#include <stdio.h>
#include <string.h>

/*14.Realizar un programa que le pida al usuario que ingrese una lista de 10 alumnos
y los resultados del examen final. Luego el programa llamará a:
 una función que calcule el promedio de notas,
 otra función que calcule la mayor nota,
 y otra que calcule la menor nota.
Luego el sistema informará estos tres valores al usuario.*/

int promedio(int notas[],int cantidad);
int notaMayor(int array[],int cantidad);
int notaMenor(int array[],int cantidad);
int main(){

    char nombres[10][100];
    int resultado[10];
    

    for(int i = 0; i < 10 ; i++){

        printf("Ingrese el nombre %d : \n",i + 1);
        fgets(nombres[i],100,stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';  // eliminar salto de línea

        printf("ingrese la nota %d para el nombre %d: ",i + 1,i + 1);
        scanf("%d",&resultado[i]);

         getchar();  // <- limpiar el búfer
    }

int promedioCurso = promedio(resultado,10);
int resultadoMayor = notaMayor(resultado,10);
int resultadoMenor = notaMenor(resultado,10);

printf("El promedio del curso es %d: \n",promedioCurso);
printf("La nota mayor del curso es: %d: \n",resultadoMayor);
printf("La nota menor del curso es: %d: \n",resultadoMenor);


    return 0;
}
int promedio(int notas[],int cantidad){

    int suma = 0;
    for(int i = 0; i < cantidad ;i++){

        suma += notas[i];
    }

    return suma / cantidad;
}

int notaMayor(int array[],int cantidad){
    int mayor = array[0];
    for(int i = 0; i < cantidad; i++ ){

        if(array[i] > mayor){
            mayor = array[i];
        }
    }

    return mayor;

}

int notaMenor(int array[],int cantidad){

    int menor = array[0];
    for(int i = 0; i < cantidad ; i++){
        if(array[i] < menor){
            menor = array[i];
        }
    }

    return menor;
}