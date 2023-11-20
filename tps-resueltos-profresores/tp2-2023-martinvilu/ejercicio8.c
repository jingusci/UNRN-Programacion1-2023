/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdbool.h>


/*
Consigna: Número defectivo

Escribe una función que determine si un número entero positivo es un número defectivo.

Un número defectivo o número deficiente es un número n para el que la suma de sus 
divisores es menor que 2n. De manera equivalente, es un número para el que la suma
 de sus divisores propios (o suma alícuota) es menor que n.

*/

/**
 * Determina si un número entero positivo es un número defectivo.
 *
 * @param numero El número entero positivo a verificar.
 * @return true si el número es defectivo, false en caso contrario.
 *
 * @pre El número debe ser un número entero positivo.
 * @post Devuelve true si el número es defectivo, es decir, 
        la suma de sus divisores propios es menor que el número mismo.
 */
bool es_defectivo(unsigned long long int numero) {
    unsigned long long int suma_divisores = 0;
    unsigned long long int i = 1;
    
    while ( i <= numero / 2 )
    {
        if (numero % i == 0)
        {
            suma_divisores = suma_divisores + i;
        }
        i++;
    }
    return suma_divisores < numero;
}

int main() 
{
    unsigned long long int numero = 2;
    bool resultado;
    
    while (numero < 100000)
    {
        resultado = es_defectivo(numero);
        
        if (resultado)
        {
            printf("%llu es un número defectivo.\n", numero);
        }
        else
        {
            printf("%llu no es un número defectivo.\n", numero);
        }
        numero++;
    }
    return 0;
}

