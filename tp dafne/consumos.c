#include "consumos_header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clientes "clientes.dat"
#define consumos "consumos.dat"
#include <conio.h>
#define ESC 27

/*stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes)
{
    ///relaciona el id del cliente en struct cliente con id cliente en struct consumo y le agrega el consumo si flag = 1 en funcion validar fecha
    stConsumos consumo;
    stCliente clientes;

    FILE *archi = fopen(nombrearchivo, "ab");
    FILE *archi = fopen(archivoCliente, "rb");
    int idcl= clientes.id

              if (archi)
    {
        consumo.idCliente = idcl;
        c = validacionDiaMesAnio(stConsumos consumo)



            fflush(stdin);
        printf("\nIngrese anio");
        scanf("%d", consumo.anio);

        fflush(stdin);
        printf("\nIngrese mes");
        scanf("%d", consumo.mes);

        fflush(stdin);
        printf("\nIngrese dia");
        scanf("%d", consumo.dia);

        if (c == 1)
        {
            fflush(stdin);
            printf("\nIngrese los datos consumidos");
            scanf("%d", consumo.datosConsumidos);
        }
        else
        {
            printf("\nFecha incorrecta");
        }



        if (cliente.eliminado == 1)
        {
            printf("\nEl cliente se encuentra dado de baja");
        }

    }
    fclose(archi);
    fclose(archivoCliente);
    return consumo;
}
*/
int validacionDiaMesAnio (stConsumos consumo)
{
    ///meses 1 3 5 7 8 10 12 = 31 --- meses 4 6 9 11 = 30 ---- mes 2 = 28 / biciesto 29 .. devuelve un flag = 1 si la fecha es correcta
    int flag = 0;
    int dia = consumo.dia;
    int mes = consumo.mes;
    int anio = consumo.anio;

    if(mes >=1 && mes <=12)
    {
        switch (mes)
    {
    case 1:
    {
        if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 2:
        {
            if (anio % 4 == 0 && anio % 100 !=0)
            {
                if(dia >=1 && dia <=29 )
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            else if (dia >= 1 && dia <=28)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 3:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 4:
        {
            if(dia >=1 && dia <=30 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 5:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 6:
        {
            if(dia >=1 && dia <=30 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;
//stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes);
int validacionDiaMesAnio (stConsumos consumo);
int validardia31(int dia);
void mostrarConsumos(stConsumos consumo, stCliente cliente, char archivoCliente[], char archivo[]);
//int sumaConsumos (stConsumos consumos, char archi[]);
        case 7:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 8:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 9:
        {
            if(dia >=1 && dia <=30 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 10:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }
        break;

        case 11:
        {
            if(dia >=1 && dia <=30 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;

            }

        }
        break;

        case 12:
        {
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

        }

        break;

        }
    }


    return flag;
}
int validardia31(int dia){
    int flag=0;
            if(dia >=1 && dia <=31 )
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

return flag;
}


void mostrarConsumos(stConsumos consumo, stCliente cliente, char archivoCliente[], char archivo[])
{
    ///mostrar los datos del cliente y los datos consumidos hasta el momento
    //stConsumos consumo;
   // stCliente cliente;

    FILE *archicons = fopen(archivo, "rb");
    FILE *archiclie = fopen(archivoCliente, "rb");

  //  printf("\nNro Cliente.............", consumo.idCliente);
    consultaCliente(cliente);
   // printf("\nDatos Consumidos........", consumo.datosConsumidos);
    if(cliente.eliminado == 0)
    {
        printf("\nCLIENTE ACTIVO");
    }
    else
    {
        printf("\nCLIENTE INACTIVO");
    }


    fclose(archicons);
    fclose(archiclie);
}

/*int sumaConsumos (stConsumos consumo, char archi[])
{
   // stConsumos consumo;
    FILE *archi = fopen(archivoCliente, "rb");

    int acum = 0;
    fclose(archi);
    ///buscar los consumos del mismo id y acumularlos, que la funcion te devuelva la cantidad de consumos

    while ()
    }

*/