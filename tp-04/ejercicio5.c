/*
Ejercicio 5 - Estadísticas
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
int minimo_de_arreglo(int capacidad, int arreglo[]);
int maximo_de_arreglo(int capacidad, int arreglo[]);
int suma_de_arreglo(int capacidad, int arreglo[]);
float calc_promedio(int capacidad, int arreglo[]);

int main()
{
   printf("\n");
   // Declaro arreglo segun la capacidad inicial
   int arreglo[CAPACIDAD_INICIAL];

   // Defino capacidad para el arreglo
   int capacidad = solicitar_capacidad();

   // Cargo el arreglo
   cargar_arreglo(capacidad, arreglo);

   // Muestro
   printf("\nArreglo: ");
   muestra_arreglo(capacidad, arreglo);
   printf("\n");

   // ejecuto funciones:
   int min = minimo_de_arreglo(capacidad, arreglo);
   int max = maximo_de_arreglo(capacidad, arreglo);
   int sum = suma_de_arreglo(capacidad, arreglo);
   float prom = calc_promedio(capacidad, arreglo);

   // Muestro resultados
   printf("El minimo del arreglo es: \t %d\n", min);
   printf("El maximo del arreglo es: \t %d\n", max);
   printf("La suma del arreglo es: \t %d\n", sum);
   printf("El promedio del arreglo es: \t %.2f\n", prom);
   printf("\n");
   return 0;
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

/**
 * Encuentra y devuelve el valor mínimo en un arreglo de enteros.
 *
 * @param capacidad - El número de elementos en el arreglo.
 * @param arreglo - Un puntero al arreglo de enteros.
 *
 * @pre 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con al menos un elemento.
 * @post Devuelve el valor mínimo en el arreglo.
 *
 * @return El valor mínimo encontrado.
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
 * Encuentra y devuelve el valor máximo en un arreglo de enteros.
 *
 * @param capacidad - El número de elementos en el arreglo.
 * @param arreglo - Un puntero al arreglo de enteros.
 *
 * @pre 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con al menos un elemento.
 * @post Devuelve el valor máximo en el arreglo.
 *
 * @return El valor máximo encontrado.
 */
int maximo_de_arreglo(int capacidad, int arreglo[])
{
   {
      int maximo;

      for (int i = 0; i < capacidad; i++)
      {
         if (i == 0)
         {
            maximo = arreglo[i];
         }
         else if (arreglo[i] > maximo)
         {
            maximo = arreglo[i];
         }
      }
      return maximo;
   }
}


/**
 * Calcula y devuelve la suma de todos los elementos en un arreglo de enteros.
 *
 * @param capacidad - El número de elementos en el arreglo.
 * @param arreglo - Un puntero al arreglo de enteros.
 *
 * @pre 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con al menos un elemento.
 * @post Devuelve la suma de todos los elementos en el arreglo.
 *
 * @return La suma de los elementos en el arreglo.
 */
int suma_de_arreglo(int capacidad, int arreglo[])
{
   int suma = 0;
   for (int i = 0; i < capacidad; i++)
   {
      suma += arreglo[i];
   }
   return suma;
}

/**
 * Calcula y devuelve el promedio de los elementos en un arreglo de enteros.
 *
 * @param capacidad - El número de elementos en el arreglo.
 * @param arreglo - Un puntero al arreglo de enteros.
 *
 * @pre 'capacidad' debe ser mayor que 0.
 * @pre 'arreglo' debe ser un puntero válido apuntando a un arreglo con al menos un elemento.
 * @post Devuelve el promedio de los elementos en el arreglo como un valor de punto flotante.
 *
 * @return El promedio de los elementos en el arreglo como un valor de punto flotante.
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