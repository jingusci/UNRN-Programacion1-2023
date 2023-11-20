
# TP 1

## Factorial [ejercicio 10]

Implementar una función que, usando lazos, permita obtener el factorial de un número entero positivo.

```C
/*
   Esta funcion recibe un número entero y calcula su factorial
   @param1 numero (int)
   @return resultado (int)
*/
int factorial(int numero)
{
   int resultado = 1;
   while (numero >=1)
   {
      resultado = resultado * numero;
      numero = numero -1;
   }

   return resultado;
}
```

### `factorial`
Esta funcion recibe un número entero y calcula su factorial.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(n).

El costo computacional es: 1 + 1 + "numero" * (1 + 1) + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara una variable del mismo tipo y utiliza un retorno también del mismo tipo.

La complejidad espacial es `3 int`'s.