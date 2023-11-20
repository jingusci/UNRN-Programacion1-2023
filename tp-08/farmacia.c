/*
Farmacia
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "ejercicio1.c" // no necesito importarlo porque ejercicio2.c lo importa
#include "ejercicio2.c"
#define MAX_CLIENTES 100

int main()
{
    // Creo una lista del total de numeros (capacidad maxima a atender)
    cola_t *cola_total_numeros = crear_cola();
    for (int i = 0; i < MAX_CLIENTES; i++)
    {
        encolar(cola_total_numeros, i);
    }

    // Creo la cola de clientes
    cola_t *cola_clientes = crear_cola();
    int opcion;

    do
    {
        printf("Bienvenido al servicio de turnos de la farmacia!\n");
        printf("Menu:\n");
        printf("1. Solicitar un turno (Soy cliente)\n");
        printf("2. Atender un cliente (Soy farmaceutico)\n");
        printf("3. Mostrar proximo turno a atender\n");
        printf("4. Mostrar clientes restantes\n");
        printf("5. Reiniciar Cola de clientes\n");
        printf("6. Salir\n");
        printf("Indique que desea hacer: ");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion)
        {
        case 1:
            // Saco el numero de la cola de numeros y se lo asigno a la cola de clientes
            int turno = desencolar(cola_total_numeros);
            encolar(cola_clientes, turno);
            printf("Su turno es:  %d \n\n", turno);
            break;
        case 2:
            // LLamo al primero de la lista de clientes para ser atendido
            printf("Llamando al cliente: %d\n\n", desencolar(cola_clientes));
            break;
        case 3:
            // Consulto quien será el proximo en ser atendido
            printf("Proximo turno: %d\n\n", frente_cola(cola_clientes));
            break;
        case 4:
            // Consulto cuantos clientes restantes hay por ser atendidos
            printf("Clientes restantes: %d\n\n", (frente_cola(cola_total_numeros) - (frente_cola(cola_clientes))));
            break;
        case 5:
            // Reinicio ambas filas, 
            vaciar_cola(cola_clientes);
            vaciar_cola(cola_total_numeros);
            for (int i = 0; i < MAX_CLIENTES; i++)
            {
                encolar(cola_total_numeros, i);
            }
            printf("Se reinicio la cola de clientes.\n");
            printf("Se repusieron numeros de turno.\n");
            break;
        case 6:
            printf("Gracias por venir a la farmacia!\n");
            break;
        }
    } while (opcion != 6);

    // Libero la memoria tomada
    free(cola_clientes);
    free(cola_total_numeros);
    
    return 0;
}
