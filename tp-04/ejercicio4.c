/*
Ejercicio 4 - División lenta II
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
void division_lenta(int dividendo, int divisor, int *cociente, int *resto);

int main()
{
   // inicializo cociente y resto
   int cociente, resto;

   // solicito dividendo y divisor
   int dividendo = solicitar_entero();
   int divisor = solicitar_entero();

   // llamo a la funcion pasando dividendo y divisor como copia, y cociente y resto por referencia
   division_lenta(dividendo, divisor, &cociente, &resto);

   // muestro resultado:
   printf("Resultado:\n");
   printf("%d / %d = %d con resto %d\n", dividendo, divisor, cociente, resto);

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
 * Esta función realiza una división lenta entre dos números entero, calculando el cociente y el resto.
 *
 * @param dividendo - El número entero que se dividirá.
 * @param divisor - El número entero por el cual se dividirá el dividendo.
 * @param cociente - Un puntero a un entero donde se almacenará el resultado de la división (cociente).
 * @param resto - Un puntero a un entero donde se almacenará el resto de la división.
 *
 * @pre 'divisor' debe ser distinto de cero.
 * @pre 'cociente' y 'resto' deben ser punteros válidos a ubicaciones de memoria donde se almacenarán los resultados.
 * @post El cociente almacenado en 'cociente' es el resultado de la división de 'dividendo' por 'divisor'.
 * @post El resto de la división se almacena en 'resto'.
 */
void division_lenta(int dividendo, int divisor, int *cociente, int *resto)
{
   *resto = dividendo; // igual resto al dividendo
   *cociente = 0;      // inicio el contador cociente en cero

   // Bucle que realiza la "division lenta"
   while (*resto >= divisor)
   {
      *resto = *resto - divisor;
      *cociente = *cociente + 1;
   }
}