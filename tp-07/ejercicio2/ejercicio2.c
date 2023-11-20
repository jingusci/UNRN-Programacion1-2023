/*
Ejercicio 2 - Arreglos III
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <time.h>


/**
 * Esta función reserva memoria dinámica para almacenar un arreglo de enteros de un tamaño específico 
 * y devuelve un puntero al arreglo.
 *
 * @param tamano - Tamaño del arreglo de enteros que se desea reservar.
 *
 * @return  - Un puntero al arreglo de enteros de tamaño 'tamano' si la reserva de memoria fue exitosa.
 *          - NULL si no se pudo reservar memoria.
 * 
 * @pre     - El parámetro 'tamano' debe ser un valor mayor que 0 para que la función tenga sentido.
 * 
 * @post    - La función reserva memoria dinámica para almacenar un arreglo de enteros de tamaño 'tamano'.
 *            Devuelve un puntero al inicio del arreglo si la reserva fue exitosa, o NULL si no se pudo reservar memoria.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
int *reserva_arreglo_enteros(int tamano)
{
    int *arreglo_enteros = (int *)malloc(sizeof(int) * tamano);

    return arreglo_enteros;
}

/**
 * Esta función libera la memoria dinámica previamente reservada para un arreglo de enteros.
 *
 * @param arreglo - Puntero al arreglo de enteros que se desea liberar.
 *
 * @pre - El parámetro 'arreglo' debe ser un puntero previamente asignado por la función 'reserva_arreglo_enteros' o por una función similar.
 * 
 * @post - La función libera la memoria dinámica apuntada por 'arreglo' si 'arreglo' no es NULL. Si 'arreglo' es NULL, no realiza ninguna operación.
 *         Es importante liberar la memoria cuando ya no sea necesaria para evitar fugas de memoria (memory leaks).
 *
 */
void libera_arreglo_enteros(int *arreglo)
{
    if (arreglo != NULL)
    {
        free(arreglo);
    }
}

