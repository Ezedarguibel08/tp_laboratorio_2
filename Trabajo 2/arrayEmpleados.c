#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmpleados.h"
#define VERD 0
#define FAL 1

char opciones(char mensaje[])
{
    char opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");

    return opcion;
}


void iniEmpleados(eEmpleado list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].vacio=VERD;

    }
}

int nuevoEmpleado(eEmpleado list[], int len, int flag)
{
    int i;

    i=buscarLibre(list, len);
    if(i!=-1)
    {
        list[i].id=i+1;

        ingresoPalabra(list[i].nombre, "Ingrese el nombre: ");
        ingresoPalabra(list[i].apellido, "Ingrese el apelldio: ");
        list[i].sector=ingresoNumero("Ingrese sector: \n1.Produccion\n2.RRHH\n3.Atencion al cliente\nEliga una opcion: ");
        while(list[i].sector!=1&&(list[i].sector!=2&&list[i].sector!=3))
        {
            list[i].sector=ingresoNumero("Reingrese sector\n1.Produccion\n2.RRHH\n3.Atencion al cliente\nEliga una opcion: ");

        }

        list[i].salario=ingresoNumero("Ingrese el sueldo: ");
        while(list[i].salario<0)
        {
            list[i].salario=ingresoNumero("Reingrese el sueldo: ");

        }

        list[i].vacio=FAL;

        system("cls");

        flag=flag+1;

    }

    return flag;
}

int buscarLibre(eEmpleado list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].vacio==0)
        {
            break;

        }

    }
    return i;
}

void modificarEmpleado(eEmpleado list[], int len, int flag)
{
    int id, indice;
    char opcion;

    if(flag!=0)
    {
        id=ingresoNumero("Ingrese ID: ");

        indice=buscarPorId(list, len, id);

        if(indice!=-1)
        {
            opcion=opciones("Que quiere cambiar?\n1.Modificar Nombre.\n2.Modificar Apelldio.\n3.Modificar Salario.\n4.Modificar Sector.\nEliga una opcion: ");
            opcionesCambio(list, indice, opcion);

        }
        else
        {
            printf("No se encontro ID.\n");

        }
    }
    else
    {
        printf("No hay datos ingresados.\n");

    }
    system("pause");
}

int buscarPorId(eEmpleado list[], int len, int id)
{
    int indice, i;

    indice=-1;

    for(i=0; i<len; i++)
    {
        if(id==list[i].id)
        {
            indice=i;
            break;

        }
    }

    return indice;
}


void opcionesCambio(eEmpleado list[], int indice, char opcion)
{
    switch(opcion)
    {
    case'1':
            ingresoPalabra(list[indice].nombre, "Reingrese nombre: ");

        break;
    case'2':
            ingresoPalabra(list[indice].apellido, "Reingrese apellido: ");

        break;
    case'3':
            list[indice].salario=ingresoNumero("Reingrese sueldo: ");
        while(list[indice].salario<0)
        {
            list[indice].salario=ingresoNumero("Reingrese sueldo:");

        }

        break;
    case'4':
            list[indice].sector=ingresoNumero("Reingrese  sector: \n1.Produccion.\n2.RRHH.\n3.Atencion al cliente.\nEliga una opcion: ");
        while(list[indice].sector<1&&list[indice].sector>3)
        {
            list[indice].sector=ingresoNumero("Reingrese sector: \n1.Produccion.\n2.RRHH.\n3.Atencion al cliente.\nEliga una opcion: ");

        }

        break;
    default:
        printf("Esta opcion no existe...\n");
        system("pause");

        break;
    }

}

void ingresoPalabra(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

    cambioLetras(buffer);
}
void cambioLetras(char buffer[])
{
    strlwr(buffer);
    buffer[0]=toupper(buffer[0]);
}

float ingresoNumero(char mensaje[])
{
    float bufferN;
    printf(mensaje);
    scanf("%f",&bufferN);

    return bufferN;
}

int bajaEmpleado(eEmpleado list[], int len, int flag)
{
    int id, r;

    if(flag!=0)
    {
        id=ingresoNumero("Ingrese ID: ");
        r=removerEmpleado(list, len, id);
        flag=flag+r;
        if(r!=-1)
        {
            printf("No se encontro ID.\n");

        }
    }
    else
    {
        printf("No hay datos ingresados.\n");
        system("pause");
    }

    return flag;
}

