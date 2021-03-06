#include "header_tpfinal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define ESC 27
#include "gotoxy.h"
#include <windows.h>

//#include "consumos_header.h"
stCliente altaUnCliente(int id,FILE * archi)
{
    int flag=0;
    stCliente cliente;

    cliente.id = id;

    system("cls");

    printf("\nnumero de cliente: ");
    scanf("%d",&cliente.nroCliente);
    flag=validacionNroCliente(cliente,archi);
    if (flag==0)
    {

        fflush(stdin);
        printf("Nombre: ");
        gets(cliente.nombre);

        fflush(stdin);
        printf("Apellido: ");
        gets(cliente.apellido);

        fflush(stdin);
        printf("DNI: ");
        gets(cliente.dni);
        if(flag==0)
        {
            flag=buscarPorDni(cliente.dni,archi,1);
        }

        if(flag==0)
        {
            fflush(stdin);
            printf("Email: ");
            gets(cliente.email);

            fflush(stdin);
            printf("Domicilio: ");
            gets(cliente.domicilio);

            fflush(stdin);
            printf("Movil: ");
            gets(cliente.movil);

            cliente.eliminado = 0;
        }
    }
    if (flag ==1)
    {
        printf("el cliente ya se encuentra en los registros.");
        // system("pause");
        cliente.nroCliente=0;
    }

    return cliente;
}


void borclien()
{
    FILE *arch =fopen("clientes.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("\ningrese el id a eliminar: ");
    int cod;
    fflush(stdin);
    scanf("%d",&cod);

    stCliente cliente;

    FILE *nuevo = fopen("cliente.tmp","ab");
    if (arch==NULL)
        exit(1);

    int existe=0;
    fread(&cliente, sizeof(stCliente), 1, arch);
    while(!feof(arch))
    {
        if (cod==cliente.id)
        {
            printf("Eliminado %i %s %s\n", cliente.id, cliente.nombre, cliente.dni);
            system("pause");
            existe=1;
        }
        else
        {
            fwrite(&cliente, sizeof(stCliente), 1, nuevo);
        }
        fread(&cliente, sizeof(stCliente), 1, arch);
    }
    if (existe==0)
    {
        printf("\nNo existe un cliente con ese id\n");
        system("pause");
    }
    fclose(arch);
    fclose(nuevo);

    remove("clientes.dat");
    rename("cliente.tmp", "clientes.dat");
}

void cargaClienteArchivo(char nombreArchivo[])
{
    int flag =0;
    int static valido=0;
    char salida='s';
    valido = contarRegistros(clientes,1);
    stCliente cliente;

    FILE* archi=fopen(nombreArchivo,"r+b");

    if(archi)
    {

        do
        {
            if(flag==0)
            {
                valido++;
            }
            flag =0;
            cliente=altaUnCliente(valido,archi);

            if(cliente.nroCliente!=0)
            {
                fwrite(&cliente,sizeof(stCliente),1,archi);
                printf("\nEl alta ha sido exitosa.");
            }
            else
            {
                flag=1;
            }
            printf("\npresione una tecla para cargar un nuevo cliente, ESC para volver al menu\n");
            fflush(stdin);
            salida=getch();

        }
        while(salida!=ESC);
    }

    else
        printf("el archivo no pudo abrirse,");

    fclose(archi);

}

int validacionNroCliente(stCliente b, FILE * archi)
{
    int flag=0;
    stCliente a;
    rewind(archi);


    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi) && flag==0)
        {

            if(b.nroCliente==a.nroCliente)
            {
                flag = 1;
            }

        }
    }
    else
        printf("el archivo no pudo ser abierto");
    return flag;
    fseek(archi,0,SEEK_END);

}

int contarRegistros(char archivo[],int tipoDato)
{
    FILE *archi=fopen(archivo,"r");
    int registros=0;
    if (archi)
    {
        if (tipoDato==1)
        {
            fseek(archi,0,SEEK_END);
            registros=ftell(archi)/sizeof(stCliente);
        }
        else if (tipoDato==0)
        {
            fseek(archi,0,SEEK_END);
            registros=ftell(archi)/sizeof(stConsumos);
        }
    }
    else
        printf("el archivo no pudo abrirse,");
    return registros;
}



