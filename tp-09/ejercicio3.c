/*
Ejercicio 1 - Series
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_arreglo(int *arreglo, unsigned int size);
void mostrar_arreglo_invertido(int *arreglo, unsigned int size);
int suma_valores_arreglo(int *arreglo, unsigned int size);

int main()
{
    unsigned int size = 5;
    int arreglo[5] = {1, 2, 3, 4, 5};

    printf("\nResultados:\n");
    printf("\nMostrar arreglo: ");
    mostrar_arreglo(arreglo, size);
    printf("\nMostrar arreglo invertido: ");
    mostrar_arreglo_invertido(arreglo, size);
    printf("\nSuma: %d\n", (suma_valores_arreglo(arreglo, size)));
    printf("\n");

    return 0;
}

/**
 * Muestra los valores de un arreglo en orden ascendente utilizando recursividad.
 *
 * @param arreglo Un puntero al arreglo de enteros.
 * @param size La cantidad de elementos en el arreglo.
 */
void mostrar_arreglo(int *arreglo, unsigned int size)
{
    if (size == 0)
    {
        return;
    }
    printf("%d ", arreglo[0]);
    return mostrar_arreglo(arreglo + 1, size - 1);
}

/**
 * Muestra los valores de un arreglo en orden inverso utilizando recursividad.
 *
 * @param arreglo Un puntero al arreglo de enteros.
 * @param size La cantidad de elementos en el arreglo.
 */
void mostrar_arreglo_invertido(int *arreglo, unsigned int size)
{
    if (size == 0)
    {
        return;
    }
    printf("%d ", arreglo[size - 1]);
    return mostrar_arreglo_invertido(arreglo, size - 1);
}

/**
 * Calcula la suma de los valores en un arreglo utilizando recursividad.
 *
 * @param arreglo Un puntero al arreglo de enteros.
 * @param size La cantidad de elementos en el arreglo.
 * @return La suma de los valores en el arreglo.
 */
int suma_valores_arreglo(int *arreglo, unsigned int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arreglo[size - 1] + suma_valores_arreglo(arreglo, size - 1);
}
