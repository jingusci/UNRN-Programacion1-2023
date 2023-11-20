#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "importar_sudoku.c"
#define CANT_SUDOKUS 10

int iniciar_tablero(int tablero[][9]);
int obtener_dificultad();
int obtener_sudoku();

/**
 * Inicia el tablero con el sudoku copleto a resolver.
 * Luego reemplaza varios numeros por ceros de acuerdo a la dificultad.
 *
 * Mejora a futuro: tener una base de datos de mas de un sudoku y elegir aleatoriamente alguno.
 */
int iniciar_tablero(int tablero[][9])
{
   int numero_sudoku = obtener_sudoku();
   importar_sudoku(tablero, numero_sudoku);

   int dificultad = obtener_dificultad();

   srand(time(NULL));
   int random;
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < dificultad; j++)
      {
         random = (rand() % 9); // Esto crea entre 0 y 8
         tablero[i][random] = 0;
      }
   }
   return 1; // Juego iniciado
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

int obtener_sudoku()
{
   int numero_sudoku;

   do
   {
      printf("Hay disponibles %d sudokus para jugar\n", CANT_SUDOKUS);
      printf("Ingrese el numero de sudoku deseado [1 - %d], o ingrese 0 para elegir aleatoriamente: ", CANT_SUDOKUS);
      scanf("%d", &numero_sudoku);

      if (numero_sudoku == 0)
      {
         srand(time(NULL));
         numero_sudoku = (rand() % 9);
      }
      else if (numero_sudoku < 1 || numero_sudoku > CANT_SUDOKUS)
      {
         printf("\nERROR: ingrese un numero entre 1 y 10: ");
         scanf("%d", &numero_sudoku);
      }
      else
      {
         printf("Numero ingresado incorrecto\n\n");
      }
   } while (numero_sudoku < 0 || numero_sudoku > CANT_SUDOKUS);

   return numero_sudoku;
}