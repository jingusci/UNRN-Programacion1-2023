/*
Ejercicio 2 - Fila (queue)
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ejercicio1.c"

// La estructura de nodo la importo del ejercicio 1, junto con la funcion de crear nodo
typedef struct cola
{
    nodo_t *frente;
    nodo_t *final;
} cola_t;


cola_t *crear_cola();
int esta_vacia(cola_t *cola);
void encolar(cola_t *cola, int dato);
int desencolar(cola_t *cola);
int frente_cola(cola_t *cola);
void vaciar_cola(cola_t *cola);

/**
 * Esta función crea y retorna una nueva cola vacía.
 *
 * @return cola_t * - Puntero a una cola vacía recién creada.
 * 
 * @post - Se reserva memoria para la cola y se inicializan sus punteros 'frente' y 'final' en NULL.
 *         Retorna un puntero a la cola recién creada.
 *
 */
cola_t *crear_cola()
{
    cola_t *cola = (cola_t *)malloc(sizeof(cola_t));
    if (cola != NULL)
    {
        cola->frente = NULL;
        cola->final = NULL;
    }

    return cola;
}

/**
 * Esta función verifica si la cola está vacía.
 *
 * @param cola - Puntero a la cola que se desea verificar.
 *
 * @return int - 1 si la cola está vacía, 0 en caso contrario.
 * 
 * @pre - El parámetro 'cola' debe ser un puntero válido a una cola previamente creada.
 * 
 * @post - La función verifica si la cola está vacía al comprobar si el puntero 'frente' de la cola es NULL.
 *         Retorna 1 si está vacía o 0 si no lo está.
 *
 */
int esta_vacia(cola_t *cola)
{
    int result = 0;
    if (cola->frente == NULL)
    {
        result = 1;
    }
    return result;
}

/**
 * Esta función agrega un nuevo elemento al final de la cola.
 *
 * @param cola - Puntero a la cola en la que se desea encolar el elemento.
 * @param dato - El valor que se desea encolar en la cola.
 * 
 * @pre - El parámetro 'cola' debe ser un puntero válido a una cola previamente creada.
 * 
 * @post - La función crea un nuevo nodo con el valor 'dato' y lo agrega al final de la cola, actualizando el puntero 'final'.
 *
 */
void encolar(cola_t *cola, int dato)
{
    nodo_t *nuevo_nodo = crear_nodo(dato); // Funcion del ejercicio1

    if (esta_vacia(cola) == 1)
    {
        cola->frente = nuevo_nodo;
    }
    else
    {
        cola->final->siguiente = nuevo_nodo;
    }
    cola->final = nuevo_nodo;
}

/**
 * Esta función remueve y retorna el elemento en el frente de la cola.
 *
 * @param cola - Puntero a la cola de la que se desea desencolar el elemento.
 *
 * @return int - El valor del elemento desencolado.
 * 
 * @pre - El parámetro 'cola' debe ser un puntero válido a una cola previamente creada.
 * 
 * @post - La función verifica si la cola está vacía. Si no lo está, desencola el elemento en el frente de la cola y actualiza 'frente'.
 *         Retorna el valor del elemento desencolado.
 *         Si la cola está vacía, muestra un mensaje de error y sale del programa.
 *
 */
int desencolar(cola_t *cola)
{
    if (esta_vacia(cola) == 1)
    {
        printf("La cola esta vacia.\n");
        exit(1); // Manejo de error, la cola está vacía.
    }

    int dato = cola->frente->valor;
    nodo_t *nodo_a_eliminar = cola->frente;
    cola->frente = cola->frente->siguiente;

    // Si la cola quedó vacía después de desencolar el nodo, actualizo final.
    if (cola->frente == NULL)
    {
        cola->final = NULL;
    }

    free(nodo_a_eliminar);
    return dato;
}

/**
 * Esta función retorna el elemento en el frente de la cola sin removerlo.
 *
 * @param cola - Puntero a la cola de la que se desea obtener el elemento en el frente.
 *
 * @return int - El valor del elemento en el frente de la cola.
 * 
 * @pre - El parámetro 'cola' debe ser un puntero válido a una cola previamente creada.
 * 
 * @post - La función verifica si la cola está vacía. Si no lo está, retorna el valor del elemento en el frente sin removerlo.
 *         Si la cola está vacía, muestra un mensaje de error y sale del programa.
 *
 */
int frente_cola(cola_t *cola)
{
    if (esta_vacia(cola) == 1)
    {
        exit(1); // Manejo de error, la cola está vacía.
    }
    return cola->frente->valor;
}

/**
 * Esta función remueve todos los elementos de la cola, dejándola vacía.
 *
 * @param cola - Puntero a la cola que se desea vaciar.
 * 
 * @pre - El parámetro 'cola' debe ser un puntero válido a una cola previamente creada.
 * 
 * @post - La función verifica si la cola está vacía. Si no lo está, utiliza la función 'desencolar' para remover todos los elementos de la cola.
 *         Al final del proceso, la cola queda vacía y lista para ser liberada.
 *
 */
void vaciar_cola(cola_t *cola)
{
    while (esta_vacia(cola) != 1) // Mientras no resulte vacia
    {
        desencolar(cola);
    }
}
