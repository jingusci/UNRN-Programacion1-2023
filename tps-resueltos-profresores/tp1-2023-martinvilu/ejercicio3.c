/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:

Implementar una función que reciba un número entero e indique si el mismo es positivo, negativo o cero.
*/

#define NEGATIVO -1
#define CERO 0
#define POSITIVO 1

/*
Esta funcion indica el signo del numero
@param numero a ser evaluado
@returns -1 si el signo de numero es negativo
          0 si el signo de numero es cero y 
          1 si el signo de numero es positivo.
precondiciones de la funcion, un numero entero
Postcondiciones de la funcion, un numero entero entre -1 y 1.
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

int main() {
    int valor = -5;
    int resultado = signo(valor);
    printf("negativo %d => %d\n", valor, resultado);
    
    valor = 0;
    resultado = signo(valor);
    printf("cero %d => %d\n", valor, resultado);
    
    valor = 5;
    resultado = signo(valor);
    printf("positivo %d => %d\n", valor, resultado);
    
    return 0;
}
