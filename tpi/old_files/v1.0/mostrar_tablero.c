#include <stdio.h>

void mostrar_tablero(int tablero[][9]);
void linea_superior();
void linea_media();
void linea_inferior();

/**
 * imprime la linea superior del tablero
*/
void linea_superior()
{
   printf("\t  1  2  3   4  5  6   7  8  9\n\t");
   for (int c = 0; c < 31; c++)
   {
      if (c == 0)
      {
         printf("%c", 218);
      }
      else if (c == 10 || c == 20)
      {
         printf("%c", 194);
      }
      else if (c == 30)
      {
         printf("%c", 191);
      }
      else
      {
         printf("%c", 196);
      }
   }
   printf("\n");
}

/**
 * imprime las lineas intermedias del tablero
*/
void linea_media()
{
   printf("\t");
   for (int c = 0; c < 31; c++)
   {
      if (c == 0)
      {
         printf("%c", 195);
      }
      else if (c == 10 || c == 20)
      {
         printf("%c", 197);
      }
      else if (c == 30)
      {
         printf("%c", 180);
      }
      else
      {
         printf("%c", 196);
      }
   }
   printf("\n");
}

/**
 * imprime la linea inferior del tablero
*/
void linea_inferior()
{
   printf("\t");
   for (int c = 0; c < 31; c++)
   {
      if (c == 0)
      {
         printf("%c", 192);
      }
      else if (c == 10 || c == 20)
      {
         printf("%c", 193);
      }
      else if (c == 30)
      {
         printf("%c", 217);
      }
      else
      {
         printf("%c", 196);
      }
   }
   printf("\n");
}

/**
 * Funcion completa que imprime el tablero.
 * Muestra los numeros almacenados
 * Llama a las funciones "linea_superior", "linea_media" y 
 * "linea_inferior" para completar correctamente el tablero
*/
void mostrar_tablero(int tablero[][9])
{
   printf("Tablero: \n");
   for (int i = 0; i < 9; i++)
   {
      if (i == 0)
      {
         linea_superior();
      }
      else if (i == 3 || i == 6)
      {
         linea_media();
      }
      printf("\t");
      for (int j = 0; j < 9; j++)
      {
         if (j == 0 || j == 3 || j == 6)
         {
            printf("%c %d ", 179, tablero[i][j]);
         }
         else if (j == 8)
         {
            printf(" %d %c %d\n", tablero[i][j], 179, i+1);
         }
         else
         {
            printf(" %d ", tablero[i][j]);
         }
      }
   }
   linea_inferior();
}