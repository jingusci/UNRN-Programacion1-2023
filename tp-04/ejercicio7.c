/*
Ejercicio 7 - Largo seguro II
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CAPACIDAD_INICIAL 25
#define CADENA_SIN_TERMINADOR -1

// Declaracion de funciones
int solicitar_entero();
int solicitar_capacidad();
int largo_seguro_1(char cadena[], int capacidad);  // Original del tp3
int largo_seguro_2(char *str);                     // Nueva version con puntero a la cadena

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena[CAPACIDAD_INICIAL];

   // Defino capacidad y solicito cadena
   int capacidad = solicitar_capacidad();
   printf("Ingrese la cadena a evaluar: ");
   scanf("%s", cadena);
   printf("\nLa cadena ingresada es: < %s >\n", cadena);

   //
   int largo = largo_seguro_1(cadena, capacidad);
   printf("El largo es: < %d >\n", largo);

   int largo2 = largo_seguro_2(&cadena[0]);
   printf("El largo es: < %d >\n", largo2);

   return 0;
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
int largo_seguro_1(char cadena[], int capacidad)
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
 * Calcula la longitud de una cadena segura utilizando punteros.
 *
 * @param str - Puntero a la cadena de caracteres de la cual se calculará la longitud.
 * @pre str es una cadena válida.
 *
 * @return Un número entero que representa la longitud de la cadena.
 * @post El valor de retorno es la cantidad de caracteres en la cadena.
 */
int largo_seguro_2(char *str)
{
   int largo = 0;

   while (*str != '\0')
   {
      largo++;
      str++;
   }

   return largo;
}