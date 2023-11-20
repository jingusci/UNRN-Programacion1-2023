/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Implementar una función que sume los números enteros 
comprendidos entre dos cotas.

Siendo n inclusive y m no inclusive.
*/

/*
Esta funcion suma entre n y m
@param n, la primera cota
@param m, la segunda cota, inclusive
@returns la suma de los numero comprendidos entre n y m.
            en donde el numero mayor no sera inclusive.

Precondiciones n y m son dos numeros enteros
Postcondiciones el resultado es un valor entero.
*/
int suma_rango(int n, int m)
{
    int suma = 0;
    if (n < m)
    {
        for (; n <= m; n++)
        {
            suma = suma + n;
        }
    }
    else if (n > m)
    {
        for (; m < n; m++)
        {
            suma = suma + m;
        }
    }
    else // n == m
    {
        suma = 0;
    }
    return suma;
}


int main() {
    int inicio = -5;
    int fin = 10;

    int resultado = suma_rango(inicio, fin);

    printf("La suma de los enteros en el rango [%d, %d) es: %d\n", inicio, fin, resultado);

    return 0;
}