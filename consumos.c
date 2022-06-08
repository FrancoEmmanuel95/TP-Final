#include "consumos_header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clientes "clientes.dat"
#define consumos "consumos.dat"
#include <conio.h>
#define ESC 27

stConsumos altaConsumos(char archivo [],char archivoCliente, stConsumos consumos, stCliente clientes)
{
    ///relaciona el id del cliente en struct cliente con id cliente en struct consumo y le agrega el consumo si flag = 1 en funcion validar fecha
    stConsumos consumo;
    stCliente clientes;

    FILE *archi = fopen(nombrearchivo, "ab");
    FILE *archi = fopen(archivoCliente, "rb");
    int idcl= clientes.id;

    if (archi)
    {
        consumos.idCliente = idcl;
        c = validacionDiaMesAnio(stConsumos consumo);



        fflush(stdin);
        printf("\nIngrese anio");
        scanf("%d", &consumos.anio);

        fflush(stdin);
        printf("\nIngrese mes");
        scanf("%d", consumos.mes);

        fflush(stdin);
        printf("\nIngrese dia");
        scanf("%d", consumos.dia);

        if (c == 1)
        {
            fflush(stdin);
            printf("\nIngrese los datos consumidos");
            scanf("%d", consumos.datosConsumidos);
            c = validacionConsumo(clientes, stConsumos);
        }
        else
        {
            printf("\nFecha incorrecta");
        }



        if (clientes.eliminado == 1)
        {
            printf("\nEl cliente se encuentra dado de baja");
        }

    }
    fclose(archi);
    fclose(archivoCliente);
    return consumos;
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
int validacionDiaMesAnio (stConsumos consumos)
{
    ///meses 1 3 5 7 8 10 12 = 31 --- meses 4 6 9 11 = 30 ---- mes 2 = 28 / biciesto 29 .. devuelve un flag = 1 si la fecha es correcta
    int flag = 0;
    int dia = consumos.dia;
    int mes = consumos.mes;
    int anio = consumos.anio;

    if(mes >=1 && mes <=12)
    {
        switch (mes)
        {
        case 1:
        {

            flag = validardia31(consumo.dia);
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
            flag = validardia31(consumo.dia);

        }
        break;

        case 4:
        {
            flag = validardia30(consumo.dia);

        }
        break;

        case 5:
        {
            flag = validardia31(consumo.dia);

        }
        break;

        case 6:
        {
            flag = validardia30(consumo.dia);

        }
        break;

        case 7:
        {
            flag = validardia31(consumo.dia);

        }
        break;

        case 8:
        {
            flag = validardia31(consumo.dia);

        }
        break;

        case 9:
        {
            flag = validardia30(consumo.dia);

        }
        break;

        case 10:
        {
            flag = validardia31(consumo.dia);

        }
        break;

        case 11:
        {
            flag = validardia30(consumo.dia);

        }
        break;

        case 12:
        {
            flag = validardia31(consumo.dia);

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

    void mostrarConsumos(stConsumos consumos, stCliente clientes, char archivoCliente[], char archivo[])
    {
        ///mostrar los datos del cliente y los datos consumidos hasta el momento
        stConsumos consumos;
        stCliente clientes;

        FILE *archicons = fopen(archivo, "rb");
        FILE *archiclie = fopen(archivoCliente, "rb");

        printf("\nNro Cliente.............", consumos.idCliente);
        consultaCliente(clientes);
        printf("\nDatos Consumidos........", consumos.datosConsumidos);
        if(clientes.eliminado == 0)
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
        int i = 0;

        srand(time(NULL));

        for (i = 1; i <= 1000; i++)
        {
            consumos.dia = rand(31 + 1)-1;
            consumos.mes = rand(12 + 1)-1;
            consumos.anio = rand(12 + 1)-1;
            consumos.datosConsumidos = rand()%1000;

        }
        fclose(archi);
        return consumos;
    }

    ///rand para cada uno de los datos , id, dia , mes , etc , todo dentro del for


    int sumaConsumos (stConsumos consumos, char archivo[])
    {
        ///buscar los consumos del mismo id y acumularlos, que la funcion te devuelva la cantidad de consumos acumulados
        stConsumos consumos;
        FILE *archivo = fopen(archivoConsumos, "r+b");

        int acum = 0;
        int flag = busquedaPorId(stConsumos consumos, stCliente clientes,archivo clientes, archivo consumos);

        if (flag == 1)
        {
            acum = acum + consumos.datosConsumidos;
        }

        ///deberia tomar el consumo anterior del cliente para acumularle el nuevo?

        fclose(archi);

        return acum;
    }

  stConsumos modifcarDatosConsumidos (stConsumos consumos)
  {
      ///igual a la logica planteada en estructura de clientes, modificacion de clientes
      printf("\nIngrese los datos consumidos ");
      fflush(stdin);
      gets(consumos.datosConsumidos);
  }

///buscar por fecha , por dia, por dni y por nro de cliente
///modificacion de datos
///modificar menu con gotoxy (funciones clientes , funciones consumos)


int busquedaPorId( stConsumos consumos, stClientes clientes, char archivo[], char archi[])
{
    ///compara dos id iguales dentro del archivo y devuelve un flag 1 en caso de encontrarlos
    stConsumos consumos;
    stClientes clientes;
    FILE *archivo = fopen(archivoCliente, "rb");
    FILE *archi = fopen(archivoConsumos, "rb");
    int flag = 0;
    if(archi && archivo)
    {
        if(consumos.idCliente == clientes.id)
        {
            flag = 1;
        }else
        {
            flag = 0;
        }
    }
    fclose(archivo);
    fclose(archi);
    return flag;
}

int busquedaPorDia( stConsumos consumos, char archi[])
{
    ///comparar los dias en estructura de consumos con los guardados en el archivo , debemos pasarlo a un arreglo? y recorrer dos arreglos paralelos?

    stConsumos consumos;
    FILE *archi = fopen(archivoConsumos, "rb");
    int flag = 0;
    if(archi)
    {


    }

    fclose(archivo);
    fclose(archi);
    return flag;
}
