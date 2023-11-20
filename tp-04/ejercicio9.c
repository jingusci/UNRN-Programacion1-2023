/*
Ejercicio 9 - Elimina duplicados
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
int elminar_duplicados(char cadena[], int capacidad_cadena);

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena[CAPACIDAD_INICIAL];

   // Defino capacidad y solicito cadena
   int capacidad = solicitar_capacidad();
   printf("Ingrese la cadena a evaluar: ");
   scanf("%s", cadena);
   printf("\nLa cadena ingresada es: < %s >\n", cadena);
   int largo = largo_seguro(cadena,capacidad);
   printf("El largo es: < %d >\n", largo);

   // Ejecuto intercambio
   int nuevo_largo = elminar_duplicados(cadena, capacidad);

   // muestro por pantalla
   printf("\nLa nueva cadena es: < %s >\n", cadena);
   printf("El nuevo largo es: < %d >\n", nuevo_largo);

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
 * Esta función busca caracteres duplicados en la cadena y los elimina, desplazando
 * los caracteres restantes para llenar el espacio dejado por los duplicados.
 *
 * @param cadena La cadena de caracteres en la que se eliminarán los duplicados.
 * @param capacidad_cadena La capacidad máxima de la cadena para evitar desbordamientos.
 *
 * @return El nuevo tamaño de la cadena después de eliminar los duplicados.
 */
int elminar_duplicados(char cadena[], int capacidad_cadena)
{
   int largo = largo_seguro(cadena, capacidad_cadena);

   for (int i = 0; i <= largo; i++)
   {
      for (int j = i + 1; j <= largo; j++)
      {
         if (cadena[i] == cadena[j])
         {
            for (int k = j + 1; k <= largo; k++)
            {
               cadena[k-1] = cadena[k];
            }
         }
         largo = largo_seguro(cadena, capacidad_cadena); // recalculo largo por si se modifico la cadena
      }
   }

   return largo;
}
