#include <stdio.h>
#include <string.h>

/*5. Dado el vector inflación = {0.8, 0.1, 0.3, 0.4, 0.3, 0.6, 0.5, 0.3, 0.7, 0.3, 0.2, 0.9}
Cada valor representa la inflación de un mes (enero a diciembre). Se pide:
a. Calcular e informar la inflación anual
b. Determinar e informar la inflación más baja y el número de mes
correspondiente. Ejemplo: Mes 2 = 0.1
c. Determinar e informar la inflación más alta y el número de mes
correspondiente. Ejemplo: Mes 12 = 0.9
*/

int main(){

    float inflacion[] = {0.8, 0.1, 0.3, 0.4, 0.3, 0.6, 0.5, 0.1, 0.7, 0.3, 0.2, 0.9};
    float suma = 0;
    float acumulador = 0;
    int mes ;
    float inflacionMenor = inflacion[0];
    for(int i = 0; i < 12; i++){
        suma += inflacion[i];
    }
    printf("La inflacion anual es : %f \n",suma);

    for(int i = 0 ; i <12; i++){
        if(inflacion[i] > acumulador){
            acumulador = inflacion[i];
            mes = i + 1 ; // se pone asi porque el indice empieza con 0.
        }
    }
    printf("mes: %d = %f \n",mes,acumulador);

        for(int i = 0 ; i < 12; i++){
        if(inflacion[i] < inflacionMenor){
            inflacionMenor = inflacion[i];
            mes = i + 1 ; // se pone asi porque el indice empieza con 0.
        }
    }
    printf("mes con la inflacion menor : %d = %f \n",mes,inflacionMenor);
    return 0;
}