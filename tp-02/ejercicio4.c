/*
Ejercicio 4. Mayor de Tres Números
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int mayor_de_tres(int numero1,int numero2, int numero3);

int main()
{
   // Solicitud de numeros
   int numero1 = solicitar_entero();
   int numero2 = solicitar_entero();
   int numero3 = solicitar_entero();

   // Funcion
   int mayor = mayor_de_tres(numero1, numero2, numero3);

   // Muestra de resultados
   printf("El mayor de los numeros es: %d", mayor);

   return 0;
}

/*
   Esta función toma tres números enteros 
   como argumentos y devuelve el mayor de ellos.
   @param1 numero1 (int)
   @param2 numero2 (int)
   @param3 numero3 (int)
   @return mayor (int)
*/
int mayor_de_tres(int numero1,int numero2, int numero3)
   {     
      int mayor = 0;
      if (numero1 >= numero2)
      {
         if (numero1 >= numero3)
         {
            mayor = numero1;
         }
         else
         {
            mayor = numero3;
         }
      }
      else
      {
         if (numero2 >= numero3)
         {
            mayor = numero2;
         }
         else
         {
            mayor = numero3;
         }
         
      }
      return mayor;
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
// gcc ejercicio4.c -o ejercicio4

