#include <stdio.h>

/*4. Imprimir la suma de los números impares que se encuentran entre los
números 1 y 10.*/
int main(){
    int suma = 0;
    for(int i = 1; i <= 10;i++){

        if(i % 2 != 0){
            suma += i;
        }
    }
    printf("%d \n",suma);
    return 0;
}