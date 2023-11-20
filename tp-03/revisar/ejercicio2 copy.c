/*
Ejercicio 1. Arreglos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
// #define CAPACIDAD_NEGATIVA -2
#define DESTINO_MENOR_ORIGEN -2

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
   // Prueba ejercicio 2.1 Largo seguro
   printf("Ejercicio 2.1\n");
   char cadena[] = "Hola mundo";
   // int capacidad = solicitar_entero();
   int capacidad = 15;
   int largo_cadena = largo_seguro(cadena, capacidad);

   if (largo_cadena >= 0)
   {
      printf("El largo de la cadena es: %d\n", largo_cadena);
   }
   else if (largo_cadena == CADENA_SIN_TERMINADOR)
   {
      printf("La cadena no tiene terminador.\n");
   }
   else
   {
      printf("Hubo algun otro problema \n");
   }
   // Fin prueba ejercicio 2.1

   // Prueba ejercicio 2.2 Copia de cadenas
   printf("Ejercicio 2.2\n");
   int capacidad_1 = 25;
   char cadena1[] = "Adios mundo";
   int capacidad_2 = 25;
   char cadena2[capacidad_2];

   int resultado_copia = copiar_cadenas(cadena1, cadena2, capacidad_1, capacidad_2);

   if (resultado_copia >= 0)
   {
      printf("El largo de la cadena es: %d\n", resultado_copia);
      printf("[ ");
      for (int i = 0; i < resultado_copia; i++)
      {
         printf("%c", cadena2[i]);
      }
      printf(" ]\n");
   }
   else if (resultado_copia == CADENA_SIN_TERMINADOR)
   {
      printf("La cadena no tiene terminador.\n");
   }
   else if (resultado_copia == DESTINO_MENOR_ORIGEN)
   {
      printf("Destino cortina \n");
   }
   // Fin prueba ejercicio 2.2

   // Prueba ejercicio 2.3 Insercion de cadenas
   printf("Ejercicio 2.3\n");
   int capacidad_3 = 5;
   char cadena3[50] = "HOLA";
   int capacidad_4 = 11;
   char cadena4[50] = "Mundo";
   int posicion = 2;

   int resultado_insercion = insertar_cadena(cadena3, cadena4, capacidad_3, capacidad_4, posicion);

   if (resultado_insercion >= 0)
   {
      printf("El largo de la cadena es: %d\n", resultado_insercion);
      printf("[ ");
      for (int i = 0; i < resultado_insercion; i++)
      {
         printf("%c", cadena4[i]);
      }
      printf(" ]\n");
   }
   else if (resultado_insercion == CADENA_SIN_TERMINADOR)
   {
      printf("La cadena no tiene terminador.\n");
   }
   else if (resultado_insercion == DESTINO_MENOR_ORIGEN)
   {
      printf("Destino cortina \n");
   }
   // Fin prueba ejercicio 2.3

   // Prueba ejercicio 2.4 Limpieza
   printf("Ejercicio 2.4\n");
   int capacidad_5 = 25;
   char cadena5[25] = "Ad$#!ios mu)/ndo";
   int capacidad_6 = 25;
   char cadena6[25] = {0};

   int resultado_limpieza = limpiar_cadena(cadena5, cadena6, capacidad_5, capacidad_6);

   if (resultado_limpieza >= 0)
   {
      printf("El largo de la cadena es: %d\n", resultado_limpieza);
      printf("[ ");
      for (int i = 0; i < resultado_limpieza; i++)
      {
         printf("%c", cadena6[i]);
      }
      printf(" ]\n");
      // muestra_arreglo(capacidad_6,cadena6);
   }
   else if (resultado_limpieza == CADENA_SIN_TERMINADOR)
   {
      printf("La cadena no tiene terminador.\n");
   }
   else if (resultado_limpieza == DESTINO_MENOR_ORIGEN)
   {
      printf("Destino cortina \n");
   }
   // Fin prueba ejercicio 2.4

   // // Prueba ejercicio 2.5 Comparacion
   printf("Ejercicio 2.5\n");
   int capacidad_7 = 25;
   char cadena7[25] = "zzzz";
   int capacidad_8 = 25;
   char cadena8[25] = "zzzz";

   int comparacion = comparar_cadena(cadena7, cadena8, capacidad_7, capacidad_8);

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
   // Fin prueba ejercicio 2.5

   // Prueba ejercicio 2.6 A minúsculas y a mayúsculas
   printf("Ejercicio 2.6\n");
   int capacidad_9 = 25;
   char cadena9[] = "HOLAHOLAchauHOLA";
   int largo_cadena_9 = largo_seguro(cadena9, capacidad_9);
   printf("larg %d\n", largo_cadena_9);

   printf("La cadena original es: \n");
   printf("[ ");
   for (int i = 0; i < largo_cadena_9; i++)
   {
      printf("%c", cadena9[i]);
   }
   printf(" ]\n");

   convertir_a_minusculas(cadena9, capacidad_9);

   printf("La cadena en minusculas es: \n");

   printf("[ ");
   for (int i = 0; i < largo_cadena_9; i++)
   {
      printf("%c", cadena9[i]);
   }
   printf(" ]\n");

   // Fin prueba ejercicio 2.6

   // Prueba ejercicio 2.7 Palindromo
   printf("Ejercicio 2.7\n");
   int capacidad_10 = 25;
   char cadena10[] = "javi a ivaj";
   int largo_cadena_10 = largo_seguro(cadena10, capacidad_10);

   int palindromo = es_palindromo(cadena10, capacidad_10);

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
   // Fin prueba ejercicio 2.7

   return 0;
}
/* ----------------- Fin del MAIN ----------------- */

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
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
 * La funcion copia una cadena en otra.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
 */
int copiar_cadenas(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino)
{
   int resultado;

   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);
   // int largo_destino = largo_seguro(cadena_destino,capacidad_destino);

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
 * La funcion inserta una cadena en otra.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
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

/*
   Esta funcion solicita y retorna un numero entero.
   @return entero (int)
*/
int solicitar_entero()
{
   int numero;
   printf("Ingrese un numero entero: ");
   scanf("%d", &numero);
   return numero;
}

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

int muestra_arreglo(int capacidad, char arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error.

   printf("[ ");
   for (int i = 0; i < capacidad; i++)
   {
      printf("%c ", arreglo[i]);
   }
   printf("]\n");
   return flag_error;
}
