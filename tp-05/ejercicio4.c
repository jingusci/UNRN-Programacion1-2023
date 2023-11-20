/*
Ejercicio 4 - Gestionando el tiempo_t
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

typedef struct
{
   int horas;
   int minutos;
   int segundos;
} tiempo_t;

tiempo_t crear_tiempo();
void mostrar_tiempo(tiempo_t tiempo);
tiempo_t sumar_tiempos(tiempo_t tiempo1, tiempo_t tiempo2);
int comparacion_tiempos(tiempo_t tiempo1, tiempo_t tiempo2);

int main()
{
   printf("\n");

   tiempo_t tiempo1 = crear_tiempo();
   printf("Tiempo 1: ");
   mostrar_tiempo(tiempo1);
   printf("\n");
   tiempo_t tiempo2 = crear_tiempo();
   printf("Tiempo 2: ");
   mostrar_tiempo(tiempo2);
   printf("\n");

   tiempo_t tiempo3 = sumar_tiempos(tiempo1, tiempo2);
   printf("Suma de tiempos: ");
   mostrar_tiempo(tiempo3);
   printf("\n");

   int comparacion = comparacion_tiempos(tiempo1, tiempo2);

   if (comparacion == 1)
   {
      printf("Tiempo 1 es mayor a Tiempo2\n");
   }
   else if (comparacion == -1)
   {
      printf("Tiempo 1 es menor a Tiempo2\n");
   }
   else if (comparacion == 0)
   {
      printf("Los tiempos son iguales\n");
   }

   return 0;
}

/**
 * Esta función permite al usuario crear una estructura de tiempo ingresando las horas, minutos y segundos.
 *
 * @return  - Estructura de tiempo creada por el usuario.
 *
 * @post    - La función solicita al usuario ingresar las horas, minutos y segundos de un tiempo.
 *            Se realizan validaciones para asegurarse de que los valores ingresados estén dentro de rangos válidos.
 *            Si el usuario ingresa un valor negativo para horas, minutos o segundos, se le pedirá que lo ingrese nuevamente.
 *            La función devuelve la estructura de tiempo creada por el usuario.
 *
 */
tiempo_t crear_tiempo()
{
   tiempo_t tiempo;
   int flag_error = 0;

   printf("Ingrese las horas: ");
   scanf("%d", &tiempo.horas);
   while (tiempo.horas < 0)
   {
      printf("Error. Ingrese numero mayor a cero: ");
      scanf("%d", &tiempo.horas);
   }
   printf("Ingrese los minutos: ");
   scanf("%d", &tiempo.minutos);
   while (tiempo.minutos < 0 || tiempo.minutos >= 60)
   {
      printf("Error. Ingrese minutos entre cero y 59: ");
      scanf("%d", &tiempo.minutos);
   }
   printf("Ingrese los segundos: ");
   scanf("%d", &tiempo.segundos);
   while (tiempo.segundos < 0)
   {
      printf("Error. Ingrese segundos entre cero y 59: ");
      scanf("%d", &tiempo.segundos);
   }

   return tiempo;
}

/**
 * Esta función muestra en la consola una estructura de tiempo en formato de horas:minutos:segundos.
 *
 * @param tiempo - Estructura que representa un tiempo con horas, minutos y segundos.
 *
 * @pre - Los campos 'horas', 'minutos' y 'segundos' en la estructura 'tiempo' deben estar en un rango válido.
 *
 * @post - La función muestra en la consola la estructura de tiempo 'tiempo' en el formato "hh:mm:ss",
 *         asegurándose de incluir ceros adicionales para mantener un formato consistente cuando sea necesario.
 *         Por ejemplo, si 'minutos' o 'segundos' son menores a 10, se incluye un cero inicial para mostrar "0X".
 *
 */
