#include <stdio.h>
#include <string.h>
#include "funciones.h"

void agregarProducto(char productos[5][30], int inventario[5][3], int *numProductos) {
    if (*numProductos >= 5) {
        printf("No se pueden agregar más productos.\n");
        return;
    }
    printf("Nombre del producto: ");
    scanf(" %[^\n]", productos[*numProductos]);

    printf("Cantidad de Tela: ");
    scanf("%d", &inventario[*numProductos][0]);
    printf("Cantidad de Hilo: ");
    scanf("%d", &inventario[*numProductos][1]);
    printf("Tiempo de elaboración (minutos): ");
    scanf("%d", &inventario[*numProductos][2]);

    (*numProductos)++;
    printf("Producto agregado correctamente.\n");
}

void editarProducto(char productos[5][30], int inventario[5][3], int numProductos) {
    char nombre[30];
    printf("Nombre del producto a editar: ");
    scanf(" %[^\n]", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombre, productos[i]) == 0) {
            printf("Nuevo nombre: ");
            scanf(" %[^\n]", productos[i]);
            printf("Nueva cantidad de Tela: ");
            scanf("%d", &inventario[i][0]);
            printf("Nueva cantidad de Hilo: ");
            scanf("%d", &inventario[i][1]);
            printf("Nuevo tiempo de elaboración (minutos): ");
            scanf("%d", &inventario[i][2]);
            printf("Producto editado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char productos[5][30], int inventario[5][3], int *numProductos) {
    char nombre[30];
    printf("Nombre del producto a eliminar: ");
    scanf(" %[^\n]", nombre);

    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nombre, productos[i]) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                strcpy(productos[j], productos[j + 1]);
                for (int k = 0; k < 3; k++)
                    inventario[j][k] = inventario[j + 1][k];
            }
            (*numProductos)--;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void mostrarResumenProductos(char productos[5][30], int inventario[5][3], int numProductos) {
    printf("\nResumen de Productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s | Tela: %d | Hilo: %d | Tiempo: %d min\n",
            productos[i], inventario[i][0], inventario[i][1], inventario[i][2]);
    }
}

void mostrarInventario(char productos[5][30], int inventario[5][3], int numProductos) {
    int totalTela = 0, totalHilo = 0, totalTiempo = 0;
    for (int i = 0; i < numProductos; i++) {
        totalTela += inventario[i][0];
        totalHilo += inventario[i][1];
        totalTiempo += inventario[i][2];
    }
    printf("\nInventario Total:\n");
    printf("Tela: %d\n", totalTela);
    printf("Hilo: %d\n", totalHilo);
    printf("Tiempo de elaboración: %d minutos\n", totalTiempo);
}

void venderProducto(char productos[5][30], int inventario[5][3], int numProductos) {
    char nombre[30];
    printf("Nombre del producto a vender: ");
    scanf(" %[^\n]", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombre, productos[i]) == 0) {
            inventario[i][0]--;
            inventario[i][1]--;
            inventario[i][2]--;
            printf("Producto vendido.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void reabastecerInventario(char productos[5][30], int inventario[5][3], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        inventario[i][0]++;
        inventario[i][1]++;
        inventario[i][2]++;
    }
    printf("Inventario reabastecido.\n");
}
