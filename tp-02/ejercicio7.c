/*
Ejercicio 7. Potencia lenta
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int potencia_lenta(int numero, int exponente);
int multiplicar(int num1, int num2);

int main()
{
   // Solicitud de numeros (flotantes)
   int numero = solicitar_entero();
   int exponente = solicitar_entero();

   // Funcion
   int resultado = potencia_lenta(numero, exponente);

   // Muestra de resultados

   printf("%d elevado a %d es igual a: %d",numero,exponente,resultado);

   return 0;
}

/*
   Esta funcion calcula la potencia de un número elevado 
   a una potencia dada, sin utilizar el operador de multiplicación.
   @param1 numero (int)
   @param2 potencia (int)
   @return resultado (int)
*/
int potencia_lenta(int numero, int exponente)
   {     
      int resultado = 1;
      int flag_signo = 1;

      for (int i=1;i<=exponente;i++)
      {
         resultado = multiplicar(resultado,numero);
      }
      

      resultado = multiplicar(resultado,flag_signo);
      return resultado;
   }

/*
   Esta funcion realiza mutiplicaciones utilizando sumas.
   @param1 num1 (int)
   @param2 num2 (int)
   @return producto (int)
*/
int multiplicar(int num1, int num2)
{
   int producto = 0;
   int abs_num1 = num1, abs_num2 = num2;
   
   // 
   if (num1<0)
   {
      abs_num1 = -num1;
   }
   if (num2<0)
   {
      abs_num2 = -num2;
   }


   for(int i=1; i<=abs_num1;i++)
   {
      producto += abs_num2;
   }

   if ((num1>0 && num2<0) || (num1<0 && num2>0))
   {
      producto = -producto;
   }

   return producto;
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
// gcc ejercicio7.c -o ejercicio7
