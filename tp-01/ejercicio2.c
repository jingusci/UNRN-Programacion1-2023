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

int main()
{
   // Declaracion de variables
   float temp_centigrados = 0;
   float temp_fahrenheit = 0;

   // Solicitud de numeros (flotantes)
   printf("ingrese los grados centigrados que desea convertir a fahrenheit: ");
   scanf("%f", &temp_centigrados);
   printf("ingrese los grados fahrenheit que desea convertir a centigrados: ");
   scanf("%f", &temp_fahrenheit);

   // Funciones que convierten
   float resultado_Fahrenheit = centigrados_a_fahrenheit(temp_centigrados);
   float resultado_Centigrados = fahrenheit_a_centigrados(temp_fahrenheit);
   
   // Muestra de resultados
   printf("%.2f grados centígrados son %.2f grados Fahrenheit\n", temp_centigrados, resultado_Fahrenheit);
   printf("%.2f grados Fahrenheit son %.2f grados centigrados\n", temp_fahrenheit, resultado_Centigrados);

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


// Linea para compilar:
// gcc ejercicio2.c -o ejercicio2