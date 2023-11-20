#include <stdio.h>

/**
 * Estructura de datos para mi jugada, que contiene:
 *    Fila
 *    Columna
 *    Valor
*/
struct jugada
{
   int fila;
   int columna;
   int valor;
} typedef jugada_t;

jugada_t solicitar_jugada();
int validar_jugada(int tablero[][9], jugada_t jugada);
void colocar_jugada(int tablero[][9], jugada_t jugada);
void jugar(int tablero[][9]);

/**
 * Solicita por teclado los valores correspondientes a la jugada.
*/
jugada_t solicitar_jugada()
{
   jugada_t jugada;

   // solicito fila
   printf("\ningrese fila: ");
   scanf("%d", &jugada.fila);
   while (jugada.fila < 1 || jugada.fila > 9)
   {
      printf("\nERROR: ingrese fila entre 1 y 9: ");
      scanf("%d", &jugada.fila);
   }
   jugada.fila--;

   // solicito columna
   printf("\ningrese columna: ");
   scanf("%d", &jugada.columna);
   while (jugada.columna < 1 || jugada.columna > 9)
   {
      printf("\nERROR: ingrese columna entre 1 y 9: ");
      scanf("%d", &jugada.columna);
   }
   jugada.columna--;

   // solicito valor
   printf("\ningrese valor: ");
   scanf("%d", &jugada.valor);
   while (jugada.valor < 1 || jugada.valor > 9)
   {
      printf("\nERROR: ingrese valor entre 1 y 9: ");
      scanf("%d", &jugada.valor);
   }

   return jugada;
}

/**
 * Valida jugada. Devuelve:
 *    0 - Si es una jugada valida
 *    1 - Si el nro ya está en la fila
 *    2 - Si el nro ya está en la columna
 *    3 - Si el nro ya está en el cuadrito
 *    4 - Si el lugar ya estaba ocupado por un numero
*/
int validar_jugada(int tablero[][9], jugada_t jugada)
{
   // validar fila:

   for (int i = 0; i < 9; i++)
   {
      if (tablero[jugada.fila][i] == jugada.valor)
      {
         return 1; // error fila
      }
   }

   // validar columna:
   for (int i = 0; i < 9; i++)
   {
      if (tablero[i][jugada.columna] == jugada.valor)
      {
         return 2; // error columna
      }
   }

   // validar cuadrito:
   int fila_cuadrito = (jugada.fila / 3) * 3;
   int columna_cuadrito = (jugada.columna / 3) * 3;
   for (int i = fila_cuadrito; i < fila_cuadrito + 3; i++)
   {
      for (int j = columna_cuadrito; j < columna_cuadrito + 3; j++)
      {
         if (tablero[i][j] == jugada.valor)
         {
            return 3; // error en el cuadrito
         }
      }
   }

   // TBC Ver si hace falta validar que el lugar no esté ocupado ya
   if (tablero[jugada.fila][jugada.columna] != 0)
   {
      return 4; // Error ya hay un numero en esa posicion
   }

   return 0;
}

/**
 * actualiza el tablero con el valor dado
*/
void colocar_jugada(int tablero[][9], jugada_t jugada)
{
   tablero[jugada.fila][jugada.columna] = jugada.valor;
}

/**
 * Funcion completa de jugar.
 * Analiza si es posible jugar o avisa lo contrario.
*/
void jugar(int tablero[][9])
{
   jugada_t jugada = solicitar_jugada();
   int jugada_valida = validar_jugada(tablero, jugada);
   if (jugada_valida == 0)
   {
      colocar_jugada(tablero, jugada);
      printf("Se ingreso el valor %d en la pos (%d,%d)\n\n", jugada.valor, jugada.fila + 1, jugada.columna + 1);
   }
   else if (jugada_valida == 1)
   {
      printf("ERROR: El numero ingresado ya se encuentra en esa fila\n");
   }
   else if (jugada_valida == 2)
   {
      printf("ERROR: El numero ingresado ya se encuentra en esa columna\n");
   }
   else if (jugada_valida == 3)
   {
      printf("ERROR: El numero ingresado ya se encuentra en ese cuadrito\n");
   }
   else if (jugada_valida == 4)
   {
      printf("ERROR: El lugar ingresado ya se encuentra ocupado\n");
   }
}