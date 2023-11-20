/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Implementar una función que, usando lazos, permita obtener el 
factorial de un número entero positivo.

Nota: Tecnicamente, el factorial mas grande con una variable de tipo
unsigned long long int es de 19! = '121645100408832000' aproximadamente.
*/

#include <stdio.h>

/**
 * Calcula el factorial de un número entero positivo.
 *
 * @param numero El número entero positivo para el cual se calcula el factorial.
 * @return       El factorial de numero. Si numero es negativo, devuelve 0.
 *
 *                     
 * Precondiciones: numero debe ser un número entero positivo o cero.
 * Postcondiciones: La función devuelve el factorial de numero.
 *                  Si numero es negativo, la función devuelve 0.
 *                  El factorial de 0 es 1 (0! = 1).
 */
unsigned long long factorial(int numero) {

    unsigned long long resultado;   
    if (numero < 0) {
        resultado = 0;
    }
    else
    {
        resultado = 1;
        while (numero > 0) {
            resultado = resultado * numero;
            numero--;
        }
    }
    return resultado;
}

int main() {
    // Pruebas con 5 números enteros.
    int numeros[5] = {5, 8, 0, -3, 19};
    int numero;
    unsigned long long resultado;

    for (int i = 0; i < 5; i++) {
        numero = numeros[i];
        resultado = factorial(numero);

        if (numero >= 0) {
            printf("El factorial de %d es %llu\n", numero, resultado);
        } else {
            printf("No se puede calcular el factorial de un numero negativo (%d)\n", numero);
        }
    }

    return 0;
}
