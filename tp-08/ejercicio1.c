/*
Ejercicio 1 - Listas Enlazadas
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} nodo_t;
// void mostrar_nodo(nodo_t *nodo)

// {
//     printf("Nodo.valor: %d\n", nodo->valor);
//     printf("Nodo.siguiente: %p\n", nodo->siguiente);
// }

nodo_t *crear_nodo(int valor);
void liberar_nodo(nodo_t *lista);
void insertar_al_principio(nodo_t **lista, int valor);
void insertar_al_final(nodo_t **lista, int valor);
void insertar_en_posicion(nodo_t **lista, int dato, int posicion);
void eliminar_del_principio(nodo_t **lista);
void eliminar_del_final(nodo_t **lista);
void eliminar_en_posicion(nodo_t **lista, int posicion);
int tamano_lista(nodo_t **lista);
int es_lista_vacia(nodo_t *lista);
int obtener_valor_en_posicion(nodo_t **lista, int posicion);
void imprimir_lista(nodo_t *lista);
void fusionar_lista(nodo_t **lista_1, nodo_t **lista_2);
void mostrar_nodo(nodo_t *nodo);
void ordenar_ascendente(nodo_t **lista);
void ordenar_descendente(nodo_t **lista);

nodo_t *crear_nodo(int valor)
{
    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    if (nuevo_nodo != NULL)
    {
        nuevo_nodo->valor = valor;
        nuevo_nodo->siguiente = NULL;
    }
    return nuevo_nodo;
}

/**
 * Esta función libera la memoria de un nodo de una estructura de lista enlazada.
 *
 * @param nodo - Puntero al nodo que se desea liberar de la memoria.
 *
 * @pre - El parámetro 'nodo' debe ser un puntero a un nodo de una lista enlazada previamente asignado.
 *
 * @post - La función libera la memoria asociada al nodo, permitiendo que sea eliminado de la lista.
 *         No realiza cambios en otros nodos de la lista. Es responsabilidad del llamador asegurarse de mantener la coherencia de la lista.
 *         Después de llamar a esta función, el puntero 'nodo' ya no es válido y no debe ser utilizado.
 *
 */
void liberar_nodo(nodo_t *nodo)
{
    free(nodo);
}

/**
 * Esta función inserta un nuevo nodo con un valor dado al principio de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada a la que se desea agregar el nuevo nodo.
 * @param valor - Valor que se desea asignar al nuevo nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función crea un nuevo nodo con el valor especificado y lo inserta al principio de la lista enlazada.
 *         Actualiza el puntero de la cabeza de la lista (*lista) para apuntar al nuevo nodo, convirtiéndolo en el nuevo primer elemento.
 *         El nuevo nodo apunta al antiguo primer elemento de la lista.
 *         La función asegura que la lista enlazada siga siendo válida y bien formada después de la inserción.
 *
 */
void insertar_al_principio(nodo_t **lista, int valor)
{
    nodo_t *nuevo_nodo = crear_nodo(valor); // reservo memoria para el primer nodo
    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
}

/**
 * Esta función inserta un nuevo nodo con un valor dado al final de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada a la que se desea agregar el nuevo nodo.
 * @param valor - Valor que se desea asignar al nuevo nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función crea un nuevo nodo con el valor especificado.
 *         Si la lista está vacía (NULL), establece el nuevo nodo como el único elemento de la lista, convirtiéndolo en la cabeza de la lista.
 *         Si la lista no está vacía, recorre la lista hasta encontrar el último nodo y agrega el nuevo nodo al final.
 *         La función asegura que la lista enlazada siga siendo válida y bien formada después de la inserción.
 *
 */
void insertar_al_final(nodo_t **lista, int valor)
{
    nodo_t *nuevo_nodo = crear_nodo(valor);

    if ((*lista) == NULL)
    {
        *lista = nuevo_nodo;
    }
    else
    {
        nodo_t *actual = *lista;

        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo_nodo;
    }
}

