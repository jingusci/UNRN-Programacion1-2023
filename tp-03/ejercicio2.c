/*
Ejercicio 2. Cadenas Seguras
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define DESTINO_MENOR_ORIGEN -2
#define CAPACIDAD 25

// Declaracion de funciones
int solicitar_entero();
int largo_seguro(char cadena[], int capacidad);
int copiar_cadenas(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino);
int insertar_cadena(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino, int posicion);
int muestra_arreglo(int capacidad, char arreglo[]);
int limpiar_cadena(char cadena_origen[], char cadena_limpia[], int capacidad_origen, int capacidad_limpia);
int comparar_cadena(char cadena_1[], char cadena_2[], int capacidad_1, int capacidad_2);
void convertir_a_minusculas(char cadena[], int capacidad);
int es_palindromo(char cadena[], int capacidad);

/* ----------------- Inicio del MAIN ----------------- */
int main()
{
   int opcion=0;
   do
   {
      printf("\nPrograma CADENAS SEGURAS\n");
      printf("Funciones a testear:\n");
      printf("1. Largo de Cadenas\n");
      printf("2. Copia de Cadenas\n");
      printf("3. Insercion de cadenas\n");
      printf("4. Limpieza\n");
      printf("5. Comparacion\n");
      printf("6. A minusculas y a mayusculas\n");
      printf("7. Palindromo seguro\n");
      printf("8. Salir\n");
      printf("Indique operacion a realizar: ");
      scanf("%d", &opcion);

      switch (opcion)
      {
      case 1:
         printf("Ejercicio 2.1 Largo de Cadenas\n");
         int capacidad_ej_2_1 = CAPACIDAD;
         char cadena_ej_2_1[CAPACIDAD]; // Capacidad iniciada en 25. Si la cadena recibe mas de 25 caracteres da error.
         printf("Ingrese la cadena a evaluar: ");
         scanf("%s", cadena_ej_2_1);
         printf("La cadena ingresada es: < %s >\n", cadena_ej_2_1);

         int largo_cadena_ej_2_1 = largo_seguro(cadena_ej_2_1, capacidad_ej_2_1);

         if (largo_cadena_ej_2_1 >= 0)
         {
            printf("El largo de la cadena es: %d\n", largo_cadena_ej_2_1);
         }
         else if (largo_cadena_ej_2_1 == CADENA_SIN_TERMINADOR)
         {
            printf("La cadena no tiene terminador.\n");
         }
         else
         {
            printf("Hubo algun otro problema \n");
         }
         break;
      case 2:
         printf("Ejercicio 2.2 Copia de Cadenas\n");
         int capacidad1_ej_2_2 = CAPACIDAD;
         char cadena1_ej_2_2[CAPACIDAD];
         int capacidad2_ej_2_2 = CAPACIDAD;
         char cadena2_ej_2_2[CAPACIDAD];
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_2);
         printf("Cadena 1: < %s >\n", cadena1_ej_2_2);

         int largo_cadena_ej_2_2 = copiar_cadenas(cadena1_ej_2_2, cadena2_ej_2_2, capacidad1_ej_2_2, capacidad2_ej_2_2);

         if (largo_cadena_ej_2_2 >= 0)
         {
            printf("El largo de la Cadena 2 es: %d\n", largo_cadena_ej_2_2);
            printf("La Cadena 2 es: < %s >\n", cadena2_ej_2_2);
         }
         else if (largo_cadena_ej_2_2 == CADENA_SIN_TERMINADOR)
         {
            printf("La cadena no tiene terminador.\n");
         }
         else if (largo_cadena_ej_2_2 == DESTINO_MENOR_ORIGEN)
         {
            printf("Largo de destino insuficiente.\n");
         }
         break;
      case 3:
         printf("Ejercicio 2.3 Insercion de cadenas\n");
         int capacidad1_ej_2_3 = CAPACIDAD;
         char cadena1_ej_2_3[CAPACIDAD];
         int capacidad2_ej_2_3 = CAPACIDAD;
         char cadena2_ej_2_3[CAPACIDAD];
         int posicion;
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_3);
         printf("Cadena 1: < %s >\n", cadena1_ej_2_3);
         printf("Ingrese la segunda cadena: ");
         scanf("%s", cadena2_ej_2_3);
         printf("Cadena 2: < %s >\n", cadena2_ej_2_3);
         printf("Ingrese la posicion donde desea insertar: ");
         scanf("%d", &posicion);
         printf("Posicion: < %d >\n", posicion);

         int resultado_insercion = insertar_cadena(cadena1_ej_2_3, cadena2_ej_2_3, capacidad1_ej_2_3, capacidad2_ej_2_3, posicion);

         if (resultado_insercion >= 0)
         {
            printf("El largo de la cadena es: %d\n", resultado_insercion);
            printf("Nueva cadena 2: < %s >\n", cadena2_ej_2_3);
         }
         else if (resultado_insercion == CADENA_SIN_TERMINADOR)
         {
            printf("La cadena no tiene terminador.\n");
         }
         else if (resultado_insercion == DESTINO_MENOR_ORIGEN)
         {
            printf("Destino cortina \n");
         }
         break;
      case 4:
         printf("Ejercicio 2.4 Limpieza\n");
         int capacidad1_ej_2_4 = CAPACIDAD;
         char cadena1_ej_2_4[CAPACIDAD];
         int capacidad2_ej_2_4 = CAPACIDAD;
         char cadena2_ej_2_4[CAPACIDAD];
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_4);
         printf("Cadena 1: < %s >\n", cadena1_ej_2_4);

         int resultado_limpieza = limpiar_cadena(cadena1_ej_2_4, cadena2_ej_2_4, capacidad1_ej_2_4, capacidad2_ej_2_4);

         if (resultado_limpieza >= 0)
         {
            printf("El largo de la cadena es: %d\n", resultado_limpieza);
            printf("Nueva cadena 2: < %s >\n", cadena2_ej_2_4);
         }
         else if (resultado_limpieza == CADENA_SIN_TERMINADOR)
         {
            printf("La cadena no tiene terminador.\n");
         }
         else if (resultado_limpieza == DESTINO_MENOR_ORIGEN)
         {
            printf("Destino cortina \n");
         }
         break;
      case 5:
         printf("Ejercicio 2.5 Comparacion\n");
         int capacidad1_ej_2_5 = CAPACIDAD;
         char cadena1_ej_2_5[CAPACIDAD];
         int capacidad2_ej_2_5 = CAPACIDAD;
         char cadena2_ej_2_5[CAPACIDAD];
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_5);
         printf("Cadena 1: < %s >\n", cadena1_ej_2_5);
         printf("Ingrese la segunda cadena: ");
         scanf("%s", cadena2_ej_2_5);
         printf("Cadena 2: < %s >\n", cadena2_ej_2_5);

         int comparacion = comparar_cadena(cadena1_ej_2_5, cadena2_ej_2_5, capacidad1_ej_2_5, capacidad2_ej_2_5);

         if (comparacion == 0)
         {
            printf("Las cadenas son iguales\n");
         }
         else if (comparacion == -1)
         {
            printf("La primera cadena va antes de que las segunda\n");
         }
         else if (comparacion == 1)
         {
            printf("La primera cadena va despues de que las segunda\n");
         }
         break;
      case 6:
         printf("Ejercicio 2.6 A minusculas y a mayusculas\n");
         int capacidad1_ej_2_6 = CAPACIDAD;
         char cadena1_ej_2_6[CAPACIDAD];
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_6);

         printf("Cadena original: \t< %s >\n", cadena1_ej_2_6);
         convertir_a_minusculas(cadena1_ej_2_6, capacidad1_ej_2_6);
         printf("Cadena en minusculas: \t< %s >\n", cadena1_ej_2_6);

         break;
      case 7:
         printf("Ejercicio 2.7 Palíndromo seguro\n");
         int capacidad1_ej_2_7 = CAPACIDAD;
         char cadena1_ej_2_7[CAPACIDAD];
         printf("Ingrese la primer cadena: ");
         scanf("%s", cadena1_ej_2_7);
         printf("Cadena ingresada:< %s >\n", cadena1_ej_2_7);

         int palindromo = es_palindromo(cadena1_ej_2_7, capacidad1_ej_2_7);

         if (palindromo == 1)
         {
            printf("La cadena es palindromo\n");
         }
         else if (palindromo == 0)
         {
            printf("La cadena no es palindromo\n");
         }
         else
         {
            printf("ERROR\n");
         }
         break;
      case 8:
         printf("Saliendo del programa...\n");
         break;
      }

   } while (opcion != 8);

   return 0;
}
/* ----------------- Fin del MAIN ----------------- */

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
 * La función copia una cadena en otra, asegurándose de no exceder la capacidad de la cadena destino.
 * 
 * @param cadena_origen es la dirección de la cadena que se copiará.
 * @param cadena_destino es la dirección de la cadena donde se copiará la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_destino es el tamaño máximo en memoria de la cadena destino.
 * 
 * @return Un número entero que representa el largo de la cadena destino después de la copia
 *         o un código de error, como CADENA_SIN_TERMINADOR o DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena destino o un código de error si la copia no se pudo realizar.
 */