int removerEmpleado(eEmpleado list[], int len, int id)
{
    int i, loEncontro;
    char respuesta;

    loEncontro=0;

    for(i=0; i<len; i++)
    {
        if(id == list[i].id)
        {
            printf("Quiere eliminar a %s %s de la lista?(s/n).", list[i].nombre, list[i].apellido);
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                list[i].vacio=VERD;
                loEncontro = -1;
            }


            break;
        }

    }

    if(loEncontro==0)
    {
        printf("No se encontro ID.\n");
        system("pause");

    }
    return loEncontro;
}
void mostrarEmpleados(eEmpleado listEmpleados[], eSectores listSectores[], int len, int lenS, int flag)
{
    int totalEmpleados, order;

    totalEmpleados=0;

    if(flag!=0)
    {
        order=opciones("Elija ordenamiento.\n\n0.Ascendente.\n1.Descendente.\nEliga una opcion: ");
        ordenarEmpleados(listEmpleados, len, order);
        cargarDatos(listEmpleados, listSectores, len);
        totalEmpleados=calcularSueldoSectores(listEmpleados, listSectores, len, lenS);
        cargaSueldos(listEmpleados, listSectores, len, lenS, totalEmpleados);
        system("pause");

    }
    else
    {
        printf("No hay datos ingresados.\n");
        system("pause");

    }

}


void ordenarEmpleados(eEmpleado list[], int len, int order)
{
    int comp;
    int i,j;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            comp=stricmp(list[i].apellido,list[j].apellido);

            if(order==1&&(comp>0&&list[i].sector==list[j].sector))
            {
                orden(list, i, j);

            }else
            {
                if(order==0&&(comp<0&&list[i].sector==list[j].sector))
                {
                    orden(list, i, j);

                }
            }
        }
    }

}

void orden(eEmpleado list[], int i, int j)
{

    eEmpleado aux;

    strcpy(aux.nombre,list[i].nombre);
    strcpy(list[i].nombre,list[j].nombre);
    strcpy(list[j].nombre,aux.nombre);

    strcpy(aux.apellido,list[i].apellido);
    strcpy(list[i].apellido,list[j].apellido);
    strcpy(list[j].apellido,aux.apellido);

    aux.id=list[i].id;
    list[i].id=list[j].id;
    list[j].id=aux.id;

    aux.sector=list[i].sector;
    list[i].sector=list[j].sector;
    list[j].sector=aux.sector;

    aux.vacio=list[i].vacio;
    list[i].vacio=list[j].vacio;
    list[j].vacio=aux.vacio;

    aux.salario=list[i].salario;
    list[i].salario=list[j].salario;
    list[j].salario=aux.salario;

}

int calcularSueldoSectores(eEmpleado listEmpleados[], eSectores listSectores[], int len, int lenS)
{
    int i, j, contador;

    contador=0;
    for(i=0; i<lenS; i++)
    {
        listSectores[i].salarioSector=0;

    }

    for(j=0; j<lenS; j++)
    {

        for(i=0; i<len; i++)
        {
            if(listEmpleados[i].sector==listSectores[j].idSector&&listEmpleados[i].vacio==FAL)
            {
                listSectores[j].salarioSector=listEmpleados[i].salario+listSectores[j].salarioSector;
                contador++;
            }
        }
    }

    return contador;
}

void cargaSueldos(eEmpleado listEmpleados[],eSectores listSectores[], int len, int lenS, int contador)
{
    int i, superarPromedio;
    float sueldototal, sueldoPromedio;

    sueldoPromedio=0;
    superarPromedio=0;
    sueldototal=0;

    for(i=0; i<lenS; i++)
    {
        sueldototal=listSectores[i].salarioSector+sueldototal;

    }

    sueldoPromedio=sueldototal/contador;

    for(i=0; i<len; i++)
    {
        if(listEmpleados[i].salario>sueldoPromedio&&listEmpleados[i].vacio==FAL)
        {
            superarPromedio++;

        }
    }

    printf("\nSueldo total: %.2f\n",sueldototal);
    printf("Sueldo promedio: %.2f\n",sueldoPromedio);
    printf("Cantidad de empleados que estan por encima del promedio : %d\n", superarPromedio);
    printf("\nSueldo total por sector: \n");

    for(i=0; i<lenS; i++)
    {
        printf("%s: %.2f\n",listSectores[i].descripcion,listSectores[i].salarioSector);

    }


}

void cargarDatos(eEmpleado list[], eSectores listSectores[], int len)
{
    int i;

    printf("ID: |Nombre:  |Apellido:  |Sector: |Sueldo:\n");

    for(i=0; i<len; i++)
    {
        if(list[i].vacio==FAL)
        {
            mostrarDatos(list[i], listSectores);

        }
    }


}

void mostrarDatos(eEmpleado list, eSectores listSectores[])
{
    int i;
    char descripcion[20];

    for(i=0; i<3; i++)
    {
        if(list.sector==listSectores[i].idSector)
        {
            strcpy(descripcion,listSectores[i].descripcion);
            break;

        }
    }

    printf("%2d |%5s |%5s |%5s |%.2f\n", list.id, list.nombre, list.apellido, descripcion, list.salario);

}
