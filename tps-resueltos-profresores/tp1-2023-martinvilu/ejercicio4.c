/*
Trabajo Practico 1 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:

Implementar una función que retorne el ordenamiento de dos números.
*/

#define MENOR -1
#define IGUAL 0
#define MAYOR 1

/*
La funcion indica el ordenamiento de otro_numero con respecto a numero
@param numero es el numero inicial a ser evaluado
@param otro_numero es el numero contra el que numero sera comparado
@returns  -1 si otro_numero es menor, 
          0  si ambos son iguales y 
          1  si otro_numero es mayor
Precondiciones de la funcion; dos numeros enteros
Postcondiciones un valor entre -1 y 1 que representa 
                el orden entre los parametros..
*/
int compara(int numero, int otro_numero)
{
    int resultado = 0;
    if (numero < otro_numero)
    {
        resultado = 1;
    }
    else if (numero > otro_numero)
    {
        resultado = -1;
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}

int main() {
    int valor_uno;
    int valor_dos;
    int resultado;
    
    valor_uno = 10;
    valor_dos = 5;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) menor que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);

    valor_uno = 10;
    valor_dos = 10;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) igual que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);
                
    valor_uno = 5;
    valor_dos = 10;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) mayor que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);

    return 0;
}


