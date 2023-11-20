#include <stdio.h>
#include <stdlib.h>
#include "mostrar_tablero.c"
#include "iniciar_tablero.c"
#include "jugada.c"
#include "verificar_ganador.c"

int sudoku_v1();

int sudoku_v1()
{
   int tablero[9][9];

   printf("\n\n   Bienvenido al sudoku!\n\n");

   int dificultad = obtener_dificultad();
   iniciar_tablero(tablero, dificultad);

   mostrar_tablero(tablero);

   int ceros = contar_ceros(tablero);

   while (ceros != 0)
   {
      printf("Faltan completar %d posiciones\n", ceros);
      jugar(tablero);
      mostrar_tablero(tablero);
      ceros = contar_ceros(tablero);
   }

   if (verificar_ganador(tablero) == 1)
   {
      printf("\n==================================================\n");
      printf("\nFELICITACIONES! COMPLETO EL SUDOKU!\n");
      mostrar_tablero(tablero);
      printf("\n==================================================\n\n");
   }
   else
   {
      printf("ERROR --> EL TABLERO COMPLETADO NO COINCIDE CON LA SOLUCION PREESTABLECIDA\n\n");
   }

   // Funciones para pausar la ejecucion por consola al final

   printf("\n Presione enter para terminar ");
   // scanf para pausar la consola
   char hola;
   scanf(" %s", &hola);

   return 0;
}