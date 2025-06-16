#include <stdio.h>
#include <stdlib.h>

/*3. Un maestro desea saber qué porcentaje de hombres y que porcentaje de
mujeres hay en un grupo de estudiantes*/

int main(){

    int hombres;
    int mujeres;
    float totalPorcentajeH;
    float totalPorcentajeM;
    float total;

    printf("Ingrese la cantidad de hombres: ");
    scanf("%d",&hombres);
    printf("Ingrese la cantidad de mujeres: ");
    scanf("%d",&mujeres);

    total = hombres + mujeres;

    if(hombres < 0  || mujeres < 0){
        printf("el numero de hombres y mujeres no puede ser negativo.\n");
    }else{
        totalPorcentajeH = hombres * 100 / total;
        totalPorcentajeM = mujeres * 100 / total;
        printf("El porcentaje de hombres es: %f\n", totalPorcentajeH);
        printf("El porcentaje de mujeres es: %f\n", totalPorcentajeM);
    }

    return 0;
}