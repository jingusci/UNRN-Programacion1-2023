/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Menor de Tres Números
Escribe una función similar a la anterior, pero que devuelva el menor de tres números enteros dados.
*/

/**
 * Encuentra el menor de tres números enteros.
 *
 * @param primero El primer número entero.
 * @param segundo El segundo número entero.
 * @param tercero El tercer número entero.
 * @return El número entero más pequeño entre los tres.
 *
 * @pre Los argumentos primero, segundo y tercero son números enteros válidos.
 * @post El valor devuelto es el número entero más pequeño entre los tres.
 */
int menor_de(int primero, int segundo, int tercero) {
    int minimo = primero;

    if (segundo < minimo) 
    {
        minimo = segundo;
    }

    if (tercero < minimo) 
    {
        minimo = tercero;
    }

    return minimo;
}


int main()
{
    int uno;
    int dos;
    int tres;

    printf("Ingrese tres números enteros separados por espacios: ");
    scanf("%d %d %d", &uno, &dos, &tres);

    int resultado = menor_de(uno, dos, tres);

    printf("El número menor es: %d\n", resultado);

    return 0;
}
