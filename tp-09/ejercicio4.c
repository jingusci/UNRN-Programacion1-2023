/*
Ejercicio 1 - Series
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int es_palindromo(char *cadena, int size);

int main()
{
    char cadena1[] = "arribalabirra";
    char cadena2[] = "abajolabirra";
    int largo1 = sizeof(cadena1) - 1;
    int largo2 = sizeof(cadena2) - 1;

    printf("\nResultados:\n");
    printf("\nEs %s palindromo?: %d\n", cadena1, es_palindromo(cadena1, largo1));
    printf("Es %s palindromo?: %d\n\n", cadena2, es_palindromo(cadena2, largo2));

    return 0;
}

/**
 * Verifica si una cadena es un palíndromo utilizando recursividad.
 *
 * @param cadena Un puntero a la cadena de caracteres.
 * @param size La longitud de la cadena.
 * @return 1 si la cadena es un palíndromo, 0 si no lo es.
 */
int es_palindromo(char *cadena, int size)
{
    if (size <= 0)
    {
        return 1;
    }
    else if (cadena[0] != cadena[size - 1])
    {
        return 0;
    }
    else
    {
        return es_palindromo(cadena + 1, size - 2);
    }
}
