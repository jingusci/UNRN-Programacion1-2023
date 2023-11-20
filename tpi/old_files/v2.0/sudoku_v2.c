#include <stdio.h>
#include <stdlib.h>
#include "mostrar_tablero.c"
#include "iniciar_tablero.c"
#include "jugada.c"
#include "verificar_ganador.c"
#include "guardar_sudoku.c"
#include "cargar_sudoku.c"

int sudoku_v2();
int menu_principal();

int sudoku_v2()
{
   int tablero[9][9];
   int opcion;
   int ceros;
   int flag_jugando = 1;
   int juego_iniciado = 0;

   printf("\n ================================ \n");
   printf("\n\n    Bienvenido al sudoku!\n\n");
   printf("\n ================================ \n");
   do
   {
      opcion = menu_principal();
      switch (opcion)
      {
      case 1:
         juego_iniciado = iniciar_tablero(tablero);
         printf("\n Sudoku Iniciado! \n");
         ceros = contar_ceros(tablero);
         while (flag_jugando == 1)
         {
            mostrar_tablero(tablero);
            printf("Faltan completar %d posiciones\n", ceros);
            flag_jugando = jugar(tablero);
            ceros = contar_ceros(tablero);
            if (ceros == 0)
            {
               flag_jugando = 0;
               verificar_ganador(tablero);
            }
         }
         break;
      case 2:
         cargar_sudoku(tablero);
         printf("   Sudoku Cargado! \n");
         ceros = contar_ceros(tablero);
         while (flag_jugando == 1)
         {
            mostrar_tablero(tablero);
            printf("Faltan completar %d posiciones\n", ceros);
            flag_jugando = jugar(tablero);
            ceros = contar_ceros(tablero);
            if (ceros == 0)
            {
               flag_jugando = 0;
               verificar_ganador(tablero);
            }
         }
         break;
      case 3:
         if (juego_iniciado == 0)
         {
            printf("Juego NO iniciado. No es posible guardar la partida! \n");
         }
         else
         {
            guardar_sudoku(tablero);
            printf("    Sudoku Guardado! \n");
         }
         break;
      case 4:
         printf("Gracias por jugar!!!\n");
         break;
      default:
         printf("Opcion ingresada incorrecta!\n");
         break;
      }
   } while (opcion != 4);

   printf("\n Presione enter para terminar ");
   // scanf para pausar la consola
   char hola;
   scanf(" %s", &hola);

   return 0;
}

int menu_principal()
{
   int opcion;
   printf("\nMenu principal: \n");
   printf("1. Comenzar juego nuevo \n");
   printf("2. Retomar juego guardado \n");
   printf("3. Guardar Juego \n");
   printf("4. Salir \n");
   printf("Ingrese la opcion: ");
   scanf("%d", &opcion);
   printf("\n");
   return opcion;
}
