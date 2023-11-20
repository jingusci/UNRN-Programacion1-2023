
# TP 2

## Cálculo de Suma de Dígitos en Serie de Fibonacci [ejercicio 9]

Escribe una función que calcule la suma de los dígitos de los términos en una serie de Fibonacci hasta el N-ésimo término.

```C
/*
   Esta funcion calcula la suma de los dígitos de los términos en una serie de 
   Fibonacci hasta el N-ésimo término
   @param1 numero (int)
   @return resultado (int)
*/
int suma_fibonacci(int numero)
{
   int suma = 0;
   int termino_fibonacci;
   int fibonacci_temp1=0;
   int fibonacci_temp2=1;
   int suma_digitos = 0;

   for (int i=0;i<numero;i++) // O(n)
   {
      // calculo termino fibonacci
      if (i == 0)
      {
         termino_fibonacci = 0;
      }
      else if (i==1)
      {
         termino_fibonacci = 1;
      }
      else
      {
         termino_fibonacci = fibonacci_temp1 + fibonacci_temp2;
         fibonacci_temp1 = fibonacci_temp2;
         fibonacci_temp2 = termino_fibonacci;
      }

      // calculo la suma de los digitos del termino
      suma_digitos = sumador_de_digitos(termino_fibonacci);
      // sumo en el total
      suma += suma_digitos;

   }

   return suma;
}
```

### `suma_fibonacci`
Esta funcion calcula la suma de los dígitos de los términos en una serie de Fibonacci hasta el N-ésimo término


#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "numero" veces. Dentro del lazo se ejecutará la funcion sumador_de_digitos.
La complejidad temporal es O(numero*log(termino_fibonacci)).

El costo computacional es: 5 + "numero" * 8

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara cinco variables del mismo tipo y utiliza un retorno también del mismo tipo.

La complejidad espacial es `7 int`'s.