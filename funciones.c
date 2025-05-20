#include <stdio.h>
#include <string.h>
#include "funciones.h"

char inventario_nombres[MAX_COMPONENTES][30];
int inventario_cantidades[MAX_COMPONENTES];
int total_componentes = 0;

char productos_nombres[MAX_PRODUCTOS][30];
int productos_tiempo_por_unidad[MAX_PRODUCTOS];
char productos_comp_nombres[MAX_PRODUCTOS][MAX_COMP_POR_PRODUCTO][30];
int productos_comp_cantidades[MAX_PRODUCTOS][MAX_COMP_POR_PRODUCTO];
int productos_num_componentes[MAX_PRODUCTOS];
int total_productos = 0;

int pedirEnteroPositivo(const char* mensaje) {
    int valor;
    char c;
    while (1) {
        printf("%s", mensaje);
        if (scanf("%d%c", &valor, &c) == 2 && c == '\n' && valor > 0) return valor;
        printf("Entrada invalida. Intenta de nuevo (solo numeros mayores a cero).\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void pedirCadena(const char* mensaje, char* destino, int tam) {
    char buffer[100];
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strlen(buffer) > 0 && strlen(buffer) < tam) {
                strcpy(destino, buffer);
                return;
            }
        }
        printf("Entrada invalida. Intenta nuevamente.\n");
    }
}

int buscarComponente(const char* nombre) {
    for (int i = 0; i < total_componentes; i++) {
        if (strcmp(inventario_nombres[i], nombre) == 0) return i;
    }
    return -1;
}

int buscarProducto(const char* nombre) {
    for (int i = 0; i < total_productos; i++) {
        if (strcmp(productos_nombres[i], nombre) == 0) return i;
    }
    return -1;
}

void mostrarInventario() {
    printf("\n+------------------+----------+\n");
    printf("| Componente       | Cantidad |\n");
    printf("+------------------+----------+\n");
    if (total_componentes == 0) {
        printf("| (sin componentes definidos)         |\n");
    } else {
        for (int i = 0; i < total_componentes; i++) {
            printf("| %-16s | %-8d |\n", inventario_nombres[i], inventario_cantidades[i]);
        }
    }
    printf("+------------------+----------+\n");
}

void reabastecerInventario() {
    if (total_componentes == 0) {
        printf("No hay componentes en el inventario.\n");
        return;
    }

    char nombre[30];
    getchar();
    pedirCadena("Nombre del componente a reabastecer: ", nombre, 30);

    int pos = buscarComponente(nombre);
    if (pos != -1) {
        int cantidad = pedirEnteroPositivo("Cantidad a añadir: ");
        inventario_cantidades[pos] += cantidad;
    } else {
        printf("Componente no encontrado.\n");
    }
}