int copiar_cadenas(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);

   if (largo_origen == CADENA_SIN_TERMINADOR)
   {
      resultado = CADENA_SIN_TERMINADOR;
   }
   else if (largo_origen >= capacidad_destino)
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else
   {
      for (int i = 0; i < (largo_origen + 1); i++)
      {
         cadena_destino[i] = cadena_origen[i];
      }
      resultado = largo_seguro(cadena_destino, capacidad_destino);
   }

   return resultado;
}

/**
 * La función inserta una cadena en otra en una posición específica, asegurándose de no exceder la capacidad de la cadena destino.
 * 
 * @param cadena_origen es la dirección de la cadena que se insertará.
 * @param cadena_destino es la dirección de la cadena donde se insertará la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_destino es el tamaño máximo en memoria de la cadena destino.
 * @param posicion es la posición en la cadena destino donde se insertará la cadena origen.
 * 
 * @return Un número entero que representa el largo de la cadena destino después de la inserción
 *         o un código de error, como CADENA_SIN_TERMINADOR o DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena destino o un código de error si la inserción no se pudo realizar.
 */
int insertar_cadena(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino, int posicion)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);
   int largo_destino = largo_seguro(cadena_destino, capacidad_destino);

   if (capacidad_destino <= (largo_origen + largo_destino))
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else if (largo_origen == CADENA_SIN_TERMINADOR || largo_destino == CADENA_SIN_TERMINADOR)
   {
      resultado = CADENA_SIN_TERMINADOR;
   }
   else
   {
      for (int i = posicion + 1; i < posicion + 1 + largo_origen; i++)
      {
         cadena_destino[i + largo_origen] = cadena_destino[i];
         cadena_destino[i] = cadena_origen[i - posicion - 1];
      }
      resultado = largo_seguro(cadena_destino, capacidad_destino);
   }
   return resultado;
}

