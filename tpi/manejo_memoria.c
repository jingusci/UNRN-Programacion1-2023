int **crear_tablero();
void liberar_tablero(int **matriz);

/**
 * Esta función crea un nuevo tablero de Sudoku.
 *
 * @return Un puntero que apunta a la matriz del nuevo tablero de Sudoku.
 *
 * @post Se crea un nuevo tablero de Sudoku de tamaño 9x9 en memoria.
 *       El tablero es una matriz 9x9 inicializada con ceros.
 *
 */
int **crear_tablero()
{
    int **tablero = (int **)malloc(9 * sizeof(int *));

    for (int i = 0; i < 9; i++)
    {
        tablero[i] = (int *)malloc(9 * sizeof(int));
    }

    return tablero;
}

/**
 * Esta función libera la memoria ocupada por un tablero de Sudoku.
 *
 * @param tablero Es un puntero que apunta a la matriz del tablero de Sudoku.
 *
 * @pre El tablero debe haber sido creado previamente con la función crear_tablero.
 *
 * @post La memoria ocupada por el tablero se libera adecuadamente.
 *
 */
void liberar_tablero(int **tablero)
{
    for (int i = 0; i < 9; i++)
    {
        free(tablero[i]);
    }

    free(tablero);
}