void mostrar_tiempo(tiempo_t tiempo)
{
   printf("%d:", tiempo.horas);
   if (tiempo.minutos < 10)
   {
      printf("0%d:", tiempo.minutos); // Incluyo alternativa para visualizar bien la hora cuando necesita un cero
   }
   else
   {
      printf("%d:", tiempo.minutos);
   }
   if (tiempo.segundos < 10)
   {
      printf("0%d\n", tiempo.segundos); // Incluyo alternativa para visualizar bien la hora cuando necesita un cero
   }
   else
   {
      printf("%d\n", tiempo.segundos);
   }
}

/**
 * Esta función suma dos estructuras de tiempo y devuelve el resultado.
 *
 * @param tiempo1 - Estructura que representa un tiempo con horas, minutos y segundos.
 * @param tiempo2 - Estructura que representa un tiempo con horas, minutos y segundos.
 *
 * @return  - Estructura de tiempo que representa la suma de 'tiempo1' y 'tiempo2'.
 *
 * @pre     - Los campos 'horas', 'minutos' y 'segundos' en ambas estructuras deben estar en un rango válido.
 *
 * @post    - La función suma los tiempos 'tiempo1' y 'tiempo2' y devuelve una nueva estructura de tiempo que representa el resultado.
 *            Se lleva a cabo la corrección necesaria para asegurarse de que los valores de 'segundos' y 'minutos' estén en rangos válidos.
 *            Por ejemplo, si la suma de 'segundos' supera los 60, se incrementa 'minutos' y se ajusta 'segundos'.
 *            Si la suma de 'minutos' supera los 60, se incrementa 'horas' y se ajusta 'minutos'.
 *
 */
tiempo_t sumar_tiempos(tiempo_t tiempo1, tiempo_t tiempo2)
{
   tiempo_t suma;

   suma.horas = tiempo1.horas + tiempo2.horas;
   suma.minutos = tiempo1.minutos + tiempo2.minutos;
   suma.segundos = tiempo1.segundos + tiempo2.segundos;
   if (suma.segundos >= 60)
   {
      suma.minutos++;
      suma.segundos = suma.segundos - 60;
   }
   if (suma.minutos >= 60)
   {
      suma.horas++;
      suma.minutos = suma.minutos - 60;
   }
   return suma;
}

/**
 * Esta función compara dos tiempos y determina cuál es mayor, menor o si son iguales.
 *
 * @param tiempo1 - Estructura que representa un tiempo con horas, minutos y segundos.
 * @param tiempo2 - Estructura que representa un tiempo con horas, minutos y segundos.
 *
 * @return  -  (1) si 'tiempo1' es mayor que 'tiempo2'.
 *          - (-1) si 'tiempo1' es menor que 'tiempo2'.
 *          -  (0) si son iguales.
 *
 * @pre     - Los campos 'horas', 'minutos' y 'segundos' en ambas estructuras deben estar en un rango válido.
 *
 * @post    - La función compara los tiempos 'tiempo1' y 'tiempo2' y devuelve 1 si 'tiempo1' es mayor que 'tiempo2',
 *            -1 si 'tiempo1' es menor que 'tiempo2' y 0 si son iguales.
 *
 */
int comparacion_tiempos(tiempo_t tiempo1, tiempo_t tiempo2)
{
   int resultado;

   if (tiempo1.horas > tiempo2.horas)
   {
      resultado = 1;
   }
   else if (tiempo1.horas < tiempo2.horas)
   {
      resultado = -1;
   }
   else
   {
      if (tiempo1.minutos > tiempo2.minutos)
      {
         resultado = 1;
      }
      else if (tiempo1.minutos < tiempo2.minutos)
      {
         resultado = -1;
      }
      else
      {
         if (tiempo1.segundos > tiempo2.segundos)
         {
            resultado = 1;
         }
         else if (tiempo1.segundos < tiempo2.segundos)
         {
            resultado = -1;
         }
         else
         {
            resultado = 0;
         }
      }
   }
   return resultado;
}