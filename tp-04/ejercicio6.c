/*
Ejercicio 6 - Intercambio de caracteres
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CAPACIDAD_INICIAL 25
#define CADENA_SIN_TERMINADOR -1
#define POSICIONES_INCORRECTAS -2

// Declaracion de funciones
int solicitar_entero();
int solicitar_capacidad();
void intercambio_de_caracteres(char *izquierda, char *derecha);
int largo_seguro(char cadena[], int capacidad);
int intercambia(char cadena[], int capacidad_cadena, int origen, int destino);

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena[CAPACIDAD_INICIAL];

   // Defino capacidad y solicito cadena
   int capacidad = solicitar_capacidad();
   printf("Ingrese la cadena a evaluar: ");
   scanf("%s", cadena);
   printf("La cadena ingresada es: < %s >\n", cadena);

   // Solicito las posiciones
   printf("Ingrese las posiciones a intercambiar: \n");
   int pos1 = solicitar_entero();
   int pos2 = solicitar_entero();
   // printf("Las posiciones a intercambiar son: %d y %d\n", pos1, pos2);
   printf("\n");

   // Ejecuto intercambio
   int resultado = intercambia(cadena, capacidad, pos1, pos2);

   // Verifico resultado y muestro por pantalla
   if (resultado == POSICIONES_INCORRECTAS)
   {
      printf("Las posiciones de intercambio no estan disponibles en la cadena.\n");
   }
   else if (resultado == 1)
   {
      printf("Intercambio exitoso!\n");
      printf("La nueva cadena es: < %s >\n", cadena);
   }

   return 0;
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
 * La función intercambia dos caracteres a través de punteros.
 *
 * @param izquierda - Puntero al primer valor.
 * @param derecha - Puntero al segundo valor.
 *
 * @pre Ambos punteros (izquierda y derecha) deben apuntar a ubicaciones de memoria válidas
 *      que contengan caracteres.
 *
 * @post Después de llamar a esta función, los caracteres a los que apuntan los punteros izquierda
 *       y derecha se intercambiarán.
 */
void intercambio_de_caracteres(char *izquierda, char *derecha)
{
   char temp = *izquierda;
   *izquierda = *derecha;
   *derecha = temp;
}

/**
 * La función cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *
 * @param cadena es la dirección de la cadena con la que se contarán los caracteres.
 * @pre cadena es una cadena válida.
 * @param capacidad es un número distinto al largo de la cadena en sí y es el tamaño en memoria del arreglo.
 * @pre capacidad es un valor numérico entero positivo mayor a uno.
 *
 * @return Un número entero, donde los valores positivos (incluyendo el cero) representan la cantidad de caracteres.
 *         Los valores negativos indican situaciones de error, como CADENA_SIN_TERMINADOR, cuando la cantidad de caracteres
 *         es al menos igual a la capacidad indicada por el argumento.
 * @post El valor de retorno es el largo del arreglo o el código de error encontrado.
 */
int largo_seguro(char cadena[], int capacidad)
{
   int largo = 0;

   while (cadena[largo] != '\0' && largo < capacidad)
   {
      largo++;
   }

   if (largo == capacidad)
   {
      largo = CADENA_SIN_TERMINADOR;
   }

   return largo;
}

/**
 * Intercambia dos caracteres en una cadena.
 *
 * @param cadena - La cadena en la que se realizará el intercambio.
 * @param capacidad_cadena - La capacidad de la cadena.
 * @param origen - La posición del primer carácter a intercambiar.
 * @param destino - La posición del segundo carácter a intercambiar.
 *
 * @pre 'cadena' debe ser una cadena de caracteres válida.
 * @pre 'capacidad_cadena' debe ser mayor que 0.
 * @pre 'origen' y 'destino' deben ser posiciones válidos en la cadena.
 *
 * @returns 1 si se realiza con éxito el intercambio, 'POSICIONES_INCORRECTAS' si hay errores.
 *
 * @post Los caracteres en las posiciones 'origen' y 'destino' se intercambian en la cadena.
 */
int intercambia(char cadena[], int capacidad_cadena, int origen, int destino)
{
   int largo = largo_seguro(cadena, capacidad_cadena);
   int resultado_intercambio = 0;

   if (origen < 0 || origen > largo || destino < 0 || destino > largo)
   {
      resultado_intercambio = POSICIONES_INCORRECTAS;
   }
   else
   {
      intercambio_de_caracteres(&cadena[origen], &cadena[destino]);
      resultado_intercambio = 1;
   }
   return resultado_intercambio;
}
