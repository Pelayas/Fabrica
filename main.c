#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[5][30];
    int inventario[5][3];
    int numProductos = 0;
    int opcion;

    do {
        printf("\n--- Menú de la Fábrica ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar resumen de productos\n");
        printf("5. Mostrar inventario total\n");
        printf("6. Vender producto\n");
        printf("7. Reabastecer inventario\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(productos, inventario, &numProductos);
                break;
            case 2:
                editarProducto(productos, inventario, numProductos);
                break;
            case 3:
                eliminarProducto(productos, inventario, &numProductos);
                break;
            case 4:
                mostrarResumenProductos(productos, inventario, numProductos);
                break;
            case 5:
                mostrarInventario(productos, inventario, numProductos);
                break;
            case 6:
                venderProducto(productos, inventario, numProductos);
                break;
            case 7:
                reabastecerInventario(productos, inventario, numProductos);
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
