/*
Ejercicio 2 - Arreglos III
Javier Ingusci (jingusci)
UNRN-16822
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include "ejercicio2.c"

// funcion para testear las funciones del ejercicio 2
void ejercicio2_main()
{
    int tamano = 5; // Tamaño del arreglo
    int *arreglo = reserva_arreglo_enteros(tamano);

    if (arreglo == NULL)
    {
        printf("Error al reservar memoria para el arreglo.\n");
        // return 1;
    }

    // Inicializamos el arreglo
    cargar_arreglo(arreglo,tamano);
    // for (int i = 0; i < tamano; i++)
    // {
    //     arreglo[i] = i * 10;
    // }

    // Imprimimos el arreglo
    printf("Arreglo de enteros:\n");
    imprimir_arreglo(arreglo,tamano);

    // Creamos la copia del arreglo
    int *arreglo_copia = copia_arreglo(arreglo,tamano);

    // Imprimimos el arreglo copia
    printf("Arreglo_copia de enteros:\n");
    imprimir_arreglo(arreglo_copia,tamano);

    // Borramos posicion 2 del arreglo copia
    arreglo_copia = elimina_elemento(arreglo_copia,&tamano,2); //paso tamaño como puntero para poder editarlo

    // Imprimimos el arreglo copia de nuevo
    printf("Arreglo_copia de enteros sin elemento en pos 2:\n");
    imprimir_arreglo(arreglo_copia,tamano);

    // insertamos un nuevo valor en el arreglo copia, en la posicion 3
    arreglo_copia = insertaElemento(arreglo_copia,&tamano,3,912);

    // Imprimimos el arreglo copia de nuevo
    printf("Arreglo_copia de enteros con nuevo elemento (912) en pos 3:\n");
    imprimir_arreglo(arreglo_copia,tamano);

    printf("-----------------\n");
    // Creo nuevos arreglos para la fusionadora
    int tamano1 = 3; // Tamaño del arreglo
    int *arreglo1 = reserva_arreglo_enteros(tamano1);
    cargar_arreglo(arreglo1,tamano1);
    // for (int i = 0; i < tamano1; i++)
    // {
    //     arreglo1[i] = i * 10;
    // }
    int tamano2 = 2; // Tamaño del arreglo
    int *arreglo2 = reserva_arreglo_enteros(tamano2);
    cargar_arreglo(arreglo2,tamano2);
    // for (int i = 0; i < tamano2; i++)
    // {
    //     arreglo2[i] = i + 12;
    // }

    // Muestro los arreglos que voy a fusionar
    printf("Arreglo 1 a fusionar:\n");
    imprimir_arreglo(arreglo1,tamano1); 
    printf("Arreglo 2 a fusionar:\n");
    imprimir_arreglo(arreglo2,tamano2);    

    // fusiono directamente en el arreglo 1
    arreglo1 = fusiona_arreglos(arreglo1,tamano1,arreglo2,tamano2);
    printf("Arreglo fusionado:\n");
    imprimir_arreglo(arreglo1,tamano1+tamano2); 

    // Liberamos la memoria
    libera_arreglo_enteros(arreglo);
    libera_arreglo_enteros(arreglo_copia);
    libera_arreglo_enteros(arreglo1);
    libera_arreglo_enteros(arreglo2);

    // return 0;
}
