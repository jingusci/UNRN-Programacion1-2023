#define JUGADA_OK 0
#define ERROR_FILA 1
#define ERROR_COLUMNA 2
#define ERROR_CUADRO 3
#define ERROR_POSICION 4

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
int verificar_jugada(int **tablero, jugada_t jugada);
void colocar_jugada(int **tablero, jugada_t jugada);
int jugar(int **tablero, int *flag_jugando);
int contar_ceros(int **tablero);

/**
 * Esta función solicita al usuario una jugada para el juego de Sudoku.
 *
 * @return Una estructura jugada_t que contiene la fila, columna y valor ingresados por el usuario.
 *         Si el usuario elige volver al menú principal, la función devuelve una jugada con valores -1.
 *
 * @pre El usuario debe ingresar valores numéricos válidos para la fila, columna y valor.
 *       Todos los valores son del rango del 1 a 9.
 *
 * @post La función devuelve una estructura jugada_t con los valores ingresados por el usuario.
 *       Si el usuario elige volver al menú principal, la función devuelve una jugada con valores -1.
 *       Se imprime un mensaje de error si el usuario ingresa valores fuera del rango permitido.
 *
 */
jugada_t solicitar_jugada()
{
   jugada_t jugada;

   // solicito fila
   printf("\nIngrese fila (o ingrese 0 para volver al menu principal): ");
   scanf("%d", &jugada.fila);
   while (jugada.fila < 0 || jugada.fila > 9)
   {
      printf("\nERROR-> ingrese fila entre 1 y 9 (o ingrese 0 para volver al menu principal): ");
      scanf("%d", &jugada.fila);
   }
   jugada.fila--;
   if (jugada.fila == -1)
   {
      jugada.fila = -1;
      jugada.columna = -1;
      jugada.valor = -1;
      return jugada;
   }

   // solicito columna
   printf("Ingrese columna: ");
   scanf("%d", &jugada.columna);
   while (jugada.columna < 1 || jugada.columna > 9)
   {
      printf("\nERROR-> ingrese columna entre 1 y 9: ");
      scanf("%d", &jugada.columna);
   }
   jugada.columna--;

   // solicito valor
   printf("Ingrese valor: ");
   scanf("%d", &jugada.valor);
   while (jugada.valor < 1 || jugada.valor > 9)
   {
      printf("\nERROR-> ingrese valor entre 1 y 9: ");
      scanf("%d", &jugada.valor);
   }

   return jugada;
}

/**
 * Esta función verifica la validez de una jugada en el juego de Sudoku.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 * @param jugada Es una estructura jugada_t que contiene la fila, columna y valor de la jugada a verificar.
 *
 * @return Un código que indica el estado de la jugada:
 *         - JUGADA_OK si la jugada es válida.
 *         - ERROR_POSICION si la posición en el tablero ya está ocupada.
 *         - ERROR_FILA si el valor ya existe en la fila.
 *         - ERROR_COLUMNA si el valor ya existe en la columna.
 *         - ERROR_CUADRO si el valor ya existe en el cuadrito 3x3 al que pertenece la posición.
 *
 * @pre El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *      La jugada contiene valores válidos para fila, columna y valor.
 *
 * @post La función devuelve un código que indica si la jugada es válida o cuál es el error.
 *       No se realizan cambios en el tablero.
 *
 */
int verificar_jugada(int **tablero, jugada_t jugada)
{

   // Validar posicion vacia
   if (tablero[jugada.fila][jugada.columna] != 0)
   {
      return ERROR_POSICION;
   }

   // validar fila:
   for (int i = 0; i < 9; i++)
   {
      if (tablero[jugada.fila][i] == jugada.valor)
      {
         return ERROR_FILA;
      }
   }

   // validar columna:
   for (int i = 0; i < 9; i++)
   {
      if (tablero[i][jugada.columna] == jugada.valor)
      {
         return ERROR_COLUMNA;
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
            return ERROR_CUADRO;
         }
      }
   }

   return JUGADA_OK;
}

/**
 * Esta función coloca una jugada en el tablero de Sudoku si la jugada es válida.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 * @param jugada Es una estructura jugada_t que contiene la fila, columna y valor de la jugada a colocar.
 *
 * @pre El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *      La jugada contiene valores válidos para fila, columna y valor.
 *
 * @post Si la jugada es válida, actualiza el tablero con el valor de la jugada en la posición correspondiente.
 *       Imprime un mensaje indicando el éxito o un mensaje de error si la jugada no es válida.
 *
 */
void colocar_jugada(int **tablero, jugada_t jugada)
{
   int flag_jugada_valida = verificar_jugada(tablero, jugada);

   if (flag_jugada_valida == JUGADA_OK)
   {
      tablero[jugada.fila][jugada.columna] = jugada.valor; // Actualizo tablero con la jugada
      printf("Se ingreso el valor %d en la pos (%d,%d)\n\n", jugada.valor, jugada.fila + 1, jugada.columna + 1);
      printf("\n==================================================\n\n");
   }
   else if (flag_jugada_valida == ERROR_FILA)
   {
      printf("ERROR: El numero ingresado ya se encuentra en esa fila\n");
   }
   else if (flag_jugada_valida == ERROR_COLUMNA)
   {
      printf("ERROR: El numero ingresado ya se encuentra en esa columna\n");
   }
   else if (flag_jugada_valida == ERROR_CUADRO)
   {
      printf("ERROR: El numero ingresado ya se encuentra en ese cuadrito\n");
   }
   else if (flag_jugada_valida == ERROR_POSICION)
   {
      printf("ERROR: El lugar ingresado ya se encuentra ocupado\n");
   }
}

/**
 * Esta función permite al jugador realizar una jugada en el juego de Sudoku.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 * @param flag_jugando Es un puntero a un entero que indica si el juego está en curso.
 *
 * @return La cantidad de posiciones vacías en el tablero después de la jugada.
 *
 * @pre El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *      flag_jugando es un puntero válido.
 *
 * @post Muestra el tablero actual y la cantidad de posiciones que faltan completar.
 *       Solicita una jugada al jugador y la coloca en el tablero si es válida.
 *       Actualiza flag_jugando a 0 si el jugador decide salir del juego.
 *       Retorna la cantidad de posiciones vacías después de la jugada.
 *
 */
int jugar(int **tablero, int *flag_jugando)
{
   int ceros = contar_ceros(tablero);

   mostrar_tablero(tablero);
   printf("\nFaltan completar %d posiciones\n", ceros);
   printf("==================================================\n\n");

   jugada_t jugada = solicitar_jugada();
   if (jugada.fila == -1)
   {
      *flag_jugando = 0;
   }
   else
   {
      colocar_jugada(tablero, jugada);
      ceros = contar_ceros(tablero);
   }
   return ceros;
}

/**
 * Esta función cuenta la cantidad de ceros en el tablero de Sudoku.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 *
 * @return La cantidad de ceros en el tablero.
 *
 * @pre El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *
 * @post Retorna la cantidad de ceros presentes en el tablero.
 *
 */
int contar_ceros(int **tablero)
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