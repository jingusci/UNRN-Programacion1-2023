/*
Ejercicio 11. Números perfectos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int es_perfecto(int numero);

int main()
{
   // Solicitud de numero
   int numero = solicitar_entero();
   
   // Funcion solo para enteros positivos
   if (numero > 0)
   {
      // Funcion
      int resultado = es_perfecto(numero);

      // Muestra de resultados
      if (resultado == 1)
      {
         printf("El numero %d es perfecto\n",numero);
      }
      else
      {
         printf("El numero %d no es perfecto\n",numero);
      }
   }
   else
   {
      printf("El numero ingresado es negativo o cero");
   }
   
   return 0;
}

/*
   Esta funcion determina si un número entero positivo es un número perfecto.
   @param1 numero (int)
   @return resultado (int)
*/
int es_perfecto(int numero)
{
   int resultado = 0;
   int resto;
   int suma_temporal = 0;

   // Evaluo que divisores tiene el numero y acumulo en suma_temporal
   for (int i=1;i<=numero;i++)
   {
      resto = numero % i;
      if (resto==0)
      {
         suma_temporal += i;
      }
   }

   // Levanto el flag del resultado si cumple con la condicion de numero perfecto
      // Un numero es perfecto si la suma de sus divisores es igual al numero
   if (suma_temporal-numero == numero)
   {
      resultado = 1;
   }

   return resultado;
}


/*
   Esta funcion solicita y retorna un numero entero.
   @return entero (int)
*/
int solicitar_entero()
{
   int numero;
   printf("Ingrese un numero entero: ");
   scanf("%d", &numero);
   return numero;
}


// Linea para compilar:
// gcc ejercicio11.c -o ejercicio11
