
# TP 2

## Suma de Números Primos [ejercicio 6]

Crea una función que calcule la suma de los primeros N números primos positivos.

```C
/*
   Esta funcion calcula la suma de los primeros N números primos positivos.
   @param1 numero (int)
   @return suma (int)
*/
int suma_de_primos(int numero)
{     
   int suma = 0;
   int posible_primo = 2;
   int flag_primo = 0;

   for (int i=1; i<=numero;i++)
   {
      do
      {
         flag_primo = es_primo(posible_primo); // O(n) // "posible_primo" *3 + 3
         if (flag_primo == 1)
         {
            suma += posible_primo;
         }
         posible_primo++;

      } while (flag_primo != 1);

   }

   return suma;
}
```

### `suma_de_primos`
Esta funcion calcula la suma de los primeros N números primos positivos.


#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces. Dentro del mismo, se ejecutará la funcion es primom con una complejidad de O(n). Por lo tanto, la complejidad temporal de "suma_de_primos" es O(n^2).

El costo computacional es: 1 + 1 + "numero" * (1 + 1 + 1) + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara tres variables del mismo tipo y utiliza un retorno también del mismo tipo.

La complejidad espacial es `5 int`'s.