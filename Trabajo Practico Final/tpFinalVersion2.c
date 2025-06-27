#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASAJEROS 240
#define MAX_DESTINOS 4
#define MAX_CADENA 50

// Códigos de destino
char codigos[MAX_DESTINOS][4] = {"BRA", "MDQ", "MZA", "BRC"};
char nombres_destinos[MAX_DESTINOS][20] = {"Brasil", "Mar del Plata", "Mendoza", "Bariloche"};
float importes[MAX_DESTINOS] = {25000.0, 14000.0, 19000.0, 23000.0};

// Datos de los pasajeros
int DNIs[MAX_PASAJEROS];
char apellidos[MAX_PASAJEROS][MAX_CADENA];
char nombres[MAX_PASAJEROS][MAX_CADENA];
int edades[MAX_PASAJEROS];
char destinos[MAX_PASAJEROS][4];
char pagos[MAX_PASAJEROS]; // 'S' si paga con tarjeta, 'N' si no

int totalPasajeros = 0;
int contadorDestinos[MAX_DESTINOS] = {0}; // 

// Función para validar DNI
int validarDNI(int dni) {
    if (dni < 1000000 || dni > 99999999) return 0;
    int inicio;
    if (dni >= 10000000)
        inicio = dni / 1000000;
    else
        inicio = dni / 100000;
    if (inicio == 5 || inicio == 6 || (inicio >= 10 && inicio <= 60)) return 1;
    return 0;
}

// Función para obtener índice de un destino
int indiceDestino(char cod[]) {
    for (int i = 0; i < MAX_DESTINOS; i++) {
        if (strcmp(codigos[i], cod) == 0) {//strcmp() sirve para comparar dos cadenas de caracteres
            return i;
        } //compara el código de destino almacenado en codigos[i] con el código recibido como parámetro cod. Si son iguales (es decir, si strcmp devuelve 0), la función retorna el índice i correspondiente a ese destino. Sirve para encontrar la posición de un destino en el arreglo de códigos.
    }
    return -1;//La función indiceDestino solo retorna -1 si no encuentra el código buscado en el array codigos.
}

// Cargar pasajeros manualmente
void cargarPasajeros() {
    int cantidad;
    printf("Ingrese la cantidad de pasajeros: ");
    scanf("%d", &cantidad);
    getchar(); // limpia '\n'

    for (int i = 0; i < cantidad && totalPasajeros < MAX_PASAJEROS; i++) {
        int dni, edad;
        char apellido[MAX_CADENA], nombre[MAX_CADENA], destino[4], pago;//son array de caracteres pero que se usan como String
        int indice;

        printf("\nPasajero #%d:\n", totalPasajeros + 1);

        // DNI
        do {
            printf("DNI: ");
            scanf("%d", &dni);
            getchar();
            if (!validarDNI(dni)) printf("DNI inválido. Intente nuevamente.\n");
        } while (!validarDNI(dni));

        // Apellido
        printf("Apellido: ");
        fgets(apellido, MAX_CADENA, stdin);
        apellido[strcspn(apellido, "\n")] = '\0';//sirve para eliminar el salto de línea (\n) que agrega la función fgets al final de la cadena leída. Así, si el usuario ingresa "Gomez" y presiona Enter, la cadena queda como "Gomez\n", pero con esa línea se reemplaza el \n por el carácter nulo (\0), dejando la cadena como "Gomez". Esto es útil para evitar problemas al comparar o mostrar cadenas.

        // Nombre
        printf("Nombre: ");
        fgets(nombre, MAX_CADENA, stdin);
        nombre[strcspn(nombre, "\n")] = '\0';

        // Edad
        printf("Edad: ");
        scanf("%d", &edad);
        getchar();

        // Destino
        do {//Comienza el ciclo que se repetirá hasta que se ingrese un código de destino válido y con cupo disponible.
            printf("Código de destino (BRA, MDQ, MZA, BRC): ");
            scanf("%s", destino);
            getchar();
            indice = indiceDestino(destino);//Busca el índice correspondiente al código ingresado usando la función indiceDestino. Si el código no existe, devuelve -1.
            if (indice == -1) {
                printf("Código inválido. Intente nuevamente.\n");
                continue;
            }
            if (contadorDestinos[indice] >= 60) { //Si el código es válido, verifica si ya hay 60 pasajeros para ese destino.
                printf("Este destino ya alcanzó los 60 pasajeros. Elija otro.\n");
                indice = -1;//Marca el índice como inválido para que el ciclo se repita.
            }
        } while (indice == -1); //El ciclo se repite mientras el índice sea -1, es decir, mientras no se ingrese un código válido y con cupo.

        // Forma de pago
        do {
            printf("¿Paga con tarjeta de crédito? (S/N): ");
            scanf(" %c", &pago);
            getchar();
            pago = toupper(pago);//onvierte el carácter almacenado en la variable pago a mayúscula. Así, si el usuario ingresa 's' o 'n', se transformará en 'S' o 'N'.
        } while (pago != 'S' && pago != 'N');

        // Guardar datos
        DNIs[totalPasajeros] = dni;
        strcpy(apellidos[totalPasajeros], apellido);
        strcpy(nombres[totalPasajeros], nombre);
        edades[totalPasajeros] = edad;
        strcpy(destinos[totalPasajeros], destino);
        pagos[totalPasajeros] = pago;
        contadorDestinos[indice]++; // //Aumenta en uno el contador de pasajeros para el destino seleccionado (usando el índice correspondiente). Así, se lleva el control de cuántos pasajeros hay para cada destino.
        //Si 20 pasajeros eligen "BRA", entonces contadorDestinos[0] será 20.
        totalPasajeros++; //Incrementa en uno el total general de pasajeros registrados en el sistema.
    }
}

