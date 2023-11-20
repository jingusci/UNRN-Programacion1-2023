/*
Ejercicio 2 - TA TE TI
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define MAX_NOMBRE 15

void mostrar_tablero(char tablero[3][3]);
int chequear_ganador(char tablero[3][3]);
char cambiar_turno(char turno);
void jugar(char turno, char tablero[3][3]);

int main()
{
   // Bienvenida y nombre de jugadores
   printf("\nBienvenido al TATETI\n");
   char jugador1[MAX_NOMBRE], jugador2[MAX_NOMBRE];
   printf("Ingrese el nombre del jugador 1 (X): ");
   scanf("%s", jugador1);
   printf("\nIngrese el nombre del jugador 2 (O): ");
   scanf("%s", jugador2);
   printf("\n");

   // Inicio tablero vacio
   char tablero[3][3] = {
       {'1', '2', '3'},
       {'4', '5', '6'},
       {'7', '8', '9'}};

   printf("\t Jugador X: %s\n\t Jugador O: %s\n", jugador1, jugador2);

   printf("Comienzo del juego!\n\n");
   mostrar_tablero(tablero);
   printf("\n\n");

   int ganador = 0;
   int contador_de_jugadas = 0;
   char turno = 'X';

   // Bucle donde se juega
   while (ganador == 0 && contador_de_jugadas < 9)
   {
      printf("Jugada numero %d\n", contador_de_jugadas + 1);
      jugar(turno, tablero);
      mostrar_tablero(tablero);
      printf("\n\n");

      // Chequeo si hay un ganador
      //    Si no hay ganador, cuento la jugada y cambio el turno
      ganador = chequear_ganador(tablero);
      if (ganador == 0)
      {
         turno = cambiar_turno(turno);
         contador_de_jugadas++;
      }
   }

   // Verificación y aviso de ganador
   if (ganador == 1 && turno == 'X')
   {
      printf("Felicidades, %s (%c)! Has ganado!\n", jugador1, turno);
   }
   else if (ganador == 1 && turno == 'O')
   {
      printf("Felicidades, %s (%c)! Has ganado!\n", jugador2, turno);
   }
   else
   {
      printf("La partida termino en empate. Bien jugado!\n");
   }

   printf("\n\n");

   return 0;
}

/**
 * Muestra el tablero del tateti.
 *
 * @param tablero - Una matriz 3x3 que representa el tablero a mostrar.
 *
 * @pre `tablero` debe ser una matriz válida de 3x3.
 *
 * @post Imprime el tablero en la consola, con un formato visual de filas y columnas.
 */
void mostrar_tablero(char tablero[3][3])
{
   printf("Tablero: \n");
   for (int i = 0; i < 3; i++)
   {
      printf("\t");
      for (int j = 0; j < 3; j++)
      {
         printf("| %c ", tablero[i][j]);
      }
      printf("|\n");
   }
}

/**
 * Verifica si hay un ganador en el juego.
 *
 * @param tablero - Una matriz 3x3 que representa el estado actual del juego.
 *
 * @pre `tablero` debe ser una matriz válida de 3x3.
 *
 * @return 1 si hay un ganador en el juego (un jugador ha completado una línea vertical, horizontal o diagonal),
 *         0 si no hay ganador y el juego continúa.
 */
int chequear_ganador(char tablero[3][3])
{
   int flag_ganador = 0;

   if (
       (tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]) || // primera fila
       (tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]) || // segunda fila
       (tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]) || // tercera fila
       (tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]) || // primera columna
       (tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]) || // segunda columna
       (tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]) || // tercera columna
       (tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) || // primera diagonal
       (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])    // segunda diagonal
   )
   {
      flag_ganador = 1;
   }
   return flag_ganador;
}

/**
 * Cambia el turno de juego de 'X' a 'O' o viceversa.
 *
 * @param turno - El turno actual, que puede ser 'X' o 'O'.
 *
 * @pre `turno` debe ser 'X' o 'O'.
 *
 * @return El nuevo turno de juego después de cambiarlo. Si `turno` es 'X', devuelve 'O';
 *         si `turno` es 'O', devuelve 'X'.
 */
char cambiar_turno(char turno)
{
   char nuevo_turno;
   if (turno == 'X')
   {
      nuevo_turno = 'O';
   }
   else
   {
      nuevo_turno = 'X';
   }
   return nuevo_turno;
}

/**
 * Función que permite a un jugador realizar una jugada en el tablero.
 *
 * @param turno - El turno actual del jugador ('X' o 'O').
 * @param tablero - El tablero de juego representado como una matriz 3x3.
 *
 * @pre 'turno' debe ser 'X' o 'O'.
 * @pre 'tablero' debe ser una matriz 3x3 que representa el estado actual del juego.
 *
 * @post El tablero se actualiza con la jugada del jugador.
 *       La función se asegura de que la jugada sea válida antes de actualizar el tablero.
 */
void jugar(char turno, char tablero[3][3])
{
   int jugada;
   char jugada_char;
   int flag_jugada_valida = 0;
   printf("Turno del jugador (%c)\n", turno);

   do // bucle que se repite hasta obtener una jugada valida
   {
      // jugada
      printf("\nIngrese en que posicion desea jugar: ");
      scanf("%d", &jugada);
      printf("\n");

      // Verificación de jugada
      if (jugada >=1 && jugada <=9)
      { 
         jugada_char = 48 + jugada; // convierto el numero en caracter (48 es cero en ascii)

         for (int i = 0; i < 3; i++)
         {
            for (int j = 0; j < 3; j++)
            {
               if (jugada_char == tablero[i][j])
               {
                  tablero[i][j] = turno;
                  flag_jugada_valida = 1; //levanto flag de jugada valida
               }
            }
         }
      }
      if (flag_jugada_valida == 0)
      {
         // Aviso que la jugada fue invalida
         printf("Lugar no disponible. Juegue nuevamente\n");
         mostrar_tablero(tablero);
      }
   } while (flag_jugada_valida == 0);
}