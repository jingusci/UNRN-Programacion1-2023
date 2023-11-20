/*
Ejercicio 6. Suma de Números Primos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int suma_de_primos(int numero);
int es_primo(int numero);

int main()
{
   // Solicitud de numero
   int numero = solicitar_entero();

   // Funcion
   int suma = suma_de_primos(numero);

   // Muestra de resultados
   printf("La suma de los primeros %d primos es igual a: %d", numero, suma);

   return 0;
}

/*
   Esta funcion calcula la suma de los primeros N números primos positivos.
   @param1 numero (int)
   @return suma (int)
*/
int suma_de_primos(int numero)
{     
   int suma = 0;
   int posible_primo = 2;
   int flag_primo = 0;

   for (int i=1; i<=numero;i++)
   {
      do
      {
         flag_primo = es_primo(posible_primo); 
         if (flag_primo == 1)
         {
            suma += posible_primo;
         }
         posible_primo++;

      } while (flag_primo != 1);

   }

   return suma;
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
// gcc ejercicio6.c -o ejercicio6