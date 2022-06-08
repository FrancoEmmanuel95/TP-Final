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

typedef struct
{
    int id; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int eliminado; /// 0 si est� activo - 1 si est� eliminado
} stCliente;

stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes);

void mostrarConsumos(stConsumos consumo, stCliente cliente, char archivoCliente[], char archivo[]);

int validacionDiaMesAnio (stConsumos consumo);
int validardia31(int dia);
int validardia30(int dia);
int sumaConsumos (stConsumos consumo, char archi[]);
int validacionConsumo (char archivo[], stConsumos a);












#endif // CONSUMOS_HEADER_H_INCLUDED
