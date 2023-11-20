/*
Ejercicio 3 - Fracciones
Javier Ingusci (jingusci)
Comision 3 - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

typedef struct
{
   int numerador;
   int denominador;
} fraccion_t;

void mostrar_fraccion(fraccion_t frac);
fraccion_t suma_fracciones(fraccion_t frac1, fraccion_t frac2);
fraccion_t mult_fracciones(fraccion_t frac1, fraccion_t frac2);
fraccion_t suma_con_entero(fraccion_t frac1, int numero);

int main()
{

   fraccion_t frac1 = {2, 4};
   fraccion_t frac2 = {4, 8};

   printf("1- Mostrar\t\t");
   mostrar_fraccion(frac1);

   printf("2- Sumar\t\t");
   fraccion_t resultado_suma = suma_fracciones(frac1, frac2);
   mostrar_fraccion(resultado_suma);

   printf("3- Multiplicar\t\t");
   fraccion_t resultado_mult = mult_fracciones(frac1, frac2);
   mostrar_fraccion(resultado_mult);

   printf("4- Sumar entero\t\t");
   fraccion_t resultado_suma_entero = suma_con_entero(frac1, 4);
   mostrar_fraccion(resultado_suma_entero);

   return 0;
}

/**
 * Esta función muestra una fracción en el formato "numerador / denominador".
 *
 * @param frac - La fracción que se mostrará.
 *
 * @pre La fracción debe ser válida, es decir, el denominador no puede ser cero.
 * @post No modifica la fracción de entrada.
 */
void mostrar_fraccion(fraccion_t frac)
{
   if (frac.denominador == 0)
   {
      printf("[ERROR] - El denominador no puede ser CERO\n");
   }
   else
   {
      printf("Fraccion: %d / %d \n", frac.numerador, frac.denominador);
   }
}

/**
 * Esta función suma dos fracciones.
 *
 * @param frac1 - La primera fracción a sumar.
 * @param frac2 - La segunda fracción a sumar.
 *
 * @pre Ambas fracciones deben ser válidas (denominadores distintos de cero).
 * @post No modifica las fracciones de entrada.
 *
 * @return La suma de las dos fracciones.
 */
fraccion_t suma_fracciones(fraccion_t frac1, fraccion_t frac2)
{

   if (frac1.denominador == 0 || frac2.denominador == 0)
   {
      printf("[ERROR] - El denominador no puede ser CERO\n");
   }
   else
   {
      fraccion_t suma;
      suma.numerador = (frac1.numerador * frac2.denominador) + (frac1.denominador * frac2.numerador);
      suma.denominador = frac1.denominador * frac2.denominador;
      return suma;
   }

}

/**
 * Esta función multiplica dos fracciones.
 *
 * @param frac1 - La primera fracción a multiplicar.
 * @param frac2 - La segunda fracción a multiplicar.
 *
 * @pre Ambas fracciones deben ser válidas (denominadores distintos de cero).
 * @post No modifica las fracciones de entrada.
 *
 * @return El resultado de la multiplicación de las dos fracciones.
 */
fraccion_t mult_fracciones(fraccion_t frac1, fraccion_t frac2)
{
   if (frac1.denominador == 0 || frac2.denominador == 0)
   {
      printf("[ERROR] - El denominador no puede ser CERO\n");
   }
   else
   {
      fraccion_t multiplicacion;
      multiplicacion.numerador = frac1.numerador * frac2.numerador;
      multiplicacion.denominador = frac1.denominador * frac2.denominador;
      return multiplicacion;
   }
}

/**
 * Esta función suma una fracción y un número entero.
 *
 * @param frac1 - La fracción a la que se le sumará el número entero.
 * @param numero - El número entero que se sumará a la fracción.
 *
 * @pre La fracción debe ser válida (denominador distinto de cero).
 * @post No modifica la fracción de entrada ni el número entero.
 *
 * @return La fracción resultante de la suma.
 */
fraccion_t suma_con_entero(fraccion_t frac1, int numero)
{
   fraccion_t f1_temp = {numero, 1};
   fraccion_t suma = suma_fracciones(frac1, f1_temp);

   return suma;
}