/**
 * La función limpia una cadena de caracteres de todos los caracteres que no sean alfanuméricos (AZaz09).
 * 
 * @param cadena_origen es la dirección de la cadena que se limpiará.
 * @param cadena_limpia es la dirección de la cadena donde se almacenará la versión limpia de la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_limpia es el tamaño máximo en memoria de la cadena limpia.
 * 
 * @return Un número entero que representa el largo de la cadena limpia después de la operación
 *         o un código de error, como DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena limpia o un código de error si la limpieza no se pudo realizar.
 */
int limpiar_cadena(char cadena_origen[], char cadena_limpia[], int capacidad_origen, int capacidad_limpia)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);

   if (largo_origen > capacidad_limpia)
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else
   {
      int j = 0;
      for (int i = 0; i <= largo_origen; i++)
      {
         if ((cadena_origen[i] >= '0' && cadena_origen[i] <= '9') ||
             (cadena_origen[i] >= 'A' && cadena_origen[i] <= 'Z') ||
             (cadena_origen[i] >= 'a' && cadena_origen[i] <= 'z') ||
             (cadena_origen[i] == '\0'))
         {
            cadena_limpia[j] = cadena_origen[i];
            j++;
         }
      }
      resultado = largo_seguro(cadena_limpia, capacidad_limpia);
   }
   return resultado;
}

/**
 * La función compara dos cadenas de caracteres.
 * 
 * @param cadena_1 es la dirección de la primera cadena a comparar.
 * @param cadena_2 es la dirección de la segunda cadena a comparar.
 * @param capacidad_1 es el tamaño máximo en memoria de la primera cadena.
 * @param capacidad_2 es el tamaño máximo en memoria de la segunda cadena.
 * 
 * @return Un número entero que indica la relación entre las cadenas:
 *         - ( 1) si la primera cadena es mayor que la segunda.
 *         - ( 0) si las cadenas son iguales.
 *         - (-1) si la primera cadena es menor que la segunda.
 */
int comparar_cadena(char cadena_1[], char cadena_2[], int capacidad_1, int capacidad_2)
{
   int resultado = 0;
   int largo_origen = largo_seguro(cadena_1, capacidad_1);
   for (int i = 0; i <= largo_origen; i++)
   {
      if (cadena_1[i] > cadena_2[i])
      {
         resultado = 1;
         break;
      }
      else if (cadena_1[i] < cadena_2[i])
      {
         resultado = -1;
         break;
      }
   }
   return resultado;
}

/**
 * La función convierte una cadena de caracteres a minúsculas.
 * 
 * @param cadena es la dirección de la cadena que se convertirá a minúsculas.
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de la cadena en memoria.
 */
void convertir_a_minusculas(char cadena[], int capacidad)
{
   int resultado = 0;
   int distancia = 32; // distancia entre la "A" y la "a" en ASCII

   int largo_cadena = largo_seguro(cadena, capacidad);

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] >= 'A' && cadena[i] <= 'Z')
      {
         cadena[i] = cadena[i] + distancia;
      }
   }
}

/**
 * La función verifica si una cadena de caracteres es un palíndromo.
 * 
 * @param cadena es la dirección de la cadena que se verificará como palíndromo.
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de la cadena en memoria.
 * 
 * @return Un número entero que indica si la cadena es un palíndromo o no:
 *         - 1 si la cadena es un palíndromo.
 *         - 0 si la cadena no es un palíndromo.
 */
int es_palindromo(char cadena[], int capacidad)
{
   int resultado = 0;
   int largo_cadena = largo_seguro(cadena, capacidad);

   // convierto todo a misnusculas para laburarlo:
   convertir_a_minusculas(cadena, capacidad);

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] != cadena[largo_cadena - 1 - i])
      {
         resultado = 0;
         break;
      }
      resultado = 1;
   }

   return resultado;
}
