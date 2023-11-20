#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "manejo_archivos.c"
#include "manejo_memoria.c"
#include "iniciar_tablero.c"
#include "mostrar_tablero.c"
#include "jugar.c"

int menu_principal();
void mensaje_ganador(int **tablero);

int main()
{
   // Declaracion de variables
   int **tablero = crear_tablero();
   int opcion;
   int ceros_faltantes = 81;
   int flag_jugando;
   int flag_juego_iniciado = 0;

   // Mensaje de bienvenida
   printf("\n================================================== \n");
   printf("\n\n    Bienvenido al sudoku!\n\n");
   printf("\n================================================== \n");

   // Loop del juego
   do
   {
      opcion = menu_principal();
      switch (opcion)
      {
      case 1:
         flag_juego_iniciado = iniciar_tablero(tablero);
         flag_jugando = 1;
         printf("\n Sudoku Iniciado! \n");
         printf("\n==================================================\n\n");
         while (flag_jugando == 1 && ceros_faltantes != 0)
         {
            ceros_faltantes = jugar(tablero, &flag_jugando);
         }
         if (ceros_faltantes == 0)
         {
            mensaje_ganador(tablero);
         }
         break;
      case 2:
         flag_juego_iniciado = cargar_sudoku(tablero);
         if (flag_juego_iniciado == 0)
         {
            printf("Juego no disponible \n");
            break;
         }

         flag_jugando = 1;
         printf("   Sudoku Cargado! \n");
         printf("\n==================================================\n\n");
         while (flag_jugando == 1 && ceros_faltantes != 0)
         {
            ceros_faltantes = jugar(tablero, &flag_jugando);
         }
         if (ceros_faltantes == 0)
         {
            mensaje_ganador(tablero);
         }
         break;
      case 3:
         if (flag_juego_iniciado == 0)
         {
            printf("Juego NO iniciado. No es posible guardar la partida! \n");
            printf("\n==================================================\n\n");
         }
         else
         {
            guardar_sudoku(tablero);
            printf("    Sudoku Guardado! \n");
            printf("\n==================================================\n\n");
         }
         break;
      case 4:
         break;
      default:
         printf("Opcion ingresada incorrecta!\n");
         break;
      }
   } while (opcion != 4);

   // Libero la memoria
   liberar_tablero(tablero);

   // Mensaje de despedida
   printf("\n    Gracias por jugar al sudoku!\n\n");
   printf("\n================================================== \n");
   printf("\nPresione enter para terminar\n");
   // getchar();  // En mi compilador no me anduvo esta opcion
   char hola;
   scanf("%s", &hola);

   return 0;
}

/**
 * Despliega un menú principal para un juego de Sudoku.
 *
 * @return La opción seleccionada por el usuario.
 *
 * @pre - La función asume que el usuario ingresará un número entero válido como opción del menú.
 *
 * @post - La función devuelve la opción seleccionada por el usuario.
 */
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
   printf("\n==================================================\n\n");
   return opcion;
}

/**
 * Esta función imprime un mensaje de felicitaciones al usuario por completar el Sudoku y muestra el tablero.
 *
 * @param tablero Es un puntero doble que representa el tablero de Sudoku.
 *
 * @pre El tablero debe contener valores válidos.
 *
 * @post Se imprime un mensaje de felicitaciones y el tablero de Sudoku.
 *
 */
void mensaje_ganador(int **tablero)
{
   // printf("\n==================================================\n");
   printf("\nFELICITACIONES! COMPLETO EL SUDOKU!\n");
   mostrar_tablero(tablero);
   printf("\n==================================================\n\n");
}