// Mostrar pasajeros ordenados por Apellido y Nombre
void mostrarOrdenadoApellidoNombre() {
    for (int i = 0; i < totalPasajeros - 1; i++) {
        for (int j = i + 1; j < totalPasajeros; j++) {//Comienza un ciclo externo para recorrer todos los pasajeros menos el último.
            if (strcmp(apellidos[i], apellidos[j]) > 0 || //Compara los apellidos de los pasajeros. Si el apellido de i es mayor (alfabéticamente) que el de j, entra al bloque.
                (strcmp(apellidos[i], apellidos[j]) == 0 && strcmp(nombres[i], nombres[j]) > 0)) { //Si los apellidos son iguales, compara los nombres. Si el nombre de i es mayor que el de j, también entra al bloque.
                // Intercambio
                int tempInt;
                char tempCad[MAX_CADENA];

                tempInt = DNIs[i]; DNIs[i] = DNIs[j]; DNIs[j] = tempInt;//Intercambia los DNIs de los pasajeros i y j.
                tempInt = edades[i]; edades[i] = edades[j]; edades[j] = tempInt; //Intercambia las edades.
                char tmpPago = pagos[i]; pagos[i] = pagos[j]; pagos[j] = tmpPago;

                strcpy(tempCad, apellidos[i]); strcpy(apellidos[i], apellidos[j]); strcpy(apellidos[j], tempCad);
                strcpy(tempCad, nombres[i]); strcpy(nombres[i], nombres[j]); strcpy(nombres[j], tempCad);
                strcpy(tempCad, destinos[i]); strcpy(destinos[i], destinos[j]); strcpy(destinos[j], tempCad);
            }
        }
    }

    printf("\nLista ordenada por Apellido y Nombre:\n");
    for (int i = 0; i < totalPasajeros; i++) {
        printf("%s %s - DNI: %d - Edad: %d - Destino: %s\n", apellidos[i], nombres[i], DNIs[i], edades[i], destinos[i]);
    }
}

// Mostrar lista ordenada por Código Destino y Apellido-Nombre
void mostrarOrdenadoDestinoApellido() {
    for (int i = 0; i < totalPasajeros - 1; i++) {
        for (int j = i + 1; j < totalPasajeros; j++) {
            if (strcmp(destinos[i], destinos[j]) > 0 ||
                (strcmp(destinos[i], destinos[j]) == 0 && strcmp(apellidos[i], apellidos[j]) > 0)) {
                // Intercambio
                int tempInt;
                char tempCad[MAX_CADENA];

                tempInt = DNIs[i]; DNIs[i] = DNIs[j]; DNIs[j] = tempInt;
                tempInt = edades[i]; edades[i] = edades[j]; edades[j] = tempInt;
                char tmpPago = pagos[i]; pagos[i] = pagos[j]; pagos[j] = tmpPago;

                strcpy(tempCad, apellidos[i]); strcpy(apellidos[i], apellidos[j]); strcpy(apellidos[j], tempCad);
                strcpy(tempCad, nombres[i]); strcpy(nombres[i], nombres[j]); strcpy(nombres[j], tempCad);
                strcpy(tempCad, destinos[i]); strcpy(destinos[i], destinos[j]); strcpy(destinos[j], tempCad);
            }
        }
    }

    printf("\nLista ordenada por Código de Destino y Apellido:\n");
    for (int i = 0; i < totalPasajeros; i++) {
        printf("%s - %s %s - DNI: %d - Edad: %d\n", destinos[i], apellidos[i], nombres[i], DNIs[i], edades[i]);
    }
}

