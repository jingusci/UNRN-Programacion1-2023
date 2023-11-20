/*
Ejercicio 2 - Ordenamiento II
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CAPACIDAD_INICIAL 25

// Declaracion de funciones
int solicitar_entero();
int solicitar_capacidad();
void cargar_arreglo(int capacidad, int arreglo[]);
void muestra_arreglo(int capacidad, int arreglo[]);
void ordenar_arreglo(int capacidad, int arreglo[]);
void intercambia(int *izquierda, int *derecha);

int main()
{
   // Declaro arreglo segun la capacidad inicial
   int arreglo_1[CAPACIDAD_INICIAL];

   // Defino capacidad para el arreglo
   int capacidad_1 = solicitar_capacidad();

   // Cargo el arreglo
   cargar_arreglo(capacidad_1, arreglo_1);

   // Muestro
   printf("\nArreglo: ");
   muestra_arreglo(capacidad_1, arreglo_1);

   // Ordeno
   ordenar_arreglo(capacidad_1, arreglo_1);

   // Muestro
   printf("\nArreglo ordenado: ");
   muestra_arreglo(capacidad_1, arreglo_1);

   return 0;
}

/**
 * Ordena un arreglo de enteros en orden ascendente.
 *
 * @param capacidad - El número de elementos en el arreglo.
 * @param arreglo - Un puntero al arreglo de enteros que se ordenará.
 *
 * @pre capacidad es un número mayor a uno.
 * @pre arreglo apunta a un arreglo válido de enteros con al menos 'capacidad' elementos.
 *
 * @post El arreglo 'arreglo' estará ordenado en de menor a mayor al finalizar la función.
 */
void ordenar_arreglo(int capacidad, int arreglo[])
{
   int *ptr_izq, *ptr_der; //declaro dos punteros
   for (int i = 0; i < capacidad; i++)
   {
      for (int j = (i + 1); j < capacidad; j++)
      {
         if (arreglo[j] < arreglo[i])  // Si tengo que ordenar, guardo pos de memoria en los punteros
         {
            ptr_izq = &arreglo[j]; 
            ptr_der = &arreglo[i];
            intercambia(ptr_izq, ptr_der);   // llamo a la funcion que intercambia usando punteros
         }
      }
   }
}

/**
 * La función intercambia dos valores enteros a través de punteros.
 *
 * @param izquierda - Puntero al primer valor.
 * @param derecha - Puntero al segundo valor.
 *
 * @pre Ambos punteros (izquierda y derecha) deben apuntar a ubicaciones de memoria válidas
 *      que contengan valores enteros.
 *
 * @post Después de llamar a esta función, los valores a los que apuntan los punteros izquierda
 *       y derecha se intercambiarán.
 */
void intercambia(int *izquierda, int *derecha)
{
   int temp = *izquierda;
   *izquierda = *derecha;
   *derecha = temp;
}

/**
 * Llena un arreglo de enteros con valores ingresados por el usuario.
 *
 * @param capacidad - El número de elementos que se solicitarán al usuario.
 * @param arreglo - Un puntero al arreglo de enteros que se llenará con los valores ingresados.
 *
 * @pre El parámetro 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con suficiente capacidad.
 *
 * @post El arreglo 'arreglo' contendrá los valores ingresados por el usuario en las primeras 'capacidad' posiciones.
 */
void cargar_arreglo(int capacidad, int arreglo[])
{

   printf("Se solicitaran %d valores para cargar el arreglo\n", capacidad);
   for (int i = 0; i < capacidad; i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ", i);
      scanf("%d", &arreglo[i]);
   }
}


/**
 * Muestra un arreglo de enteros en la consola.
 *
 * @param capacidad - El número de elementos en el arreglo que se mostrarán.
 * @param arreglo - Un puntero al arreglo de enteros que se mostrará en la consola.
 *
 * @pre El parámetro 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con suficientes elementos.
 */
void muestra_arreglo(int capacidad, int arreglo[])
{
   printf("[ ");
   for (int i = 0; i < capacidad; i++)
   {
      printf("%d ", arreglo[i]);
   }
   printf("]");
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
      if (numero >= 0 && numero <= CAPACIDAD_INICIAL)
      {
         flag = 1;
      }
      else
      {
         printf("Error. La capacidad debe estar entre 0 y %d\n", CAPACIDAD_INICIAL);
      }
   } while (flag != 1);

   return numero;
}