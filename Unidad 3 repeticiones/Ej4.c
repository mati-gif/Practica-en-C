#include <stdio.h>

/*4. Realizar un programa que calcule el promedio de las notas de los parciales
de un curso. Comenzar pidiendo al usuario la cantidad de alumnos del curso
y la cantidad de parciales que se tomaron durante el cuatrimestre. Calcular el
promedio de notas de los alumnos del curso. A medida que se ingresan las
notas, validar que las mismas sean mayores que 0 (cero) y menores que 10,
en caso contrario requerir el ingreso de dicha nota hasta que sea correcta.
Mostrar el promedio de cada alumno a medida que se va calculando y por
último, el promedio general del curso*/

int main(){

    int cantidadAlumnos;
    int cantidadParciales;
    int contador = 1;
    int contadorNota = 1;
    int nota;
    int sumaNotas = 0;
    int promedio;
    int promedioCurso = 0;
    printf("Ingrese la cantidad de alumnos del curso: ");
    scanf("%d", &cantidadAlumnos);
    printf("Ingrese la cantidad de parciales: ");
    scanf("%d", &cantidadParciales);

    while(contador <= cantidadAlumnos){
    printf("Ingrese las notas del alumno : %d\n", contador);
    while(contadorNota <= cantidadParciales){
        printf("Ingrese la nota %d : ", contadorNota);
        scanf("%d",&nota);
        if(nota <= 0 || nota > 10){
            printf("La nota debe ser positivo ingrese nuevamente la nota\n");
        }else{
        sumaNotas += nota;
        contadorNota++;
        }

    }
    promedio = sumaNotas / cantidadParciales;
    printf("El promedio de notas del alumno %d es:  %d\n", contador, promedio);
    contador++;
    promedioCurso += promedio;
    contadorNota = 1;
    sumaNotas = 0;

    }
    int promedioTotal = promedioCurso / cantidadAlumnos;
    printf("El promedio total de todo el curso es : %d\n",promedioTotal);

}