// Mostrar lista de destinos
void mostrarListaDestinos() {
    float totalPorDestino[MAX_DESTINOS] = {0.0}, totalGeneral = 0.0;

    for (int i = 0; i < totalPasajeros; i++) {
        int idx = indiceDestino(destinos[i]);
        if (edades[i] < 5)
            totalPorDestino[idx] += 2000.0;
        else {
            float precio = importes[idx];
            if (pagos[i] == 'S') precio *= 1.05;
            totalPorDestino[idx] += precio;
        }
    }

    printf("\nLista de Destinos:\n");
    for (int i = 0; i < MAX_DESTINOS; i++) {
        printf("%s - Pasajeros: %d - Importe total: $%.2f\n", codigos[i], contadorDestinos[i], totalPorDestino[i]);
        totalGeneral += totalPorDestino[i];
    }
    printf("Importe total general: $%.2f\n", totalGeneral);
}

// Buscar pasajero por DNI
void buscarPasajero() {
    int dni;
    printf("Ingrese DNI a buscar: ");
    scanf("%d", &dni);
    getchar();

    if (!validarDNI(dni)) {
        printf("DNI inválido.\n");
        return;
    }

    for (int i = 0; i < totalPasajeros; i++) {
        if (DNIs[i] == dni) {
            int idx = indiceDestino(destinos[i]);
            float precio = (edades[i] < 5) ? 2000.0 : importes[idx];
            if (edades[i] >= 5 && pagos[i] == 'S') precio *= 1.05;

            printf("Pasajero encontrado: %s %s - Edad: %d - Destino: %s - A pagar: $%.2f\n",
                apellidos[i], nombres[i], edades[i], nombres_destinos[idx], precio);
            return;
        }
    }
    printf("No existe pasajero con ese DNI.\n");
}

// Mostrar estadísticas
void mostrarEstadisticas() {
    int menores[MAX_DESTINOS] = {0};

    for (int i = 0; i < totalPasajeros; i++) {
        int idx = indiceDestino(destinos[i]);
        if (edades[i] < 5){
            menores[idx]++;
        }
    }

    printf("\nEstadísticas:\n");
    int max = 0;
    for (int i = 0; i < MAX_DESTINOS; i++) {
        float porcentaje = (totalPasajeros == 0) ? 0 : (contadorDestinos[i] * 100.0) / totalPasajeros;
        float porcentajeMenores = (contadorDestinos[i] == 0) ? 0 : (menores[i] * 100.0) / contadorDestinos[i];
        printf("%s: %.2f%% del total - %.2f%% menores de 5 años\n", codigos[i], porcentaje, porcentajeMenores);
        if (contadorDestinos[i] > contadorDestinos[max]) max = i;
    }
    printf("Destino más solicitado: %s\n", nombres_destinos[max]);
}

// Menú principal
void menu() {
    int opcion;
    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Mostrar lista ordenada por Apellido y Nombre\n");
        printf("2. Mostrar lista ordenada por Código de Destino y Apellido\n");
        printf("3. Mostrar lista de Destinos\n");
        printf("4. Buscar por DNI\n");
        printf("5. Mostrar estadísticas\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: mostrarOrdenadoApellidoNombre(); break;
            case 2: mostrarOrdenadoDestinoApellido(); break;
            case 3: mostrarListaDestinos(); break;
            case 4: buscarPasajero(); break;
            case 5: mostrarEstadisticas(); break;
            case 6: printf("Gracias por usar el sistema.\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 6);
}

// Función principal
int main() {
    cargarPasajeros();
    menu();
    return 0;
}
