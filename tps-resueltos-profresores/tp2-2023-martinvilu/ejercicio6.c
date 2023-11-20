/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Suma de Números Primos

Crea una función que calcule la suma de los primeros N números primos positivos.
unsigned long long int suma_primos(int cantidad)
*/

int es_primo(unsigned long long int numero);

/**
 * Calcula la suma de los primeros N números primos positivos.
 *
 * @param cantidad de números primos a sumar, debe ser mayor a 0.
 * @return La suma de los primeros N números primos positivos.
 * @pre La función espera un número entero positivo cantidad como entrada.
 * @post Devuelve la suma de los primeros cantidad números primos positivos.
 */

unsigned long long int suma_primos(int cantidad) {
    unsigned long long int suma = 0;
    int contador = 0;
    unsigned long long int numero = 2;
    if (cantidad > 0) 
    {
        while (contador < cantidad) 
        {
            if (es_primo(numero)) 
            {
                suma = suma + numero;
                contador++;
            }
            numero++;
        }
    }
    else // no hay nada que calcular
    {
        suma = 0;
    }
    return suma;
}


/**
Esta funcion indica si el numero es primo.

Esto es que la division del numero da resto cero con 1 y si mismo.

@param el numero a evaluar la condicion
@returns un valor entero representando 0 si no es primo y 1 si lo es.
Precondiciones de la funcion, un numero natural.
Postcondiciones un valor entero entre 0 y 1.

Nota: a diferencia de la del TP1, esta funcion puede trabajar con números mucho
        mas grandes
*/
int es_primo(unsigned long long int numero)
{
    int bandera = 1;
    unsigned long long int contador = (numero / 2) + 1;

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

int main()
{
    int cantidad;

    printf("Ingrese la cantidad de números primos a sumar: ");
    scanf("%d", &cantidad);

    unsigned long long int resultado = suma_primos(cantidad);

    printf("La suma de los primeros %d números primos es: %llu\n", cantidad, resultado);

    return 0;
}
