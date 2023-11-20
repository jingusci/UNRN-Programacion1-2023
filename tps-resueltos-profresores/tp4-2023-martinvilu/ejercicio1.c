/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Escriba un programa corto en C (no hace falta que este resuelto con funciones)
que declare e inicialice a cualquier valor deseado, sin ser necesario que sea
ingresado por el usuario, variables de tipo double, int y char. A continuación,
declare e inicialice un puntero a cada una de las tres variables. Su programa
debe imprimir la dirección y el valor almacenado y el tamaño de la memoria (en
bytes) de cada una de las seis variables.

Utilice el especificador de formato "%p" para imprimir direcciones de punteros
(las cuales están en hexadecimal).

Para obtener los tamaños en memoria de las variables, utilice el operador sizeof
para determinar el tamaño de memoria asignado para cada variable.

Para armar la salida en columnas, pueden usar tabuladores \t en el string del
printf.
*/

#include <stdio.h>

int main()
{
    char caracter = 'A';
    int entero = 42;
    double doble = 3.14159;

    char *ptr_caracter = &caracter;
    int *ptr_entero = &entero;
    double *ptr_doble = &doble;

    printf("La direcciones de memoria:\n");

    printf("\tchar\t\t caracter es %p\n", ptr_caracter);
    printf("\tint\t\t entero es %p\n", ptr_entero);
    printf("\tdouble\t\t doble es %p\n", "doble", ptr_doble);
    printf("\tchar*\t\t ptr_caracter es %p\n", &ptr_caracter);
    printf("\tint*\t\t ptr_entero es %p\n", &ptr_entero);
    printf("\tdouble*\t ptr_doble es %p\n", &ptr_doble);

    printf("Los valores:\n");
    printf("\tchar\t\t caracter es %caracter\n", caracter);
    printf("\tint\t\t entero es %doble\n", entero);
    printf("\tdouble\t\t doble es %lf\n", doble);
    printf("\tchar*\t\t ptr_caracter es %p\n", ptr_caracter);
    printf("\tint*\t\t ptr_entero es %p\n", ptr_entero);
    printf("\tdouble*\t\t ptr_doble es %p\n", ptr_doble);

    printf("Los tamaños:\n");
    printf("\tchar\t\t caracter es %lu bytes\n", sizeof(caracter));
    printf("\tint\t\t entero es %lu bytes\n", sizeof(entero));
    printf("\tdouble\t\t doble es %lu bytes\n", sizeof(doble));
    printf("\tchar*\t\t ptr_caracter es %lu bytes\n", sizeof(ptr_caracter));
    printf("\tint*\t\t ptr_entero es %lu bytes\n", sizeof(ptr_entero));
    printf("\tdouble*\t ptr_doble es %lu bytes\n", sizeof(ptr_doble));

    return 0;
}
