
# TP 9

## Fibonacci [ejercicio 2]

Escribe una función que calcule el término "n" de la secuencia de Fibonacci utilizando recursividad.


```C
/**
 * Calcula el término "n" de la secuencia de Fibonacci utilizando recursividad.
 *
 * @param n El número de término de la secuencia de Fibonacci que se desea calcular.
 * @return El valor del término "n" de la secuencia de Fibonacci.
 */
unsigned int fibonacci(unsigned int n) // f(n) = f(n-1) + f(n-2)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
```

### `fibonacci`
Calcula el término "n" de la secuencia de Fibonacci utilizando recursividad.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(2^n).

El costo computacional es: 2 + 2^n

#### Complejidad espacial
La función analizada recibe un número de tipo `unsigned int`.
Debido a la recursividad, esta variable se generará un total de "n" veces.

La complejidad espacial es `"n" unsigned int`'s.


## Factorial [ejercicio 2]

Escribe una función que calcule el factorial de un número utilizando recursividad.

```C
/**
 * Calcula el factorial de un número utilizando recursividad.
 *
 * @param n El número del cual se desea calcular el factorial.
 * @return El factorial de n.
 */
unsigned int factorial(unsigned int n) // n! = n (n-1)!
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
```

### `factorial`
Calcula el factorial de un número utilizando recursividad.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(n).

El costo computacional es: 2 + "n"*2

#### Complejidad espacial
La función analizada recibe un número de tipo `unsigned int`.
Debido a la recursividad, esta variable se generará un total de "n" veces.

La complejidad espacial es `"n" unsigned int`'s.