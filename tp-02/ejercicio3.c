/*
Ejercicio 3. Tabla de multiplicar
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
void tabla_de_multiplicar(int numero);

int main()
{
   
   // Solicitud de numeros
   int numero = solicitar_entero();

   // funcion
   tabla_de_multiplicar(numero);

   return 0;
}

/*
   Esta funcion recibe un numero entero y muestra por pantalla
   su tabla de multiplicar del 1 al 10.
   // Printf vale la pena en la funcion para practicidad del programa
   @param1 numero (int)
   @return suma_digitos (int)
*/
void tabla_de_multiplicar(int numero)
   {     
      int multiplicacion;
      for (int i = 1; i <= 10; i++)
      {
         multiplicacion = i * numero;
         printf("%d * %d\t=  %d\n",numero,i,multiplicacion);   
      }      
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
// gcc ejercicio3.c -o ejercicio3

