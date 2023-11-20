/*
Ejercicio 1. Arreglos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CAPACIDAD_INIAL 100

// Declaracion de funciones
int solicitar_entero();
int solicitar_capacidad();
int cargar_arreglo(int capacidad, int arreglo[]);
int muestra_arreglo(int capacidad, int arreglo[]);
int unir_arreglos(int capacidad_1, int arreglo_1[], int capacidad_2, int arreglo_2[], int arreglo_unido[]);
float calc_promedio(int capacidad, int arreglo[]);
int minimo_de_arreglo(int capacidad, int arreglo[]);
int posicion_del_max(int capacidad, int arreglo[]);
void ordenar_arreglo(int capacidad, int arreglo[]);

/* ----------------- Inicio del MAIN ----------------- */
int main()
{
   int flag_error;

   // Declaro arreglos segun la capacidad inicial
   int arreglo_1[CAPACIDAD_INIAL];
   int arreglo_2[CAPACIDAD_INIAL];

   // Defino dos capacidades para 2 arreglos
   int capacidad_1 = solicitar_capacidad();
   int capacidad_2 = solicitar_capacidad();

   // Mensaje al usuario
   printf("\n#########\nComienzo de pruebas de Ej 1.1 y 1.2\n#########\n\n");

   // Cargo los dos primeros arreglos
   flag_error = cargar_arreglo(capacidad_1, arreglo_1);
   flag_error = cargar_arreglo(capacidad_2, arreglo_2);

   // Muestro los primeros 2 arreglos
   printf("\nArreglo 1: ");
   muestra_arreglo(capacidad_1, arreglo_1);
   printf("\nArreglo 2: ");
   muestra_arreglo(capacidad_2, arreglo_2);

   ///// Hasta aca se probaron ejercicios 1.1 y 1.2 /////

   printf("\n\n#########\nComienzo de pruebas de Ej 1.3\n#########\n");
   // Creo arreglo 3 para unir los dos arreglos (prueba ejercicio 1.3)
   int capacidad_3 = capacidad_1 + capacidad_2;
   int arreglo_unido[capacidad_3];

   // Funcion para unir
   flag_error = unir_arreglos(capacidad_1, arreglo_1, capacidad_2, arreglo_2, arreglo_unido);

   // muestro arreglo unido
   printf("Arreglos 1 y 2 unidos en uno solo: ");
   muestra_arreglo(capacidad_3, arreglo_unido);
   printf("\n\n");

   ///// Hasta aca se probó ejercicio 1.3 /////

   int opcion = 0;

   do
   {
      printf("\n\nSu Arreglo: ");
      muestra_arreglo(capacidad_1, arreglo_1);
      printf("\nOperaciones:\n");
      printf("1. Promedio\n");
      printf("2. Valor Minimo\n");
      printf("3. Posicion del Maximo\n");
      printf("4. Ordenar de mayor a menor\n");
      printf("5. Salir\n");
      printf("Indique operacion a realizar: ");
      scanf("%d", &opcion);

      switch (opcion)
      {
      case 1:
         float promedio = calc_promedio(capacidad_1, arreglo_1);
         printf("El promedio del arreglo es: %.2f \n", promedio);
         break;
      case 2:
         int min = minimo_de_arreglo(capacidad_1, arreglo_1);
         printf("El minimo del arreglo es: %d \n", min);
         break;
      case 3:
         int pos_max = posicion_del_max(capacidad_1, arreglo_1);
         printf("La posicion del maximo del arreglo es: %d \n", pos_max);
         break;
      case 4:
         ordenar_arreglo(capacidad_1, arreglo_1);
         muestra_arreglo(capacidad_1, arreglo_1);
         break;
      case 5:
         printf("\nSaliendo...\n");
         break;
      default:
         break;
      }

   } while (opcion != 5);

   return 0;
}
/* ----------------- Fin del MAIN ----------------- */

