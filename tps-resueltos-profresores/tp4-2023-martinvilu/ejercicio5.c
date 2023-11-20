/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

#define TODO_OK 0
#define PUNTERO_NO_VALIDO -1
#define SIN_ELEMENTOS -2

/*
Consigna:
Implementar una única función que obtenga el mínimo, máximo, suma y promedio de
un arreglo.
*/

/**
 * Calcula el mínimo, máximo, suma y promedio de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros.
 * @param tamano Tamaño del arreglo.
 * @param min Puntero al lugar donde se almacenará el valor mínimo.
 * @param max Puntero al lugar donde se almacenará el valor máximo.
 * @param suma Puntero al lugar donde se almacenará la suma de los elementos.
 * @param promedio Puntero al lugar donde se almacenará el promedio.
 *
 * @pre
 * - El puntero 'arreglo' debe apuntar a un arreglo válido de enteros.
 * - 'tamano' debe ser mayor que 0.
 * - Los punteros 'min', 'max', 'suma' y 'promedio' deben ser válidos.
 *
 * @post
 * - Los punteros 'min', 'max', 'suma' y 'promedio' contendrán los valores
 *      calculados correspondientes.
 * - En caso de que el código de salida no sea TODO_OK, los valores
 *      apuntados no seran modificados.
 */
int estadisticas(int arreglo[], int tamano, int *min, int *max, int *suma,
                 double *promedio)
{
    int codigo_salida = TODO_OK;
    if (tamano <= 0)
    {
        codigo_salida = SIN_ELEMENTOS;
    }
    else if ((min == NULL) || (max == NULL) || (suma == NULL) ||
             (promedio == NULL))
    {
        codigo_salida = PUNTERO_NO_VALIDO;
    }
    else // Esta dentro del else, para que si falla, los valores apuntados no
         // cambien
    {
        *min = arreglo[0];
        *max = arreglo[0];
        *suma = 0;

        for (int i = 0; i < tamano; i++)
        {
            int valor = arreglo[i];

            if (valor < *min)
            {
                *min = valor;
            }

            if (valor > *max)
            {
                *max = valor;
            }

            *suma += valor;
        }
        *promedio = (double)*suma / tamano;
    }
    return codigo_salida;
}

int main()
{
    int arr[] = {5, 8, 2, 12, 7};
    int size = 5;
    int min = 0;
    int max = 0;
    int sum = 0;
    double avg = 0.0;

    int estado = estadisticas(arr, size, &min, &max, &sum, &avg);

    printf("estado de ejecución %d", estado);
    printf("Mínimo: %d\n", min);
    printf("Máximo: %d\n", max);
    printf("Suma: %d\n", sum);
    printf("Promedio: %.2lf\n", avg);

    return 0;
}
