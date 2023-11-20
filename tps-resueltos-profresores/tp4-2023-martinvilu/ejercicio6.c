/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Intercambiar dos caracteres en una misma cadena segura.
*/
#define TODO_OK 0
#define ARREGLO_NULO -1
#define CAPACIDAD_INCORRECTA -2
#define POSICION_INCORRECTA -3
#define ARGUMENTOS_EN_FALLA -4

/**
 * Verifica si un arreglo es válido según las precondiciones especificadas.
 *
 * @param capacidad Capacidad máxima del arreglo.
 * @param arreglo Arreglo de caracteres a verificar.
 * @return Código de salida que indica la validez del arreglo:
 *         - ARREGLO_NULO si el arreglo es NULL.
 *         - CAPACIDAD_INCORRECTA si la capacidad es menor que 1.
 *         - TODO_OK si el arreglo cumple con todas las condiciones.
 *
 * Precondiciones:
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - El puntero 'arreglo' puede ser NULL o apuntar a un arreglo válido.
 *
 * Postcondiciones:
 * - El arreglo no es modificado.
 * - La función devuelve un código de salida que indica la validez del arreglo.
 * - Si el arreglo es NULL, se devuelve ARREGLO_NULO.
 * - Si la capacidad es menor que 1, se devuelve CAPACIDAD_INCORRECTA.
 * - Si el arreglo es distinto de NULL y la capacidad es mayor o igual a 1, se
 * devuelve TODO_OK.
 */
int es_valido(int capacidad, char arreglo[])
{
    int codigo_salida;

    if (arreglo == NULL)
    {
        codigo_salida = ARREGLO_NULO;
    }
    else if (capacidad < 1)
    {
        codigo_salida = CAPACIDAD_INCORRECTA;
    }
    else
    {
        codigo_salida = TODO_OK;
    }
    return codigo_salida;
}

/**
 * Intercambia dos elementos enteros.
 *
 * @param izquierda Puntero al primer elemento.
 * @param derecha Puntero al segundo elemento.
 */
void swap(char *izquierda, char *derecha)
{
    int temp = *izquierda;
    *izquierda = *derecha;
    *derecha = temp;
}

/**
 * Intercambia dos caracteres en una cadena segura.
 *
 * @param cadena Cadena en la que se realizará el intercambio.
 * @param capacidad Capacidad máxima de la cadena (incluyendo el carácter
 * nulo).
 * @param origen Posición del primer carácter a intercambiar.
 * @param destino Posición del segundo carácter a intercambiar.
 * @return 0 si el intercambio fue exitoso, -1 si ocurrió un error.
 *
 * Precondiciones:
 *  - La cadena no debe ser nula (cadena != NULL).
 *  - La capacidad de la cadena debe ser mayor o igual a 2 (capacidad >= 2).
 *  - Las posiciones de origen y destino deben estar dentro de los límites de la
 * cadena: (0 <= origen < capacidad) y (0 <= destino < capacidad).
 *
 * Postcondiciones:
 *  - Si las precondiciones se cumplen y el intercambio se realiza
 * correctamente, los caracteres en las posiciones 'origen' y 'destino' de la
 * cadena 'cadena' serán intercambiados.
 *  - Si las precondiciones no se cumplen, la función no modificará la cadena y
 *          devolverá valores negativos representado el error especifico.
 *  - En caso de éxito, la función devolverá 0.
 */
int intercambia(char cadena[], int capacidad, int origen, int destino)
{
    int codigo_salida;

    if ((origen < 0) || (origen >= capacidad) || (destino < 0) ||
        (destino >= capacidad))
    {
        codigo_salida = POSICION_INCORRECTA;
    }
    else
    {
        if (es_valido(capacidad, cadena) == TODO_OK)
        {
            swap(&cadena[origen], &cadena[destino]);
        }
        else
        {
            codigo_salida = ARGUMENTOS_EN_FALLA;
        }
    }
    return codigo_salida;
}

int main()
{
    char cadena[] = "Ejemplo";
    int capacidad_cadena = sizeof(cadena);

    printf("Cadena original: %s\n", cadena);

    if (intercambia(cadena, capacidad_cadena, 1, 4) == 0)
    {
        printf("Cadena modificada: %s\n", cadena);
    }
    else
    {
        printf("Error en el intercambio.\n");
    }

    return 0;
}
