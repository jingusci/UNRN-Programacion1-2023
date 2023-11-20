/*
Trabajo Practico 4 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Consigna:
Invertir el orden de los elementos presentes en un arreglo
*/

#define CAPACIDAD_MAXIMA 10

// Codigos de salida
#define TODO_OK 0
#define ARREGLO_NULO -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3
#define RANGO_INCORRECTO -4

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
 * Genera un arreglo de enteros con valores aleatorios en un rango especificado.
 *
 * @param arreglo Arreglo de enteros que se llenará con valores aleatorios.
 * @param tamanio Tamaño del arreglo.
 * @param valorMinimo Valor mínimo para los números aleatorios (inclusive).
 * @param valorMaximo Valor máximo para los números aleatorios (inclusive).
 *
 * Precondiciones:
 *  - 'arreglo' no debe ser un puntero nulo.
 *  - 'tamanio' debe ser mayor que 0.
 *  - 'valorMinimo' debe ser menor o igual a 'valorMaximo'.
 *
 * Postcondiciones:
 *  - La función llenará el arreglo 'arreglo' con 'tamanio' valores aleatorios
 * en el rango [valorMinimo, valorMaximo], inclusive.
 *  - El generador de números aleatorios se inicializa con la hora actual para
 * obtener valores realmente aleatorios en cada ejecución.
 *  - La función no devuelve ningún valor; en su lugar, modifica el arreglo
 * 'arreglo' en su lugar.
 */
int carga_aleatoria(int arreglo[], int tamanio, int minimo, int maximo)
{

    int estado = es_valido(tamanio, arreglo);

    if (minimo > maximo)
    {
        estado = RANGO_INCORRECTO;
    }

    if (estado == TODO_OK)
    {
        // Inicializa la semilla para generar números aleatorios
        srand(time(NULL));
        int i = 0;
        while (i < tamanio)
        {
            arreglo[i] = rand() % (maximo - minimo + 1) + minimo;
            i++;
        }
    }
    return estado;
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
 * Invierte un arreglo de enteros en su lugar.
 *
 * @param arreglo Arreglo de enteros que se invertirá.
 * @param tamanio Tamaño del arreglo.
 *
 * Precondiciones:
 *  - 'arreglo' no debe ser un puntero nulo.
 *  - 'tamanio' debe ser mayor o igual a 0.
 *
 * Postcondiciones:
 *  - La función modificará 'arreglo' invirtiendo sus elementos en su lugar.
 *  - Si 'arreglo' es NULL o 'tamanio' es 0, la función no realizará ninguna
 *    modificación en el arreglo.
 *  - Después de llamar a esta función, los elementos del arreglo estarán en
 *    orden inverso.
 */
int invertir(int arreglo[], int tamanio)
{
    int estado = es_valido(tamanio, arreglo);

    int inicio;
    int fin;

    if (estado == TODO_OK)
    {
        inicio = 0;
        fin = tamanio - 1;

        while (inicio < fin)
        {
            intercambia(&arreglo[inicio], &arreglo[fin]);
            inicio++;
            fin--;
        }
    }
    return estado;
}

int main()
{
    int arreglo[CAPACIDAD_MAXIMA];
    int tamanio = CAPACIDAD_MAXIMA;
    int resultado;

    carga_aleatoria(arreglo, tamanio, 0, 100);

    printf("Arreglo original: \n");
    muestra_arreglo(tamanio, arreglo);

    resultado = invertir(arreglo, tamanio);

    printf("Arreglo invertido %d: \n", resultado);
    muestra_arreglo(tamanio, arreglo);

    return 0;
}