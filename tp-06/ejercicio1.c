/*
Ejercicio 1 - Esta ordenado?
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMEROS_ARCHIVO 10000
#define ERROR_ARCHIVO 2

int esta_ordenado(int total_numeros, int arreglo[]);

/**
 * Debe recibir como argumento el nombre del archivo txt
 */
int main(int argc, char *argv[])
{
   // Declaro salida del programa
   int salida_programa = 0;

   // Declarar un puntero a un archivo Intentar abrir el archivo en modo lectura
   FILE *archivo = fopen(argv[1], "r");

   // Verificar si el archivo se abrió correctamente
   if (archivo == NULL)
   {
      perror("fopen() fallo");
      salida_programa = ERROR_ARCHIVO;
   }
   else
   {
      int cantidad_numeros;
      // Obtengo total de numeros (primera linea del archivo)
      fscanf(archivo, "%d", &cantidad_numeros);
      printf("\nCantidad de numeros en el archivo: < %d >\n", cantidad_numeros);

      int arreglo_numeros[MAX_NUMEROS_ARCHIVO];
      // cargo en un arreglo (verifico que entra)
      if (cantidad_numeros <= MAX_NUMEROS_ARCHIVO)
      {
         for (int i = 0; i < cantidad_numeros; i++)
         {
            fscanf(archivo, "%d", &arreglo_numeros[i]);
         }
      }
      else
      {
         printf("Archivo demasiado largo\n");
      }

      // Cerrar el archivo (ya no lo necesito, lo tengo en el arreglo)
      fclose(archivo);

      // Verifico orden
      salida_programa = esta_ordenado(cantidad_numeros, arreglo_numeros);

      // Muestro resultado
      // printf("resultado: %d\n", salida_programa);
      if (salida_programa == -1)
      {
         printf("Ordenado - Descendente\n");
      }
      else if (salida_programa == 1)
      {
         printf("Ordenado - Ascendente\n");
      }
      else
         printf("No Ordenado\n");
      {
      }
   }

   printf("\n");
   return salida_programa;
}

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