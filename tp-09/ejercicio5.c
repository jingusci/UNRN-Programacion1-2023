/*
Ejercicio 1 - Series
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
} nodo_t;

nodo_t *arreglo_a_lista(int *arreglo, int size);
int suma_lista(nodo_t *lista);
int longitud_lista(nodo_t *lista);
nodo_t *invierte_lista(nodo_t *lista);
void imprime_lista(nodo_t *lista);

int main()
{
    int arreglo[5] = {9, 12, 18, 3, 1};
    nodo_t *lista = arreglo_a_lista(arreglo, 5);

    printf("\nResultados:\n");
    printf("Lista: ");
    imprime_lista(lista);
    printf("\nLargo de la lista: %d", longitud_lista(lista));
    printf("\nSuma: %d", suma_lista(lista));
    nodo_t *lista2 = invierte_lista(lista);
    printf("\nLista invertida: ");
    imprime_lista(lista2);

    return 0;
}

/**
 * Convierte un arreglo en una lista enlazada utilizando recursividad.
 *
 * @param arreglo Un puntero al arreglo de enteros.
 * @param size El tamaño del arreglo.
 * @return Un puntero al nodo inicial de la lista enlazada.
 */
nodo_t *arreglo_a_lista(int *arreglo, int size)
{
    if (size == 0)
        return NULL;
    nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
    nodo->valor = arreglo[0];
    nodo->siguiente = arreglo_a_lista(arreglo + 1, size - 1);
    return nodo;
}

/**
 * Calcula la suma de los valores de una lista enlazada utilizando recursividad.
 *
 * @param lista Un puntero al nodo inicial de la lista.
 * @return La suma de los valores en la lista.
 */
int suma_lista(nodo_t *lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    return lista->valor + suma_lista(lista->siguiente);
}

/**
 * Calcula la longitud de una lista enlazada utilizando recursividad.
 *
 * @param lista Un puntero al nodo inicial de la lista.
 * @return La longitud de la lista.
 */
int longitud_lista(nodo_t *lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    return 1 + longitud_lista(lista->siguiente);
}

/**
 * Invierte una lista enlazada utilizando recursividad.
 *
 * @param lista Un puntero al nodo inicial de la lista.
 * @return Un puntero al nuevo nodo inicial de la lista invertida.
 */
nodo_t *invierte_lista(nodo_t *lista)
{
    if (lista == NULL || lista->siguiente == NULL)
    {
        return lista;
    }
    nodo_t *resultado = invierte_lista(lista->siguiente);
    lista->siguiente->siguiente = lista;
    lista->siguiente = NULL;

    return resultado;
}

/**
 * Imprime los valores de una lista enlazada utilizando recursividad.
 *
 * @param lista Un puntero al nodo inicial de la lista.
 */
void imprime_lista(nodo_t *lista)
{
    if (lista == NULL)
        return;
    printf("%d ", lista->valor);
    imprime_lista(lista->siguiente);
}
