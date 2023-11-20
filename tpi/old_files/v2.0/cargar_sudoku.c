#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar_sudoku(int tablero[][9]);

void cargar_sudoku(int tablero[][9])
{
    char nombre_archivo[] = "v2.0/sudokus_resueltos/sudoku_guardado.txt";

    FILE *archivo = fopen(nombre_archivo, "r");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo\n");
        // return 1;
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
