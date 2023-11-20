/*
Ejercicio 1. Contador de dígitos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int contador_de_digitos(int numero);

int main()
{
   // Solicitud de numeros (flotantes)
   int numero = solicitar_entero();

   if (numero > 0)
   {
      // Funcion que cuenta digitos
      int digitos = contador_de_digitos(numero);
      // Muestra de resultados
      printf("%d tiene %d digito(s)", numero, digitos);
   }
   else
   {
      printf("El numero ingresado es negativo o cero");
   }

   return 0;
}

/*
   Esta funcion recibe un numero entero y cuenta sus digitos.
   @param1 numero (int)
   @return digitos (int)
*/
int contador_de_digitos(int numero)
   {
      int digitos = 0;

      while (numero >=1)
      {
         numero = numero / 10;
         digitos++;
      }

      return digitos;
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
// gcc ejercicio1.c -o ejercicio1