void consultaCliente(stCliente cliente)
{
    printf("\nNumero de id........: %d",cliente.id);
    printf("\nNumero de cliente...: %d",cliente.nroCliente);
    printf("\nNombre............: %s",cliente.nombre);
    printf("\nApellido..........: %s",cliente.apellido);
    printf("\nDNI...............: %s",cliente.dni);
    printf("\nEmail.............: %s",cliente.email);
    printf("\nDomicilio.........: %s",cliente.domicilio);
    printf("\nMovil.............: %s",cliente.movil);

    if(cliente.eliminado == 0)
        printf("\nEl usuario se encuentra activo");
    else
        printf("\nEl usuario se encuentra dado de baja");
    printf("\n\n========================================================================================\n");

}
void muestraArchivoClientes(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            consultaCliente(a);
        }
        fclose(archi);
        system("pause");
    }

}


void mostrarMenu()
{
    int i;
    printf("%c", 201);
    for (i=0; i<34; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 187);
    gotoxy(0,1);
    printf("%c\tFunciones Clientes.\n",186);
    gotoxy(35,1);
    printf("%c",186);

    gotoxy(1,2);
    for (i=1; i<35; i++)
    {
        printf("%c", 196);
    }

    gotoxy(0,2);
    printf("%c\n",186);
    gotoxy(35,2);
    printf("%c",186);

    gotoxy(0,3);
    printf("%c1)Carga nuevo cliente.\n",186);
    gotoxy(35,3);
    printf("%c",186);

    gotoxy(0,4);
    printf("%c2)Listado clientes.\n",186);
    gotoxy(35,4);
    printf("%c",186);

    gotoxy(0,5);
    printf("%c3)Consulta clientes.\n",186);
    gotoxy(35,5);
    printf("%c",186);

    gotoxy(0,6);
    printf("%c4)Modificar cliente.\n",186);
    gotoxy(35,6);
    printf("%c",186);

    gotoxy(0,7);
    printf("%c\n",186);
    gotoxy(35,7);
    printf("%c",186);

    gotoxy(1,7);
    for (i=1; i<35; i++)
    {
        printf("%c", 196);
    }

    gotoxy(0,8);
    printf("%c\tFunciones Consumos.\n",186);
    gotoxy(35,8);
    printf("%c",186);

    gotoxy(0,9);
    printf("%c\n",186);
    gotoxy(35,9);
    printf("%c",186);

    gotoxy(1,9);
    for (i=1; i<35; i++)
    {
        printf("%c", 196);
    }

    gotoxy(0,10);
    printf("%c5)Carga nuevo consumo.\n",186);
    gotoxy(35,10);
    printf("%c",186);

    gotoxy(0,11);
    printf("%c6)mostrar consumos de un cliente.\n",186);
    gotoxy(35,11);
    printf("%c",186);

    gotoxy(0,12);
    printf("%c7)Consulta de Consumos.\n",186);
    gotoxy(35,12);
    printf("%c",186);

    gotoxy(0,13);
    printf("%c8)Listado de Consumos.\n",186);
    gotoxy(35,13);
    printf("%c",186);

    gotoxy(0,14);
    printf("%c9)dar de baja un consumo.\n",186);
    gotoxy(35,14);
    printf("%c",186);
    gotoxy(35,15);
    printf("%c",186);
    gotoxy(0,15);
    printf("%c",186);
    gotoxy(1,15);
    for (i=1; i<35; i++)
    {
        printf("%c", 196);
    }
    gotoxy(0,16);
    printf("%c",186);
    gotoxy(35,17);
    printf("%c",186);
    gotoxy(35,16);
    printf("%c",186);
    gotoxy(0,16);

    printf("%cESC Salir.\n",186);

    printf("%c", 200);
    for (i=0; i<34; i++)
    {
        printf( "%c", 205);
    }
    printf("%c",188);


}
void seleccion()
{int opc=0;
    char opcion;
    do
    {
        system("cls");
        mostrarMenu();
        gotoxy(0,20);
        fflush(stdin);
        opcion=getch();
        switch(opcion)
        {
        case 27:
            break;
                case 48:
        {
           cargaRandCons(consumos,clientes);
        }
        break;
        case 49:
        {
            cargaClienteArchivo(clientes);
        }
        break;
        case 50:
            muestraArchivoClientes(clientes);
            break;
        case 51:
        {
            menuModificar();
        }
        break;
        case 52:
        {
            menuModificar();
        }
        break;
        case 53:
        {
            cargaConsumoArchivo(consumos,clientes);
        }
        break;
        case 54:
        {
            menuModificar();
        }
        break;
        case 55:
        {
            menuBuscarConsumo();
        }
        break;
        case 56:
        {
            listadoConsumos(consumos,clientes);
        }
        break;
        case 57:
        {
            system("cls");
            printf("\ningrese el id del consumo: ");
            scanf("%d",&opc);
           modificarAltaBajaCons(consumos,clientes,opc);
        }
        break;
        default:
            printf("Opcion incorrecta \n");
            break;
        }
    }
    while(opcion != ESC);
}

