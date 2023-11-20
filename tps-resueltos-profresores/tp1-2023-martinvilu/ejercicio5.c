/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:

*/

/*
Esta funcion reimplementa el operador de suma utilizando sumas
de a 1, en lugar de usar el operador.

(podria usar los ++ y --, para dejarlo mas compacto)

@param numero el primer termino a sumar
@param otro_numero el sumando a sumar
@returns la suma de ambos numeros
Precondiciones dos numeros enteros
Postcondiciones 
        el signo del retorno sera el del valor mayor.
        el valor sera un numero entero equivalente a la suma tradicional
            de ambos.
*/
int suma_lenta(int numero, int otro_numero)
{
    if (otro_numero > 0)
    {
        while (otro_numero)
        {
            otro_numero = otro_numero - 1;
            numero = numero + 1;
        }
    }
    else if (otro_numero < 0)
    {
        while (otro_numero)
        {
            otro_numero = otro_numero + 1;
            numero = numero - 1;
        }
    }
//    else
//    {
// no hay mucho que hacer cuando el otro_numero es cero
//    }
    return numero;
}

int main()
{
    int valor_uno;
    int valor_dos;
    int resultado;
    
    valor_uno = 10;
    valor_dos = 5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    valor_uno = -10;
    valor_dos = -5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    
    valor_uno = 10;
    valor_dos = -10;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    valor_uno = -10;
    valor_dos = 5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    return 0;
}
