// void mostrar_tablero(int tablero[][9]);
void mostrar_tablero(int **tablero);
void linea_superior();
void linea_media();
void linea_inferior();

/**
 * Esta función imprime la línea superior del tablero de Sudoku.
 *
 * @post Se imprime la línea superior del tablero de Sudoku en el formato especificado.
 *
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
 * Esta función imprime la línea media del tablero de Sudoku.
 *
 * @post Se imprime la línea media del tablero de Sudoku en el formato especificado.
 *
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
 * Esta función imprime la línea inferior del tablero de Sudoku.
 *
 * @post Se imprime la línea inferior del tablero de Sudoku en el formato especificado.
 *
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
 * Esta función imprime el tablero de Sudoku.
 *
 * @param tablero Es un puntero doble que representa el tablero de Sudoku.
 *
 * @pre El tablero debe contener valores válidos.
 *
 * @post Se imprime el tablero de Sudoku en el formato especificado.
 *
 */
void mostrar_tablero(int **tablero)
{
   printf("Tablero: \n\n");
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
            if (tablero[i][j] == 0)
            {
               printf("%c   ", 179); // No muestros los ceros, dejo espacios vacios
            }
            else
            {
               printf("%c %d ", 179, tablero[i][j]);
            }
         }
         else if (j == 8)
         {
            if (tablero[i][j] == 0)
            {
               printf("   %c %d\n", 179, i + 1); // No muestros los ceros, dejo espacios vacios
            }
            else
            {
               printf(" %d %c %d\n", tablero[i][j], 179, i + 1);
            }
         }
         else
         {
            if (tablero[i][j] == 0)
            {
               printf("   "); // No muestros los ceros, dejo espacios vacios
            }
            else
            {
               printf(" %d ", tablero[i][j]);
            }
         }
      }
   }
   linea_inferior();
}