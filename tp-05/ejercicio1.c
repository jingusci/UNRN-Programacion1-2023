/*
Ejercicio 1
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CAPACIDAD_MAX_MATRIZ 10
#define ERROR_TAMANIO_MATRIZ -1
#define ERROR_MATRICES_DISTINTAS -2

void mostrar_matriz(int filas, int columnas, int matriz[][CAPACIDAD_MAX_MATRIZ]);
int producto_escalar(int filas, int columnas, int matriz[][CAPACIDAD_MAX_MATRIZ], int escalar);
// int suma_matrices(int filas, int columnas, int matriz1[][CAPACIDAD_MAX_MATRIZ],
//                   int matriz2[][CAPACIDAD_MAX_MATRIZ],
//                   int matriz3[][CAPACIDAD_MAX_MATRIZ]);
int suma_matriz(int filas_1, int columnas_1, int matriz_1[][CAPACIDAD_MAX_MATRIZ],
                int filas_2, int columnas_2, int matriz_2[][CAPACIDAD_MAX_MATRIZ],
                int filas_r, int columnas_r, int resultado[][CAPACIDAD_MAX_MATRIZ]);

int main()
{
   // prueba de mostrar una matriz
   printf("\n--------------------------------------------\n");
   printf("Prueba mostrar matriz: \n\n");
   int matriz_1[3][CAPACIDAD_MAX_MATRIZ] = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}};

   printf("\n");
   mostrar_matriz(3, 3, matriz_1);
   printf("\n--------------------------------------------\n");

   // prueba de matriz por un escalar
   printf("\n--------------------------------------------\n");
   printf("Prueba matriz por un escalar: \n\n");
   int matriz_2[2][CAPACIDAD_MAX_MATRIZ] = {
       {2, 4},
       {6, 8}};
   int escalador = 3;
   printf("Matriz original: \n");
   mostrar_matriz(2, 2, matriz_2);
   printf("\n");
   printf("Matriz multiplicada por el escalar: %d\n", escalador);
   int error = producto_escalar(2, 2, matriz_2, escalador);
   printf("\n");
   if (error == ERROR_TAMANIO_MATRIZ)
   {
      printf("Error en los parametros filas y columnas.\n");
   }
   else
   {
      mostrar_matriz(2, 2, matriz_2);
   }
   printf("\n--------------------------------------------\n");

   // prueba suma de matrices
   printf("\n--------------------------------------------\n");
   printf("Prueba suma de matrices: \n\n");
   int matriz_3[2][CAPACIDAD_MAX_MATRIZ] = {
       {1, 5},
       {3, 7}};
   int matriz_4[2][CAPACIDAD_MAX_MATRIZ] = {
       {2, 6},
       {4, 8}};
   int matriz_resulado_suma[2][CAPACIDAD_MAX_MATRIZ] = {
       {0, 0},
       {0, 0}};
   // printf("Matrices a sumar: \n");
   mostrar_matriz(2, 2, matriz_3);
   printf("    +\n");
   mostrar_matriz(2, 2, matriz_4);
   // printf("\n");
   error = suma_matriz(2, 2, matriz_3, 2, 2, matriz_4, 2, 2, matriz_resulado_suma);
   if (error == ERROR_TAMANIO_MATRIZ)
   {
      printf("Error en los parametros filas y columnas.\n");
   }
   else if (error == ERROR_MATRICES_DISTINTAS)
   {
      printf("Las matrices no tienen el mismo tamaño. No es posible sumarlas.\n");
   }
   else
   {
      printf("    =\n");
      // printf("Matrices sumadas: \n");
      mostrar_matriz(2, 2, matriz_resulado_suma);
   }
   printf("\n--------------------------------------------\n");

   return 0;
}

/**
 * Esta función muestra en la consola el contenido de una matriz.
 *
 * @param filas       - Número de filas de la matriz.
 * @param columnas    - Número de columnas de la matriz.
 * @param matriz      - Matriz que se desea mostrar.
 *
 * @pre     - La matriz debe tener tamaños válidos (entre 0 y CAPACIDAD_MAX_MATRIZ).
 *
 * @post    - La función imprime en la consola el contenido de la matriz 'matriz', mostrando sus elementos fila por fila,
 *            separados por barras verticales '|'. Cada elemento se muestra con un formato "| valor ".
 *            Al final de cada fila se imprime una barra vertical '|', y luego se pasa a la siguiente fila.
 *
 */
void mostrar_matriz(int filas, int columnas, int matriz[][CAPACIDAD_MAX_MATRIZ])
{
   for (int i = 0; i < filas; i++)
   {
      for (int j = 0; j < columnas; j++)
      {
         printf("| %d ", matriz[i][j]);
      }
      printf("|\n");
   }
}

/**
 * Esta función multiplica una matriz por un escalar.
 *
 * @param filas       - Número de filas de la matriz.
 * @param columnas    - Número de columnas de la matriz.
 * @param matriz      - Matriz de entrada.
 * @param escalar     - Valor escalar por el cual se multiplicarán los elementos de la matriz.
 *
 * @return  - 0 si la operación se realizó con éxito.
 *           ERROR_TAMANIO_MATRIZ si el tamaño de matriz es inválido.
 *
 * @pre     - La matriz debe tener tamaños válidos (entre 0 y CAPACIDAD_MAX_MATRIZ).
 *
 * @post    - Si flag_error es 0, la matriz 'matriz' contendrá todos sus elementos multiplicados por 'escalar'.
 * @post    - Si la multiplicación no se puede realizar debido a una condición de error, no se modifican los datos de `matriz`.
 *
 */
int producto_escalar(int filas, int columnas, int matriz[][CAPACIDAD_MAX_MATRIZ], int escalar)
{
   int flag_error = 0;

   if (filas < 0 || filas > CAPACIDAD_MAX_MATRIZ || columnas < 0 || columnas > CAPACIDAD_MAX_MATRIZ)
   {
      flag_error = ERROR_TAMANIO_MATRIZ;
   }
   else
   {
      for (int i = 0; i < filas; i++)
      {
         for (int j = 0; j < columnas; j++)
         {
            matriz[i][j] = matriz[i][j] * escalar;
         }
      }
   }
   return flag_error;
}

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
