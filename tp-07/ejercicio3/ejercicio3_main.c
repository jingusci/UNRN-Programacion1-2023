/*
Ejercicio 3 - Cadenas IV
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio3.c"

// funcion para testear las funciones del ejercicio 3
void ejercicio3_main()
{

    // Pruebas concatenacion
    char *cadena1 = "Hola, ";
    char *cadena2 = "mundo!";
    char *resultado = concatenaCadenas(cadena1, cadena2);

    printf("--------------------------\n");
    if (resultado != NULL)
    {
        printf("Cadena 1: %s\n",cadena1);
        printf("Cadena 2: %s\n",cadena2);
        printf("Cadenas concatenadas: %s\n", resultado);
        free(resultado); // Liberar la memoria cuando ya no la necesites
    }
    else
    {
        printf("Error al concatenar cadenas.\n");
    }
    printf("--------------------------\n");

    // Pruebas Eliminar duplicados
    char *cadena3 = "Holla, munndoo!!";
    int largo_cadena3 = strlen(cadena3);
    printf("\n");
    printf("Cadena original:\t%s (Largo %d)\n", cadena3,largo_cadena3);
    cadena3 = elimina_duplicados(cadena3, &largo_cadena3);
    printf("Cadena sin duplicados:\t%s (Largo %d)\n", cadena3,largo_cadena3);
    free(cadena3);
    printf("--------------------------\n");

    // return 0;
}