
# TP 8

## Insertar en posición [ejercicio 1]

Escribe una función que inserte un nuevo nodo con un valor dado en una posición específica de una lista enlazada.

```C
/**
 * Esta función inserta un nuevo nodo con un valor dado en una posición específica de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada a la que se desea agregar el nuevo nodo.
 * @param dato - Valor que se desea asignar al nuevo nodo.
 * @param posicion - Posición en la que se desea insertar el nuevo nodo. La posición 0 corresponde al principio de la lista.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función crea un nuevo nodo con el valor especificado.
 *         Si la posición es 0, inserta el nuevo nodo al principio de la lista.
 *         Si la posición es mayor que 0, recorre la lista hasta encontrar la posición deseada (o el final de la lista) y agrega el nuevo nodo en esa posición.
 *         La función asegura que la lista enlazada siga siendo válida y bien formada después de la inserción.
 *
 */
void insertar_en_posicion(nodo_t **lista, int dato, int posicion)
{

    if (posicion == 0)
    {
        insertar_al_principio(lista, dato);
    }
    else
    {
        nodo_t *nuevo_nodo = crear_nodo(dato);

        if ((*lista) == NULL)
        {
            *lista = nuevo_nodo;
        }
        else
        {
            nodo_t *actual = *lista;
            int c = 0;

            while ((c != posicion - 1) && (actual->siguiente != NULL)) // si llego al final de la lista lo inserto al final
            {
                actual = actual->siguiente;
                c++;
            }

            nuevo_nodo->siguiente = actual->siguiente;
            actual->siguiente = nuevo_nodo;
        }
    }
}
```

### `insertar_en_posicion`
Esta función inserta un nuevo nodo con un valor dado en una posición específica de una lista enlazada.

#### Complejidad temporal:
El algoritmo tiene un lazo, que se ejecutará un total de "posicion" veces.
Su complejidad temporal es O(n).

El costo computacional es: 5 + "posicion" *2 + 2

#### Complejidad espacial
La función analizada recibe dos variables de tipo `int`, y una de tipo `puntero`.
Ademas, declara dos punteros mas y un entero.

La complejidad espacial es `3 int`'s y `3 punteros`.


## Eliminar del principio [ejercicio 1]

Escribe una función que elimine el nodo que se encuentra al principio de una lista enlazada.

```C
/**
 * Esta función elimina el nodo que se encuentra al principio de una lista enlazada.
 *
 * @param lista - Puntero al puntero de la lista enlazada de la que se desea eliminar el primer nodo.
 *
 * @pre - El parámetro 'lista' debe ser un puntero a un puntero que apunta a la cabeza de una lista enlazada previamente asignada.
 *
 * @post - La función verifica si la lista no está vacía (no es NULL).
 *         Si la lista no está vacía, elimina el primer nodo de la lista, actualizando el puntero de la cabeza (*lista).
 *         La función libera la memoria del nodo eliminado.
 *         Después de la eliminación, la lista sigue siendo válida y bien formada, incluso si ahora está vacía.
 *
 */
void eliminar_del_principio(nodo_t **lista)
{
    if ((*lista) != NULL)
    {
        nodo_t *actual = *lista;
        *lista = actual->siguiente;
        liberar_nodo(actual);
    }
}
```

### `eliminar_del_principio`
Esta función elimina el nodo que se encuentra al principio de una lista enlazada.

#### Complejidad temporal:
El algoritmo no tiene lazos.
Su complejidad temporal es O(1).

El costo computacional es: 4.

#### Complejidad espacial
La función analizada recibe variable de tipo puntero y declara otra variable del mismo tipo.

La complejidad espacial es `2 punteros`.