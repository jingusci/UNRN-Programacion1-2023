/**
 * La función cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 * 
 * @param cadena es la dirección de la cadena con la que se contarán los caracteres.
 * @pre cadena es una cadena válida.
 * @param capacidad es un número distinto al largo de la cadena en sí y es el tamaño en memoria del arreglo.
 * @pre capacidad es un valor numérico entero positivo mayor a uno.
 * 
 * @return Un número entero, donde los valores positivos (incluyendo el cero) representan la cantidad de caracteres.
 *         Los valores negativos indican situaciones de error, como CADENA_SIN_TERMINADOR, cuando la cantidad de caracteres
 *         es al menos igual a la capacidad indicada por el argumento.
 * @post El valor de retorno es el largo del arreglo o el código de error encontrado.
 */
int largo_seguro(char cadena[], int capacidad)
{
   // Implementación de la función
}

/**
 * La función copia una cadena en otra, asegurándose de no exceder la capacidad de la cadena destino.
 * 
 * @param cadena_origen es la dirección de la cadena que se copiará.
 * @param cadena_destino es la dirección de la cadena donde se copiará la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_destino es el tamaño máximo en memoria de la cadena destino.
 * 
 * @return Un número entero que representa el largo de la cadena destino después de la copia
 *         o un código de error, como CADENA_SIN_TERMINADOR o DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena destino o un código de error si la copia no se pudo realizar.
 */
int copiar_cadenas(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino)
{
   // Implementación de la función
}

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
   // Implementación de la función
}

/**
 * La función solicita un número entero al usuario y lo retorna.
 * 
 * @return Un número entero ingresado por el usuario.
 */
int solicitar_entero()
{
   // Implementación de la función
}

/**
 * La función limpia una cadena de caracteres de todos los caracteres que no sean alfanuméricos (AZaz09).
 * 
 * @param cadena_origen es la dirección de la cadena que se limpiará.
 * @param cadena_limpia es la dirección de la cadena donde se almacenará la versión limpia de la cadena origen.
 * @param capacidad_origen es el tamaño máximo en memoria de la cadena origen.
 * @param capacidad_limpia es el tamaño máximo en memoria de la cadena limpia.
 * 
 * @return Un número entero que representa el largo de la cadena limpia después de la operación
 *         o un código de error, como DESTINO_MENOR_ORIGEN.
 * @post El valor de retorno es el largo de la cadena limpia o un código de error si la limpieza no se pudo realizar.
 */
int limpiar_cadena(char cadena_origen[], char cadena_limpia[], int capacidad_origen, int capacidad_limpia)
{
   // Implementación de la función
}

/**
 * La función compara dos cadenas de caracteres.
 * 
 * @param cadena_1 es la dirección de la primera cadena a comparar.
 * @param cadena_2 es la dirección de la segunda cadena a comparar.
 * @param capacidad_1 es el tamaño máximo en memoria de la primera cadena.
 * @param capacidad_2 es el tamaño máximo en memoria de la segunda cadena.
 * 
 * @return Un número entero que indica la relación entre las cadenas:
 *         - 1 si la primera cadena es mayor que la segunda.
 *         - 0 si las cadenas son iguales.
 *         - (-1) si la primera cadena es menor que la segunda.
 */
int comparar_cadena(char cadena_1[], char cadena_2[], int capacidad_1, int capacidad_2)
{
   // Implementación de la función
}

/**
 * La función convierte una cadena de caracteres a minúsculas.
 * 
 * @param cadena es la dirección de la cadena que se convertirá a minúsculas.
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de la cadena en memoria.
 */
void convertir_a_minusculas(char cadena[], int capacidad)
{
   // Implementación de la función
}

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
   // Implementación de la función
}

/**
 * Muestra un arreglo de caracteres.
 * 
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de caracteres en memoria.
 * @param arreglo es la dirección del arreglo de caracteres que se mostrará.
 * 
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int muestra_arreglo(int capacidad, char arreglo[])
{
   // Implementación de la función
}

/**
 * Carga un arreglo de enteros con valores ingresados por el usuario.
 * 
 * @param capacidad es un número mayor a uno que representa la capacidad del arreglo de enteros en memoria.
 * @param arreglo es la dirección del arreglo de enteros que se llenará con valores ingresados por el usuario.
 * 
 * @return Un valor entero que no tiene un significado específico en este contexto.
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
   // Implementación de la función
}
