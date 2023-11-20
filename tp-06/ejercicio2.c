/*
Ejercicio 1 - ordenar
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMEROS_ARCHIVO 1000

void ordenar_arreglo(int capacidad, int arreglo[], int orden);

/**
 * Debe recibir como argumento el nombre del archivo txt a ordenar,
 * el orden que se desea y el nombre del nuevo archivo ordenado a crear
 */
int main(int argc, char *argv[])
{
   // verifico haber recibido todos los argumentos
   if (argc != 4)
   {
      printf("Faltaron argumentos\n");
   }
   else
   {
      // Declarar un puntero a un archivo Intentar abrir el archivo en modo lectura
      FILE *archivo = fopen(argv[1], "r");

      // Verificar si el archivo se abrió correctamente
      if (archivo == NULL)
      {
         perror("fopen() fallo");
      }
      else
      {
         /* --- Parte 1: Leo los numeros ---*/
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

         /* --- Parte 2: Ordeno el arreglo ---*/
         int orden = 0;
         if (strcmp(argv[2], "asc") == 0)
         {
            orden = 1;
         }
         else if (strcmp(argv[2], "desc") == 0)
         {
            orden = -1;
         }
         else
         {
            printf("argumento de orden erroneo. Ingrese \"asc\" o \"desc\"\n");
         }
         ordenar_arreglo(cantidad_numeros, arreglo_numeros, orden);

         /* --- Parte 3: Escribo el nuevo archivo ---*/
         FILE *archivo_ordenado = fopen(argv[3], "w");
         // escribo el total de numeros
         fprintf(archivo_ordenado, "%d\n", cantidad_numeros);
         // genero los numeros
         for (int i = 0; i < cantidad_numeros; i++)
         {
            fprintf(archivo_ordenado, "%d\n", arreglo_numeros[i]);
         }
         // cierro archivo
         fclose(archivo_ordenado);
      }
   }
   printf("\n");
   return 0;
}

/**
 * Esta función ordena un arreglo de enteros en orden ascendente o descendente.
 *
 * @param capacidad - Número total de elementos en el arreglo.
 * @param arreglo   - Arreglo de enteros a ordenar.
 * @param orden     - Valor que determina el tipo de ordenamiento:
 *                   - 1 para orden ascendente.
 *                   - -1 para orden descendente.
 *                   - 0 para no realizar ningún ordenamiento.
 *
 * @pre     - El parámetro 'capacidad' debe ser mayor que 0 para que la función tenga sentido.
 *
 * @post    - La función ordena el arreglo 'arreglo' en orden ascendente si 'orden' es 1,
 *            en orden descendente si 'orden' es -1, o no realiza ningún ordenamiento si 'orden' es 0.
 */
void ordenar_arreglo(int capacidad, int arreglo[], int orden)
{
   int temp;
   if (orden == 1)
   {
      for (int i = 0; i < capacidad; i++)
      {
         for (int j = (i + 1); j < capacidad; j++)
         {
            if (arreglo[j] < arreglo[i])
            {
               temp = arreglo[i];
               arreglo[i] = arreglo[j];
               arreglo[j] = temp;
            }
         }
      }
   }
   else if (orden == -1)
   {
      for (int i = 0; i < capacidad; i++)
      {
         for (int j = (i + 1); j < capacidad; j++)
         {
            if (arreglo[j] > arreglo[i])
            {
               temp = arreglo[i];
               arreglo[i] = arreglo[j];
               arreglo[j] = temp;
            }
         }
      }
   }
   // if orden 0, no ordena
}