/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Encontrar la longitud de una cadena segura empleando aritmética de punteros y
sin usar el operador de arreglos [].
*/

#define TODO_OK 0
#define CADENA_NULA -1
#define CAPACIDAD_INCORRECTA -3
#define CADENA_SIN_TERMINADOR -6

/**
 * Comprueba si un arreglo es válido.
 *
 * Esta función verifica si un arreglo es válido según las siguientes
 * condiciones:
 * - El puntero al arreglo no es nulo.
 * - La capacidad del arreglo es mayor o igual a 1.
 * - Esta función no verifica que el largo de la cadena sea consistente o que la
 * misma contenga el terminador.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo.
 *
 * @return Un código de salida que indica si el arreglo es válido o no.
 *         - Si el arreglo es nulo, devuelve CADENA_NULA.
 *         - Si la capacidad es menor que 1, devuelve CAPACIDAD_INCORRECTA.
 *         - Si el arreglo es válido, devuelve TODO_OK.
 *
 * @pre
 * - El puntero al arreglo puede ser nulo o apuntar a un arreglo válido.
 * - La capacidad debe ser un valor mayor o igual a 1.
 *
 * @post
 * - El arreglo no es modificado.
 * - La función devuelve uno de los siguientes códigos:
 *   - CADENA_NULA si el arreglo es nulo.
 *   - CAPACIDAD_INCORRECTA si la capacidad es menor que 1.
 *   - TODO_OK si el arreglo es válido.
 */
int es_valido(char arreglo[], int capacidad)
{
    int codigo_salida;

    if (arreglo == NULL)
    {
        codigo_salida = CADENA_NULA;
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
 * 2.1
 * Calcula la longitud de una cadena segura.
 *
 * @param cadena Arreglo de caracteres que representa la cadena.
 * @param capacidad Capacidad máxima del arreglo (incluyendo el carácter nulo).
 * @return La longitud de la cadena (sin incluir el carácter nulo) o un código
 * de error. ver @post
 *
 * @pre
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - El puntero 'cadena' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función devuelve la longitud de la cadena si es válida y no está vacía.
 * - Si el largo es igual a la capacidad, se devuelve CADENA_SIN_TERMINADOR.
 * - Aplican los mismos codigos de error que `es_valido`
 */
int largo_seguro(char cadena[], int capacidad)
{
    int longitud = es_valido(cadena, capacidad);
    char *puntero = cadena;
    if (longitud == TODO_OK)
    {
        longitud = 0;
        while (*puntero != '\0' && longitud < capacidad)
        {
            longitud++;
        }
        if (longitud == capacidad)
        {
            longitud = CADENA_SIN_TERMINADOR;
        }
    }
    return longitud;
}

int main()
{
    char cadena[] = "Ejemplo";
    int capacidad_cadena = sizeof(cadena);

    int longitud = largo_seguro(cadena, capacidad_cadena);

    if (longitud != -1)
    {
        printf("Longitud de la cadena: %d\n", longitud);
    }
    else
    {
        printf("Error en el cálculo de la longitud.\n");
    }

    return 0;
}