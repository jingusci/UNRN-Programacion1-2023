/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdbool.h>
#include <stdio.h>

/*
Consigna:
Implementar una función que reemplace las vocales de una cadena segura
reemplazándolas por un carácter indicado.
*/

char a_mayuscula(char letra)
{
    if (es_minuscula(letra))
    {
        letra = letra - 32;
    }
    return letra;
}

char a_minuscula(char letra)
{
    if (es_mayuscula(letra))
    {
        letra = letra + 32;
    }
    return letra;
}

/**
 * Verifica si un carácter es una vocal.
 *
 * @param letra El carácter a verificar.
 * @return true si es una vocal, false de lo contrario.
 */
bool es_vocal(char letra)
{
    letra = a_minuscula(letra);
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' ||
            letra == 'u');
}

/**
 * Verifica si un carácter es una letra mayúscula.
 *
 * @param letra El carácter a verificar.
 * @return true si es una letra mayúscula, false de lo contrario.
 */
bool es_mayuscula(char letra)
{
    return (letra >= 'A' && letra <= 'Z');
}

/**
 * Verifica si un carácter es una letra minúscula.
 *
 * @param letra El carácter a verificar.
 * @return true si es una letra minúscula, false de lo contrario.
 */
bool es_minuscula(char letra)
{
    return (letra >= 'a' && letra <= 'z');
}

/**
 * Verifica si un carácter es alfabético (letra mayúscula o minúscula).
 *
 * @param letra El carácter a verificar.
 * @return true si es alfabético, false de lo contrario.
 */
bool es_alfabetica(char letra)
{
    return (es_mayuscula(letra) || es_minuscula(letra));
}

/**
 * Reemplaza las vocales en una cadena segura por un carácter indicado.
 *
 * @param cadena Cadena en la que se realizará el reemplazo.
 * @param capacidad_cadena Capacidad máxima de la cadena (incluyendo el carácter
 * nulo).
 * @param reemplazo Carácter con el que se reemplazarán las vocales.
 */
void reemplazo_vocales(char cadena[], int capacidad_cadena, char reemplazo)
{
    if (cadena == NULL || capacidad_cadena <= 0)
    {
        return; // Error en los parámetros
    }

    for (int i = 0; cadena[i] != '\0' && i < capacidad_cadena - 1; i++)
    {
        if (es_vocal(cadena[i])
        {
            cadena[i] = reemplazo;
        }
    }
}

int main()
{
    char cadena[] = "Reemplaza las vocales";
    int capacidad_cadena = sizeof(cadena);

    printf("Cadena original: %s\n", cadena);

    reemplazo_vocales(cadena, capacidad_cadena, '*');

    printf("Cadena con vocales reemplazadas: %s\n", cadena);

    return 0;
}