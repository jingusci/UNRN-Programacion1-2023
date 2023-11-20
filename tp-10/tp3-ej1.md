
# TP 3

## Cargador de arreglos [ejercicio 1.1]

Desarrollar una función que dado un arreglo de números enteros, y la cantidad de elementos, solicite valores por teclado para llenar las posiciones.

```C
/**
 * La función carga un arreglo de enteros con valores ingresados por el usuario.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se llenará con valores ingresados por el usuario.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;

   printf("Se solicitaran %d valores para cargar el arreglo\n", capacidad);
   for (int i = 0; i < capacidad; i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ", i);
      scanf("%d", &arreglo[i]);
   }
   return flag_error;
}
```

### `cargar_arreglo`
La función carga un arreglo de enteros con valores ingresados por el usuario.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "capacidad" veces.
Su complejidad temporal es O(n).

El costo computacional es: 1 + "capacidad" + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros, declara una variable del tipo int y utiliza un retorno también del mismo tipo.

La complejidad espacial es `3 + "capacidad" int`'s.

---

## Impresora de arreglos [ejercicio 1.2]

Desarrollar una función que permita mostrar el contenido de un arreglo.

```C
/**
 * La función muestra un arreglo de enteros en la consola.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se mostrará en la consola.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int muestra_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;

   printf("[ ");
   for (int i = 0; i < capacidad; i++)
   {
      printf("%d ", arreglo[i]);
   }
   printf("]");
   return flag_error;
}
```

### `muestra_arreglo`
La función muestra un arreglo de enteros en la consola.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "capacidad" veces.
Su complejidad temporal es O(n).

El costo computacional es: 2 + "capacidad" * 2 + 2

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros, declara una variable del tipo `int` y utiliza un retorno también del mismo tipo.

La complejidad espacial es `2+capacidad int`'s.

---

## Fusionadora de arreglos [ejercicio 1.3]

Desarrollar una función que permita unir dos arreglos en un tercero que tenga la capacidad suficiente.

```C
/**
 * La función une dos arreglos de enteros en un tercer arreglo.
 *
 * @param capacidad_1 es un número mayor a uno que representa la capacidad del primer arreglo de enteros.
 * @param arreglo_1 es la dirección del primer arreglo de enteros que se unirá.
 * @param capacidad_2 es un número mayor a uno que representa la capacidad del segundo arreglo de enteros.
 * @param arreglo_2 es la dirección del segundo arreglo de enteros que se unirá.
 * @param arreglo_unido es la dirección del tercer arreglo donde se almacenarán los elementos unidos de los dos arreglos originales.
 *
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int unir_arreglos(int capacidad_1, int arreglo_1[], int capacidad_2, int arreglo_2[], int arreglo_unido[])
{
   int flag_error = 0;

   int i = 0;
   for (int j = 0; j < capacidad_1; j++)
   {
      arreglo_unido[i] = arreglo_1[j];
      i++;
   }
   for (int j = 0; j < capacidad_2; j++)
   {
      arreglo_unido[i] = arreglo_2[j];
      i++;
   }
   return flag_error;
}
```

### `unir_arreglos`
La función une dos arreglos de enteros en un tercer arreglo.

#### Complejidad temporal:
El algoritmo tiene dos lazos, que se ejecutarán un total de "capacidad_1" + "capacidad_2" veces.
Su complejidad temporal es O(n). (n = suma de capacidad1 y capacidad2)

El costo computacional es: 2 + "capacidad_1" * 2 + "capacidad_2" * 2 + 1

#### Complejidad espacial
La función analizada recibe dos números de tipo `int`, y el inicio de 3 arreglos de numeros enteros.
Declara además dos variables del tipo `int` y utiliza un retorno del mismo tipo.

La complejidad espacial es `5 int`'s + "capacidad_1" `int`'s + "capacidad_2" `int`'s + "capacidad_1+capacidad_"" `int`'s. 

---

## Operaciones con arreglos [ejercicio 1.4]

