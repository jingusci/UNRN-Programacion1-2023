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

unsigned int fibonacci(unsigned int n);
unsigned int factorial(unsigned int n);

int main()
{
    unsigned int num = 6;

    printf("\nResultados:\n");
    printf("Fibonacci: %d\n", (fibonacci(num)));
    printf("factorial: %d\n", (factorial(num)));
    printf("\n");

    return 0;
}

/**
 * Calcula el término "n" de la secuencia de Fibonacci utilizando recursividad.
 *
 * @param n El número de término de la secuencia de Fibonacci que se desea calcular.
 * @return El valor del término "n" de la secuencia de Fibonacci.
 */
unsigned int fibonacci(unsigned int n) // f(n) = f(n-1) + f(n-2)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

/**
 * Calcula el factorial de un número utilizando recursividad.
 *
 * @param n El número del cual se desea calcular el factorial.
 * @return El factorial de n.
 */
unsigned int factorial(unsigned int n) // n! = n (n-1)!
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
