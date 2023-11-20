/*
Ejercicio  - Divisiones
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int division_lenta(int dividendo, int divisor);
int cociente_lento(int dividendo, int divisor);

int main()
{
   // Declaracion de variable
   int dividendo;
   int divisor;

   // Solicitud de numeros
   printf("ingrese el dividendo: ");
   scanf("%d", &dividendo);
   printf("ingrese el divisor: ");
   scanf("%d", &divisor);

   // Funciones
   int cociente = cociente_lento(dividendo,divisor);
   int resto = division_lenta(dividendo,divisor);
   
   // Muestra de resultados
   printf("%d dividido %d es igual a %d con resto %d",dividendo,divisor,cociente,resto);

   return 0;
}


/*
   Esta funcion recibe dos números enteros y realiza una
   "division lenta" de los mismos, y devuelve el resto de la división.
   @param1 dividendo (int)
   @param1 divisor (int)
   @return resultado (int)
*/
int division_lenta(int dividendo, int divisor)
{
   // creo el resto igual al dividendo
   int resto = dividendo;

   // Bucle que realiza la "division lenta"
   while (resto >= divisor)
   {
      resto = resto - divisor;
   }
   return resto;
}

/*
   Esta funcion recibe dos números enteros y realiza una
   "division lenta" de los mismos, y devuelve el cociente de la división.
   @param1 dividendo (int)
   @param1 divisor (int)
   @return cociente (int)
*/
int cociente_lento(int dividendo, int divisor)
{
   // inicio el resultado en cero
   int cociente = 0;

   // creo el resto igual al dividendo
   int resto = dividendo;

   // Bucle que realiza la "division lenta"
   while (resto >= divisor)
   {
      resto = resto - divisor;
      cociente++;
   }
   return cociente;
}


// Linea para compilar:
// gcc ejercicio6.c -o ejercicio6


/*
   NOTAS:
      - No funciona para numeros negativos.
   Posible mejora:
      - Realizarlo en una única funcion, ya que el proceso está repetido.
*/