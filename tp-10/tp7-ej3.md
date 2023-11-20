
# TP 7

## Deduplicador [ejercicio 3]

Escribe una función que elimine los caracteres duplicados de una cadena.

```C
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
```

### `elimina_duplicados`
Esta función elimina caracteres duplicados de una cadena de caracteres y devuelve una nueva cadena sin duplicados.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(n^3). (n=largo)

El costo computacional es: 2 + ("largo"^2) * 4

#### Complejidad espacial
La función analizada recibe dos punteros, uno de tipo `char` y uno de tipo `int`.
Ademas, se declara una cadena de caracteres, con capacidad "largo".

La complejidad espacial es `1 int` y `"largo"^2 char`s.