/**
 * Esta función crea una copia de un arreglo de enteros y devuelve un puntero a la copia.
 *
 * @param original - Puntero al arreglo de enteros que se desea copiar.
 * @param tamano   - Tamaño del arreglo de enteros a copiar.
 *
 * @return  - Un puntero al arreglo de enteros copiado si la operación fue exitosa.
 *           NULL si no se pudo realizar la copia o si 'original' es NULL.
 * 
 * @pre     - El parámetro 'original' debe ser un puntero a un arreglo de enteros previamente asignado.
 *           El parámetro 'tamano' debe ser un valor mayor que 0 para que la función tenga sentido.
 * 
 * @post    - La función reserva memoria dinámica para almacenar una copia del arreglo de enteros 'original' de tamaño 'tamano'.
 *            Realiza la copia de los elementos del arreglo 'original' al nuevo arreglo 'copia'.
 *            Devuelve un puntero al arreglo 'copia' si la operación fue exitosa, o NULL en caso de error.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
int *copia_arreglo(int *original, int tamano)
{
    int *copia = reserva_arreglo_enteros(tamano);

    if (copia != NULL)
    {
        for (int i = 0; i < tamano; i++)
        {
            copia[i] = original[i];
        }
        return copia;
    }
    else
    {
        return NULL;
    }
}

/**
 * Esta función elimina un elemento de un arreglo de enteros en una posición específica y devuelve un nuevo arreglo sin ese elemento.
 *
 * @param arreglo   - Puntero al arreglo de enteros del cual se eliminará un elemento.
 * @param tamano    - Puntero al tamaño del arreglo antes y después de la eliminación.
 * @param posicion  - Posición del elemento que se eliminará del arreglo.
 *
 * @return  - Un puntero al nuevo arreglo de enteros sin el elemento eliminado si la operación fue exitosa.
 *           NULL en caso de errores, como un arreglo inválido, una posición fuera de rango o falta de memoria.
 * 
 * @pre     - El parámetro 'arreglo' debe ser un puntero a un arreglo de enteros previamente asignado.
 *           El parámetro 'tamano' debe ser un puntero que almacena el tamaño del arreglo.
 *           El parámetro 'posicion' debe ser una posición válida en el rango [0, *tamano - 1].
 * 
 * @post    - La función crea un nuevo arreglo de enteros que es una copia del arreglo original, pero sin el elemento en la posición especificada.
 *            Actualiza el tamaño del arreglo al eliminar un elemento.
 *            Devuelve un puntero al nuevo arreglo si la operación fue exitosa, o NULL en caso de errores.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
int *elimina_elemento(int *arreglo, int *tamano, int posicion)
{
    if (arreglo == NULL || *tamano <= 0 || posicion < 0 || posicion >= *tamano)
    {
        return NULL; // Manejo de errores: arreglo inválido o posición fuera de rango
    }

    // Creamos un nuevo arreglo de un tamaño menor
    int *nuevo_arreglo = reserva_arreglo_enteros(*tamano);

    if (nuevo_arreglo == NULL)
    {
        return NULL; // Manejo de error: no se pudo reservar memoria
    }

    int indice_nuevo = 0;

    for (int i = 0; i < *tamano; i++)
    {
        if (i != posicion)
        {
            nuevo_arreglo[indice_nuevo] = arreglo[i];
            indice_nuevo++;
        }
    }

    // Actualizamos el tamaño del arreglo
    (*tamano)--;

    libera_arreglo_enteros(arreglo); // Liberamos la memoria del arreglo original

    return nuevo_arreglo;
}

/**
 * Esta función inserta un elemento en una posición específica de un arreglo de enteros y devuelve un nuevo arreglo con el elemento insertado.
 *
 * @param arreglo   - Puntero al arreglo de enteros en el cual se insertará el elemento.
 * @param tamano    - Puntero al tamaño del arreglo antes y después de la inserción.
 * @param posicion  - Posición en la que se insertará el nuevo elemento.
 * @param valor     - Valor entero que se insertará en el arreglo.
 *
 * @return  - Un puntero al nuevo arreglo de enteros con el elemento insertado si la operación fue exitosa.
 *           NULL en caso de errores, como un arreglo inválido, una posición fuera de rango o falta de memoria.
 * 
 * @pre     - El parámetro 'arreglo' debe ser un puntero a un arreglo de enteros previamente asignado.
 *           El parámetro 'tamano' debe ser un puntero que almacena el tamaño del arreglo.
 *           El parámetro 'posicion' debe ser una posición válida en el rango [0, *tamano].
 * 
 * @post    - La función crea un nuevo arreglo de enteros que es una copia del arreglo original, pero con el elemento insertado en la posición especificada.
 *            Actualiza el tamaño del arreglo al insertar un elemento.
 *            Devuelve un puntero al nuevo arreglo si la operación fue exitosa, o NULL en caso de errores.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
int *insertaElemento(int *arreglo, int *tamano, int posicion, int valor)
{
    if (arreglo == NULL || posicion < 0 || posicion > *tamano)
    {
        return NULL; // Manejo de errores: arreglo inválido o posición fuera de rango
    }

    // Creamos un nuevo arreglo de un tamaño mayor
    int *nuevo_arreglo = reserva_arreglo_enteros((*tamano) + 1);

    if (nuevo_arreglo == NULL)
    {
        return NULL; // Manejo de error: no se pudo reservar memoria
    }

    int indice_nuevo = 0;

    for (int i = 0; i < *tamano; i++)
    {
        if (i == posicion)
        {
            nuevo_arreglo[indice_nuevo] = valor; // Insertamos el nuevo valor
            indice_nuevo++;
        }

        nuevo_arreglo[indice_nuevo] = arreglo[i];
        indice_nuevo++;
    }

    if (posicion == *tamano)
    {
        // Insertamos el valor al final
        nuevo_arreglo[*tamano] = valor;
    }

    // Actualizamos el tamaño del arreglo
    (*tamano)++;

    free(arreglo); // Liberamos la memoria del arreglo original

    return nuevo_arreglo;
}

/**
 * Esta función fusiona dos arreglos de enteros en un nuevo arreglo y devuelve dicho arreglo resultante.
 *
 * @param arreglo1 - Puntero al primer arreglo de enteros que se fusionará.
 * @param tamano1  - Tamaño del primer arreglo.
 * @param arreglo2 - Puntero al segundo arreglo de enteros que se fusionará.
 * @param tamano2  - Tamaño del segundo arreglo.
 *
 * @return  - Un puntero al nuevo arreglo de enteros que contiene la fusión de los dos arreglos originales si la operación fue exitosa.
 *           NULL en caso de errores, como arreglos inválidos o falta de memoria.
 * 
 * @pre     - El parámetro 'arreglo1' debe ser un puntero a un arreglo de enteros previamente asignado.
 *           El parámetro 'tamano1' debe ser el tamaño del primer arreglo.
 *           El parámetro 'arreglo2' debe ser un puntero a un arreglo de enteros previamente asignado.
 *           El parámetro 'tamano2' debe ser el tamaño del segundo arreglo.
 * 
 * @post    - La función crea un nuevo arreglo de enteros que es una fusión de los dos arreglos originales.
 *            El tamaño del nuevo arreglo es la suma de los tamaños de los arreglos originales.
 *            Devuelve un puntero al nuevo arreglo si la operación fue exitosa, o NULL en caso de errores.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea necesaria utilizando la función 'free()'.
 *
 */