Implementar funciones que permitan hacer las siguientes operaciones sobre arreglos de números enteros.
- Promedio
- Obtenga el valor mínimo
- Obtenga la posición del valor máximo
- Ordenar de menor a mayor

```C
/**
 * La función calcula el promedio de los elementos en un arreglo de enteros.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros del cual se calculará el promedio.
 *
 * @return El promedio de los elementos en el arreglo.
 */
float calc_promedio(int capacidad, int arreglo[])
{
   float suma = 0;
   float promedio;
   for (int i = 0; i < capacidad; i++)
   {
      suma += arreglo[i];
   }
   promedio = suma / capacidad;
   return promedio;
}

/**
 * Encuentra la posición del valor mínimo en un arreglo de enteros.
 *
 * @param capacidad Número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo Dirección del arreglo de enteros en el cual se buscará el valor mínimo.
 *
 * @return La posición (índice) del valor mínimo en el arreglo.
 */
int minimo_de_arreglo(int capacidad, int arreglo[])
{
   int minimo;

   for (int i = 0; i < capacidad; i++)
   {
      if (i == 0)
      {
         minimo = arreglo[i];
      }
      else if (arreglo[i] < minimo)
      {
         minimo = arreglo[i];
      }
   }
   return minimo;
}

/**
 * La función encuentra la posición del valor máximo en un arreglo de enteros.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros en el cual se buscará el valor máximo.
 *
 * @return La posición (índice) del valor máximo en el arreglo.
 */
int posicion_del_max(int capacidad, int arreglo[])
{
   int max, pos_max;

   for (int i = 0; i < capacidad; i++)
   {
      if (i == 0)
      {
         max = arreglo[i];
         pos_max = i;
      }
      else if (arreglo[i] > max)
      {
         max = arreglo[i];
         pos_max = i;
      }
   }
   return pos_max;
}

/**
 * La función ordena un arreglo de enteros en orden ascendente.
 *
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se ordenará.
 */
void ordenar_arreglo(int capacidad, int arreglo[])
{
   int temp;
   for (int i = 0; i < capacidad; i++)
   {
      for (int j = (i + 1); j < capacidad; j++)
      {
         if (arreglo[j] < arreglo[i])
         {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
         }
      }
   }
}
```

### `calc_promedio`
La función calcula el promedio de los elementos en un arreglo de enteros.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "capacidad" veces.
Su complejidad temporal es O(n).

El costo computacional es: 2 + "capacidad" *2 + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros, declara dos variables del tipo int y utiliza un retorno también del mismo tipo.

La complejidad espacial es `4 + "capacidad" int`'s.

### `minimo_de_arreglo`
Encuentra la posición del valor mínimo en un arreglo de enteros.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "capacidad" veces.
Su complejidad temporal es O(n).

El costo computacional es: 1 + "capacidad" *2 + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros, declara una variable del tipo int y utiliza un retorno también del mismo tipo.

La complejidad espacial es `3 + "capacidad" int`'s.

### `posicion_del_max`
La función encuentra la posición del valor máximo en un arreglo de enteros.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "capacidad" veces.
Su complejidad temporal es O(n).

El costo computacional es: 2 + "capacidad"*3 + 1

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros, declara dos variables del tipo int y utiliza un retorno también del mismo tipo.

La complejidad espacial es `4 + "capacidad" int`'s.

### `ordenar_arreglo`
La función ordena un arreglo de enteros en orden ascendente.

#### Complejidad temporal:
El algoritmo tiene un lazo dentro de otro lazo, que se ejecutarán un total de ("capacidad" * "capacidad") veces.
Su complejidad temporal es O(n^2).

El costo computacional es: 2 + ("capacidad" ^2) * 4

#### Complejidad espacial
La función analizada recibe un número de tipo `int` y el puntero al comienzo del arreglo de enteros y declara una variable del tipo int.

La complejidad espacial es `2 + "capacidad" int`'s.

---