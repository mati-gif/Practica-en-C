#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASAJEROS 240
#define MAX_DESTINOS 4
#define MAX_CADENA 50

// Estructura para un pasajero
typedef struct {
    int dni;
    char apellido[MAX_CADENA];
    char nombre[MAX_CADENA];
    int edad;
    char destino[4];
    char pago; // 'S' o 'N'
} Pasajero;

// Datos fijos
char codigos[MAX_DESTINOS][4] = {"BRA", "MDQ", "MZA", "BRC"};
char nombres_destinos[MAX_DESTINOS][20] = {"Brasil", "Mar del Plata", "Mendoza", "Bariloche"};
float importes[MAX_DESTINOS] = {25000.0, 14000.0, 19000.0, 23000.0};

// Lista de pasajeros
Pasajero pasajeros[MAX_PASAJEROS];
int totalPasajeros = 0;
int contadorDestinos[MAX_DESTINOS] = {0};

// Función para validar DNI
int validarDNI(int dni) {
    if (dni < 1000000 || dni > 99999999) return 0;
    int inicio = (dni >= 10000000) ? dni / 1000000 : dni / 100000;
    return (inicio == 5 || inicio == 6 || (inicio >= 10 && inicio <= 60));
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
    getchar();

    for (int i = 0; i < cantidad && totalPasajeros < MAX_PASAJEROS; i++) {
        Pasajero p;
        int indice;

        printf("\nPasajero #%d:\n", totalPasajeros + 1);

        do {
            printf("DNI: ");
            scanf("%d", &p.dni);
            getchar();
            if (!validarDNI(p.dni)) printf("DNI inválido. Intente nuevamente.\n");
        } while (!validarDNI(p.dni));

        printf("Apellido: ");
        fgets(p.apellido, MAX_CADENA, stdin);
        p.apellido[strcspn(p.apellido, "\n")] = '\0';

        printf("Nombre: ");
        fgets(p.nombre, MAX_CADENA, stdin);
        p.nombre[strcspn(p.nombre, "\n")] = '\0';

        printf("Edad: ");
        scanf("%d", &p.edad);
        getchar();

        do {
            printf("Código de destino (BRA, MDQ, MZA, BRC): ");
            scanf("%s", p.destino);
            getchar();
            indice = indiceDestino(p.destino);
            if (indice == -1) {
                printf("Código inválido. Intente nuevamente.\n");
                continue;
            }
            if (contadorDestinos[indice] >= 60) {
                printf("Este destino ya alcanzó los 60 pasajeros. Elija otro.\n");
                indice = -1;
            }
        } while (indice == -1);

        do {
            printf("¿Paga con tarjeta de crédito? (S/N): ");
            scanf(" %c", &p.pago);
            getchar();
            p.pago = toupper(p.pago);
        } while (p.pago != 'S' && p.pago != 'N');

        pasajeros[totalPasajeros] = p;
        contadorDestinos[indice]++;
        totalPasajeros++;
    }
}

// Mostrar pasajeros ordenados por Apellido y Nombre
void mostrarOrdenadoApellidoNombre() {
    for (int i = 0; i < totalPasajeros - 1; i++) {
        for (int j = i + 1; j < totalPasajeros; j++) {
            if (strcmp(pasajeros[i].apellido, pasajeros[j].apellido) > 0 ||
                (strcmp(pasajeros[i].apellido, pasajeros[j].apellido) == 0 &&
                 strcmp(pasajeros[i].nombre, pasajeros[j].nombre) > 0)) {
                Pasajero temp = pasajeros[i];
                pasajeros[i] = pasajeros[j];
                pasajeros[j] = temp;
            }
        }
    }

    printf("\nLista ordenada por Apellido y Nombre:\n");
    for (int i = 0; i < totalPasajeros; i++) {
        printf("%s %s - DNI: %d - Edad: %d - Destino: %s\n", pasajeros[i].apellido, pasajeros[i].nombre,
               pasajeros[i].dni, pasajeros[i].edad, pasajeros[i].destino);
    }
}

// Mostrar lista ordenada por Código Destino y Apellido-Nombre
void mostrarOrdenadoDestinoApellido() {
    for (int i = 0; i < totalPasajeros - 1; i++) {
        for (int j = i + 1; j < totalPasajeros; j++) {
            if (strcmp(pasajeros[i].destino, pasajeros[j].destino) > 0 ||
                (strcmp(pasajeros[i].destino, pasajeros[j].destino) == 0 &&
                 strcmp(pasajeros[i].apellido, pasajeros[j].apellido) > 0)) {
                Pasajero temp = pasajeros[i];
                pasajeros[i] = pasajeros[j];
                pasajeros[j] = temp;
            }
        }
    }

    printf("\nLista ordenada por Código de Destino y Apellido:\n");
    for (int i = 0; i < totalPasajeros; i++) {
        printf("%s - %s %s - DNI: %d - Edad: %d\n", pasajeros[i].destino, pasajeros[i].apellido,
               pasajeros[i].nombre, pasajeros[i].dni, pasajeros[i].edad);
    }
}

// Mostrar lista de destinos
void mostrarListaDestinos() {
    float totalPorDestino[MAX_DESTINOS] = {0.0}, totalGeneral = 0.0;

    for (int i = 0; i < totalPasajeros; i++) {
        int idx = indiceDestino(pasajeros[i].destino);
        if (pasajeros[i].edad < 5)
            totalPorDestino[idx] += 2000.0;
        else {
            float precio = importes[idx];
            if (pasajeros[i].pago == 'S') precio *= 1.05;
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
        if (pasajeros[i].dni == dni) {
            int idx = indiceDestino(pasajeros[i].destino);
            float precio = (pasajeros[i].edad < 5) ? 2000.0 : importes[idx];
            if (pasajeros[i].edad >= 5 && pasajeros[i].pago == 'S') precio *= 1.05;

            printf("Pasajero encontrado: %s %s - Edad: %d - Destino: %s - A pagar: $%.2f\n",
                   pasajeros[i].apellido, pasajeros[i].nombre, pasajeros[i].edad, nombres_destinos[idx], precio);
            return;
        }
    }
    printf("No existe pasajero con ese DNI.\n");
}

// Mostrar estadísticas
void mostrarEstadisticas() {
    int menores[MAX_DESTINOS] = {0};

    for (int i = 0; i < totalPasajeros; i++) {
        int idx = indiceDestino(pasajeros[i].destino);
        if (pasajeros[i].edad < 5) menores[idx]++;
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
