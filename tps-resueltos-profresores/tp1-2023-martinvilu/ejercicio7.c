/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/**
Consigna:
Escribir una función que retorne 1 si un número entero 
indicado es Primo y 0 cuando no lo sea.

Un número es primo cuando sus divisores son solo si mismo y 1.
*/

/**
Esta funcion indica si el numero es primo.

Esto es que la division del numero da resto cero con 1 y si mismo.

@param el numero a evaluar la condicion
@returns un valor entero representando 0 si no es primo y 1 si lo es.
Precondiciones de la funcion, un numero natural.
Postcondiciones un valor entero entre 0 y 1.
*/
int es_primo(unsigned int numero)
{
    int bandera = 1;
    unsigned int contador = (numero / 2) + 1;

    while(contador > 2 && bandera)
    {
        if (numero % contador == 0)
        {
            bandera = 0;
        }
        else
        {
            bandera = 1;
        }
        contador = contador - 1;
    }
    return bandera;
}

int main() {
    unsigned int valor;
    
    valor = 7;
    int resultado = es_primo(valor);
    printf("%d es primo? %d\n", valor, resultado);
    
    valor = 14;
    resultado = es_primo(valor);
    printf("%d es primo? %d\n", valor, resultado);
    
    valor = 271; // el numero primo numero 59.
    resultado = es_primo(valor);
    printf("%d es primo? %d\n", valor, resultado);
    
    return 0;
}
