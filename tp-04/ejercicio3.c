/*
Ejercicio 3 - Duplica
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

// Declaracion de funciones
int solicitar_entero();
void duplicar(int *ptr);

int main()
{
   int variable = solicitar_entero();

   printf("Valor original: \t %d\n", variable);
   duplicar(&variable); // Ejecuto función pasando directamente la direccion de memoria
   printf("Valor duplicado: \t %d\n", variable);

   return 0;
}

/**
 * La función solicita al usuario ingresar un número entero.
 *
 * @return El número entero ingresado por el usuario.
 */
int solicitar_entero()
{
   int numero;
   printf("Ingrese un numero entero: ");
   scanf("%d", &numero);
   return numero;
}

/**
 * Duplica el valor de un entero al que apunta un puntero.
 *
 * @param ptr - Un puntero que apunta a un valor entero que se duplicará.
 *
 * @pre 'ptr' debe ser un puntero válido que apunte a una ubicación de memoria que almacena un entero.
 *
 * @post El valor al que apunta 'ptr' se duplica, es decir, se multiplica por 2.
 */
void duplicar(int *ptr)
{
   *ptr = *ptr * 2;
}