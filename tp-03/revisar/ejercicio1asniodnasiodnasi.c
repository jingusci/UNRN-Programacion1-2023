/*
Ejercicio 1. Contador de dígitos
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int cargar_arreglo(int capacidad, int arreglo[]);

int main()
{
   // Solicitud de numeros
   int arreglo_1[];

   arreglo_1[] = cargar_arreglo(5,arreglo_1[]);

   // Funcion que cuenta digitos

   // Muestra de resultados

   return 0;
}



/*
   Esta funcion carga un arreglo de números 
   enteros, segun una cantidad dada de elementos, 
   solicita valores por teclado para llenar las posiciones.
   @param1 numero (int)
   @return digitos (int)
*/
int cargar_arreglo(int capacidad, int arreglo[])
{
   for (int i =0; i<capacidad;i++)
   {
      arreglo[i] = solicitar_entero();
   }
   return arreglo;
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