/**
 * Esta función inserta un nuevo nodo con un valor dado en una posición específica de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada a la que se desea agregar el nuevo nodo.
 * @param dato - Valor que se desea asignar al nuevo nodo.
 * @param posicion - Posición en la que se desea insertar el nuevo nodo. La posición 0 corresponde al principio de la lista.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función crea un nuevo nodo con el valor especificado.
 *         Si la posición es 0, inserta el nuevo nodo al principio de la lista.
 *         Si la posición es mayor que 0, recorre la lista hasta encontrar la posición deseada (o el final de la lista) y agrega el nuevo nodo en esa posición.
 *         La función asegura que la lista enlazada siga siendo válida y bien formada después de la inserción.
 *
 */
void insertar_en_posicion(nodo_t **lista, int dato, int posicion)
{

    if (posicion == 0)
    {
        insertar_al_principio(lista, dato);
    }
    else
    {
        nodo_t *nuevo_nodo = crear_nodo(dato);

        if ((*lista) == NULL)
        {
            *lista = nuevo_nodo;
        }
        else
        {
            nodo_t *actual = *lista;
            int c = 0;

            while ((c != posicion - 1) && (actual->siguiente != NULL)) // si llego al final de la lista lo inserto al final
            {
                actual = actual->siguiente;
                c++;
            }

            nuevo_nodo->siguiente = actual->siguiente;
            actual->siguiente = nuevo_nodo;
        }
    }
}

/**
 * Esta función elimina el nodo que se encuentra al principio de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea eliminar el primer nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL).
 *         Si la lista no está vacía, elimina el primer nodo de la lista, actualizando el puntero de la cabeza (*lista).
 *         La función libera la memoria del nodo eliminado.
 *         Después de la eliminación, la lista sigue siendo válida y bien formada, incluso si ahora está vacía.
 *
 */
void eliminar_del_principio(nodo_t **lista)
{
    if ((*lista) != NULL)
    {
        nodo_t *actual = *lista;
        *lista = actual->siguiente;
        liberar_nodo(actual);
    }
}

/**
 * Esta función elimina el nodo que se encuentra al final de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea eliminar el último nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL).
 *         Si la lista no está vacía, recorre la lista hasta encontrar el penúltimo nodo (el nodo anterior al último).
 *         Luego, elimina el último nodo de la lista, actualizando el puntero del penúltimo nodo para que apunte a NULL.
 *         La función libera la memoria del nodo eliminado.
 *         Después de la eliminación, la lista sigue siendo válida y bien formada, incluso si ahora está vacía.
 *
 */
void eliminar_del_final(nodo_t **lista)
{
    if ((*lista) != NULL)
    {
        nodo_t *actual = *lista;
        nodo_t *siguiente = actual->siguiente;

        int flag = 0;
        while (flag == 0)
        {
            if (siguiente->siguiente != NULL)
            {
                actual = actual->siguiente;
                siguiente = siguiente->siguiente;
            }
            else
            {
                flag = 1;
            }
        }

        actual->siguiente = NULL;
        liberar_nodo(siguiente);
    }
}

/**
 * Esta función elimina el nodo que se encuentra en una posición específica de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea eliminar el nodo.
 * @param posicion - Posición del nodo que se desea eliminar. La posición 0 corresponde al primer nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL).
 *         Si la posición es 0, elimina el primer nodo de la lista.
 *         Si la posición es mayor que 0, recorre la lista hasta encontrar el nodo en la posición deseada (o el final de la lista).
 *         Luego, elimina ese nodo, actualizando el puntero del nodo anterior para que apunte al nodo siguiente al eliminado.
 *         La función libera la memoria del nodo eliminado.
 *         Después de la eliminación, la lista sigue siendo válida y bien formada, incluso si ahora está vacía.
 *
 */
