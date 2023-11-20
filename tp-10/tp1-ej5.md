
# TP 1

## Suma Lenta [ejercicio 5]

Implementar una función que haga la suma entre dos números enteros sin hacer la operación de manera directa. Esto quiere decir que para hacer la suma entre 4 y 3, las operaciones 
resultantes deberán ser 4+1+1+1.

La función debe ser capaz de sumar cualquier número entero, positivo y negativo.

```C
/**
   Esta funcion recibe dos números enteros y realiza una
   "suma lenta" de los mismos.
   @param numero es el primer valor que recibe (int)
   @param otro_numero es el segundo valor que recibe (int)
   @return resultado (int)
*/
int suma_lenta(int numero, int otro_numero)
{
   int resultado = numero;
   if (otro_numero >= 0)
   {
      for (int i = 1; i <= otro_numero; i++) 
      {
         resultado = resultado + 1;
      } 
   } 
   else
   {
      for (int i = otro_numero; i < 0; i++) 
      {
         resultado = resultado - 1;
      } 
   }
   return resultado;
}
```

### `suma_lenta`
Esta funcion recibe dos números enteros y realiza una "suma lenta" de los mismos.

#### Complejidad temporal:
El algoritmo tiene dos lazos, pero solo uno se ejecutará.
Se realizará un total de veces igual al valor absoluto de "otro_numero".
Su complejidad temporal es O(n).

El costo computacional es: 1 + 1 + 1 + "otro_numero"

#### Complejidad espacial
La función analizada recibe dos números de tipo `int`, declara una variable del mismo tipo y utiliza un retorno también del mismo tipo.

La complejidad espacial es `4 int`'s.