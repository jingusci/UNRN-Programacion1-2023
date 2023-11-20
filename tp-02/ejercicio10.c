/*
Ejercicio 2 - Conversión de temperaturas
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
float centigrados_a_fahrenheit(float centigrados);
float fahrenheit_a_centigrados(float fahrenheit);
float litros_a_galones(float litros);
float galones_a_litros(float galones);
float millas_a_kilometros(float millas);
float kilometros_a_millas(float kilometros);
float solicitar_float();

int main()
{

   // Declaracion de variables
   float centigrados,fahrenheit,litros,galones,millas,kilometros;
   int opcion;

   // ejecucion de programa en consola de forma permanente hasta que el usuario desee salir
   do 
   {
      printf("\nOpciones:\n");
      printf("1. Grados Centigrados a Grados Fahrenheit\n");
      printf("2. Grados Fahrenheit a Grados Centigrados\n");
      printf("3. Litros a Galones\n");
      printf("4. Galones a Litros\n");
      printf("5. Millas a Kilometros\n");
      printf("6. Kilometros a Millas\n");
      printf("7. Salir\n");
      printf("Ingrese opcion: ");
      scanf("%d", &opcion);

      switch (opcion)
      {
         case 1:
            printf("\nIngrese candtidad de grados Centigrados a convertir: ");
            centigrados = solicitar_float();
            fahrenheit = centigrados_a_fahrenheit(centigrados);
            printf("%.2f grados centigrados son %.2f grados Fahrenheit\n", centigrados, fahrenheit);
            break;
         case 2:
            printf("\nIngrese candtidad de grados Fahrenheit a convertir: ");
            fahrenheit = solicitar_float();
            centigrados = fahrenheit_a_centigrados(fahrenheit);
            printf("%.2f grados Fahrenheit son %.2f grados centigrados\n", fahrenheit, centigrados);
            break;
         case 3:
            printf("\nIngrese candtidad de litros a convertir: ");
            litros = solicitar_float();
            galones = litros_a_galones(litros);
            printf("%.2f litros son %.2f galones\n", litros, galones);
            break;
         case 4:
            printf("\nIngrese candtidad de galones a convertir: ");
            galones = solicitar_float();
            litros = galones_a_litros(galones);
            printf("%.2f galones son %.2f litros\n", galones, litros);
            break;
         case 5:
            printf("\nIngrese candtidad de millas a convertir: ");
            millas = solicitar_float();
            kilometros = millas_a_kilometros(millas);
            printf("%.2f millas son %.2f kilometros\n", millas, kilometros);
            break;
         case 6:
            printf("\nIngrese candtidad de kilometros a convertir: ");
            kilometros = solicitar_float();
            millas = kilometros_a_millas(kilometros);
            printf("%.2f kilometros son %.2f millas\n", kilometros, millas);
            break;
         case 7:
            printf("Saliendo del programa...\n");
            break;
         default:
            break;
      }
   } while (opcion !=7);

   return 0;
}

/*
   Esta funcion convierte valores de grados centigrados a fahrenheit.
   @param centigrados es el valor que recibe (float)
   @return fahrenheit valor convertido (float)
*/
float centigrados_a_fahrenheit(float centigrados)
   {
      float fahrenheit = (centigrados * 9 / 5) + 32;
      return fahrenheit;
   }

/*
   Esta funcion convierte valores de grados fahrenheit a centigrados.
   @param fahrenheit es el valor que recibe (float)
   @return centigrados valor convertido (float)
*/
float fahrenheit_a_centigrados(float fahrenheit) 
   {
      float centigrados = (fahrenheit - 32) * 5 / 9;
      return centigrados;
   }

/*
   Esta funcion convierte valores de litros a galones.
   @param litros es el valor que recibe (float)
   @return galones valor convertido (float)
*/
float litros_a_galones(float litros)
   {
      float galones = litros / 3.785;
      return galones;
   }

/*
   Esta funcion convierte valores de galones a litros.
   @param galones es el valor que recibe (float)
   @return litros valor convertido (float)
*/
float galones_a_litros(float galones)
   {
      float litros = galones * 3.785;
      return litros;
   }

/*
   Esta funcion convierte valores de millas a kilometros.
   @param millas es el valor que recibe (float)
   @return kilometros valor convertido (float)
*/
float millas_a_kilometros(float millas)
   {
      float kilometros = millas * 1.60934;
      return kilometros;
   }

/*
   Esta funcion convierte valores de kilometros a millas.
   @param kilometros es el valor que recibe (float)
   @return millas valor convertido (float)
*/
float kilometros_a_millas(float kilometros)
   {
      float millas = kilometros / 1.60934;
      return millas;
   }


/*
   Esta funcion solicita y retorna un numero flotante.
   @return flotante (float)
*/
float solicitar_float()
{
   float flotante;
   // printf("Ingrese un numero: "); // se comenta esta linea para tener mensajes personalizados
   scanf("%f", &flotante);
   return flotante;
}

// Linea para compilar:
// gcc ejercicio10.c -o ejercicio10