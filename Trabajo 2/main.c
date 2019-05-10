#include <stdio.h>
#include <stdlib.h>
#include "arrayEmpleados.h"
#define T 1000
#define S 3

int main()
{
    eEmpleado arrayEmpleados[T];
    eSectores arraySectores[S] = {{1,"Produccion"},{2,"RRHH"},{3,"Atencion al cliente"}};;
    int flag=0;
    char opcion;

    iniEmpleados(arrayEmpleados, T);

    do{
        opcion=opciones("1.Dar de alta a un empleado.\n2.Modificar un empleado.\n3.Dar de baja un empleado.\n4.Informar.\n5.Salir.\nQue quiere hacer: ");


        switch(opcion)
        {
            case'1':
                flag=nuevoEmpleado(arrayEmpleados, T, flag);

            break;
            case'2':
                modificarEmpleado(arrayEmpleados, T, flag);

            break;
            case'3':
                flag=bajaEmpleado(arrayEmpleados, T, flag);

            break;
            case'4':
                mostrarEmpleados(arrayEmpleados, arraySectores, T, S, flag);

            break;
            case'5':
                printf("Esta saliendo del programa...\n");
                system("pause");

            break;
            default:
                printf("Opcion Incorrecta...\n");
                system("pause");

            break;
        }

        system("cls");

    }while(opcion!='5');

    return 0;
}