/**
 * La función carga un arreglo de enteros con valores ingresados por el usuario.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se llenará con valores ingresados por el usuario.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;

   printf("Se solicitaran %d valores para cargar el arreglo\n", capacidad);
   for (int i = 0; i < capacidad; i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ", i);
      scanf("%d", &arreglo[i]);
   }
   return flag_error;
}

/**
 * La función muestra un arreglo de enteros en la consola.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se mostrará en la consola.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int muestra_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;

   printf("[ ");
   for (int i = 0; i < capacidad; i++)
   {
      printf("%d ", arreglo[i]);
   }
   printf("]");
   return flag_error;
}

/**
 * La función une dos arreglos de enteros en un tercer arreglo.
 *
 * @param capacidad_1 es un número mayor a uno que representa la capacidad del primer arreglo de enteros.
 * @param arreglo_1 es la dirección del primer arreglo de enteros que se unirá.
 * @param capacidad_2 es un número mayor a uno que representa la capacidad del segundo arreglo de enteros.
 * @param arreglo_2 es la dirección del segundo arreglo de enteros que se unirá.
 * @param arreglo_unido es la dirección del tercer arreglo donde se almacenarán los elementos unidos de los dos arreglos originales.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int unir_arreglos(int capacidad_1, int arreglo_1[], int capacidad_2, int arreglo_2[], int arreglo_unido[])
{
   int flag_error = 0;

   int i = 0;
   for (int j = 0; j < capacidad_1; j++)
   {
      arreglo_unido[i] = arreglo_1[j];
      i++;
   }
   for (int j = 0; j < capacidad_2; j++)
   {
      arreglo_unido[i] = arreglo_2[j];
      i++;
   }
   return flag_error;
}

/**
 * La función calcula el promedio de los elementos en un arreglo de enteros.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros del cual se calculará el promedio.
 *
 * @return El promedio de los elementos en el arreglo.
 */
float calc_promedio(int capacidad, int arreglo[])
{
   float suma = 0;
   float promedio;
   for (int i = 0; i < capacidad; i++)
   {
      suma += arreglo[i];
   }
   promedio = suma / capacidad;
   return promedio;
}

/**
 * La función encuentra la posición del valor máximo en un arreglo de enteros.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros en el cual se buscará el valor máximo.
 *
 * @return La posición (índice) del valor máximo en el arreglo.
 */
int minimo_de_arreglo(int capacidad, int arreglo[])
{
   int minimo;

   for (int i = 0; i < capacidad; i++)
   {
      if (i == 0)
      {
         minimo = arreglo[i];
      }
      else if (arreglo[i] < minimo)
      {
         minimo = arreglo[i];
      }
   }
   return minimo;
}

/**
 * La función encuentra la posición del valor máximo en un arreglo de enteros.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros en el cual se buscará el valor máximo.
 *
 * @return La posición (índice) del valor máximo en el arreglo.
 */
int posicion_del_max(int capacidad, int arreglo[])
{
   int max, pos_max;

   for (int i = 0; i < capacidad; i++)
   {
      if (i == 0)
      {
         max = arreglo[i];
         pos_max = i;
      }
      else if (arreglo[i] > max)
      {
         max = arreglo[i];
         pos_max = i;
      }
   }
   return pos_max;
}

/**
 * La función ordena un arreglo de enteros en orden ascendente.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se ordenará.
 */
void ordenar_arreglo(int capacidad, int arreglo[])
{
   int temp;
   for (int i = 0; i < capacidad; i++)
   {
      for (int j = (i + 1); j < capacidad; j++)
      {
         if (arreglo[j] < arreglo[i])
         {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
         }
      }
   }
}

/**
 * La función solicita al usuario ingresar un número entero.
 *
 * @return El número entero ingresado por el usuario.
 */
int solicitar_entero()
{
   int numero;
   printf("Ingrese un numero entero: ");
   scanf("%d", &numero);
   return numero;
}

/**
 * La función solicita al usuario ingresar un número entero
 * que será usado como capacidad de un arreglo.
 * Verifica que sea menor a la CAPACIDAD_INICIAL definida
 *
 * @return El número entero ingresado por el usuario.
 */
int solicitar_capacidad()
{
   int numero;
   int flag = 0;
   do
   {
      printf("Ingrese una capacidad: ");
      scanf("%d", &numero);
      if (numero >= 0 && numero <= CAPACIDAD_INIAL)
      {
         flag = 1;
      }
      else
      {
         printf("Error. La capacidad debe estar entre 0 y %d\n", CAPACIDAD_INIAL);
      }
   } while (flag != 1);

   return numero;
}