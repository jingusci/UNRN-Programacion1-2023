/*
Trabajo Practico 1 - Ejercicio 11
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/


/*
 Consigna:
 Implementar una función que dado un número entero 
 y un límite, retorne el número incrementado en 1 hasta el límite.
 
 Cuando i == limite, la función retornará 0.
 */
 
#include <stdio.h>

/*
Mantiene i entre 0 y limite?
*/
int contador_circular_alternativo_uno(int i, int limite)
{
    return (i + 1) % (limite + 1);
}

/*
@pre i tiene que ser mayor que cero
*/
int contador_circular_alternativo_dos(int i, int limite)
{
    if (i>= limite)
    {
        i = 0;
    }
    else
    {
        i = i + 1;
    }
    return i;
}

/**
 * Mantiene a i entre 0 y limite
 * @param i el valor del 'contador' a incrementar
 * @param limite, cota superior, no inclusive.
 * @returns i incrementado en 1, 
 *              devuelve 0 cuando i es >= limite o < 0;
 * @precondiciones i puede ser cualquier numero entero
 * @postcondiciones i igual o mayor a 0 
 *                   incrementado en 1 salvo las condiciones indicadas
 *                   en el retorno.
 */

int contador_circular(int i, int limite)
{
    if ((i < 0) || (i>= limite))
    {
        i = 0;
    }
    else
    {
        i = i + 1;
    }
    return i;
}


int main()
{
    int circular = -10;
    int uno = -10;
    int dos = -10;
    int j;

    printf("los contadores comienzan en -10\n");
    printf("20 llamadas a la funcion\n");
    for(j = 0; j < 20; j++)
    {
        circular = contador_circular(circular, 3);
        uno = contador_circular_alternativo_uno(uno, 3);
        dos = contador_circular_alternativo_dos(dos, 3);
        printf("vuelta: %d\t", j);
        printf("circular: %d\t", circular);
        printf("formula: %d\t", uno);
        printf("positivos: %d\n", dos);
    }
    
    return 0;
}
