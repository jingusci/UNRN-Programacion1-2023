/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Tabla de multiplicar
Desarrolla una función que reciba un número entero como parámetro y muestre en pantalla su tabla de multiplicar del 1 al 10. 
*/


/*
Muestra por pantalla las multiplicaciones de un numero
@param el numero para armar la fila
@returns no hay retornos
Precondiciones el numero debe ser un entero positivo
Postcondiciones la fila incluyendo los operandos y resultados tabulados.
*/
void tabla_de_multiplicar(unsigned int numero)
{
    int i = 0;
    for (i = 0; i < 10 ; i++)
    {
        printf("%dx%d=%d\t", i, numero, i*numero);
    }
    printf("\n");
}


// Mucho sentido no tiene que se pueda ingresar un valor
// por lo que se arma la tabla completa para los digitos
// de siempre.
int main()
{
    for (int i = 0; i < 10 ; i++)
    {
        tabla_de_multiplicar(i);
    }
    return 0;
}
