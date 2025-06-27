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

// Función para validar DNI
int validarDNI(int dni) {
    if (dni < 1000000 || dni > 99999999) return 0;
    int inicio = dni / 10000000; // primer dígito
    if (inicio == 5 || inicio == 6 || (inicio >= 10 && inicio <= 60)) return 1;
    return 0;
}

// Función para obtener índice de un destino
int indiceDestino(char cod[]) {
    for (int i = 0; i < MAX_DESTINOS; i++) {
        if (strcmp(codigos[i], cod) == 0) return i;
    }
    return -1;
}

// Cargar pasajeros manualmente
void cargarPasajeros() {
    int cantidad;
    printf("Ingrese la cantidad de pasajeros: ");
    scanf("%d", &cantidad);

    for (int i = 0; i < cantidad && totalPasajeros < MAX_PASAJEROS; i++) {
        int dni, edad;
        char apellido[MAX_CADENA], nombre[MAX_CADENA], destino[4], pago;
        int indice;

        printf("\nPasajero #%d:\n", totalPasajeros + 1);

        // DNI
        do {
            printf("DNI: ");
            scanf("%d", &dni);
            if (!validarDNI(dni)) printf("DNI inválido. Intente nuevamente.\n");
        } while (!validarDNI(dni));

        // Apellido
        printf("Apellido: ");
        scanf("%s", apellido);

        // Nombre
        printf("Nombre: ");
        scanf("%s", nombre);

        // Edad
        printf("Edad: ");
        scanf("%d", &edad);

        // Destino
        do {
            printf("Código de destino (BRA, MDQ, MZA, BRC): ");
            scanf("%s", destino);
            indice = indiceDestino(destino);
            if (indice == -1) printf("Código inválido. Intente nuevamente.\n");
        } while (indice == -1);

        // Forma de pago
        do {
            printf("¿Paga con tarjeta de crédito? (S/N): ");
            scanf(" %c", &pago);
            pago = toupper(pago);
        } while (pago != 'S' && pago != 'N');

        // Guardar datos
        DNIs[totalPasajeros] = dni;
        strcpy(apellidos[totalPasajeros], apellido);
        strcpy(nombres[totalPasajeros], nombre);
        edades[totalPasajeros] = edad;
        strcpy(destinos[totalPasajeros], destino);
        pagos[totalPasajeros] = pago;

        totalPasajeros++;
    }
}

// Mostrar pasajeros ordenados por Apellido y Nombre
void mostrarOrdenadoApellidoNombre() {
    for (int i = 0; i < totalPasajeros - 1; i++) {
        for (int j = i + 1; j < totalPasajeros; j++) {
            if (strcmp(apellidos[i], apellidos[j]) > 0 ||
                (strcmp(apellidos[i], apellidos[j]) == 0 && strcmp(nombres[i], nombres[j]) > 0)) {
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
    int contador[MAX_DESTINOS] = {0};
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
        contador[idx]++;
    }

    printf("\nLista de Destinos:\n");
    for (int i = 0; i < MAX_DESTINOS; i++) {
        printf("%s - Pasajeros: %d - Importe total: $%.2f\n", codigos[i], contador[i], totalPorDestino[i]);
        totalGeneral += totalPorDestino[i];
    }
    printf("Importe total general: $%.2f\n", totalGeneral);
}

// Buscar pasajero por DNI
void buscarPasajero() {
    int dni;
    printf("Ingrese DNI a buscar: ");
    scanf("%d", &dni);

    if (!validarDNI(dni)) {
        printf("DNI inválido.\n");
        return;
    }

    for (int i = 0; i < totalPasajeros; i++) {
        if (DNIs[i] == dni) {
            int idx = indiceDestino(destinos[i]);
            float precio = 0.0;
            if (edades[i] < 5)
                precio = 2000.0;
            else {
                precio = importes[idx];
                if (pagos[i] == 'S') precio *= 1.05;
            }
            printf("Pasajero encontrado: %s %s - Edad: %d - Destino: %s - A pagar: $%.2f\n",
                apellidos[i], nombres[i], edades[i], nombres_destinos[idx], precio);
            return;
        }
    }
    printf("No existe pasajero con ese DNI.\n");
}

// Mostrar estadísticas
void mostrarEstadisticas() {
    int contador[MAX_DESTINOS] = {0};
    int menores[MAX_DESTINOS] = {0};

    for (int i = 0; i < totalPasajeros; i++) {
        int idx = indiceDestino(destinos[i]);
        contador[idx]++;
        if (edades[i] < 5) menores[idx]++;
    }

    printf("\nEstadísticas:\n");
    int max = 0;
    for (int i = 0; i < MAX_DESTINOS; i++) {
        float porcentaje = (totalPasajeros == 0) ? 0 : (contador[i] * 100.0) / totalPasajeros;
        float porcentajeMenores = (contador[i] == 0) ? 0 : (menores[i] * 100.0) / contador[i];
        printf("%s: %.2f%% del total - %.2f%% menores de 5 años\n", codigos[i], porcentaje, porcentajeMenores);
        if (contador[i] > contador[max]) max = i;
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
