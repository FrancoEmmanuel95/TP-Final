#ifndef HEADER_TPFINAL_H_INCLUDED
#define  HEADER_TPFINAL_H_INCLUDED
#include "consumos_header.h"
typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado
} stCliente;

typedef struct
{
    int id; /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
}stConsumos;



void menuModificar();
stCliente buscarporID(char archivo[],int id);
stCliente buscarPorDni(char dni[],char archivo[]);
stCliente buscarPorNroCliente(int nrocliente,char archivo[]);
stCliente modificardomicilio(stCliente cliente);
stCliente modificarNombre(stCliente cliente);
stCliente modificarApellido(stCliente cliente);
stCliente modificarDNI(stCliente cliente);
stCliente modificarMovil(stCliente cliente);
stCliente modificarEmail(stCliente cliente);
stCliente modificarAltaBaja(stCliente cliente);
void seleccionModificar(int id);
void modificarCliente(char archivo[],int id,int flag);
void consultaCliente(stCliente cliente);
stCliente altaUnCliente(int id);
int validacionNroCliente(stCliente b, char archivo[]);
int validacionDni(char dni[], char archivo[]);
void mostrarMenu();
void seleccion();
void muestraArchivoClientes(char nombreArchivo[]);
void cargaClienteArchivo(char nombreArchivo[]);
int contarRegistros(char archivo[]);
void borclien();

//stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes);
int validacionDiaMesAnio (stConsumos consumo);
int validardia31(int dia);
void mostrarConsumos(stConsumos consumos, stCliente clientes, char archivoCliente[], char archivo[]);
//int sumaConsumos (stConsumos consumos, char archi[]);

#endif // HEADER-TPFINAL_H_INCLUDED
