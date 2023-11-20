
# TP 6

## Esta ordenado? [ejercicio 1]

Implementar la función esta_ordenado que dado un conjunto de números, indique:

Sí está o no ordenado y

En qué sentido lo está (ascendente o descendente).

El programa que hace uso de esta función debe de aceptar el nombre de archivo por línea de comandos y mostrar por pantalla (y retornar el código de salida)

```C
/**
 * Esta función determina si un arreglo de enteros está ordenado en orden ascendente, descendente o no está ordenado.
 *
 * @param total_numeros - Número total de elementos en el arreglo.
 * @param arreglo       - Arreglo de enteros a analizar.
 *
 * @return  - 1 si el arreglo está ordenado en orden ascendente.
 *          -1 si el arreglo está ordenado en orden descendente.
 *           0 si el arreglo no está ordenado en ningún orden.
 *
 * @pre     - El parámetro 'total_numeros' debe ser mayor que 0 para que la función tenga sentido.
 *
 * @post    - La función analiza el arreglo 'arreglo' para determinar si está ordenado en orden ascendente, descendente o no ordenado.
 *            Devuelve 1 si está ordenado en orden ascendente, -1 si está ordenado en orden descendente y 0 si no está ordenado en ningún orden.
 *
 */
int esta_ordenado(int total_numeros, int arreglo[])
{
   int orden = 0;

   int ascendente = 1;  // Suponemos orden ascendente
   int descendente = 1; // Suponemos orden descendente

   for (int i = 1; i < total_numeros; i++)
   {
      if (arreglo[i - 1] > arreglo[i])
      {
         ascendente = 0; // No es ascendente
      }
      else if (arreglo[i - 1] < arreglo[i])
      {
         descendente = 0; // No es descendente
      }

      // Si los dos flags bajaron a 0, no está ordenado.
      if (ascendente == 0 && descendente == 0)
      {
         orden = 0;
         break; // corto el bucle
      }
   }

   // Determinar el resultado final
   if (ascendente == 1)
   {
      orden = 1; // Ascendente
   }
   else if (descendente == 1)
   {
      orden = -1; // Descendente
   }

   return orden;
}
```

### `esta_ordenado`
Esta función determina si un arreglo de enteros está ordenado en orden ascendente, descendente o no está ordenado.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "total_numeros" veces.
Su complejidad temporal es O(n). (n=total_numeros)

El costo computacional es: 3 + "total_numeros" * 4 + 3

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara tres variables del mismo tipo y utiliza un retorno también del tipo int.
Ademas recibe el puntero int al comienzo de un arreglo de enteros.

La complejidad espacial es `5 + "total_numeros" int`'s.