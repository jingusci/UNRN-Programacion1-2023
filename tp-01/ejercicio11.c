/*
Ejercicio 11 - Contador circular
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int contador_circular(int i, int limite);

int main()
{
   // Declaracion de variables
   int numero;
   int limite;

   // Solicitud de numeros
   printf("ingrese el numero: ");
   scanf("%d", &numero);
   printf("ingrese el limite: ");
   scanf("%d", &limite);

   // int resultado = contador_circular(numero,limite);
   while (numero <= limite)
   {
      numero = contador_circular(numero,limite);
      printf("El numero es %d\n",numero);
   }
   
   // Muestra de resultados
   // printf("El resultado es: %d\n",resultado);

   return 0;
}


/*
   Esta funcion recibe dos números, un entero y un limite,
   y retorna el numero incrementado en uno mientras no alcance 
   el limite. Cuando alcanza el limite, retorna 0.
   @param1 i (int)
   @param2 limite (int)
   @return resultado (int)
*/
int contador_circular(int i, int limite)
{
   int resultado;
   if (i == limite)
   {
      resultado = 0;
   }
   else
   {
      resultado = i + 1;
   }

   return resultado;
}


// Linea para compilar:
// gcc ejercicio11.c -o ejercicio11