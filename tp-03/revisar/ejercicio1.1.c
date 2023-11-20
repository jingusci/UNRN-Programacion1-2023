/*
Ejercicio 1.1 Cargador de arreglos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion
int cargar_arreglo(int capacidad, int arreglo[]);

/*
   Esta funcion recibe un arreglo y su capacidad, y solicita valores para completarlo.
   @param1 capacidad (int)
   @param2 arreglo[] (int)
   @return flag_error (int)
*/
int cargar_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error. 

   printf("Se solicitaran %d valores para cargar el arreglo\n",capacidad);
   for (int i = 0; i<capacidad;i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ",i);
      scanf("%d", &arreglo[i]);
   }

   return flag_error;
}
