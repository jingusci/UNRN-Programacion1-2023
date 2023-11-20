#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guardar_sudoku(int tablero[][9]);

void guardar_sudoku(int tablero[][9])
{
    char nombre_archivo[] = "v2.0/sudokus_resueltos/sudoku_guardado.txt";
    // sprintf(nombre_archivo, "v2.0/sudokus_resueltos/sudoku%d.txt", numero_sudoku);

    FILE *archivo = fopen(nombre_archivo, "w");

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
                fprintf(archivo, "%d\n", tablero[i][j]);
            }
        }
    }
    fclose(archivo);
}