void eliminar_en_posicion(nodo_t **lista, int posicion)
{
    if ((*lista) != NULL)
    {
        if (posicion == 0)
        {
            eliminar_del_principio(lista);
        }
        else
        {
            nodo_t *previo = NULL;
            nodo_t *actual = *lista;
            // nodo_t *siguiente = actual->siguiente;
            int c = 0;

            while ((c != posicion) && (actual->siguiente != NULL)) // si llego al final de la lista borro el ultimo
            {
                previo = actual;
                actual = actual->siguiente;
                // siguiente = siguiente->siguiente;
                c++;
            }

            previo->siguiente = actual->siguiente;
            liberar_nodo(actual);
        }
    }
}

/**
 * Esta función calcula el tamaño (cantidad de nodos) de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea conocer el tamaño.
 *
 * @return - El tamaño de la lista enlazada. Si la lista está vacía, devuelve 0.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función recorre la lista enlazada contando los nodos.
 *         Devuelve el tamaño de la lista.
 *         Si la lista está vacía, el tamaño devuelto es 0.
 *
 */
int tamano_lista(nodo_t **lista)
{
    int tamano = 0;

    if ((*lista) != NULL)
    {
        nodo_t *actual = *lista;

        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
            tamano++;
        }
        tamano++; // Sumo 1 al final porque arranca de cero
    }
    return tamano;
}

/**
 * Esta función verifica si una lista enlazada está vacía.
 *
 * @param lista - Puntero a la cabeza de la lista enlazada de la que se desea verificar si está vacía.
 *
 * @return - 1 si la lista está vacía, 0 si la lista no está vacía.
 *
 * @pre - El parámetro 'lista' debe ser un puntero que apunta a la cabeza de una lista enlazada previamente asignada o puede ser NULL.
 *
 * @post - La función verifica si el puntero 'lista' es NULL.
 *         Devuelve 1 si la lista está vacía (NULL) o 0 si la lista no está vacía.
 *
 */
int es_lista_vacia(nodo_t *lista)
{
    int valor = 0; // 1 lista vacia, 0 lista no vacia
    if (lista == NULL)
    {
        valor = 1;
    }
    return valor;
}

/**
 * Esta función obtiene el valor de un nodo en una posición específica de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea obtener el valor del nodo.
 * @param posicion - Posición del nodo del que se desea obtener el valor. La posición 0 corresponde al primer nodo.
 *
 * @return - El valor del nodo en la posición especificada. Si la posición es inválida, devuelve un valor no especificado.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL) y si la posición es válida.
 *         Si la posición es válida, recorre la lista hasta encontrar el nodo en la posición deseada.
 *         Devuelve el valor del nodo en esa posición.
 *         Si la posición es inválida, la función imprime un mensaje de error y devuelve un valor no especificado.
 *
 */
int obtener_valor_en_posicion(nodo_t **lista, int posicion)
{
    int largo = tamano_lista(lista);
    int valor;
    if ((*lista) != NULL)
    {
        if (posicion < 0 || posicion >= largo)
        {
            printf("ERROR EN POSICION\n");
        }
        else
        {
            nodo_t *actual = *lista;
            int c = 0;

            while ((c != posicion) && (actual->siguiente != NULL)) // si llego al final de la lista borro el ultimo
            {
                actual = actual->siguiente;
                c++;
            }

            valor = actual->valor;
        }
    }

    return valor;
}

/**
 * Esta función imprime los valores de los nodos de una lista enlazada.
 *
 * @param lista - Puntero a la cabeza de la lista enlazada de la que se desean imprimir los valores de los nodos.
 *
 * @pre - El parámetro 'lista' debe ser un puntero que apunta a la cabeza de una lista enlazada previamente asignada o puede ser NULL.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL).
 *         Recorre la lista enlazada e imprime los valores de los nodos en el formato "Nodo N -> Valor".
 *         Si la lista está vacía, imprime un mensaje indicando que la lista está vacía.
 *
 */
