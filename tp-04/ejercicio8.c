/*
Ejercicio 8 - Búsqueda
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
char *busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda);

int main()
{
   // Declaro cadena segun la capacidad inicial
   char cadena1[CAPACIDAD_INICIAL];
   // Defino capacidad y solicito cadena
   int capacidad1 = solicitar_capacidad();
   printf("Ingrese la cadena: ");
   scanf("%s", cadena1);
   printf("La cadena ingresada es: < %s >\n", cadena1);

   // Declaro cadena que busco
   char cadena_buscada[CAPACIDAD_INICIAL];
   // Defino capacidad y solicito cadena
   int capacidad2 = solicitar_capacidad();
   printf("Ingrese la cadena a buscar: ");
   scanf("%s", cadena_buscada);
   printf("La cadena a buscar es: < %s >\n", cadena_buscada);

   char *puntero_busqueda = busqueda(cadena1, capacidad1, cadena_buscada, capacidad2);

   // muestro por pantalla
   if (puntero_busqueda == NULL)
   {
      printf("No se encontro la cadena buscada.\n");
   }
   else
   {
      printf("Se encontro la cadena buscada.\n");
      printf("La direccionde memoria donde comienza es: < 0x%p >\n", puntero_busqueda);
   }

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
 * Busca la primera ocurrencia de una subcadena en una cadena dada.
 *
 * @param cadena - La cadena en la que se buscará la subcadena.
 * @param capacidad_cadena - La capacidad de memoria asignada para la cadena.
 * @param busqueda - La subcadena que se buscará en la cadena principal.
 * @param capacidad_busqueda - La capacidad de memoria asignada para la subcadena.
 *
 * @return Un puntero a la primera ocurrencia de la subcadena en la cadena principal.
 *         Si la subcadena no se encuentra, se devuelve un puntero nulo (NULL).
 *
 * @pre Ambas cadenas, 'cadena' y 'busqueda', deben ser cadenas de caracteres válidas.
 * @pre 'capacidad_cadena' y 'capacidad_busqueda' deben ser mayores que 0.
 *
 * @post El puntero retornado apunta a la primera ocurrencia de la subcadena en la cadena principal,
 *       o es nulo (NULL) si la subcadena no se encuentra en la cadena principal.
 */
char *busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda)
{
   char *resultado = NULL;

   int largo_cadena = largo_seguro(cadena, capacidad_cadena);
   int largo_cadena_buscada = largo_seguro(busqueda, capacidad_busqueda);
   int flag_busqueda = 0;

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] == busqueda[0])
      {
         flag_busqueda = 1;
         for (int j = 0; j < largo_cadena_buscada; j++)
         {
            if (cadena[i + j] != busqueda[j])
            {
               flag_busqueda = 0;
            }
         }
         if (flag_busqueda == 1)
         {
            resultado = &cadena[i];
            break;
         }
      }
   }

   return resultado;
}