/*
Trabajo Practico 2 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Freedom units

Para completar la conversión de grados Fahrenheit del TP1, ahora agregaremos 
la implementación de las otras ‘freedom units’

Implementen las conversiones en ambos sentidos de:

Conversión de Litros a Galones: Implementa una función que convierta 
un volumen en litros a su equivalente en galones.

Conversión de Millas a Kilómetros: Diseña una función que convierta 
una distancia en millas a su equivalente en kilómetros.
*/

/**
 * Convierte un volumen en litros a su equivalente en galones.
 *
 * @param litros La cantidad de litros a convertir.
 * @return La cantidad equivalente en galones.
 *
 * @pre litros debe ser un numero.
 * @post El valor devuelto es la cantidad equivalente en galones.
 */
double litros_a_galones(double litros) {
    return litros * 0.264172;
}

/**
 * Convierte un volumen en galones a su equivalente en litros.
 *
 * @param galones La cantidad de galones a convertir.
 * @return La cantidad equivalente en litros.
 *
 * @pre galones debe ser un numero.
 * @post El valor devuelto es la cantidad equivalente en litros.
 */
double galones_a_litros(double galones) {
    return galones * 3.78541;
}

/**
 * Convierte una distancia en millas a su equivalente en kilómetros.
 *
 * @param millas La distancia en millas a convertir.
 * @return La distancia equivalente en kilómetros.
 *
 * @pre millas debe ser un numero.
 * @post El valor devuelto es la distancia equivalente en kilómetros.
 */
double millas_a_kilometros(double millas) {
    return millas * 1.60934;
}

/**
 * Convierte una distancia en kilómetros a su equivalente en millas.
 *
 * @param kilometros La distancia en kilómetros a convertir.
 * @return La distancia equivalente en millas.
 *
 * @pre kilometros debe ser un numero.
 * @post El valor devuelto es la distancia equivalente en millas.
 */
double kilometros_a_millas(double kilometros) {
    return kilometros * 0.621371;
}

int main() {
    int opcion;
    double valor;
    double resultado;

    printf("FREEDOM UNITS:\n");    
    printf("Seleccione una opción:\n");
    printf("1. Litros a Galones\n");
    printf("2. Galones a Litros\n");
    printf("3. Millas a Kilómetros\n");
    printf("4. Kilómetros a Millas\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese la cantidad de litros: ");
            scanf("%lf", &valor);
            resultado = litros_a_galones(valor);
            printf("%.2lf litros equivalen a %.2lf galones.\n", valor, resultado);
            break;
        case 2:
            printf("Ingrese la cantidad de galones: ");
            scanf("%lf", &valor);
            resultado = galones_a_litros(valor);
            printf("%.2lf galones equivalen a %.2lf litros.\n", valor, resultado);
            break;
        case 3:
            printf("Ingrese la distancia en millas: ");
            scanf("%lf", &valor);
            resultado = millas_a_kilometros(valor);
            printf("%.2lf millas equivalen a %.2lf kilómetros.\n", valor, resultado);
            break;
        case 4:
            printf("Ingrese la distancia en kilómetros: ");
            scanf("%lf", &valor);
            resultado = kilometros_a_millas(valor);
            printf("%.2lf kilómetros equivalen a %.2lf millas.\n", valor, resultado);
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}

