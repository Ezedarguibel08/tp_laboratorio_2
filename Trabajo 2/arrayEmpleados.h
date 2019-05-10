#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int vacio;

}eEmpleado;
typedef struct
{
    int idSector;
    char descripcion[51];
    float salarioSector;

}eSectores;

void iniEmpleados(eEmpleado[], int);
char opciones(char[]);

int nuevoEmpleado(eEmpleado[], int, int);
int buscarLibre(eEmpleado[], int);
void modificarEmpleado(eEmpleado[], int, int);
int buscarPorId(eEmpleado[], int, int);
void opcionesCambio(eEmpleado[], int, char);
int bajaEmpleado(eEmpleado[], int, int);
int removerEmpleado(eEmpleado[], int, int);


void ingresoPalabra(char[], char[]);
void cambioLetras(char[]);
float ingresoNumero(char[]);

void mostrarEmpleados(eEmpleado[], eSectores[], int, int, int);
void ordenarEmpleados(eEmpleado[], int, int);
void orden(eEmpleado[], int, int);
int calcularSueldoSectores(eEmpleado[], eSectores[], int, int);

void cargarDatos(eEmpleado[], eSectores[], int);
void mostrarDatos(eEmpleado, eSectores[]);
void cargaSueldos(eEmpleado[], eSectores[], int, int, int);
