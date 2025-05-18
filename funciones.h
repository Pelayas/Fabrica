// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

void agregarProducto(char productos[5][30], int inventario[5][3], int *numProductos);
void editarProducto(char productos[5][30], int inventario[5][3], int numProductos);
void eliminarProducto(char productos[5][30], int inventario[5][3], int *numProductos);
void mostrarResumenProductos(char productos[5][30], int inventario[5][3], int numProductos);
void mostrarInventario(char productos[5][30], int inventario[5][3], int numProductos);
void venderProducto(char productos[5][30], int inventario[5][3], int numProductos);
void reabastecerInventario(char productos[5][30], int inventario[5][3], int numProductos);

#endif
