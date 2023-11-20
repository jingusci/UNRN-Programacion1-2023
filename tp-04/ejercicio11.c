/*
Ejercicio 11 - Inversión
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
int largo_seguro(char cadena[], int capacidad);
void invertir(char cadena[], int capacidad_cadena);

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena[CAPACIDAD_INICIAL];

   // Defino capacidad y solicito cadena
   int capacidad = solicitar_capacidad();
   printf("Ingrese la cadena a evaluar: ");
   scanf("%s", cadena);
   printf("La cadena ingresada es: < %s >\n", cadena);

   // Ejecuto intercambio
   invertir(cadena, capacidad);

   // muestro por pantalla
   printf("La nueva cadena es: < %s >\n", cadena);

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
 * Esta función toma una cadena y su capacidad, y revierte el orden de sus caracteres.
 *
 * @param cadena - La cadena cuyo orden de caracteres se invertirá.
 * @param capacidad_cadena - La capacidad máxima de la cadena.
 *
 * @pre `cadena` debe ser una cadena de caracteres válida.
 * @pre `capacidad_cadena` debe ser mayor que cero.
 *
 * @post La cadena dada se modifica directamente, invirtiendo el orden de sus caracteres.
 */
void invertir(char cadena[], int capacidad_cadena)
{
   int largo = largo_seguro(cadena, capacidad_cadena);

   char temp;
   for (int i = 0; i < largo / 2; i++)
   {
      temp = cadena[i];
      cadena[i] = cadena[largo - i - 1];
      cadena[largo - i - 1] = temp;
   }
}
