/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <string.h>

#define TODO_OK 0
#define CADENA_NULA -1
#define CADENA_SIN_TERMINADOR -2
#define CAPACIDAD_INCORRECTA -3

/*
Consigna:
Implementar una función que retorne el puntero relativo a una cadena segura, en
donde se encuentre la primera ocurrencia de una segunda.
*/

/**
 * Comprueba si un arreglo es válido.
 *
 * Esta función verifica si una cadena es válida según las siguientes
 * condiciones:
 * - El puntero a la cadena no es nulo.
 * - La capacidad de la cadena es mayor o igual a 1.
 * - Esta función no verifica que el largo de la cadena sea consistente o que la
 * misma contenga el terminador.
 *
 * @param capacidad La capacidad de la cadena.
 * @param cadena   Un puntero a la cadena.
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
int es_valido(char cadena[], int capacidad)
{
    int codigo_salida;

    if (cadena == NULL)
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
    if (longitud == TODO_OK)
    {
        longitud = 0;
        while ((cadena[longitud] != '\0') && (longitud <= capacidad))
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

/**
 * Busca la primera ocurrencia de una cadena en otra cadena segura.
 *
 * @param cadena Cadena principal en la que se realizará la búsqueda.
 * @param capacidad_cadena Capacidad máxima de la cadena principal (incluyendo
 * el carácter nulo).
 * @param busqueda Cadena que se está buscando en la cadena principal.
 * @param capacidad_busqueda Capacidad máxima de la cadena de búsqueda
 * (incluyendo el carácter nulo).
 * @return Un puntero al inicio de la primera ocurrencia de 'busqueda' en
 * 'cadena', o NULL si no se encuentra.
 *
 * Precondiciones:
 *  - 'cadena' y 'busqueda' no deben ser punteros nulos.
 *  - 'capacidad_cadena' y 'capacidad_busqueda' deben ser mayores que 0.
 *  - Las cadenas deben estar terminadas con el carácter nulo '\0'.
 *
 * Postcondiciones:
 *  - Si se encuentra una coincidencia completa de 'busqueda' en 'cadena', la
 * función devuelve un puntero al inicio de esa coincidencia en 'cadena'.
 *  - Si no se encuentra ninguna coincidencia, la función devuelve NULL.
 */
char *buscar(char cadena[], int capacidad, char busqueda[],
             int capacidad_busqueda)
{
    int i;
    int j;

    int largo_cadena = largo_seguro(cadena, capacidad);
    int largo_busqueda = largo_seguro(busqueda, capacidad_busqueda);

    char *resultado = NULL;

    if (largo_cadena < 1 || largo_busqueda < 1)
    {
        resultado = NULL;
    }
    else
    {
        for (i = 0; i <= largo_cadena - largo_busqueda; i++)
        {
            j = 0;
            while (j < largo_busqueda && cadena[i + j] == busqueda[j])
            {
                j++;
            }

            if (j == largo_busqueda)
            {
                resultado = &cadena[i];
                j = largo_busqueda;
            }
        }
    }

    return resultado;
}

int main()
{
    char cadena[100] = "Ejemplo de busqueda en una cadena.";
    char busqueda[100] = "busque";

    char *resultado;

    resultado = buscar(cadena, 100, busqueda, 100);

    if (resultado != NULL)
    {
        printf("La cadena: <%s>\n", busqueda);
        printf("Se encontro en: <%s>\n", cadena);
        printf("Se encontro la cadena: <%s>\n", resultado);
    }
    else
    {
        printf("La cadena de busqueda no se encontró en la cadena.\n");
    }

    return 0;
}
