/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

#define ERA_NEGATIVO -1

/*
Consigna: Escribir una función que indique si un número es perfecto.

Se dice que un número es perfecto cuando es igual a la suma de sus divisores 
propios menos sí mismo. Por ejemplo, el 15 no es un número perfecto, pero el 28 sí lo es.
*/


/**
 * Determina si un número es perfecto.
 *
 * @param numero El número entero positivo a verificar.
 * @return 1 si el número es perfecto, 0 en caso contrario.
            ERA_NEGATIVO (-1) si el numero pasado era negativo
 *
 * @pre El número debe ser un número entero positivo.
 * @post Devuelve true si el número es perfecto, es decir, la suma de sus divisores propios
 *       (excluyendo a sí mismo) es igual al número mismo.
 */
int es_perfecto(unsigned long long int numero)
{
    int resultado = 0;
    unsigned long long int suma_divisores = 0;
    unsigned long long int i = 1;
    if (numero <= 0) 
    {
        printf("Error: El número debe ser un entero positivo.\n");
        resultado = ERA_NEGATIVO;
    }
    else
    {
        while ( i <= numero / 2 )
        {
            if (numero % i == 0) 
            {
                suma_divisores += i;
            }
            i++;
        }
        resultado = suma_divisores == numero;
    }
    return resultado;
}

int main()
{
    unsigned long long int numero = 2;
    int resultado;

    while (numero < 10000)
    {
        resultado = es_perfecto(numero);

        if (resultado) 
        {
            printf("%llu es un número perfecto.\n", numero);
        }
        numero++;
    }
    return 0;
}
