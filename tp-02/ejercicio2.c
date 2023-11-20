/*
Ejercicio 2. Suma de dígitos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int sumador_de_digitos(int numero);

int main()
{
   // Solicitud de numeros (flotantes)
   int numero = solicitar_entero();

   if (numero > 0)
   {
      // Funcion que suma digitos
      int suma = sumador_de_digitos(numero);
      // Muestra de resultados
      printf("La suma de los digitos de %d es %d", numero, suma);
   }
   else
   {
      printf("El numero ingresado es negativo o cero");
   }

   return 0;
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
// gcc ejercicio2.c -o ejercicio2