int *fusiona_arreglos(int *arreglo1, int tamano1, int *arreglo2, int tamano2)
{
    if (arreglo1 == NULL || arreglo2 == NULL)
    {
        return NULL; // Manejo de errores: arreglos inválidos
    }

    // Creamos un nuevo arreglo de un tamaño igual a la suma de los tamaños de ambos arreglos
    int nuevo_tamano = tamano1 + tamano2;
    int *nuevo_arreglo = reserva_arreglo_enteros(nuevo_tamano);

    if (nuevo_arreglo == NULL)
    {
        return NULL; // Manejo de error: no se pudo reservar memoria
    }

    int indice = 0;
    for (int i = 0; i < tamano1; i++)
    {
        nuevo_arreglo[indice] = arreglo1[i];
        indice++;
    }
    for (int i = 0; i < tamano2; i++)
    {
        nuevo_arreglo[indice] = arreglo2[i];
        indice++;
    }

    return nuevo_arreglo;
}

/**
 * Esta función imprime los elementos de un arreglo de enteros en la consola.
 *
 * @param arreglo - Arreglo de enteros que se desea imprimir.
 * @param tamano  - Tamaño del arreglo.
 *
 * @pre - El parámetro 'arreglo' debe ser un arreglo de enteros previamente asignado.
 *       El parámetro 'tamano' debe indicar el número de elementos en el arreglo.
 * 
 * @post - La función imprime cada elemento del arreglo en la consola, separados por espacios, seguido de un salto de línea.
 *         No realiza cambios en el arreglo ni en sus elementos, solo muestra su contenido en la salida estándar.
 *
 */
void imprimir_arreglo(int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

/**
 * Esta función carga un arreglo de enteros con valores aleatorios en el rango [1, 99].
 *
 * @param arreglo - Arreglo de enteros que se desea cargar con valores aleatorios.
 * @param tamano  - Tamaño del arreglo.
 *
 * @pre - El parámetro 'arreglo' debe ser un arreglo de enteros previamente asignado.
 *       El parámetro 'tamano' debe indicar el número de elementos en el arreglo.
 * 
 * @post - La función asigna valores aleatorios en el rango [1, 99] a cada elemento del arreglo.
 *         Los valores aleatorios son generados mediante la función 'rand()'.
 *         No imprime ni muestra los valores, solo los asigna al arreglo.
 *
 */
void cargar_arreglo(int arreglo[], int tamano)
{
    srand(time(NULL));
    for (int i = 0; i < tamano; i++)
    {
        arreglo[i] =  rand() % (100 - 1) + 1;
    }
}