void menuBuscarConsumo()
{
    char opcion;
    int anio;
    int dia;
    int mes;
    system("cls");
    printf("\n1. Busqueda por cliente.");
    printf("\n2. Busqueda por fecha.");
    printf("\nESC para volver.\n");

    opcion=getch();

    switch(opcion)
    {
    case 27:
        break;

    case 49:
    {
        menuModificar();
    }
    break;
    case 50:
    {
        system("cls");
        printf("\n1. Busqueda por a%co.",164);
        printf("\n2. Busqueda por mes.");
        printf("\n3. Busqueda por dia.");
        opcion=getch();

        switch(opcion)
        {
        case 27:
            break;
        case 49:
        {
            printf("\ningrese el a%co a buscar: "),164;
            scanf("%d",&anio);
            muestraConsFecha(consumos,clientes,0,anio,0,1);
        }
        break;
        case 50:
        {
            printf("\ningrese el a%co a buscar: "),164;
            scanf("%d",&anio);
            printf("\ningrese el mes a buscar: ");
            scanf("%d",&mes);
            muestraConsFecha(consumos,clientes,0,anio,mes,2);
        }
        break;
        case 51:
        {
            printf("\ningrese el a%co a buscar: "),164;
            scanf("%d",&anio);
            printf("\ningrese el mes a buscar: ");
            scanf("%d",&mes);
            printf("\ningrese el dia a buscar: ");
            scanf("%d",&dia);
            muestraConsFecha(consumos,clientes,dia,anio,mes,3);
        }
        break;
        }

    }
    break;


    }


}
void menuModificar()
{
    int opcion;
    char valor[9];

    system("cls");
    printf("\n1. Busqueda por numero de cliente.");
    printf("\n2. Busqueda por numero de DNI");
    printf("\n3: volver.\n\nOpcion: ");
    scanf("%d",&opcion);
    FILE* archi = fopen(clientes,"r+b");
    switch(opcion)
    {
    case 1:
    {
        printf("\nIngrese el numero de cliente: ");
        scanf("%d",&opcion);
        if(archi)
        {
            buscarPorNroCliente(opcion,archi);
        }
    }
    break;
    case 2:
    {
        printf("\ningrese el dni a buscar, 0 para salir.\n");
        fflush(stdin);
        gets(valor);

        if(archi)
        {
            buscarPorDni(valor,archi,3);
        }

    }
    break;
    case 3:
    {}
    break;
    default:
        break;
    }
    if(archi)
    {
        fclose(archi);
    }
}
void seleccionModificar(int id)
{
    int opcion=0;
    //char valor[45];

    printf("\n1. Nombre");
    printf("\n2. Apellido");
    printf("\n3. DNI");
    printf("\n4. Email");
    printf("\n5. Domicilio");
    printf("\n6. Movil");
    printf("\n7. Alta/baja");
    printf("\n0. Volver.\n");
    scanf("%d",&opcion);

    if(opcion!=0)
    {
        modificarCliente(clientes,id,opcion);
    }

}
void modificarCliente(char archivo[],int id,int flag)
{
    FILE* archi = fopen(archivo,"r+b");
    stCliente cliente;
    if (archi)
    {

        fseek(archi,sizeof(stCliente)*(id-1),0);
        fread(&cliente,sizeof(stCliente),1,archi);

        switch(flag)
        {
        case 1:
        {
            cliente=modificarNombre(cliente);
        }
        break;
        case 2:
        {
            cliente=modificarApellido(cliente);
        }
        break;
        case 3:
        {
            cliente=modificarDNI(cliente,archi);

        }
        break;
        case 4:
        {
            cliente=modificarEmail(cliente);
        }
        break;
        case 5:
        {
            cliente=modificardomicilio(cliente);
        }
        break;
        case 6:
        {
            cliente=modificarMovil(cliente);
        }
        break;
        case 7:
        {
            cliente=modificarAltaBaja(cliente);
        }
        break;

        }
        if(cliente.nroCliente !=0)
        {

            fseek(archi,sizeof(stCliente)*(id-1),0);
            consultaCliente(cliente);
            system("pause");
            fwrite(&cliente,sizeof(stCliente),1,archi);
        }
        else
        {
            printf("\nEl DNI ingresado ya existe.\n");
            system("pause");
        }

        fclose(archi);

    }

}
stCliente modificarNombre(stCliente cliente)
{
    printf("\ningrese el nuevo nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    return cliente;
}
stCliente modificardomicilio(stCliente cliente)
{
    printf("\ningrese el nuevo domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

    return cliente;
}
stCliente modificarApellido(stCliente cliente)
{
    printf("\ningrese el nuevo Apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

    return cliente;
}
stCliente modificarDNI(stCliente cliente,FILE* archi)
{
    int flag=0;
    printf("\ningrese el nuevo DNI: ");
    fflush(stdin);
    gets(cliente.dni);
    flag=buscarPorDni(cliente.dni,archi,1);

    if(flag==1)
    {
        cliente.nroCliente=0;
    }

    return cliente;
}
stCliente modificarMovil(stCliente cliente)
{
    printf("\ningrese el nuevo movil: ");
    fflush(stdin);
    gets(cliente.movil);

    return cliente;
}
stCliente modificarEmail(stCliente cliente)
{
    printf("\ningrese el nuevo Email: ");
    fflush(stdin);
    gets(cliente.email);

    return cliente;
}
stCliente modificarAltaBaja(stCliente cliente)
{
    char alta;
    // int flag=0;
    if (cliente.eliminado==0)
    {
        printf("el cliente se encuentra activo, quiere darle de baja? y/n");
        alta=getch();

    }
    else
    {
        printf("el cliente se encuentra dado de baja, quiere darle el alta? y/n");
        alta=getch();
    }

    if (cliente.eliminado == 0 && alta=='y')
        cliente.eliminado=1;
    else if(cliente.eliminado==1 && alta=='y')
        cliente.eliminado=0;

    return cliente;
}
int buscarPorDni(char dni[],FILE * archi,int param)
{
    system("cls");
    rewind(archi);
    stCliente a;
    int opcion = 0;
    int id;
    int flag=0;
    if(archi)
    {
        while(flag==0 && fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(strcmpi(dni,a.dni)==0)
            {
                flag=1;
                fseek(archi,0,SEEK_END);
                if(param ==2 || param==3)
                {
                    fclose(archi);
                    consultaCliente(a);
                    id = a.id;
                }
            }
        }


        if(param==3)
        {
            if (flag==0)
            {
                printf("\nEl DNI ingresado no existe en nuestros archivos.\n\n");
                system("pause");
            }

            if (flag==1)
            {
                printf("\n1: modificar cliente.");
                printf("\n2: consultar consumos de este cliente.");
                printf("\n3: volver.\n\nOpcion: ");
                scanf("\n%d",&opcion);


                if (opcion ==1)
                {
                    seleccionModificar(id);
                }
                else if(opcion ==2)
                {
                    mostrarConsumos(a,consumos,clientes);
                }
            }
        }
    }
    return flag;
}

stCliente buscarPorNroCliente(int nrocliente,FILE * archi)
{
    system("cls");
    rewind(archi);
    stCliente a;
    int opcion = 0;
    int id;
    int flag=0;
    if(archi)
    {
        while(flag==0 && fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(nrocliente==a.nroCliente)
            {
                flag=1;
                consultaCliente(a);
                id=a.id;
            }
        }
        fseek(archi,0,SEEK_END);

        if (flag==0)
        {
            printf("\nEl Numero de cliente ingresado no existe en nuestros archivos.\n\n");
            system("pause");
        }
        if (flag==1)
        {

            printf("\n1: modificar cliente.");
            printf("\n2: consultar consumos de este cliente.");
            printf("\n3: volver.\n\nOpcion: ");
            scanf("\n%d",&opcion);


            switch(opcion)
            {
            case 1:
            {
                seleccionModificar(id);
            }
            break;
            case 2:
                {
                    mostrarConsumos(a,consumos,clientes);
                }
                break;
            case 3:
                break;
            default:
            {
                printf("el numero ingresado no es valido");
            }
            break;
            }

        }

    }
    return a;
}
