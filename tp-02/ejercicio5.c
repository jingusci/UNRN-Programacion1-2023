/*
Ejercicio 5. Menor de Tres Números
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
int menor_de_tres(int numero1,int numero2, int numero3);

int main()
{
   // Solicitud de numeros
   int numero1 = solicitar_entero();
   int numero2 = solicitar_entero();
   int numero3 = solicitar_entero();

   // Funcion
   int menor = menor_de_tres(numero1, numero2, numero3);

   // Muestra de resultados
   printf("El menor de los numeros es: %d", menor);

   return 0;
}

/*
   Esta función toma tres números enteros 
   como argumentos y devuelve el menor de ellos.
   @param1 numero1 (int)
   @param2 numero2 (int)
   @param3 numero3 (int)
   @return menor (int)
*/
int menor_de_tres(int numero1,int numero2, int numero3)
   {     
      int menor = 0;
      if (numero1 <= numero2)
      {
         if (numero1 <= numero3)
         {
            menor = numero1;
         }
         else
         {
            menor = numero3;
         }
      }
      else
      {
         if (numero2 <= numero3)
         {
            menor = numero2;
         }
         else
         {
            menor = numero3;
         }
         
      }
      return menor;
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
// gcc ejercicio5.c -o ejercicio5

