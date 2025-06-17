#include <stdio.h>

/*10- Pedir al usuario que ingrese un número del 1 al 12 e indicar a qué mes
corresponde dicho número (por ejemplo: si ingresa el número 2 se deberá
mostrar febrero en la consola, si ingresa el 8, agosto, etc.) (realizar el ejercicio
primero utilizando estructura if y luego estructura switch).
*/
int main()
{

    int mes;
    printf("Ingrese un numero del 1 al 12 : ");
    scanf("%d", &mes);
    /* if(mes < 1 || mes > 12){
        printf("Numero invalido. Debe ser un numero del 1 al 12.\n");
    }else{
        printf("El mes correspondiente es: ");
        if(mes == 1){
            printf("Enero\n");
        }else if(mes == 2){
            printf("Febrero\n");
        }else if(mes == 3){
            printf("Marzo\n");
        }else if(mes == 4){
            printf("Abril\n");
        }else if(mes == 5){
            printf("Mayo\n");
        }else if(mes == 6){
            printf("Junio\n");
        }else if(mes == 7){
            printf("Julio\n");
        }else if(mes == 8){
            printf("Agosto\n");
        }else if(mes == 9){
            printf("Septiembre\n");
        }else if(mes == 10){
            printf("Octubre\n");
        }else if(mes == 11){
            printf("Noviembre\n");
        }else{
            printf("Diciembre\n");
        }
    } */
    switch (mes)
    {
        case 1: printf("Enero\n"); 
        break;
        case 2: printf("Febrero\n");
        break;
        case 3: printf("Marzo\n");
        break;
        case 4: printf("Abril\n");
        break;
        case 5: printf("Mayo\n");
        break;
        case 6: printf("Junio\n");
        break;
        case 7: printf("Julio\n");
        break;
        case 8: printf("Agosto\n");
        break;
        case 9: printf("Septiembre\n");
        break;
        case 10: printf("Octubre\n");
        break;
        case 11: printf("Noviembre\n");
        break;
        case 12: printf("Diciembre\n");
        break;
        default: printf("Numero invalido. Debe ser un numero del 1 al 12.\n");
    }
    return 0;
}