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

#include "consumos_header.h"
stCliente altaUnCliente(int id)
{
    int flag=0;
    stCliente cliente;

    cliente.id = id;

    system("cls");

    printf("\nnumero de cliente: ");
    scanf("%d",&cliente.nroCliente);
    flag=validacionNroCliente(cliente,clientes);
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
            flag=validacionDni(cliente.dni,clientes);
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

/*stCliente ordPorID()
{
    int validos=contarRegistros(clientes);
    stcliente arraycliente[validos]



}*/

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
    valido = contarRegistros(clientes);
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
            cliente=altaUnCliente(valido);

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

int validacionNroCliente(stCliente b, char archivo[])
{
    int flag=0;
    stCliente a;
    FILE* archi = fopen(archivo,"rb");


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

}

int validacionDni(char dni[], char archivo[])
{
    int flag=0;
    stCliente a;
    FILE* archi = fopen(archivo,"rb");


    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi) && flag==0)
        {

            if(strcmpi(dni,a.dni)==0)
            {
                flag = 1;
            }

        }
    }
    else
        printf("el archivo no pudo ser abierto");
    return flag;

}

int contarRegistros(char archivo[])
{
    FILE *archi=fopen(archivo,"r");
    int registros=0;
    if (archi)
    {
        fseek(archi,0,SEEK_END);
        registros=ftell(archi)/sizeof(stCliente);
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
    int cont=0;
    if(archi)
    {
        while(fread(&a, sizeof(stCliente), 1, archi)>0)
        {
            consultaCliente(a);
            if (cont==10)
            {
                cont=0;
            }
            else
            {
                cont++;
            }

        }
        system("pause");
        fclose(archi);
    }

}





/*stCliente buscarporID(char archivo[],int id)
{
    FILE* archi = fopen(archivo,"r+b");
    stCliente cliente;

    if (archi)
    {
        fseek(archi,sizeof(stCliente)*(id-1),0);
        fread(&cliente,sizeof(stCliente),1,archi);
       // consultaCliente(cliente);
        // cliente=modificardomicilio(cliente);
        // fseek(archi,sizeof(stCliente)*(id-1),0);
        // consultaCliente(cliente);
        system("pause");
        //    fwrite(&cliente,sizeof(stCliente),1,archi);
        fclose(archi);

    }
    return cliente;
}*/
void mostrarMenu()
{
    int i;
    printf("%c", 201);
    for (i=0; i<29; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n%c1)Carga nuevo cliente.\n",186);
    gotoxy(30,1);
    printf("%c",186);
    gotoxy(0,2);
    printf("%c2)Listado clientes.\n",186);

    gotoxy(30,2);
    printf("%c",186);
    gotoxy(0,3);
    printf("%c3)Consulta clientes.\n",186);

    gotoxy(30,3);
    printf("%c",186);
    gotoxy(0,4);
    printf("%c4)Modificar cliente.\n",186);
    gotoxy(30,4);
    printf("%c",186);
    gotoxy(0,5);
    printf("%c",186);
    gotoxy(0,6);
    printf("%c",186);
    gotoxy(30,5);
    printf("%c",186);
    gotoxy(30,6);
    printf("%c",186);
    gotoxy(0,6);

    printf("%cESC Salir.\n",186);

    printf("%c", 200);
    for (i=0; i<29; i++)
    {
        printf( "%c", 205);
    }
    printf("%c",188);


}
void seleccion()
{
    char opcion;
    do
    {
        system("cls");
        mostrarMenu();
        fflush(stdin);
        opcion=getch();
        switch(opcion)
        {
        case 27:
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
            // borclien();
            break;
        case 54:
            break;
        case 55:
        {

            break;
            case 56:
                break;
            case 57:

                break;
            default:
                printf("Opcion incorrecta \n");
                break;

            }
        }
    }
    while(opcion != ESC);
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

    switch(opcion)
    {
    case 1:
    {
        printf("\nIngrese el numero de cliente: ");
        scanf("%d",&opcion);
        buscarPorNroCliente(opcion,clientes);
    }
    break;
    case 2:
    {
        printf("\ningrese el dni a buscar, 0 para salir.\n");
        fflush(stdin);
        gets(valor);
        buscarPorDni(valor,clientes);
    }
    break;
    case 3:
    {}
    break;
    default:
        break;
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
            cliente=modificarDNI(cliente);

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
stCliente modificarDNI(stCliente cliente)
{
    int flag=0;
    printf("\ningrese el nuevo DNI: ");
    fflush(stdin);
    gets(cliente.dni);
    flag=validacionDni(cliente.dni,clientes);

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
stCliente buscarPorDni(char dni[],char archivo[])
{
    system("cls");
    FILE* archi = fopen(archivo, "rb");
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
                consultaCliente(a);
                id = a.id;
            }
        }
        fclose(archi);
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
        }
    }
    return a;
}

stCliente buscarPorNroCliente(int nrocliente,char archivo[])
{
    system("cls");
    // int reg=contarRegistros(clientes);
    FILE* archi = fopen(archivo, "rb");
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
        fclose(archi);
        if (flag==0)
        {
            printf("\nEl Numero de cliente ingresado no existe en nuestros archivos.\n\n");
            system("pause");

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


    }return a;
 }
