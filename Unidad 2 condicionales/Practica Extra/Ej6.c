#include <stdio.h>

/*3. Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig.
manera: Si trabaja 40 horas o menos se le paga $300 por hora Si trabaja más
de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400
por cada hora extra.*/
int main(){

    int horasTrabajadas;
    int salario;


    printf("Ingrese las horas trabajadas : ");
    scanf("%d",&horasTrabajadas);
    if( horasTrabajadas <= 40){

        salario = horasTrabajadas * 300;
        printf("El salario total por %d horas trabajadas es : %d",horasTrabajadas,salario);
        
    }else{
        salario = 40 * 300;
        int resultado = ( horasTrabajadas - 40) * 400;
        int resultadoTotal = salario + resultado;
        printf("El salario por las horas trabajadas es : %d\n",resultadoTotal);
    }


    return 0;
}