#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    do {
        printf("\n==== Menu ====\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar resumen de productos\n");
        printf("5. Mostrar inventario\n");
        printf("6. Vender producto\n");
        printf("7. Reabastecer inventario\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: editarProducto(); break;
            case 3: eliminarProducto(); break;
            case 4: mostrarResumenProductos(); break;
            case 5: mostrarInventario(); break;
            case 6: venderProducto(); break;
            case 7: reabastecerInventario(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
