/*
Trabajo Practico 3 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Arreglos
*/

//
#define CAPACIDAD_MAXIMA 15

// Codigos de salida
#define TODO_OK 0
#define ARREGLO_NULO -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3

// Prototipos de las funciones
int es_valido(int capacidad, int arreglo[]);
int cargar_arreglo(int capacidad, int arreglo[]);
int muestra_arreglo(int capacidad, int arreglo[]);
int fusiona_arreglos(int capacidad_primero, int primero[],
                     int capacidad_segundo, int segundo[],
                     int capacidad_fusionado, int fusionado[]);
int suma(int capacidad, int arreglo[]);
float promedio(int capacidad, int arreglo[]);
int minimo(int capacidad, int arreglo[]);
int posicion_maximo(int capacidad, int arreglo[]);
int ordena_ascendente(int capacidad, int arreglo[]);
void imprime_mensaje_error(int codigo_error);

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
 * Fusiona dos arreglos en uno más grande.
 *
 * Esta función fusiona dos arreglos en uno más grande, siempre y cuando todos
 * los arreglos involucrados sean válidos según la función `es_valido`, y haya
 * suficiente espacio en el arreglo fusionado.
 *
 * @param capacidad_primero   La capacidad del primer arreglo.
 * @param primero             Un puntero al primer arreglo de enteros.
 * @param capacidad_segundo   La capacidad del segundo arreglo.
 * @param segundo             Un puntero al segundo arreglo de enteros.
 * @param capacidad_fusionado La capacidad del arreglo fusionado.
 * @param fusionado           Un puntero al arreglo fusionado de enteros.
 *
 * @return Un código de salida que indica si la fusión se realizó correctamente
 * o no.
 *         - Si alguno de los arreglos no es válido, devuelve códigos de error
 * segun es_valido.
 *         - Si no hay suficiente espacio en el arreglo fusionado, devuelve
 * SIN_LUGAR_SUFICIENTE.
 *         - Si la fusión se realizó exitosamente, devuelve la cantidad de
 * elementos fusionados.
 *
 * @pre Los arreglos deben ser validos segun la funcion es_valido
 *      La capacidad del arreglo fusionado debe ser mayor que la suma de las
 *          capacidades de los dos arreglos originales.
 *
 * @post Si la fusión se realiza correctamente, el arreglo fusionado contendrá
 *          los elementos de los dos arreglos originales.
 *       Si alguno de los arreglos no es válido o no hay suficiente espacio,
 *          no se realizará ninguna fusión y se mantendrá sin cambios.
 */
int fusiona_arreglos(int capacidad_primero, int primero[],
                     int capacidad_segundo, int segundo[],
                     int capacidad_fusionado, int fusionado[])
{
    int codigo_salida;

    int posicion = 0;
    if ((es_valido(capacidad_primero, primero) != TODO_OK) ||
        (es_valido(capacidad_segundo, segundo) != TODO_OK) ||
        (es_valido(capacidad_fusionado, fusionado) != TODO_OK))
    {
        codigo_salida = ARREGLO_NULO;
        // No sabemos cual exactamente el error y quien es el del problema
    }
    else if (capacidad_fusionado < (capacidad_primero + capacidad_segundo))
    {
        codigo_salida = SIN_LUGAR_SUFICIENTE;
    }
    else
    {
        while (posicion < (capacidad_primero + capacidad_segundo))
        {
            if (posicion < capacidad_primero)
            {
                fusionado[posicion] = primero[posicion];
            }
            else
            {
                fusionado[posicion] = segundo[posicion - capacidad_primero];
            }
            posicion++;
        }
        codigo_salida = posicion;
    }
    return codigo_salida;
}

/**
 * Calcula la suma de los elementos de un arreglo.
 *
 * Esta función suma todos los elementos de un arreglo y devuelve el resultado.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return La suma de los elementos del arreglo.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post La función devuelve la suma de todos los elementos del arreglo.
 */
int suma(int capacidad, int arreglo[])
{
    int i = 0;
    int sumador = 0;

    while (i < capacidad)
    {
        sumador = sumador + arreglo[i];
        i++;
    }

    return sumador;
}

/**
 * Calcula el promedio de los elementos de un arreglo.
 *
 * Esta función calcula el promedio de los elementos de un arreglo.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return El promedio de los elementos del arreglo como un valor de punto
 * flotante.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post La función devuelve el promedio de los elementos del arreglo.
 */
float promedio(int capacidad, int arreglo[])
{
    return suma(capacidad, arreglo) / capacidad;
}

/**
 * Encuentra el valor mínimo en un arreglo.
 *
 * Esta función encuentra y devuelve el valor mínimo en un arreglo de enteros.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return El valor mínimo en el arreglo.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post La función devuelve el valor mínimo encontrado en el arreglo.
 */
