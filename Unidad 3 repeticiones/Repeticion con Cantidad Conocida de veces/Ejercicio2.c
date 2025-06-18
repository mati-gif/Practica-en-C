#include <stdio.h>
#include <string.h>

/*2. Imprimir los números del 1 al 10 uno abajo del otro saltando de a dos.*/

int main(){

    for(int i = 1; i <= 10; i += 2){
        printf("%d \n",i);
    }
    return 0;
}