/*
Ejercicio 1
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

int main()
{

   double var_double = 9.12;
   int var_int = 912;
   char var_char = 'A';

   double *ptr_double = &var_double;
   int *ptr_int = &var_int;
   char *ptr_char = &var_char;
   printf("\n");

   printf("La direccion del char \t\t< var_char >\t es \t0x%p\n", &var_char);
   printf("La direccion del int \t\t< var_int >\t es \t0x%p\n", &var_int);
   printf("La direccion del double \t< var_double >\t es \t0x%p\n", &var_double);
   printf("La direccion del char* \t\t< ptr_char >\t es \t0x%p\n", &ptr_char);
   printf("La direccion del int* \t\t< ptr_int >\t es \t0x%p\n", &ptr_int);
   printf("La direccion del double* \t< ptr_double >\t es \t0x%p\n", &ptr_double);
   printf("\n");

   printf("El valor del char \t\t< var_char >\t es \t%c\n", var_char);
   printf("El valor del int \t\t< var_int >\t es \t%d\n", var_int);
   printf("El valor del double \t\t< var_double >\t es \t%.2f\n", var_double);
   printf("El valor del char* \t\t< ptr_char >\t es \t0x%p\n", ptr_char);
   printf("El valor del int* \t\t< ptr_int >\t es \t0x%p\n", ptr_int);
   printf("El valor del double* \t\t< ptr_double >\t es \t0x%p\n", ptr_double);
   printf("\n");

   printf("El tamanio del char \t\t< var_char >\t es \t%d bytes\n", sizeof(var_char));
   printf("El tamanio del int \t\t< var_int >\t es \t%d bytes\n", sizeof(var_int));
   printf("El tamanio del double \t\t< var_double >\t es \t%d bytes\n", sizeof(var_double));
   printf("El tamanio del char* \t\t< ptr_char >\t es \t%d bytes\n", sizeof(ptr_char));
   printf("El tamanio del int* \t\t< ptr_int >\t es \t%d bytes\n", sizeof(ptr_int));
   printf("El tamanio del double* \t\t< ptr_double >\t es \t%d bytes\n", sizeof(ptr_double));
   printf("\n");

   printf("\n");
   return 0;
}
