#include <stdio.h>
// #include "sudoku_resuelto.h"

int contar_ceros(int tablero[][9]);
int verificar_ganador(int tablero[][9]);

/**
 * Cuenta la cantidad de ceros en el tablero.
 * Dicha cantidad representa la cantidad de posiciones faltantes.
 */
int contar_ceros(int tablero[][9])
{
   int ceros = 0;
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         if (tablero[i][j] == 0)
         {
            ceros++;
         }
      }
   }
   return ceros;
}

/**
 * Verifica si el tablero completo coincide con el resuelto almacenado.
 * Devuelve 1 si está correcto.
 * Devuelve 0 si no está correcto.
 */
int verificar_ganador(int tablero[][9])
{
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         if (tablero[i][j] != sudoku_resuelto_extrafacil[i][j])
         {
            return 0;
         }
      }
   }
   return 1;
}