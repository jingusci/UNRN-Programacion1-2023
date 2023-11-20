/*
Ejercicio 3 - Números positivos y negativos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int signo(int numero);

int main()
{
   // Declaracion de variable
   int numero = 0;

   // Solicitud de numero
   printf("ingrese un numero: ");
   scanf("%d", &numero);

   // Función
   int numero_resultado = signo(numero);
   
   // Muestra de resultados
   if (numero_resultado == 1)
   {
      printf("El numero %d es positivo\n", numero);
   }
   else if (numero_resultado == 0)
   {
      printf("El numero %d es cero\n", numero);
   }
   else if (numero_resultado == -1)
   {
      printf("El numero %d es negativo\n", numero);
   }
   
   return 0;
}


/*
   Esta funcion recibe un número entero e indica si el mismo
   es positivo, negativo o cero.
   @param numero es el valor que recibe (int)
   @return resultado (int)
*/
int signo(int numero)
{
   int resultado = 0;
   if (numero > 0) 
   {
      resultado = 1;
   } 
   else if (numero < 0) 
   {
      resultado = -1;
   }
   else
   {
      resultado = 0;
   }
   return resultado;
}

// Linea para compilar:
// gcc ejercicio3.c -o ejercicio3