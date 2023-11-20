/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:

*/

#define CAPACIDAD_MAXIMA 15

// Codigos de salida
#define TODO_OK 0
#define ARREGLO_NULO -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3

/**
 * Comprueba si un arreglo es válido.
 *
 * Esta función verifica si un arreglo es válido según las siguientes
 * condiciones:
 * - El puntero al arreglo no es nulo.
 * - La capacidad del arreglo es mayor o igual a 1.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return Un código de salida que indica si el arreglo es válido o no.
 *         - Si el arreglo es nulo, devuelve ARREGLO_NULO.
 *         - Si la capacidad es menor que 1, devuelve CAPACIDAD_INCORRECTA.
 *         - Si el arreglo es válido, devuelve TODO_OK.
 *
 * @pre El puntero al arreglo puede ser nulo o apuntar a un arreglo válido.
 *      La capacidad debe ser un valor mayor o igual a 1.
 *
 * @post La función devuelve uno de los siguientes códigos:
 *       - ARREGLO_NULO si el arreglo es nulo.
 *       - CAPACIDAD_INCORRECTA si la capacidad es menor que 1.
 *       - TODO_OK si el arreglo es válido.
 */
int es_valido(int capacidad, int arreglo[])
{
    int codigo_salida;

    if (arreglo == NULL)
    {
        codigo_salida = ARREGLO_NULO;
    }
    else if (capacidad < 1)
    {
        codigo_salida = CAPACIDAD_INCORRECTA;
    }
    else
    {
        codigo_salida = TODO_OK;
    }
    return codigo_salida;
}

/**
 * Muestra los elementos de un arreglo.
 *
 * Esta función muestra los elementos de un arreglo si este es válido según la
 * función `es_valido`.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return Un código de salida que indica si la operación se realizó
 * correctamente o no.
 *         - Si el arreglo es nulo o la capacidad es menor que 1, devuelve
 * códigos de error segun es_valido.
 *         - Si la muestra se realizó exitosamente, devuelve TODO_OK.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post Si la muestra se realiza correctamente, se imprimirán los elementos del
 * arreglo. Si el arreglo no es válido, no se realizará ninguna muestra y se
 * mantendrá sin cambios.
 */
int muestra_arreglo(int capacidad, int arreglo[])
{
    int i = 0;
    int codigo_salida = es_valido(capacidad, arreglo);

    if (codigo_salida == TODO_OK)
    {
        printf("(");
        while (i < capacidad)
        {
            printf("%d:%d", i, arreglo[i]);
            i++;
            if (i < capacidad)
            {
                printf(", ");
            }
        }
        printf(")\n");
        codigo_salida = TODO_OK;
    }
    return codigo_salida;
}

/**
 * Elimina elementos duplicados de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros que se modificará para eliminar duplicados.
 * @param capacidad Capacidad máxima del arreglo.
 * @return El nuevo tamaño del arreglo después de eliminar duplicados.
 *
 * Precondiciones:
 *  - 'arreglo' no debe ser un puntero nulo.
 *  - 'capacidad' debe ser mayor o igual a 1.
 *
 * Postcondiciones:
 *  - La función modificará 'arreglo' eliminando elementos duplicados y
 * reorganizándolo para que los elementos no duplicados estén al principio del
 * arreglo.
 *  - La función devolverá el nuevo tamaño del arreglo después de eliminar
 * duplicados.
 *  - Si 'arreglo' es NULL o 'capacidad' es menor que 1, la función no realizará
 * ninguna modificación y devolverá el código de error segun es_valido./
 */
int elimina_duplicados(int arreglo[], int capacidad)
{
    int codigo_salida = es_valido(capacidad, arreglo);
    int nuevo_tamaño = 1;
    int duplicado = 0; // tecnicamente un bool

    int i;
    int j;

    if (codigo_salida == TODO_OK)
    {
        for (i = 1; i < capacidad; i++)
        {
            duplicado = 0;
            j = 0;
            while (j < nuevo_tamaño && !duplicado)
            {
                duplicado = (arreglo[i] == arreglo[j]);
                j++;
            }

            if (!duplicado)
            {
                arreglo[nuevo_tamaño] = arreglo[i];
                nuevo_tamaño++;
            }
        }
    }
    else
    {
        nuevo_tamaño = codigo_salida;
    }
    return nuevo_tamaño;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 1, 3};

    printf("Arreglo original: ");
    muestra_arreglo(6, arr);

    int nuevo_tamanio = elimina_duplicados(arr, 6);

    printf("Arreglo sin duplicados: \n");

    muestra_arreglo(nuevo_tamanio, arr);

    return 0;
}