
# TP 7

## Inserta elemento [ejercicio 2]

Escribe una función que inserte un elemento en una posición específica de un arreglo dinámico de enteros.

```C
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
```

### `insertaElemento`
Esta función inserta un elemento en una posición específica de un arreglo de enteros y devuelve un nuevo arreglo con el elemento insertado.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(n). (n=*tamano)

El costo computacional es: 4 + 6*(tamamo) + 4

#### Complejidad espacial
La función analizada recibe dos variables de tipo `int` y dos variables de tipo `puntero int`.
Ademas, declara una variable de tipo `int` y una variable de tipo `puntero int`.

La complejidad espacial es `3 int`'s y `3 puntero int`'s.