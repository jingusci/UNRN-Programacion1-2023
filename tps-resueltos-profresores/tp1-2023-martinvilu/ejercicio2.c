/*
Trabajo Practico 1 - Ejercicio 2
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/**
  Esta funcion convierte temperaturas celcius expresadas como
  un numero decimal a su equivalente en fahrenheit
  @param centigrados la temperatura a convertir
  @returns la temperatura ingresada convertida
  @pre el valor de la temperatura no puede ser menor a -371
  @post la temperatura obtenida será obtenida a partir del argumento
 */
float centigrados_a_fahrenheit(float centigrados) {
    return (centigrados * 1.8f) + 32.0f;
}

float fahrenheit_a_centigrados(float fahrenheit) {
    float retorno = (fahrenheit - 32.0f) / 1.8f; 
    return retorno;
}


int main()
{
   //COMPLETAR
}

