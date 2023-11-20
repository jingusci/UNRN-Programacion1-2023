/*
Trabajo Practico 2 - Ejercicio 1
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

/*
Consigna: Contador de dígitos
Escribe una función que cuente y muestre en pantalla la cantidad de dígitos en un número entero positivo.
*/

unsigned int valor_absoluto(int numero);
int signo(int numero);


/*
Esta funcion cuenta los digitos de un numero entero
@param el numero a procesar
@returns cuantos digitos tiene el valor pasado, sin importar su signo.
Precondiciones: un numero entero
Postcondiciones: un numero que será menor al original pero mayor o igual a 0.
(La funcion considera 0 no como un digito)
*/
int cuenta_digitos(int numero)
{
    int contador = 0;
    numero = valor_absoluto(numero);
    while (numero > 0)
    {
        numero = numero / 10;
        contador++;
    }
    return contador;
}

/*
Esta funcion indica el signo del numero
@param numero a ser evaluado
@returns -1 si el signo de numero es negativo
          0 si el signo de numero es cero y 
          1 si el signo de numero es positivo.
precondiciones de la funcion, un numero entero
Postcondiciones de la funcion, un numero entero entre -1 y 1.
*/
int signo(int numero)
{
    int retorno;
    if (numero < 0)
    {
        retorno = -1;
    }
    else if (numero > 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/*
Esta funcion devuelve el valor absoluto del numero ingresado
@param numero para obtener la distancia del cero.
@returns un valor sin signo que representa la distanca con respecto al cero.
Precondiciones: un numero entero
Postcondiciones: el mismo numero ingresado pero sin signo
*/
unsigned int valor_absoluto(int numero)
{
    return signo(numero) * numero;
}

#define CASOS 6

int main()
{
    // Casos significativos
    int casos[CASOS][2] = {
        {0, 0 },
        {1, 1},
        {10, 2},
        {100, 3},
        {-1234, 4},
        {54321, 5}
    };

    for (int i = 0; i < CASOS; i++)
    {
        int numero = casos[i][0];
        int esperado = casos[i][1];

        int resultado = cuenta_digitos(numero);

        printf("El numero %d dio que tiene %d ", numero, resultado);
        
        printf("y se esperaba %d, que fue ", esperado);
        if (resultado == esperado)
        {
            printf("correcto");
        }
        else
        {
            printf("incorrecto");
        }
        printf(" con %d\n", resultado);

    }

    return 0;
}
