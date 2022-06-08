#include "consumos_header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clientes "clientes.dat"
#define consumos "consumos.dat"
#include <conio.h>
#define ESC 27

stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumo, stCliente clientes)
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
            c = validacionConsumo(clientes, stConsumos);
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
int validacionConsumo (char archivo[], stConsumos a)
{
    int flag = 0;
    stConsumos b;
    FILE *archi = fopen(archivo, "r+b");
    if (archi)
    {
        while (flag == 0 &&fread(&a, sizeof(stConsumos), 11 archi)>0)
        {
            if(a.idCliente == b.idCliente && a.anio == b.anio && a.mes == b.mes && a.dia == b.dia)
            {
                flag = 1;
                b.datosConsumidos = a.datosConsumidos + b.datosConsumidos;
                fseek(archi,sizeof(stConsumos)*(-1),0);
                fwrite(&b, sizeof(stConsumos),1,archi);
            }
            else if (flag == 0)
            {
                fseek(archi, sizeof(stConsumos), SEEK_END);
                fwrite(&a,sizeof(stConsumos),1,archi);
            }
            fclose(archi);

        }
    }
    return flag;
}
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

            flag = int validardia31(int dia);
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
            flag = int validardia31(int dia);

        }
        break;

        case 4:
        {
            flag =int validardia30(int dia);

        }
        break;

        case 5:
        {
            flag =int validardia31(int dia);

        }
        break;

        case 6:
        {
            flag =int validardia30(int dia);

        }
        break;

        case 7:
        {
            flag =int validardia31(int dia);

        }
        break;

        case 8:
        {
            flag =int validardia31(int dia);

        }
        break;

        case 9:
        {
            flag =int validardia30(int dia);

        }
        break;

        case 10:
        {
            flag =int validardia31(int dia);

        }
        break;

        case 11:
        {
            flag =int validardia30(int dia);

        }
        break;

        case 12:
        {
            flag =int validardia31(int dia);

        }

        break;

        }
    }


    return flag;
}
int validardia31(int dia)
{
    int flag=0;
    if(dia >=1 && dia <=31 )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
        flag =
    }

    return flag;
}
int validardia30(int dia)
{
    int flag=0;
    if(dia >=1 && dia <=30 )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;

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

    stConsumos cargaConsumosRand(stConsumos consumos, stCliente clientes, char archivo[])
    {
        stConsumos consumos;
        stCliente clientes;
        FILE *archi = fopen(archivoClientes, "r+b");

        int id = clientes.id
        int datos = consumos.datosConsumidos;

        for (id = 1; id <= 1000; id++)
        {
            datos = rand()%1000;
        }
        fclose(archi);
        return datos;
    }

    ///rand para cada uno de los datos , id, dia , mes , etc , todo dentro del for


int sumaConsumos (stConsumos consumo, char archi[])
    {
        // stConsumos consumo;
        FILE *archi = fopen(archivoCliente, "rb");

        int acum = 0;

        acum = acum + cargaConsumosRand;
        fclose(archi);
        ///buscar los consumos del mismo id y acumularlos, que la funcion te devuelva la cantidad de consumos
        return acum;
    }

    void consultaConsumo(stConsumo consumos)
{
    printf("\nNumero de Cliente........: %d",consumos.numeroDeCliente);
    printf("\nDia......................: %d",consumos.dia);
    printf("\nMes......................: %s",cliente.mes);
    printf("\nAnio.....................: %s",cliente.anio);
    printf("\nDNI......................: %s",cliente.dni);

}
///buscar por fecha , por dia, por dni y por nro de cliente
///modificacion de datos
///carga rand
///modificar menu con gotoxy (funciones clientes , funciones consumos)
