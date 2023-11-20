/*
Ejercicio 4 - Comparación de números
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int compara(int numero, int otro_numero);

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
   int resultado = compara(numero,otro_numero);
   
   // Muestra de resultados
   if (resultado == 1)
   {
      printf("El primer numero es mayor que el segundo\n");
   }
   else if (resultado == 0)
   {
      printf("Los numeros son iguales\n");
   }
   else if (resultado == -1)
   {
      printf("El primer numero es menor que el segundo\n");
   }

   return 0;
}

/*
   Esta funcion recibe dos números enteros e identifica cual
   es el mayor y cual es el menor.
   @param1 numero es el primer valor que recibe (int)
   @param1 otro_numero es el segundo valor que recibe (int)
   @return resultado (int)
*/
int compara(int numero, int otro_numero)
{
   int resultado = 0;
   if (numero > otro_numero) 
   {
      resultado = 1;
   } 
   else if (numero < otro_numero) 
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
// gcc ejercicio4.c -o ejercicio4