/*
Ejercicio 7 - Números primos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int es_primo(int numero);

int main()
{
   // Declaracion de variable
   int numero;

   // Solicitud de numero
   printf("ingrese el primer numero: ");
   scanf("%d", &numero);

   // Función
   int resultado = es_primo(numero);
   
   // Muestra de resultados
   if (resultado == 1)
   {
      printf("El numero %d es primo\n",numero);
   }
   else
   {
      printf("El numero %d no es primo\n",numero);
   }

   return 0;
}

/*
   Esta funcion recibe un número entero e identifica si es primo o no.
   @param1 numero (int)
   @return resultado (int)
*/
int es_primo(int numero)
{
   int resultado = 1;
   int resto;
   for (int i=2; i<numero; i++)
   {
      resto = numero % i;

      if (resto == 0)
      {
         resultado = 0;
      }

   }
   return resultado;
}


// Linea para compilar:
// gcc ejercicio7.c -o ejercicio7