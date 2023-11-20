/*
Ejercicio 8 - Suma en rango
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int suma_rango(int n, int m);

int main()
{
   // Declaracion de variables
   int n;
   int m;

   // Solicitud de numeros
   printf("ingrese el primer numero: ");
   scanf("%d", &n);
   printf("ingrese el segundo numero: ");
   scanf("%d", &m);

   // Función
   int suma = suma_rango(n,m);
   
   // Muestra de resultados
   printf("El resultado es: %d\n",suma);

   return 0;
}

/*
   Esta funcion recibe dos números enteros y realiza la suma del rango 
   comprendido entre ellos, sin incluir el segundo numero.
   @param1 n (int)
   @param2 m (int)
   @return resultado (int)
*/
int suma_rango(int n, int m)
{
   int resultado = 0;
   int inicio;
   int fin;

   // Creo variables de inicio y fin segun que numero es mayor
   if (n>m)
   {
      inicio = m;
      fin = n;
   }
   else
   {
      inicio = n;
      fin = m;
   }

   // int inicio = 0;
   // bucle
   for (inicio;inicio<fin;inicio++)
   {
      printf("Sumando %d...\n",inicio);
      resultado = resultado + inicio;
   }

   return resultado;
}

// Linea para compilar:
// gcc ejercicio8.c -o ejercicio8


/*
   Notas:
      En el proceso de salvar el bucle cuando
      el segundo numero es mayor que el primero,
      es siempre el numero mayor el "m" no incluido en
      la cuenta.
*/