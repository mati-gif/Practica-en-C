#include <stdio.h>

/*7. Diseñe un algoritmo que sume los 20 primeros números impares.*/

int main(){

    int suma = 0;
    for(int i = 1; i <= 20;i++){

        if(i % 2 != 0){
            suma += i;
        }
    }
    printf("%d \n",suma);
    return 0;
}