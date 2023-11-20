/*
Ejercicio 1 - Listas Enlazadas
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ejercicio1.c"

int main()
{
    nodo_t *lista = NULL;
    nodo_t *lista2 = NULL;

    // Llenar las listas con números aleatorios
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        int valor = rand() % 100;
        insertar_al_final(&lista, valor);
    }
    for (int i = 0; i < 10; i++)
    {
        int valor = rand() % 100;
        insertar_al_final(&lista2, valor);
    }

    printf("Lista original:\n");
    imprimir_lista(lista);
    printf("Tamano de la lista: %d\n\n", tamano_lista(&lista));

    insertar_al_principio(&lista, 999);
    printf("Despues de insertar 999 al principio:\n");
    imprimir_lista(lista);
    printf("Tamano de la lista: %d\n\n", tamano_lista(&lista));

    eliminar_del_principio(&lista);
    printf("Despues de eliminar el primer elemento:\n");
    imprimir_lista(lista);
    printf("Tamano de la lista: %d\n\n", tamano_lista(&lista));

    insertar_en_posicion(&lista, 777, 2);
    printf("Despues de insertar 777 en la posicion 2:\n");
    imprimir_lista(lista);
    printf("Tamano de la lista: %d\n\n", tamano_lista(&lista));

    eliminar_en_posicion(&lista, 3);
    printf("Despues de eliminar el elemento en la posicion 3:\n");
    imprimir_lista(lista);
    printf("Tamano de la lista: %d\n\n", tamano_lista(&lista));

    printf("Valor en la posicion 2: %d\n", obtener_valor_en_posicion(&lista, 2));

    fusionar_lista(&lista, &lista2);
    printf("Despues de fusionar la lista con otra lista vacia:\n");
    printf("\n--- 1 ---\n");
    imprimir_lista(lista);
    printf("\n--- 2 ---\n");
    imprimir_lista(lista2);
    printf("\n--- 1 ord asc ---\n");
    ordenar_ascendente(&lista);
    imprimir_lista(lista);
    printf("\n--- 1 ord desc ---\n");
    ordenar_descendente(&lista);
    imprimir_lista(lista);
    printf("\n---\n");

    liberar_nodo(lista);
    liberar_nodo(lista2);

    return 0;
}
