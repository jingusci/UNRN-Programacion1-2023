/*
Ejercicio 10 - Factorial
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int factorial(int numero);

int main()
{
   // Declaracion de variables
   int numero;

   // Solicitud de numeros
   printf("ingrese el primer numero: ");
   scanf("%d", &numero);

   // Función
   int resultado = factorial(numero);
   
   // Muestra de resultados
   printf("El resultado es: %d\n",resultado);

   return 0;
}

/*
   Esta funcion recibe un número entero calcula su factorial
   @param1 numero (int)
   @return resultado (int)
*/
int factorial(int numero)
{
   int resultado = 1;
   while (numero >=1)
   {
      resultado = resultado * numero;
      numero = numero -1;
   }

   return resultado;
}


// Linea para compilar:
// gcc ejercicio10.c -o ejercicio10