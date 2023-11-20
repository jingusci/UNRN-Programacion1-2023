/*
Ejercicio 5 - Suma lenta
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int suma_lenta(int numero, int otro_numero);

int main()
{
   // Declaracion de variable
   int numero = 0;
   int otro_numero = 0;

   // Solicitud de numeros
   printf("ingrese el primer numero: ");
   scanf("%d", &numero);
   printf("ingrese el segundo numero: ");
   scanf("%d", &otro_numero);

   // Función
   int resultado = suma_lenta(numero,otro_numero);
   
   // Muestra de resultados
   printf("El resultado es: %d\n",resultado);

   return 0;
}

/*
   Esta funcion recibe dos números enteros y realiza una
   "suma lenta" de los mismos.
   @param1 numero es el primer valor que recibe (int)
   @param1 otro_numero es el segundo valor que recibe (int)
   @return resultado (int)
*/
int suma_lenta(int numero, int otro_numero)
{
   int resultado = numero;
   if (otro_numero >= 0)
   {
      for (int i = 1; i <= otro_numero; i++) 
      {
         printf("Sumando...\n");      // No es recomendable el printf en una funcion, lo mantengo para mostrar el proceso.
         resultado = resultado + 1;
      } 
   } 
   else
   {
      for (int i = otro_numero; i < 0; i++) 
      {
         printf("Sumando...\n");
         resultado = resultado - 1;
      } 
   }
   return resultado;
}

// Linea para compilar:
// gcc ejercicio5.c -o ejercicio5