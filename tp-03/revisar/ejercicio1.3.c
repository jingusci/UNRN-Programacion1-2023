/*
Ejercicio 1.2 Impresora de arreglos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int muestra_arreglo(int capacidad, int arreglo[]);

/*
   Esta funcion recibe un arreglo y su capacidad, y muestra por pantalla sus valores.
   @param1 capacidad (int)
   @param2 arreglo[] (int)
   @return flag_error (int)
*/
int muestra_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error. 

   printf("Arreglo: [ ");
   for (int i = 0; i<capacidad;i++)
   {
      printf("%d ", arreglo[i]);
   }
   printf("]");
   return flag_error;
}
