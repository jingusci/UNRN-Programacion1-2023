int cargar_sudoku(int **tablero);
void guardar_sudoku(int **tablero);
void importar_sudoku(int **tablero, int numero_sudoku);

/**
 * Esta función carga un tablero de Sudoku desde un archivo.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 *
 * @return Retorna 1 si la carga se realizó con éxito, de lo contrario, imprime un mensaje de error y sale del programa.
 *
 * @pre El archivo "sudoku_guardado.txt" debe existir y contener un tablero de Sudoku válido.
 *      El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *
 * @post El tablero se carga con los valores del archivo.
 *
 */
int cargar_sudoku(int **tablero)
{
    char nombre_archivo[] = "sudokus_resueltos/sudoku_guardado.txt";

    FILE *archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                fscanf(archivo, "%d", &tablero[i][j]);
            }
        }
    }
    fclose(archivo);

    return 1;
}

/**
 * Esta función guarda un tablero de Sudoku en un archivo.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 *
 * @pre El archivo "sudoku_guardado.txt" debe tener permisos de escritura.
 *      El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *
 * @post El tablero se guarda en el archivo "sudoku_guardado.txt".
 *
 */
void guardar_sudoku(int **tablero)
{
    char nombre_archivo[] = "sudokus_resueltos/sudoku_guardado.txt";

    FILE *archivo = fopen(nombre_archivo, "w");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo\n");
        // return 0;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                fprintf(archivo, "%d\n", tablero[i][j]);
            }
        }
    }
    fclose(archivo);
}

/**
 * Esta función importa un tablero de Sudoku desde un archivo.
 *
 * @param tablero Es un puntero a un puntero que apunta a la matriz del tablero de Sudoku.
 * @param numero_sudoku Número que identifica el archivo de Sudoku a importar.
 *
 * @pre El archivo "sudoku{numero_sudoku}.txt" debe existir y tener permisos de lectura.
 *      El tablero es una matriz 9x9 que representa el juego de Sudoku.
 *
 * @post El tablero se llena con los valores del archivo "sudoku{numero_sudoku}.txt".
 *
 */
void importar_sudoku(int **tablero, int numero_sudoku)
{
    char nombre_archivo[50];
    sprintf(nombre_archivo, "sudokus_resueltos/sudoku%d.txt", numero_sudoku);

    FILE *archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo: ");
        // return 0;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                fscanf(archivo, "%d", &tablero[i][j]);
            }
        }
    }
    fclose(archivo);
}
