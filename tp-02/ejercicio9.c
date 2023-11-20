/*
Ejercicio 9. Cálculo de Suma de Dígitos en Serie de Fibonacci
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int suma_fibonacci(int numero);
int sumador_de_digitos(int numero);

int main()
{
   // Solicitud de numero
   int numero = solicitar_entero();
   
   // Funcion
   int resultado = suma_fibonacci(numero);

   // Muestra de resultados
   printf("La suma de los digitos de los primeros %d numeros de fibonacci es %d \n",numero,resultado);

   return 0;
}

/*
   Esta funcion calcula la suma de los dígitos de los términos en una serie de 
   Fibonacci hasta el N-ésimo término
   @param1 numero (int)
   @return resultado (int)
*/
int suma_fibonacci(int numero)
{
   int suma = 0;
   int termino_fibonacci;
   int fibonacci_temp1=0;
   int fibonacci_temp2=1;
   int suma_digitos = 0;

   for (int i=0;i<numero;i++)
   {
      // calculo termino fibonacci
      if (i == 0)
      {
         termino_fibonacci = 0;
      }
      else if (i==1)
      {
         termino_fibonacci = 1;
      }
      else
      {
         termino_fibonacci = fibonacci_temp1 + fibonacci_temp2;
         fibonacci_temp1 = fibonacci_temp2;
         fibonacci_temp2 = termino_fibonacci;
      }

      // calculo la suma de los digitos del termino
      suma_digitos = sumador_de_digitos(termino_fibonacci);
      // sumo en el total
      suma += suma_digitos;

   }

   return suma;
}



/*
   Esta funcion recibe un numero entero y suma sus digitos.
   @param1 numero (int)
   @return suma_digitos (int)
*/
int sumador_de_digitos(int numero)
{     
   int suma_digitos = 0;

   while (numero >=1)
   {
      suma_digitos += numero % 10;
      numero = numero / 10;
   }

   return suma_digitos;
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
// gcc ejercicio9.c -o ejercicio9
