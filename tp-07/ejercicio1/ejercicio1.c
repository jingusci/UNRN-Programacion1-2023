/*
Ejercicio 1 - Valores Puntuales
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/**
 * Esta función reserva memoria dinámica para almacenar un valor entero y devuelve
 * un puntero a la memoria reservada.
 *
 * @param valor - Valor entero que se almacenará en la memoria reservada.
 *
 * @return  - Un puntero a la memoria reservada si la reserva de memoria fue exitosa.
 *           NULL si no se pudo reservar memoria.
 *
 * @pre     - La función espera recibir un valor entero como parámetro.
 *
 * @post    - La función reserva memoria dinámica para almacenar un valor entero y
 *            asigna el valor proporcionado a la memoria reservada.
 *            Devuelve un puntero a la memoria reservada si la reserva fue exitosa,
 *            o NULL si no se pudo reservar memoria.
 *            Es responsabilidad del llamador liberar la memoria cuando ya no sea
 *            necesaria utilizando la función 'free()'.
 *
 */
int *reserva_entero(int valor)
{
    int *entero = (int *)malloc(sizeof(int));

    if (entero != NULL)
    {
        *entero = valor;
    }

    return entero;
}

/**
 * Esta función libera la memoria dinámica previamente reservada para un valor
 * entero y devuelve dicho valor, si el puntero no es NULL.
 *
 * @param ptr_entero - Puntero a la memoria dinámica que se desea liberar.
 *
 * @return  - El valor entero previamente almacenado en la memoria dinámica
 *            liberada, si el puntero no es NULL.
 *          - Si el puntero es NULL, se muestra un mensaje de error y no se
 *            devuelve ningún valor definido.
 *
 * @pre     - El parámetro 'ptr_entero' debe ser un puntero previamente asignado
 *            por la función 'reserva_entero' o por una función similar.
 *
 * @post    - La función libera la memoria dinámica apuntada por 'ptr_entero' si
 *            'ptr_entero' no es NULL.
 *          - El valor entero previamente almacenado en la memoria dinámica se
 *            devuelve como resultado, si el puntero no es NULL.
 *          - Si 'ptr_entero' es NULL, se muestra un mensaje de error y no se
 *            devuelve ningún valor definido.
 *          - Es importante liberar la memoria cuando ya no sea necesaria para
 *            evitar fugas de memoria (memory leaks).
 *
 */
int libera_entero(int *ptr_entero)
{
    if (ptr_entero != NULL)
    {
        int valor = *ptr_entero;
        free(ptr_entero);
        return valor;
    }
    else
    {
        printf("Puntero NULL, no se pudo liberar la memoria.");
    }
}

// Funciones extra para realizar operciones
int suma(int a, int b)
{
    return a + b;
}
int resta(int a, int b)
{
    return a - b;
}
int multiplicacion(int a, int b)
{
    return a * b;
}
float division(int a, int b)
{
    if (b != 0)
    {
        return ((a * 1.0) / (b * 1.0));
    }
}