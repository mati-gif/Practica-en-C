#include <stdio.h>

/*6. Suma de los 10 primeros números múltiplos de tres*/

int main(){

    int suma = 0;
    for(int i = 1; i <= 10;i++){
        if(i % 3 == 0){
            suma += i;

        }
    }
    printf("%d \n",suma);
    return 0;
}