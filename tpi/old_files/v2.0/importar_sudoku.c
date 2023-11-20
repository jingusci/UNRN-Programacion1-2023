#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void importar_sudoku(int tablero[][9], int numero_sudoku);

void importar_sudoku(int tablero[][9], int numero_sudoku)
{
    char nombre_archivo[50];
    sprintf(nombre_archivo, "v2.0/sudokus_resueltos/sudoku%d.txt", numero_sudoku);

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
