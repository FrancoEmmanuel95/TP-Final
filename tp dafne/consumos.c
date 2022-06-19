#include "header_tpfinal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clientes "clientes.dat"
#include <conio.h>
#define ESC 27
#include "gotoxy.h"
#include <windows.h>


int buscarId(int id,char archivo[])
{

    stCliente cliente;
    int flag=0;

    FILE * archi = fopen(archivo, "rb");
    if(archi)
    {
        while(flag==0 && fread(&cliente,sizeof(stCliente),1,archi)>0)
        {
            if(id==cliente.id)
            {
                flag=1;
                if(cliente.eliminado==1)
                {
                    flag=3;
                }
            }
        }
    }
    fclose(archi);
    return flag;
}


stConsumos altaConsumos(int id,FILE *archi)
{
    stConsumos consumo;
    int flag=0;
    int flag2=0;

    consumo.id=id;
    system("cls");
    printf("\nIngrese el id del cliente: ");
    scanf("%d",&consumo.idCliente);
    flag=buscarId(consumo.idCliente,clientes);

    if (flag==1 || flag==3)
    {

        fflush(stdin);
        printf("\nIngrese a%co: ",164);
        scanf("%d", &consumo.anio);

        fflush(stdin);
        printf("\nIngrese mes: ");
        scanf("%d", &consumo.mes);

        fflush(stdin);
        printf("\nIngrese dia: ");
        scanf("%d", &consumo.dia);

        flag2 = validacionDiaMesAnio(consumo.anio,consumo.mes,consumo.dia);

        if (flag2 == 1 )
        {
            fflush(stdin);
            printf("\nIngrese los datos consumidos: ");
            scanf("%d", &consumo.datosConsumidos);
            flag2 = validacionConsumo(archi, consumo);
        }
        else
        {
            printf("\nFecha incorrecta");
        }
        if (flag2==2 || flag2==0)
            {
                consumo.id=0;
            }
        /*  if (cliente.eliminado == 1)
          {
              printf("\nEl cliente se encuentra dado de baja");
          }*/

    }
    else
    {
        printf("el id del usuario es invalido");
        consumo.id=0;
    }

    return consumo;
}

void cargaConsumoArchivo(char archivo[])
{
    char opcion;
    static int id=0;
    id=contarRegistros(consumos,0);

    stConsumos consumo;

    FILE * archi = fopen (archivo, "r+b");
    if(archi)
    {
        do
        {
            id++;
            consumo = altaConsumos(id,archi);

            if(consumo.id!=0)
            {
                fwrite(&consumo,sizeof(stConsumos),1,archi);
                printf("\n se ha cargado el consumo con exito.");
            }


            printf("\nESC para salir, cualquier tecla para continuar. ");
            opcion=getch();
        }
        while (opcion!=ESC);

        fclose(archi);
    }
    else{
        printf("\nintente nuevamente.");
         FILE * archi = fopen (archivo, "ab");
         fclose(archivo);
    }




}


