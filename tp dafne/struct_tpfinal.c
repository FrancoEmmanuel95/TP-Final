#include "header_tpfinal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define clientes "clientes.dat"
#include <conio.h>
#define ESC 27

#include "consumos_header.h"
stCliente altaUnCliente(int id)
{
    int ncl=contarRegistros(clientes);
    int flag=0;
    stCliente cliente;

    cliente.id = id;

    system("cls");

    printf("\nEl ultimo nro cliente es: %d\n",ncl);

    printf("\nnumero de cliente: ");
    scanf("%d",&cliente.nroCliente);
    flag=validacionNroCliente(cliente,clientes);

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
        flag=validacionDni(cliente.dni,clientes);


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
    int static valido=0;
    char salida='s';
    valido = contarRegistros(clientes);
    stCliente cliente;

    FILE* archi=fopen(nombreArchivo,"ab");

    if(archi)
    {

        do
        {
            valido++;
            cliente=altaUnCliente(valido);

            if(cliente.nroCliente!=0)
            {
                fwrite(&cliente,sizeof(stCliente),1,archi);
                printf("\nEl alta ha sido exitosa.");
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

stCliente buscarPorDni(char dni[],char archivo[])
{
    system("cls");
  //  int reg=contarRegistros(clientes);
    FILE* archi = fopen(archivo, "rb");
    stCliente a;
    int opcion = 0;
    int flag=0;
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0 && flag==0)
        {
            if(strcmpi(dni,a.dni)==0)
            {
                flag=1;
                consultaCliente(a);
            }
        }
        fclose(archi);
        if (flag==1)
        {
            //  do
            // {
            printf("\n1: modificar cliente.");
            printf("\n2: consultar consumos de este cliente.");
            printf("\n3: volver.");
            scanf("\n%d",&opcion);
            // }
            // while (opcion!=3);

            if (opcion ==1)
            {
               seleccionModificar(a.id);
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
    int flag=0;
    if(archi)
    {
        while(flag==0 && fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(nrocliente==a.nroCliente)
            {
                flag=1;
                consultaCliente(a);
            }
        }
        fclose(archi);
        if (flag==1)
        {
             do
             {
            printf("\n1: modificar cliente.");
            printf("\n2: consultar consumos de este cliente.");
            printf("\n3: volver.");
            scanf("\n%d",&opcion);


            switch(opcion)
            {
            case 1:
            {
                    seleccionModificar(a.id);
            }
            break;
            case 2:
                break;
            case 3:
                break;
             default:{
                    printf("el numero ingresado no es valido");
            }
                break;
            }
             }
            while (opcion!=3);
        }

    }

    return a;
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
    printf("1)Carga cliente\n");
    printf("2)opcion 2\n");
    printf("3)opcion 3\n");
    printf("4)opcion 4\n");
    printf("5)opcion 5\n");
    printf("6)opcion 6\n");
    printf("7)Busqueda cliente.\n");
    printf("8)opcion 8\n");
    printf("9)opcion 9\n");
    printf("10)opcion 10\n");
    printf("\n");
}
void seleccion()
{
    int registros=0;
    char valor[9];
   // char st[3]= "0";
    int opcion;
    do
    {
        system("cls");
        mostrarMenu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 0:
            break;
        case 1:
        {
            cargaClienteArchivo(clientes);
        }
        break;
        case 2:
            muestraArchivoClientes(clientes);
            break;
        case 3:
        {
            registros=contarRegistros(clientes);
            printf("\n%d\n",registros);
            system("pause");
        }
        break;
        case 4:
        {

            // modificarCliente(clientes,48);
        }
        break;
        case 5:
            borclien();
            break;
        case 6:
            printf("\ningrese el id: ");
            scanf("%d",&registros);
            // buscarporID(clientes,registros);
            break;
        case 7:
        {
          //  do
            // {
                system("cls");
                printf("\n1. Busqueda por numero de cliente.");
                printf("\n2. Busqueda por numero de DNI");
                printf("\n3. Volver");
                scanf("%d",&registros);

                switch(registros){
                case 1:{
                        printf("\nIngrese el numero de cliente");
                        scanf("%d",&registros);
                        buscarPorNroCliente(registros,clientes);
                        }
                    break;
                case 2:{
                                 printf("\ningrese el dni a buscar, 0 para salir.\n");
                 fflush(stdin);
                 gets(valor);
                // if (strcmpi(valor,st)!=0)
                     buscarPorDni(valor,clientes);
                }
                    break;
                case 3:{}
                    break;
                 default:
                    break;



                     }


         //    }*/
         //   while(strcmpi(valor,st)!=0);

        }
        break;
        case 8:
            printf("ingrese el id");
            scanf("%d",&registros);
            seleccionModificar(registros);

            break;
        case 9:
            printf("Usted selecciono %i \n",opcion);
            break;
        case 10:
            printf("Usted selecciono %i \n",opcion);
            break;
        default:
            printf("Opcion incorrecta \n");
            break;
        }
    }
    while(opcion != 0);
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

      if(opcion!=0){
      modificarCliente(clientes,id,opcion);}

}
void modificarCliente(char archivo[],int id,int flag)
{
    FILE* archi = fopen(archivo,"r+b");
    stCliente cliente;
    //printf("\n\n %d\n\n",id);
    //  system("pause");
    if (archi)
    {


        fseek(archi,sizeof(stCliente)*(id-1),0);
        fread(&cliente,sizeof(stCliente),1,archi);
      //  consultaCliente(cliente);

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

        fseek(archi,sizeof(stCliente)*(id-1),0);
       consultaCliente(cliente);
        system("pause");
        fwrite(&cliente,sizeof(stCliente),1,archi);
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
    printf("\ningrese el nuevo DNI: ");
    fflush(stdin);
    gets(cliente.dni);

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

/*stConsumos altaConsumos(char archivo [],char archivoCliente clientes, stConsumos consumo, stCliente clientes)
{
    ///relaciona el id del cliente en struct cliente con id cliente en struct consumo y le agrega el consumo si flag = 1 en funcion validar fecha
    stConsumos consumo;
    stCliente clientes;

    FILE *archi = fopen(nombrearchivo, "ab");
    FILE *archi = fopen(archivoCliente, "rb");
    int idcl= clientes.id

    ///agregar una condicion que si la carga de consumos es igual al id de consumo que llame a la funcion int sumarConsumos

    if (archi)
    {
        consumo.idCliente = idcl;
        c = validacionDiaMesAnio(stConsumos consumo);



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
        } else
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
            }else if (dia >= 1 && dia <=28)
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

void mostrarConsumos(stConsumos consumos, stCliente clientes, char archivoCliente[], char archivo[])
{
    ///mostrar los datos del cliente y los datos consumidos hasta el momento
    stConsumos consumos;
    stCliente clientes;

    FILE *archivo = fopen(archivoConsumos, "rb");
    FILE *archivo = fopen(archivoCliente, "rb");

    printf("\nNro Cliente.............", consumos.idCliente);
    muestraArchivoClientes(archivoCliente);
    printf("\nDatos Consumidos........", consumos.datosConsumidos);
    if(clientes.eliminado == 0)
    {
        printf("\nCLIENTE ACTIVO");
    } else
    {
        printf("\nCLIENTE INACTIVO");
    }


    fclose(archivo);
}

int sumaConsumos (stConsumos consumos, char archi[])
{
    stConsumos consumos;
    FILE *archi = fopen(archivoCliente, "rb");

    int acum = 0;

    ///buscar los consumos del mismo id y acumularlos, que la funcion te devuelva la cantidad de consumos

    while ()
}
*/
