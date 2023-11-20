/*
Ejercicio 9 - Múltiplos de
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int es_multiplo(int numero, int multiplo);

int main()
{
   // Declaracion de variables
   int numero;
   int multiplo;

   // Solicitud de numeros
   printf("ingrese el primer numero: ");
   scanf("%d", &numero);
   printf("ingrese el segundo numero: ");
   scanf("%d", &multiplo);

   // Función
   int resultado = es_multiplo(numero,multiplo);
   
   // Muestra de resultados
   if (resultado == 1)
   {
      printf("Un numero es multiplo del otro\n",numero,multiplo);
   }
   else
   {
      printf("Los numeros no son multiplos\n",numero,multiplo);
   }

   return 0;
}

/*
   Esta funcion recibe dos números enteros y verifica si un numero
   es multiplo del otro, realizando restas.
   @param1 numero (int)
   @param2 multiplo (int)
   @return resultado (int)
*/
int es_multiplo(int numero, int multiplo)
{
   int resultado = 0;

   if (numero >= multiplo)
   {
      while (numero >= multiplo) 
      {
         numero -= multiplo;
      }
      if (numero == 0)
      {
         resultado = 1;
      }  
   }
   else 
   {
      while (multiplo >= numero) 
      {
         multiplo -= numero;
      }  
      if (multiplo == 0)
      {
         resultado = 1;
      }  
   }
   return resultado;
}


// Linea para compilar:
// gcc ejercicio9.c -o ejercicio9

/*
   Notas:
      No funciona con numeros negativos.   
*/