int validacionDiaMesAnio (int anio,int mes,int dia)
{
    ///meses 1 3 5 7 8 10 12 = 31 --- meses 4 6 9 11 = 30 ---- mes 2 = 28 / biciesto 29 .. devuelve un flag = 1 si la fecha es correcta
    int flag = 0;

    if(mes >=1 && mes <=12)
    {
        switch (mes)
        {
        case 1:                         ///ENERO
        {
            flag=validardia31(dia);

        }
        break;

        case 2:                         ///FEBRERO
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

        case 3:                                    ///MARZO
        {
            flag=validardia31(dia);
        }
        break;

        case 4:                                     ///ABRIL
        {
            flag=validardia30(dia);

        }
        break;

        case 5:                                    /// MAYO
        {
            flag=validardia31(dia);

        }
        break;

        case 6:                                  ///JUNIO
        {
            flag=validardia30(dia);

        }
        break;

        case 7:                                 ///JULIO
        {
            flag=validardia31(dia);

        }
        break;

        case 8:                                 ///AGOSTO
        {
            flag=validardia31(dia);

        }
        break;

        case 9:                                 ///SEPTIEMBRE
        {
            flag=validardia30(dia);

        }
        break;

        case 10:                                ///OCTUBRE
        {
            flag=validardia31(dia);

        }
        break;

        case 11:                                ///NOVIEMBRE
        {
            flag=validardia30(dia);

        }
        break;

        case 12:                                ///DICIEMBRE
        {
            flag=validardia31(dia);

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
}

void mostrarConsumos(stCliente cliente, char archivo[])
{
    ///mostrar los datos del cliente y los datos consumidos hasta el momento
    stConsumos consumo;
    int acum=0;

    FILE *archicons = fopen(archivo, "rb");

    if (archicons)
    {
        consultaCliente(cliente);

        while(fread(&consumo,sizeof(stConsumos),1,archicons)>0)
        {
            if(cliente.id==consumo.idCliente)
            {
                muestraUnConsumo(consumo);
                acum=acum+consumo.datosConsumidos;
            }
        }
        printf("el total de datos consumidos es de : %d MB",acum);
        system("pause");
    }

    fclose(archicons);
}

void muestraUnConsumo(stConsumos cons)
{
    printf("\nID.....................: %d",cons.id);
    printf("\nfecha..................:  %d/%d/%d",cons.dia,cons.mes,cons.anio);
    printf("\ndatos consumidos (MB)..: %d",cons.datosConsumidos);


    if (cons.baja==1)
    {
        printf("\nel consumo se encuentra dado de baja.");
    }
    else
    {
        printf("\nEl consumo se encuentra activo.");
    }
    printf("\n\n========================================================================================\n");


}

void muestraConsFecha(char archivo[],int dia,int anio,int mes,int flag)
{stConsumos consumo;

FILE* archi = fopen(archivo,"rb");

if (archi)
{
    while(fread(&consumo,sizeof(stConsumos),1,archi)>0){

        if (flag==3 && consumo.anio == anio && consumo.dia == dia && consumo.mes == mes)
        {
            muestraUnConsumo(consumo);
        }
        if (flag==2 && consumo.anio == anio && consumo.mes == mes)
        {
            muestraUnConsumo(consumo);
        }
        if (flag==1 && consumo.anio == anio)
        {
            muestraUnConsumo(consumo);
        }
}
fclose(archi);
system("pause");
}
}

int validacionConsumo (FILE * archi, stConsumos a)
{
    int flag = 1;
    stConsumos b;
  //  FILE* archi = fopen(archivo, "r+b");
    if (archi)
    {
        rewind(archi);

    while(flag==1 && fread(&b,sizeof(stConsumos),1,archi)>0){

            if(a.idCliente == b.idCliente && a.anio == b.anio && a.mes == b.mes && a.dia == b.dia)
            {
                flag = 2;
                //printf("\n\n%d (1)... %d (2)...===     . ",a.datosConsumidos,b.datosConsumidos);

                b.datosConsumidos = a.datosConsumidos + b.datosConsumidos;
                fseek(archi,sizeof(stConsumos)*(-1),SEEK_CUR);
                fwrite(&b, sizeof(stConsumos),1,archi);
                printf("\n se ha cargado el consumo con exito.");
            }
            }
        //fclose(archi);
     }


    else{

        printf("el archivo no se pudo abrir");
        system("pause");
    }
    return flag;
}

void listadoConsumos(char archivo[])
{
    system("cls");
    stConsumos consumo;

    FILE * archi =fopen(archivo,"rb");

    if (archi)
    {
        while(fread(&consumo,sizeof(stConsumos),1,archi)>0)
        {
            muestraUnConsumo(consumo);
        }
    }

    system("pause");
    fclose(archi);

}