void agregarProducto() {
    if (total_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    char nombre[30];
    getchar();
    pedirCadena("Nombre del producto: ", nombre, 30);

    if (buscarProducto(nombre) != -1) {
        printf("El producto ya existe.\n");
        return;
    }

    int tiempo = pedirEnteroPositivo("Tiempo (en horas) para producir una unidad: ");

    int num_comp = 0;
    char comp_name[30];
    int comp_cant;

    for (int i = 0; i < MAX_COMP_POR_PRODUCTO; i++) {
        pedirCadena("Nombre del componente (o 'fin' para terminar): ", comp_name, 30);
        if (strcmp(comp_name, "fin") == 0) break;

        int posComp = buscarComponente(comp_name);
        if (posComp == -1) {
            if (total_componentes >= MAX_COMPONENTES) {
                printf("No se pueden agregar más componentes al inventario.\n");
                break;
            }
            strcpy(inventario_nombres[total_componentes], comp_name);
            inventario_cantidades[total_componentes] = 0;
            total_componentes++;
        }
        comp_cant = pedirEnteroPositivo("Cantidad requerida: ");

        strcpy(productos_comp_nombres[total_productos][num_comp], comp_name);
        productos_comp_cantidades[total_productos][num_comp] = comp_cant;
        num_comp++;
    }

    strcpy(productos_nombres[total_productos], nombre);
    productos_tiempo_por_unidad[total_productos] = tiempo;
    productos_num_componentes[total_productos] = num_comp;

    total_productos++;

    printf("Producto agregado con éxito.\n");
}

void editarProducto() {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    // Mostrar los productos existentes
    printf("\nProductos registrados:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("  %d. %s\n", i + 1, productos_nombres[i]);
    }

    // Pedir al usuario que seleccione el producto a editar
    int opcion;
    printf("Seleccione el número del producto a editar: ");
    opcion = pedirEnteroPositivo("Opción: ");

    if (opcion < 1 || opcion > total_productos) {
        printf("Opción inválida.\n");
        return;
    }

    int idx = opcion - 1; // Convertir la opción en un índice válido

    char nuevo_nombre[30];
    pedirCadena("Nuevo nombre del producto: ", nuevo_nombre, 30);

    if (strcmp(nuevo_nombre, productos_nombres[idx]) != 0 && buscarProducto(nuevo_nombre) != -1) {
        printf("Ya existe un producto con ese nombre.\n");
        return;
    }

    int nuevo_tiempo = pedirEnteroPositivo("Nuevo tiempo por unidad: ");

    int num_comp = 0;
    char comp_name[30];
    int comp_cant;

    for (int i = 0; i < MAX_COMP_POR_PRODUCTO; i++) {
        pedirCadena("Nombre del componente (o 'fin' para terminar): ", comp_name, 30);
        if (strcmp(comp_name, "fin") == 0) break;

        int posComp = buscarComponente(comp_name);
        if (posComp == -1) {
            if (total_componentes >= MAX_COMPONENTES) {
                printf("No se pueden agregar más componentes al inventario.\n");
                break;
            }
            strcpy(inventario_nombres[total_componentes], comp_name);
            inventario_cantidades[total_componentes] = 0;
            total_componentes++;
        }
        comp_cant = pedirEnteroPositivo("Cantidad requerida: ");

        strcpy(productos_comp_nombres[idx][num_comp], comp_name);
        productos_comp_cantidades[idx][num_comp] = comp_cant;
        num_comp++;
    }

    strcpy(productos_nombres[idx], nuevo_nombre);
    productos_tiempo_por_unidad[idx] = nuevo_tiempo;
    productos_num_componentes[idx] = num_comp;

    printf("Producto editado con éxito.\n");
}

void eliminarProducto() {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    // Mostrar los productos existentes antes de pedir cuál eliminar
    printf("\nProductos registrados:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("  - %s\n", productos_nombres[i]);
    }

    char nombre[30];
    getchar();
    pedirCadena("Nombre del producto a eliminar: ", nombre, 30);

    int idx = buscarProducto(nombre);
    if (idx == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = idx; i < total_productos - 1; i++) {
        strcpy(productos_nombres[i], productos_nombres[i + 1]);
        productos_tiempo_por_unidad[i] = productos_tiempo_por_unidad[i + 1];
        productos_num_componentes[i] = productos_num_componentes[i + 1];
        for (int j = 0; j < MAX_COMP_POR_PRODUCTO; j++) {
            strcpy(productos_comp_nombres[i][j], productos_comp_nombres[i + 1][j]);
            productos_comp_cantidades[i][j] = productos_comp_cantidades[i + 1][j];
        }
    }
    total_productos--;
    printf("Producto eliminado con éxito.\n");
}

void mostrarResumenProductos() {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n=== RESUMEN DE PRODUCTOS ===\n");
    for (int i = 0; i < total_productos; i++) {
        printf("Producto: %s\n", productos_nombres[i]);
        printf("Tiempo por unidad: %d horas\n", productos_tiempo_por_unidad[i]);
        printf("Componentes:\n");
        for (int j = 0; j < productos_num_componentes[i]; j++) {
            printf("- %s (%d)\n", productos_comp_nombres[i][j], productos_comp_cantidades[i][j]);
        }
        printf("---------------------------\n");
    }
}

void venderProducto() {
    if (total_productos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\nProductos disponibles:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("- %s\n", productos_nombres[i]);
    }

    char nombre[30];
    getchar();
    pedirCadena("Nombre del producto a vender: ", nombre, 30);

    int idx = buscarProducto(nombre);
    if (idx == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    int cantidad = pedirEnteroPositivo("Cantidad a vender: ");
    int tiempo_disponible = pedirEnteroPositivo("Tiempo disponible para producir (en horas): ");

    for (int i = 0; i < productos_num_componentes[idx]; i++) {
        int posComp = buscarComponente(productos_comp_nombres[idx][i]);
        if (posComp == -1) {
            printf("Error: Componente %s no encontrado en inventario.\n", productos_comp_nombres[idx][i]);
            return;
        }
        int cantidad_necesaria = productos_comp_cantidades[idx][i] * cantidad;
        if (inventario_cantidades[posComp] < cantidad_necesaria) {
            printf("No hay suficiente componente %s en inventario. Necesita %d, hay %d.\n",
                   inventario_nombres[posComp], cantidad_necesaria, inventario_cantidades[posComp]);
            return;
        }
    }

    int tiempo_total = productos_tiempo_por_unidad[idx] * cantidad;
    if (tiempo_total > tiempo_disponible) {
        printf("No hay suficiente tiempo para producir %d unidades. Se requieren %d horas, hay %d disponibles.\n",
               cantidad, tiempo_total, tiempo_disponible);
        return;
    }

    for (int i = 0; i < productos_num_componentes[idx]; i++) {
        int posComp = buscarComponente(productos_comp_nombres[idx][i]);
        inventario_cantidades[posComp] -= productos_comp_cantidades[idx][i] * cantidad;
    }

    printf("Venta realizada con exito. Tiempo usado: %d horas.\n", tiempo_total);
}
