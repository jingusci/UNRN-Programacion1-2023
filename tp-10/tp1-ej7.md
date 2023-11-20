
# TP 1

## Es primo [ejercicio 7]

Escribir una función que retorne `1` si un número entero indicado es Primo y `0` cuando no lo sea.

```C
/*
   Esta funcion recibe un número entero e identifica si es primo o no.
   @param1 numero (int)
   @return resultado (int)
*/
int es_primo(int numero)
{
   int resultado = 1;
   int resto;
   for (int i=2; i<numero; i++)
   {
      resto = numero % i;

      if (resto == 0)
      {
         resultado = 0;
      }

   }
   return resultado;
}
```

### `es_primo`
Esta funcion recibe un número entero e identifica si es primo o no.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces.
Su complejidad temporal es O(n).

El costo computacional es: 1 + 1 + "numero" * (1 + 1 + 1) + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara dos variables del mismo tipo y utiliza un retorno también del mismo tipo.

La complejidad espacial es `4 int`'s.