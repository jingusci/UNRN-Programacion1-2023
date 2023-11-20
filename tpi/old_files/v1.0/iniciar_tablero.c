#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku_resuelto.h"

void iniciar_tablero(int tablero[][9], int dificultad);
int obtener_dificultad();

/**
 * Inicia el tablero con el sudoku copleto a resolver.
 * Luego reemplaza varios numeros por ceros de acuerdo a la dificultad.
 *
 * Mejora a futuro: tener una base de datos de mas de un sudoku y elegir aleatoriamente alguno.
 */
void iniciar_tablero(int tablero[][9], int dificultad)
{
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         tablero[i][j] = sudoku_resuelto_extrafacil[i][j];
      }
   }
   srand(time(NULL));
   int c = 0;
   int random;
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < dificultad; j++)
      {
         // random = (rand() % 9) + 1; // Esto crea entre 1 y 9
         random = (rand() % 9); // Esto crea entre 0 y 8
         tablero[i][random] = 0;
      }
   }
}

/**
 * Obtiene un entero que determinará la dificultad del juego.
 */
int obtener_dificultad()
{
   int dificultad;
   printf("Por favor, ingrese la dificultad deseada.\n");
   printf("-> Niveles entre 1 y 10: ");
   scanf("%d", &dificultad);
   while (dificultad < 1 || dificultad > 10)
   {
      printf("\nERROR: ingrese un numero entre 1 y 10: ");
      scanf("%d", &dificultad);
   }
   return dificultad;
}