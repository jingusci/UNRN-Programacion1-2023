/*
Ejercicio 3 - Cadenas IV
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <time.h>
#include <string.h>

/**
 * Esta función reserva memoria dinámica para almacenar una cadena de caracteres de un tamaño específico y devuelve un puntero a la cadena.
 *
 * @param tamano - Tamaño de la cadena de caracteres que se desea reservar.
 *
 * @return  - Un puntero a la cadena de caracteres de tamaño 'tamano' si la reserva de memoria fue exitosa.
 *           NULL si no se pudo reservar memoria.
 *
 * @pre     - El parámetro 'tamano' debe ser un valor mayor que 0 para que la función tenga sentido.
 *
 * @post    - La función reserva memoria dinámica para almacenar una cadena de caracteres de tamaño 'tamano' más un carácter nulo de terminación.
 *            Devuelve un puntero al inicio de la cadena si la reserva fue exitosa, o NULL en caso de error.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
char *reserva_cadena(int tamano)
{
    char *arreglo_enteros = (char *)malloc((tamano + 1) * sizeof(char));

    return arreglo_enteros;
}

/**
 * Esta función concatena dos cadenas de caracteres y devuelve una nueva cadena que contiene la concatenación de ambas.
 *
 * @param cadena1 - Puntero a la primera cadena de caracteres que se desea concatenar.
 * @param cadena2 - Puntero a la segunda cadena de caracteres que se desea concatenar.
 *
 * @return  - Un puntero a una nueva cadena de caracteres que es la concatenación de 'cadena1' y 'cadena2' si la operación fue exitosa.
 *           NULL en caso de errores, como cadenas inválidas o falta de memoria.
 * 
 * @pre     - Los parámetros 'cadena1' y 'cadena2' deben ser punteros a cadenas de caracteres previamente asignadas.
 * 
 * @post    - La función calcula la longitud total de la cadena resultante sumando las longitudes de 'cadena1' y 'cadena2'.
 *            Reserva memoria para la cadena resultante, incluyendo el carácter nulo '\0'.
 *            Copia la primera cadena 'cadena1' al resultado, seguida por la concatenación de la segunda cadena 'cadena2'.
 *            Devuelve un puntero a la nueva cadena si la operación fue exitosa, o NULL en caso de errores.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
char *concatenaCadenas(char *cadena1, char *cadena2)
{
    if (cadena1 == NULL || cadena2 == NULL)
    {
        return NULL; // Manejo de errores: cadenas inválidas
    }

    // Calcula la longitud total de la cadena resultante (funciones de la libreria string)
    int longitud_total = strlen(cadena1) + strlen(cadena2);

    // Reserva memoria para la cadena resultante, incluyendo el carácter nulo '\0'
    // char *resultado = (char *)malloc((longitud_total + 1) * sizeof(char));
    char *resultado = reserva_cadena(longitud_total);

    if (resultado == NULL)
    {
        return NULL; // Manejo de errores: no se pudo reservar memoria
    }

    // Copia la primera cadena al resultado
    int indice = 0;
    for (int i = 0; i < (strlen(cadena1)); i++)
    {
        resultado[indice] = cadena1[i];
        indice++;
    }

    // Concatena la segunda cadena al resultado
    for (int i = 0; i <= (strlen(cadena2)); i++) // Aca recorro hasta <= para incluir el \0
    {
        resultado[indice] = cadena2[i];
        indice++;
    }

    // Se podrian usar dos funciones de la libreria string para evitar los for
    // strcpy(resultado, cadena1);  // Copia la primer cadena
    // strcat(resultado, cadena2);  // Concatena
    return resultado;
}

/**
 * Esta función elimina caracteres duplicados de una cadena de caracteres y devuelve una nueva cadena sin duplicados.
 *
 * @param cadena - Puntero a la cadena de caracteres original.
 * @param largo  - Puntero al tamaño de la cadena original antes y después de la eliminación de duplicados.
 *
 * @return  - Un puntero a una nueva cadena de caracteres que no contiene caracteres duplicados si la operación fue exitosa.
 *           NULL en caso de errores, como una cadena inválida o falta de memoria.
 * 
 * @pre     - El parámetro 'cadena' debe ser un puntero a una cadena de caracteres previamente asignada.
 *           El parámetro 'largo' debe ser un puntero que almacena el tamaño de la cadena.
 * 
 * @post    - La función crea una nueva cadena de caracteres que es una copia de la cadena original, pero sin caracteres duplicados.
 *            Actualiza el tamaño del 'largo' al eliminar los caracteres duplicados.
 *            Devuelve un puntero a la nueva cadena si la operación fue exitosa, o NULL en caso de errores.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
char *elimina_duplicados(char *cadena, int *largo)
{
    // Creo la cadena resultado como copia de la que recibo, reservando memoria dinamica
    char *resultado = reserva_cadena(*largo);
    strcpy(resultado, cadena);

    // Recorro la nueva cadena buscando duplicados (funcion de tp4 ejercicio9)
    for (int i = 0; i <= *largo; i++)
    {
        for (int j = i + 1; j <= *largo; j++)
        {
            if (resultado[i] == resultado[j])
            {
                for (int k = j + 1; k <= *largo; k++)
                {
                    resultado[k - 1] = resultado[k];
                }
            }
            *largo = strlen(resultado); // recalculo largo por si se modifico la cadena
        }
    }

    return resultado;
}
