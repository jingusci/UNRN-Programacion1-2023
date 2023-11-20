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
#include "ejercicio2.c"

int main()
{
    cola_t *cola1 = crear_cola();

    encolar(cola1, 10);
    printf("Frente de la cola: %d\n", frente_cola(cola1));
    encolar(cola1, 20);
    printf("Frente de la cola: %d\n", frente_cola(cola1));
    printf("Desencolando: %d\n", desencolar(cola1));
    encolar(cola1, 30);
    printf("Frente de la cola: %d\n", frente_cola(cola1));
    encolar(cola1, 40);
    printf("Frente de la cola: %d\n", frente_cola(cola1));


    printf("\n-----------\n");
    while (esta_vacia(cola1) != 1)
    {
        printf("Desencolando: %d\n", desencolar(cola1));
    }

    vaciar_cola(cola1);
    free(cola1);

    return 0;
}
