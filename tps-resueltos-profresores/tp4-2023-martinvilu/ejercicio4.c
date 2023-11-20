/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Implementar una única función que obtenga el cociente y resto de dos números
enteros.
*/

#define DIVISION_POR_CERO -1
#define PUNTERO_NO_VALIDO -2

/**
 * Determina el signo de un número entero.
 *
 * @param numero El número entero a evaluar.
 * @return -1 si el número es negativo, 0 si el número es cero y 1 si el número
 * es positivo.
 *
 * @pre
 * - El parámetro 'numero' debe ser un número entero.
 *
 * @post
 * - La función devuelve un número entero entre -1 y 1 que representa el signo
 * de 'numero'.
 */
int signo(int numero)
{
    int retorno;
    if (numero < 0)
    {
        retorno = -1;
    }
    else if (numero > 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
 * Realiza una división de enteros utilizando un enfoque de división lenta,
 * calculando el cociente y el resto.
 *
 * @param dividendo El número que se va a dividir.
 * @param divisor El número por el cual se va a dividir.
 * @param cociente Puntero a un entero donde se almacenará el cociente.
 * @param resto Puntero a un entero donde se almacenará el resto.
 * @return Un código de salida que indica el resultado de la operación:
 *         - Si la división se realiza con éxito, devuelve 0.
 *         - Si el divisor es igual a cero, devuelve DIVISION_POR_CERO.
 *         - Si los punteros 'cociente' o 'resto' son nulos, devuelve
 *                  PUNTERO_NO_VALIDO.
 *
 * @pre
 * - El puntero 'cociente' debe ser válido y apuntar a un entero.
 * - El puntero 'resto' debe ser válido y apuntar a un entero.
 * - El divisor no debe ser igual a cero.
 *
 * @post
 * - Si la división se realiza con éxito, 'cociente' contendrá el valor del
 * cociente y 'resto' contendrá el valor del resto.
 * - Si el divisor es igual a cero, se devuelve DIVISION_POR_CERO y no se
 * modifican los punteros.
 * - Si los punteros 'cociente' o 'resto' son nulos, se devuelve
 * PUNTERO_NO_VALIDO y no se realizan modificaciones.
 */
int division_lenta(int dividendo, int divisor, int *cociente, int *resto)
{
    int signo_dividendo = signo(dividendo);
    int signo_divisor = signo(divisor);
    int codigo_salida;

    *cociente = 0;
    *resto = 0;

    if (divisor == 0)
    {
        codigo_salida = DIVISION_POR_CERO;
    }
    else if ((cociente == NULL) || (resto == NULL))
    {
        codigo_salida = PUNTERO_NO_VALIDO;
    }
    else
    {
        dividendo = dividendo * signo_dividendo;
        divisor = divisor * signo_divisor;

        while (dividendo >= divisor)
        {
            dividendo -= divisor;
            (*cociente)++;
        }
        *cociente = (*cociente) * signo_dividendo * signo_divisor;
        *resto = dividendo * signo_dividendo;
        codigo_salida = 0;
    }
    return codigo_salida;
}

int main()
{
    int dividendo = 10;
    int divisor = 3;

    int cociente = 0;
    int resto = 0;

    int salida = division_lenta(dividendo, divisor, &cociente, &resto);

    printf("Codigo de error? %d\n", salida);

    printf("Dividendo: %d\n", dividendo);
    printf("Divisor: %d\n", divisor);
    printf("Cociente: %d\n", cociente);
    printf("Resto: %d\n", resto);

    return 0;
}
