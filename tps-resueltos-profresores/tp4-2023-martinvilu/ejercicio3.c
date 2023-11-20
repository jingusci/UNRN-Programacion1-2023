/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Duplicar el valor de una variable usando punteros
*/

#define SIN_ERROR 0
#define PUNTERO_NULO 1

/**
 * Duplica el valor de una variable usando punteros.
 *
 * @param ptr_numero Puntero a la variable que se duplicará.
 *
 * @returns SIN_ERROR cuando la operacion pudo ser efectuada
 *          PUNTERO_NULO si ptr_numero no es valido
 * @pre
 * - El puntero 'ptr_numero' debe ser válido y apuntar a una variable entera.
 *
 * @post
 * - El valor apuntado por 'ptr_numero' se duplica, es decir, se multiplica
 * por 2.
 */
int duplica(int *ptr_numero)
{
    int codigo_salida = SIN_ERROR;
    if (ptr_numero == NULL)
    {
        codigo_salida = PUNTERO_NULO;
    }
    else
    {
        *ptr_numero = (*ptr_numero) * 2;
    }
    return codigo_salida;
}

int main()
{
    int numero = 7;
    int codigo;
    printf("Antes de duplicar: numero = %d\n", numero);

    codigo = duplica(&numero);
    if (codigo == SIN_ERROR)
    {
        printf("Después de duplicar: numero = %d\n", numero);
    }
    else
    {
        printf("El puntero empleado no era valido\n");
    }

    return 0;
}