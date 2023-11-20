/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna:
Implementar una función que, en el ordenamiento de arreglos de números enteros,
haga uso de la función "intercambia" para hacer los movimientos de los valores
en el arreglo en lugar de hacer las asignaciones entre las posiciones.
*/

/*
 * Notas de la solución del ejercicio:
 * Este ejercicio toma practicamente todo lo del TP3 ejercicio 1, solo
 * modificando lo referido al ordenamiento.
 */

#define CAPACIDAD_MAXIMA 10

// Codigos de salida
#define TODO_OK 0
#define ARREGLO_NULO -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3

/**
 * Imprime un mensaje de error basado en un código de error.
 *
 * Esta función toma el código numérico de error como entrada y muestra un
 * mensaje correspondiente en la salida estándar. Los mensajes se utilizan para
 * describir los diferentes tipos de errores posibles en el programa.
 *
 * @param codigo_error El código de error que indica la naturaleza del problema.
 *
 * @pre El código de error debe ser alguno de los definidos y conocidos:
 *              (TODO_OK, ARREGLO_NULO, SIN_LUGAR_SUFICIENTE,
 * CAPACIDAD_INCORRECTA).
 *
 * @post Se imprime el mensaje de error correspondiente al código de error
 * proporcionado. Si el código de error no es reconocido, se muestra un mensaje
 * genérico que indica un código de error desconocido.
 */
void imprime_mensaje_error(int codigo_error)
{
    if (codigo_error == TODO_OK)
    {
        printf("Todo bien!\n");
    }
    else if (codigo_error == ARREGLO_NULO)
    {
        printf("El arreglo es nulo\n");
    }
    else if (codigo_error == SIN_LUGAR_SUFICIENTE)
    {
        printf("No hay lugar suficiente para la operacion\n");
    }
    else if (codigo_error == CAPACIDAD_INCORRECTA)
    {
        printf("La capacidad no es la correcta (0 o negativa)\n");
    }
    else
    {
        printf("Codigo de error '%d' desconocido!\n", codigo_error);
    }
}

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
 * Carga un arreglo con valores ingresados por el usuario.
 *
 * Esta función carga un arreglo con valores ingresados por el usuario,
 * siempre y cuando el arreglo sea válido según la función `es_valido`.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return Un código de salida que indica si la carga se realizó correctamente o
 * no.
 *         - Si el arreglo es nulo o la capacidad es menor que 1, devuelve
 *            códigos de error segun es_valido.
 *         - Si la carga se realizó exitosamente, devuelve TODO_OK.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post Si la carga se realiza correctamente, el arreglo contendrá los valores
 * ingresados por el usuario. Si el arreglo no es válido, no se realizará
 * ninguna carga y se mantendrá sin cambios.
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
    int i = 0;
    int ingresado = 0;
    int codigo_salida = es_valido(capacidad, arreglo);

    if (codigo_salida == TODO_OK)
    {
        printf("Cargando %d elementos\n", capacidad);
        while (i < capacidad)
        {
            printf("ingresando el %d numero, quedan %d: ", i + 1,
                   capacidad - i);
            scanf("%d", &ingresado);
            arreglo[i] = ingresado;
            i++;
        }
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
 * Intercambia los valores apuntados por dos punteros.
 *
 * @param izquierda Puntero a un entero que apunta al primer valor.
 * @param derecha Puntero a un entero que apunta al segundo valor.
 *
 * @pre
 * - Los punteros 'izquierda' y 'derecha' deben ser válidos y apuntar a enteros.
 *
 * @post
 * - Los valores apuntados por 'izquierda' y 'derecha' han sido intercambiados.
 */
void intercambia(int *izquierda, int *derecha)
{
    int temp = *izquierda;
    *izquierda = *derecha;
    *derecha = temp;
}

/**
 * Ordena un arreglo en orden ascendente.
 *
 * Esta función ordena un arreglo de enteros en orden ascendente.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return Un código de salida que indica si la operación se realizó
 * correctamente o no.
 *         - Si el arreglo no es válido, devuelve códigos de error segun
 * es_valido.
 *         - Si la ordenación se realizó exitosamente, devuelve TODO_OK.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post Si la ordenación se realiza correctamente, el arreglo estará ordenado
 * en orden ascendente. Si el arreglo no es válido, no se realizará ninguna
 * ordenación y se mantendrá sin cambios.
 */
int ordena_ascendente(int capacidad, int arreglo[])
{
    int codigo_salida = es_valido(capacidad, arreglo);
    if (codigo_salida == TODO_OK)
    {
        for (int i = 0; i < capacidad - 1; i++)
        {
            for (int j = 0; j < capacidad - i - 1; j++)
            {
                if (arreglo[j] > arreglo[j + 1])
                {
                    intercambia(&arreglo[j], &arreglo[j + 1]);
                }
            }
        }
    }
    return codigo_salida;
}

int main()
{
    int arreglo[CAPACIDAD_MAXIMA] = {5, 2, 9, 1, 5, 6, 10, -1, 0};
    int capacidad = CAPACIDAD_MAXIMA;

    printf("Antes");
    muestra_arreglo(capacidad, arreglo);

    ordena_ascendente(capacidad, arreglo);

    printf("despues");
    muestra_arreglo(capacidad, arreglo);

    return 0;
}
