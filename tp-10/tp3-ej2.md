
# TP 3

## Inserción de cadenas [ejercicio 2.3]

Implementar una función que inserte una cadena en otra luego de la posición indicada de manera segura.

Que hacer cuando la cadena destino no tiene la capacidad necesaria para alojar la cadena a insertar es su decisión, la cual debe quedar registrada en el comentario de la función.

#### Ejemplo

Insertar "HOLA" en "Mundo" en la posición 2 daría como resultado "MunHOLAdo"

La función debe retornar el largo de la cadena destino o el código de error correspondiente.


```C
/**
 * La función inserta una cadena en otra en una posición específica, asegurándose de no exceder la capacidad de la cadena destino.
 * 
 * @param cadena_origen es la dirección de la cadena que se insertará.
 * @param cadena_destino es la dirección de la cadena donde se insertará la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_destino es el tamaño máximo en memoria de la cadena destino.
 * @param posicion es la posición en la cadena destino donde se insertará la cadena origen.
 * 
 * @return Un número entero que representa el largo de la cadena destino después de la inserción
 *         o un código de error, como CADENA_SIN_TERMINADOR o DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena destino o un código de error si la inserción no se pudo realizar.
 */
int insertar_cadena(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino, int posicion)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);  // costo capacidad
   int largo_destino = largo_seguro(cadena_destino, capacidad_destino); // costo capacidad

   if (capacidad_destino <= (largo_origen + largo_destino))
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else if (largo_origen == CADENA_SIN_TERMINADOR || largo_destino == CADENA_SIN_TERMINADOR)
   {
      resultado = CADENA_SIN_TERMINADOR;
   }
   else
   {
      for (int i = posicion + 1; i < posicion + 1 + largo_origen; i++)
      {
         cadena_destino[i + largo_origen] = cadena_destino[i];
         cadena_destino[i] = cadena_origen[i - posicion - 1];
      }
      resultado = largo_seguro(cadena_destino, capacidad_destino);
   }
   return resultado;
}
```

### `insertar_cadena`
La función inserta una cadena en otra en una posición específica, asegurándose de no exceder la capacidad de la cadena destino.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "largo_origen" veces.
Su complejidad temporal es O(n).

El costo computacional es: 1 + "capacidad_origen" + "capacidad_destino" + 2 + "largo_origen" * 2 + 2

#### Complejidad espacial
La función analizada recibe dos números de tipo `int`, declara tres variables del mismo tipo y utiliza un retorno también del mismo tipo.
Ademas, recibe dos punteros al comienzo de dos cadenas de caracteres.

La complejidad espacial es `5 int`'s y "capacidad_origen"+"capacidad_destino" `chars`'s.

---

## Palíndromo seguro [ejercicio 2.7]

Implementar una función que indique con TRUE si la cadena es un palíndromo, con FALSE si no lo es o indicar un error si no posee \0.

Una palabra es palíndromo cuando se puede leer de la misma manera en ambas direcciones.

Ignoren mayúsculas y minúsculas.

Neuquen -> es palíndromo


```C
/**
 * La función verifica si una cadena de caracteres es un palíndromo.
 * 
 * @param cadena es la dirección de la cadena que se verificará como palíndromo.
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de la cadena en memoria.
 * 
 * @return Un número entero que indica si la cadena es un palíndromo o no:
 *         - 1 si la cadena es un palíndromo.
 *         - 0 si la cadena no es un palíndromo.
 */
int es_palindromo(char cadena[], int capacidad)
{
   int resultado = 0;
   int largo_cadena = largo_seguro(cadena, capacidad);

   // convierto todo a misnusculas para laburarlo:
   convertir_a_minusculas(cadena, capacidad);

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] != cadena[largo_cadena - 1 - i])
      {
         resultado = 0;
         break;
      }
      resultado = 1;
   }

   return resultado;
}
```

### `es_palindromo`
La función verifica si una cadena de caracteres es un palíndromo.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "largo_cadena" veces.
Su complejidad temporal es O(n).

El costo computacional es: 4 + "largo_cadena" * 2 + 2

#### Complejidad espacial
La función analizada recibe un número de tipo `int`, declara dos variables del mismo tipo. Ademas, recibe el puntero al comienzo de una cadena de caracteres.

La complejidad espacial es `3 int`'s y "capacidad" `chars`'s.