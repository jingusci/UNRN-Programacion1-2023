/*
Ejercicio 1 - Valores Puntuales
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio1.c"

// funcion para testear las funciones del ejercicio 1
void ejercicio1_main()
{
    int *numero1 = reserva_entero(9);
    int *numero2 = reserva_entero(12);
    printf("Memoria reservada para <%d> y <%d>\n", *numero1, *numero2);

    // Funciones dentro del archivo ejercicio1.c
    printf(" Suma:\t\t< %d >\n", suma(*numero1, *numero2));
    printf(" Resta:\t\t< %d >\n", resta(*numero1, *numero2));
    printf(" Multipl.:\t< %d >\n", multiplicacion(*numero1, *numero2));
    printf(" Division:\t< %.2f >\n", division(*numero1, *numero2));

    // Finalizo liberando la memoria y recuperando los valores
    int numero_1 = libera_entero(numero1);
    int numero_2 = libera_entero(numero2);
    printf("Memoria libreada\n");

    // return 0;
}
