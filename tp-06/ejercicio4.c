/*
Ejercicio 4 - generador aleatorio
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Argumentos que debe recibir, en orden:
 * nombre_archivo.txt
 * total_de_numeros
 * limite inferior
 * limite superior
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
         int minimo = atoi(argv[3]);
         int maximo = atoi(argv[4]);
         int valor_aleatorio;

         if (total_de_numeros < 0) // ver que errores me faltan aca
         {
            printf("ERROR: cantidad de numeros negativa.\n");
         }
         else
         {
            // escribo el total de numeros
            fprintf(archivo, "%d\n", total_de_numeros);
            // genero los numeros
            srand(time(NULL)); 
            for (int i = 0; i < total_de_numeros; i++)
            {
               valor_aleatorio = rand() % (maximo - minimo) + minimo;
               fprintf(archivo, "%d\n", valor_aleatorio);
            }
            // cierro archivo
            fclose(archivo);
         }
      }
   }

   return 0;
}