int minimo(int capacidad, int arreglo[])
{
    int i = 1;
    int minimo;

    i = 1;
    minimo = arreglo[0];
    while (i < capacidad)
    {
        if (minimo > arreglo[i])
        {
            minimo = arreglo[i];
        }
        i++;
    }

    return minimo;
}

/**
 * Encuentra la posición del valor máximo en un arreglo.
 *
 * Esta función encuentra y devuelve la posición del valor máximo en un arreglo
 * de enteros. La posición se refiere al índice del arreglo donde se encuentra
 * el valor máximo.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo de enteros.
 *
 * @return La posición del valor máximo en el arreglo.
 *
 * @pre El arreglo debe ser valido segun la funcion es_valido
 *
 * @post La función devuelve la posición del valor máximo encontrado en el
 * arreglo.
 */
int posicion_maximo(int capacidad, int arreglo[])
{
    int i = 1;
    int maximo = arreglo[0];
    int posicion = 0;

    while (i < capacidad)
    {
        if (maximo < arreglo[i])
        {
            maximo = arreglo[i];
            posicion = i;
        }
        i++;
    }

    return posicion;
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
    int temporario;
    int i;
    int j;
    int codigo_salida = es_valido(capacidad, arreglo);

    if (codigo_salida == TODO_OK)
    {
        for (i = 0; i < capacidad - 1; i++)
        {
            for (j = 0; j < capacidad - i - 1; j++)
            {
                if (arreglo[j] > arreglo[j + 1])
                {
                    temporario = arreglo[j];
                    arreglo[j] = arreglo[j + 1];
                    arreglo[j + 1] = temporario;
                }
            }
        }
    }
    return codigo_salida;
}

int main()
{
    int capacidad = 5;
    int arreglo1[5] = {5, 4, 3, 2, 1};
    int arreglo2[5] = {10, 20, 30, 40, 50};
    int arreglo_fusionado[CAPACIDAD_MAXIMA];

    printf("Arreglo 1: ");
    muestra_arreglo(capacidad, arreglo1);

    printf("Arreglo 2: ");
    muestra_arreglo(capacidad, arreglo2);

    // Cargar
    int carga_arreglo1 = cargar_arreglo(capacidad, arreglo1);
    int carga_arreglo2 = cargar_arreglo(capacidad, arreglo2);

    if (carga_arreglo1 == TODO_OK && carga_arreglo2 == TODO_OK)
    {
        printf("Arreglo 1 cargado con exito: \n");
        muestra_arreglo(capacidad, arreglo1);

        printf("Arreglo 2 cargado con exito: \n");
        muestra_arreglo(capacidad, arreglo2);
    }
    else
    {
        printf("Error en la carga de los arreglos.\n");
    }

    // Fusion
    int capacidad_fusionado = capacidad * 2;
    int fusion_resultado =
        fusiona_arreglos(capacidad, arreglo1, capacidad, arreglo2,
                         capacidad_fusionado, arreglo_fusionado);

    if (fusion_resultado >= TODO_OK)
    {
        printf("Arreglo fusionado: \n");
        muestra_arreglo(capacidad_fusionado, arreglo_fusionado);
    }
    else
    {
        imprime_mensaje_error(fusion_resultado);
        printf("Error en la fusion de los arreglos.\n");
    }

    // Operaciones
    int suma_resultado = suma(capacidad_fusionado, arreglo_fusionado);
    float promedio_resultado = promedio(capacidad_fusionado, arreglo_fusionado);
    int minimo_resultado = minimo(capacidad_fusionado, arreglo_fusionado);
    int posicion_maximo_resultado =
        posicion_maximo(capacidad_fusionado, arreglo_fusionado);

    printf("Suma de elementos en el arreglo fusionado: %d\n", suma_resultado);
    printf("Promedio de elementos en el arreglo fusionado: %.2f\n",
           promedio_resultado);
    printf("Valor minimo en el arreglo fusionado: %d\n", minimo_resultado);
    printf("Posicion del valor maximo en el arreglo fusionado: %d y es %d\n",
           posicion_maximo_resultado,
           arreglo_fusionado[posicion_maximo_resultado]);

    // Ordenar
    int ordena_resultado =
        ordena_ascendente(capacidad_fusionado, arreglo_fusionado);

    if (ordena_resultado == TODO_OK)
    {
        printf("Arreglo fusionado ordenado en orden ascendente:\n");
        muestra_arreglo(capacidad_fusionado, arreglo_fusionado);
    }
    else
    {
        imprime_mensaje_error(ordena_resultado);
        printf("Error en la ordenación del arreglo fusionado.\n");
    }

    return 0;
}