void imprimir_lista(nodo_t *lista) // supongo que "lista" es el valor inicial o cabecera
{
    if (lista != NULL)
    {
        nodo_t *actual = lista;
        int i = 0;
        while (actual->siguiente != NULL)
        {
            printf("Nodo %d -> %d\n", i, actual->valor);
            i++;
            actual = actual->siguiente;
        }
        if (actual->siguiente == NULL) // para imprimir el ultimo
        {
            printf("Nodo %d -> %d\n", i, actual->valor);
        }
    }
    else
    {
        printf("Lista vacia\n");
    }
}

/**
 * Esta función fusiona dos listas enlazadas simples, insertando la segunda lista al final de la primera.
 *
 * @param lista_1 - Puntero al puntero de la primera lista enlazada.
 * @param lista_2 - Puntero al puntero de la segunda lista enlazada que se fusionará con la primera.
 *
 * @pre - Los parámetros 'lista_1' y 'lista_2' deben ser punteros a punteros que apunten a las cabezas de listas enlazadas simples previamente asignadas.
 *
 * @post - La función verifica si ambas listas no están vacías (no son NULL).
 *         Recorre la primera lista hasta encontrar el último nodo.
 *         Conecta el último nodo de la primera lista con la cabeza de la segunda lista, fusionándolas.
 *         La primera lista apunta ahora a la fusión de ambas listas.
 *         La segunda lista queda vacía y no se libera la memoria de los nodos de la segunda lista.
 *
 */
void fusionar_lista(nodo_t **lista_1, nodo_t **lista_2) // meto lista 2 al final de lista 1
{
    if (((*lista_1) != NULL) && ((*lista_2) != NULL))
    {
        nodo_t *actual_1 = *lista_1;

        while (actual_1->siguiente != NULL)
        {
            actual_1 = actual_1->siguiente;
        }

        actual_1->siguiente = *lista_2;
    }
}

/**
 * Esta función ordena una lista enlazada en orden ascendente (de menor a mayor).
 *
 * @param lista - Puntero al puntero de la lista enlazada que se desea ordenar en orden ascendente.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función recorre la lista enlazada para ordenar los nodos en orden ascendente.
 *         Compara los valores de los nodos y, si encuentra un valor menor, intercambia los valores de los nodos.
 *         El resultado es una lista enlazada ordenada en orden ascendente (de menor a mayor).
 *
 */
void ordenar_ascendente(nodo_t **lista)
{
    nodo_t *actual = *lista;

    while (actual != NULL)
    {
        nodo_t *minimo = actual;
        nodo_t *siguiente = actual->siguiente;

        while (siguiente != NULL)
        {
            if (siguiente->valor < minimo->valor)
            {
                minimo = siguiente;
            }
            siguiente = siguiente->siguiente;
        }

        // Intercambiar los valores
        int temp = actual->valor;
        actual->valor = minimo->valor;
        minimo->valor = temp;

        actual = actual->siguiente;
    }
}

/**
 * Esta función ordena una lista enlazada en orden descendente (de mayor a menor).
 *
 * @param lista - Puntero al puntero de la lista enlazada que se desea ordenar en orden descendente.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 * 
 * @post - La función recorre la lista enlazada para ordenar los nodos en orden descendente.
 *         Compara los valores de los nodos y, si encuentra un valor mayor, intercambia los valores de los nodos.
 *         El resultado es una lista enlazada ordenada en orden descendente (de mayor a menor).
 *
 */
void ordenar_descendente(nodo_t **lista)
{
    nodo_t *actual = *lista;

    while (actual != NULL)
    {
        nodo_t *maximo = actual;
        nodo_t *siguiente = actual->siguiente;

        while (siguiente != NULL)
        {
            if (siguiente->valor > maximo->valor)
            {
                maximo = siguiente;
            }
            siguiente = siguiente->siguiente;
        }

        // Intercambiar los valores
        int temp = actual->valor;
        actual->valor = maximo->valor;
        maximo->valor = temp;

        actual = actual->siguiente;
    }
}
