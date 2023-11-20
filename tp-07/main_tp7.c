/*
Trabajo Practico 7
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio1/ejercicio1_main.c"
#include "ejercicio2/ejercicio2_main.c"
#include "ejercicio3/ejercicio3_main.c"

int main()
{
    int opcion;
    
    do
    {
        printf("\n");
        printf("Menu de opciones:\n");
        printf("1. Testear ejercicio 1\n");
        printf("2. Testear ejercicio 2\n");
        printf("3. Testear ejercicio 3\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion)
        {
        case 1:
            ejercicio1_main();
            break;
        case 2:
            ejercicio2_main();
            break;
        case 3:
            ejercicio3_main();
            break;
        case 0:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida. Ingresa un numero valido.\n");
        }
    } while (opcion != 0);

    return 0;
}