/*
Ejercicio 1 - Matematica recursiva
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int potencia(unsigned int num1, unsigned int num2);
unsigned int suma(unsigned int num1, unsigned int num2);
unsigned int producto(unsigned int num1, unsigned int num2);

int main()
{
    unsigned int numero1 = 2;
    unsigned int numero2 = 3;

    printf("\nResultados:\n");
    printf("Suma:     %d\n", (suma(numero1, numero2)));
    printf("Producto: %d\n", (producto(numero1, numero2)));
    printf("Potencia: %d\n", (potencia(numero1, numero2)));
    printf("\n");

    return 0;
}

/**
 * Calcula la potencia de un número usando recursividad.
 *
 * @param num1 El número base.
 * @param num2 El exponente al que se elevará num1.
 * @return El resultado de num1 elevado a la potencia num2.
 */
unsigned int potencia(unsigned int num1, unsigned int num2)
{
    if (num2 == 1)
    {
        return num1;
    }
    else
    {
        return num1 * potencia(num1, num2 - 1);
    }
}

/**
 * Realiza la suma de dos números usando recursividad.
 *
 * @param num1 El primer número a sumar.
 * @param num2 El segundo número a sumar.
 * @return La suma de num1 y num2.
 */
unsigned int suma(unsigned int num1, unsigned int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return 1 + suma(num1, num2 - 1);
    }
}

/**
 * Realiza el producto de dos números usando recursividad.
 *
 * @param num1 El primer número a multiplicar.
 * @param num2 El segundo número a multiplicar.
 * @return El producto de num1 y num2.
 */
unsigned int producto(unsigned int num1, unsigned int num2)
{
    if (num2 == 1)
    {
        return num1;
    }
    else
    {
        return num1 + producto(num1, num2 - 1);
    }
}