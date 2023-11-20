#define CANT_SUDOKUS 10

int iniciar_tablero(int **tablero);
int obtener_dificultad();
int obtener_sudoku();

/**
 * Inicia un tablero de Sudoku importando un Sudoku predefinido y ajustando la dificultad.
 *
 * @param tablero Un puntero doble que representa el tablero de Sudoku.
 *
 * @return 1 si el juego se inicia correctamente.
 *
 * @pre - El puntero `tablero` debe apuntar a un tablero de Sudoku válido.
 *
 * @post - La función devuelve 1 si el juego se inicia correctamente.
 *       - El tablero se inicializa con un Sudoku predefinido.
 *       - La dificultad se aplica eliminando algunos números del tablero según el nivel seleccionado.
 */
int iniciar_tablero(int **tablero)
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
         random = (rand() % 9);
         tablero[i][random] = 0;
      }
   }
   return 1; // Juego iniciado
}

/**
 * Solicita al usuario ingresar la dificultad deseada para el Sudoku.
 *
 * @return La dificultad ingresada por el usuario.
 *
 * @pre - El usuario deberá ingresar un número entero válido como dificultad.
 *
 * @post - La función devuelve la dificultad seleccionada por el usuario, que debe estar en el rango de 1 a 10.
 *       - Se realiza una validación para asegurar que la dificultad ingresada esté en el rango permitido.
 *       - La función imprime mensajes para guiar al usuario durante la entrada.
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
   printf("\n Dificultad elegida: %d\n\n", dificultad);

   return dificultad;
}

/**
 * Solicita al usuario ingresar el número de Sudoku deseado para jugar.
 * Ofrece la opción de elegir aleatoriamente si se ingresa 0.
 *
 * @return El número de Sudoku seleccionado por el usuario.
 *
 * @pre - El usuario deberá ingresar un número entero válido como selección de Sudoku.
 * @pre - Se requiere que la constante `CANT_SUDOKUS` esté definida con la cantidad total de sudokus disponibles.
 *
 * @post - La función devuelve el número de Sudoku seleccionado por el usuario.
 *       - Si el usuario ingresa 0, se elige aleatoriamente un Sudoku.
 *       - La función realiza validaciones para asegurarse de que el número ingresado esté en el rango correcto.
 *       - Imprime mensajes para guiar al usuario durante la entrada.
 */
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
         printf("\nERROR: Numero ingresado incorrecto\n\n");
         // scanf("%d", &numero_sudoku);
      }
      else
      {
         printf("\n Sudoku elegido: %d\n\n", numero_sudoku);
      }
   } while (numero_sudoku < 0 || numero_sudoku > CANT_SUDOKUS);

   return numero_sudoku;
}