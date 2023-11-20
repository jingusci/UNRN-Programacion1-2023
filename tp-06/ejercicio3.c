/*
Ejercicio 3 - generador lineal
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Argumentos que debe recibir, en orden:
 * nombre_archivo.txt
 * total_de_numeros
 * numero_inicial
 * pasos
*/
int main(int argc, char *argv[])
{

   // verifico haber recibido todos los argumentos
   if (argc != 5)
   {
      printf("Faltaron argumentos\n");
   }

   // Si recibí todos los argumentos
   else
   {
      // abro archivo con el primer argumento
      FILE *archivo = fopen(argv[1], "w");

      // verifico que pude abrir el archivo
      if (archivo == NULL)
      {
         perror("fopen() fallo");
      }

      // si pude abrir el archivo
      else
      {
         // declaro valores iniciales a partir de los argumentos (convierto a entero)
         int total_de_numeros = atoi(argv[2]);
         int inicio = atoi(argv[3]);
         int pasos = atoi(argv[4]);

         if (total_de_numeros < 0) // ver que errores me faltan aca
         {
            printf("ERROR: cantidad de numeros negativa.\n");
         }
         else
         {
            // escribo el total de numeros
            fprintf(archivo, "%d\n", total_de_numeros);
            // genero los numeros
            for (int i = 0; i < total_de_numeros; i++)
            {
               fprintf(archivo, "%d\n", inicio);
               inicio = inicio + pasos;
            }
            // cierro archivo
            fclose(archivo);
         }
      }
   }

   return 0;
}
