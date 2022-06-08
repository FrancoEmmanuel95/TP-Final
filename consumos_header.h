#ifndef CONSUMOS_HEADER_H_INCLUDED
#define CONSUMOS_HEADER_H_INCLUDED
#include "header_tpfinal.h"


typedef struct
{
    int id; /// campo �nico y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a � dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si est� activo - 1 si est� eliminado
}stConsumos;

stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes);
int validacionConsumo (char archivo[], stConsumos a);
int validacionDiaMesAnio (stConsumos consumo);
int validardia31(int dia);
int validardia30(int dia);
void mostrarConsumos(stConsumos consumo, stCliente cliente, char archivoCliente[], char archivo[]);
int sumaConsumos (stConsumos consumo, char archi[]);











#endif // CONSUMOS_HEADER_H_INCLUDED
