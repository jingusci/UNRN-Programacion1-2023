/*
Ejercicio 10 - Reemplazo
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
void reemplazo_vocales(char cadena[], int capacidad_cadena, char caracter);

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena[CAPACIDAD_INICIAL];

   // Defino capacidad y solicito cadena
   int capacidad = solicitar_capacidad();
   printf("Ingrese la cadena a evaluar: ");
   scanf("%s", cadena);
   printf("La cadena ingresada es: < %s >\n", cadena);

   // Solicito caracter
   char caracter;
   printf("Ingrese el caracter:");
   scanf(" %c", &caracter);
   printf("\n");

   // Ejecuto intercambio
   reemplazo_vocales(cadena, capacidad, caracter);

   // muestro por pantalla
   printf("La nueva cadena es: < %s >\n", cadena);

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
 * Reemplaza las vocales en una cadena dada con un carácter especificado.
 *
 * Esta función recorre la cadena dada y reemplaza todas las vocales (mayúsculas
 * y minúsculas) con el carácter especificado.
 *
 * @param cadena - La cadena en la que se reemplazarán las vocales.
 * @param capacidad_cadena - La capacidad máxima de la cadena.
 * @param caracter - El carácter con el que se reemplazarán las vocales.
 *
 * @pre `cadena` debe ser una cadena de caracteres válida.
 * @pre `capacidad_cadena` debe ser mayor que cero.
 *
 * @post La cadena dada se modifica directamente, reemplazando las vocales por el carácter especificado.
 */
void reemplazo_vocales(char cadena[], int capacidad_cadena, char caracter)
{
   int largo_cadena = largo_seguro(cadena, capacidad_cadena);

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] == 'a' || cadena[i] == 'A' ||
          cadena[i] == 'e' || cadena[i] == 'E' ||
          cadena[i] == 'i' || cadena[i] == 'I' ||
          cadena[i] == 'o' || cadena[i] == 'O' ||
          cadena[i] == 'u' || cadena[i] == 'U')
      {
         cadena[i] = caracter;
      }
   }
}
