
# TP 5

## Suma de Matrices [ejercicio 1.1]

La suma de matrices, es solo posible con matrices de las mismas dimensiones, esta operación requiere de un tercer argumento de matriz para almacenar el resultado.

En la suma de matrices, se toma el elemento en la misma ubicación en ambas matrices y se suma, para cada uno de ellos.

```C
/**
 * Esta función suma dos matrices y almacena el resultado en una tercera matriz.
 *
 * @param filas_1       - Número de filas de la primera matriz.
 * @param columnas_1    - Número de columnas de la primera matriz.
 * @param matriz_1      - Matriz 1 de entrada.
 * @param filas_2       - Número de filas de la segunda matriz.
 * @param columnas_2    - Número de columnas de la segunda matriz.
 * @param matriz_2      - Matriz 2 de entrada.
 * @param filas_r       - Número de filas de la matriz de resultado.
 * @param columnas_r    - Número de columnas de la matriz de resultado.
 * @param resultado     - Matriz de salida donde se almacenará la suma.
 *
 * @return  - 0 si la operación se realizó con éxito.
 *           ERROR_TAMANIO_MATRIZ si alguno de los tamaños de matriz es inválido.
 *           ERROR_MATRICES_DISTINTAS si las matrices no tienen las mismas dimensiones.
 *
 * @pre     - Todas las matrices deben tener tamaños válidos (entre 0 y CAPACIDAD_MAX_MATRIZ).
 * @pre     - Las matrices deben tener las mismas dimensiones para poder sumarse.
 *
 * @post    - Si flag_error es 0, la matriz 'resultado' contendrá la suma de 'matriz_1' y 'matriz_2'.
 * @post    - Si flag_error es diferente de 0, 'resultado' puede contener valores no definidos o definidos previamente.
 *
 */
int suma_matriz(int filas_1, int columnas_1, int matriz_1[][CAPACIDAD_MAX_MATRIZ],
                int filas_2, int columnas_2, int matriz_2[][CAPACIDAD_MAX_MATRIZ],
                int filas_r, int columnas_r, int resultado[][CAPACIDAD_MAX_MATRIZ])
{
   int flag_error = 0;

   if (filas_1 < 0 || filas_1 > CAPACIDAD_MAX_MATRIZ ||
       columnas_1 < 0 || columnas_1 > CAPACIDAD_MAX_MATRIZ ||
       filas_2 < 0 || filas_2 > CAPACIDAD_MAX_MATRIZ ||
       columnas_2 < 0 || columnas_2 > CAPACIDAD_MAX_MATRIZ ||
       filas_r < 0 || filas_r > CAPACIDAD_MAX_MATRIZ ||
       columnas_r < 0 || columnas_r > CAPACIDAD_MAX_MATRIZ)
   {
      flag_error = ERROR_TAMANIO_MATRIZ;
   }
   else if (filas_1 != filas_2 || filas_1 != filas_r || filas_2 != filas_r ||
            columnas_1 != columnas_2 || columnas_1 != columnas_r || columnas_2 != columnas_r)
   {
      flag_error = ERROR_MATRICES_DISTINTAS;
   }
   else
   {
      for (int i = 0; i < filas_r; i++)
      {
         for (int j = 0; j < columnas_r; j++)
         {
            resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
         }
      }
   }
   return flag_error;
}
```

### `suma_matriz`
Esta función suma dos matrices y almacena el resultado en una tercera matriz.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(filas_r * columnas_r).

El costo computacional es: 3 + filas_r * columnas_r

#### Complejidad espacial
La función analizada recibe 6 enteros de tipo `int` y los punteros al comienzo de tres matrices de enteros.
Ademas, declara una variable del tipo `int`.

La complejidad espacial es `7 int`'s.