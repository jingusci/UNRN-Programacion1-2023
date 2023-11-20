/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Escribir una función que retorne 1 si un número entero es múltiplo de otro, utilizando sumas y restas.
*/

/**
 * Verifica si un número es múltiplo de otro utilizando sumas y restas.
 *
 * @param numero   El número que se va a verificar si es múltiplo.
 * @param multiplo El número por el cual se va a verificar si 'numero' es múltiplo.
 * @return         1 si 'numero' es múltiplo de 'multiplo', 0 en caso contrario.
 *                   -1 si el multiplo es 0
 *
 * Precondiciones: Ambos 'numero' y 'multiplo' deben ser enteros.
 *                 'multiplo' debe ser distinto de cero (no se puede dividir por cero).
 * Postcondiciones: 
 *                  La función devuelve -1 si el multiplo es negativo.
 *                  La función devuelve 1 si 'numero' es múltiplo de 'multiplo'.
 *                  La función devuelve 0 en caso contrario.
 */
int es_multiplo(int numero, int multiplo) 
{
    int bandera;
    if (multiplo == 0)
    {
        bandera = -1;
    }
    else
    {
        while (numero >= multiplo) 
        {
            numero = numero - multiplo;
        }
        bandera = (numero == 0);
    }
    return bandera;
}

int main()
{
    // Casos significativos
    int casos[6][3] = {
        {12, 4, 1},    // 12 es múltiplo de 4
        {15, 5, 1},    // 15 es múltiplo de 5
        {20, 7, 0},    // 20 no es múltiplo de 7
        {8, 2, 1},     // 8 es múltiplo de 2
        {25, 3, 0},    // 25 no es múltiplo de 3
        {10,0,-1}      // division por cero
    };

    for (int i = 0; i < 5; i++)
    {
        int numero = casos[i][0];
        int multiplo = casos[i][1];
        int esperado = casos[i][2];

        int resultado = es_multiplo(numero, multiplo);

        printf("El numero %d ", numero);
        if (resultado)
        {
            printf("es");
        }
        else
        {
            printf("no es");
        }
        printf(" multiplo de %d - ", multiplo);

        printf("se esperaba %d, que fue ", esperado);
        if (resultado == esperado)
        {
            printf("correcto");
        }
        else
        {
            printf("incorrecto");
        }
        printf(" con %d\n", resultado);

    }

    return 0;
}
