#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_COMPONENTES 100
#define MAX_PRODUCTOS 50
#define MAX_COMP_POR_PRODUCTO 10

extern char inventario_nombres[MAX_COMPONENTES][30];
extern int inventario_cantidades[MAX_COMPONENTES];
extern int total_componentes;

extern char productos_nombres[MAX_PRODUCTOS][30];
extern int productos_tiempo_por_unidad[MAX_PRODUCTOS];
extern char productos_comp_nombres[MAX_PRODUCTOS][MAX_COMP_POR_PRODUCTO][30];
extern int productos_comp_cantidades[MAX_PRODUCTOS][MAX_COMP_POR_PRODUCTO];
extern int productos_num_componentes[MAX_PRODUCTOS];
extern int total_productos;

int pedirEnteroPositivo(const char* mensaje);
void pedirCadena(const char* mensaje, char* destino, int tam);
int buscarComponente(const char* nombre);
int buscarProducto(const char* nombre);
void mostrarInventario();
void reabastecerInventario();
void agregarProducto();
void editarProducto();
void eliminarProducto();
void mostrarResumenProductos();
void venderProducto();

#endif
