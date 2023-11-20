
# TP 4

## Busqueda [ejercicio 8]

Implementar una función que retorne el puntero relativo a una cadena segura, en donde se encuentre la primera ocurrencia de una segunda.

Retornen NULL si no se encuentra.

```C
/**
 * Busca la primera ocurrencia de una subcadena en una cadena dada.
 *
 * @param cadena - La cadena en la que se buscará la subcadena.
 * @param capacidad_cadena - La capacidad de memoria asignada para la cadena.
 * @param busqueda - La subcadena que se buscará en la cadena principal.
 * @param capacidad_busqueda - La capacidad de memoria asignada para la subcadena.
 *
 * @return Un puntero a la primera ocurrencia de la subcadena en la cadena principal.
 *         Si la subcadena no se encuentra, se devuelve un puntero nulo (NULL).
 *
 * @pre Ambas cadenas, 'cadena' y 'busqueda', deben ser cadenas de caracteres válidas.
 * @pre 'capacidad_cadena' y 'capacidad_busqueda' deben ser mayores que 0.
 *
 * @post El puntero retornado apunta a la primera ocurrencia de la subcadena en la cadena principal,
 *       o es nulo (NULL) si la subcadena no se encuentra en la cadena principal.
 */
char *busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda)
{
   char *resultado = NULL;

   int largo_cadena = largo_seguro(cadena, capacidad_cadena); // ver O de largo_seguro
   int largo_cadena_buscada = largo_seguro(busqueda, capacidad_busqueda);
   int flag_busqueda = 0;

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] == busqueda[0])
      {
         flag_busqueda = 1;
         for (int j = 0; j < largo_cadena_buscada; j++)
         {
            if (cadena[i + j] != busqueda[j])
            {
               flag_busqueda = 0;
            }
         }
         if (flag_busqueda == 1)
         {
            resultado = &cadena[i];
            break;
         }
      }
   }

   return resultado;
}
```

### `busqueda`
Busca la primera ocurrencia de una subcadena en una cadena dada.

#### Complejidad temporal:
El algoritmo tiene dos lazos, anidados que se ejecutarán un total de "capacidad_cadena" y "capacidad_busqueda" veces.
Su complejidad temporal es O(capacidad_cadena * capacidad_busqueda).

El costo computacional es: 4 + largo_cadena*(5+(largo_cadena_buscada*2)) +1 

#### Complejidad espacial
La función analizada recibe dos número de tipo `int` y dos punteros al comienzo de una cadena de caracteres. 
Ademas, se declaran tres variables del tipo `int` y una del tipo `puntero char`.

La complejidad espacial es `5 int`'s, `1 puntero char` y `"capacidad_cadena"+"capacidad_busqueda" char`.