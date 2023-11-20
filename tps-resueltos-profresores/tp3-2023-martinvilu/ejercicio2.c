/*
Trabajo Practico 3 - Ejercicio
Profe Martín
Comision Profes - 2023
Programacion 1 - Ingenieria en computacion
*/

#include <stdbool.h>
#include <stdio.h>

/*
Consigna: Cadenas seguras
Manipular un cadena de manera segura es poder limitar la cantidad de posiciones
que serán recorridas en el caso de que la cadena de caracteres no cuente con su
carácter de terminación (\0).
*/

// Codigos de salida
#define CADENA_MENOR 1
#define CADENA_IGUAL 2
#define CADENA_MAYOR 3
#define TODO_OK 0
#define CADENA_NULA -1
#define SIN_LUGAR_SUFICIENTE -2
#define CAPACIDAD_INCORRECTA -3
#define POSICION_INVALIDA -4
#define CAPACIDAD_INSUFICIENTE -5
#define CADENA_SIN_TERMINADOR -6

// Prototipos de función
void imprime_mensaje_error(int codigo_error);
int es_valido(char arreglo[], int capacidad);
char a_mayuscula(char letra);
char a_minuscula(char letra);
bool es_vocal(char letra);
bool es_mayuscula(char letra);
bool es_numero(char letra);
bool es_minuscula(char letra);
bool es_alfabetica(char letra);
bool es_alfanumerico(char letra);
int largo_seguro(char cadena[], int capacidad);
int copiar(char origen[], int capacidad_origen, char destino[],
           int capacidad_destino);
int insertar_cadena(char destino[], int capacidad_destino, int posicion,
                    char origen[], int capacidad_origen);
int limpiadora(int capacidad, char cadena[]);
int comparacion(int capacidad, char cadena[], int capacidad_a_comparar,
                char a_comparar[]);
int a_minusculas(int capacidad, char cadena[]);

/**
 * Imprime un mensaje de error basado en un código de error.
 *
 * Esta función toma el código numérico de error como entrada y muestra un
 * mensaje correspondiente en la salida estándar. Los mensajes se utilizan para
 * describir los diferentes tipos de errores posibles en el programa.
 *
 * @param codigo_error El código de error que indica la naturaleza del problema.
 *
 * @pre El código de error debe ser alguno de los definidos
 *
 * @post Se imprime el mensaje de error correspondiente al código de error
 * proporcionado. Si el código de error no es reconocido, se muestra un mensaje
 * genérico que indica un código de error desconocido.
 */
void imprime_mensaje_error(int codigo_error)
{
    if (codigo_error == TODO_OK)
    {
        printf("Todo bien!\n");
    }
    else if (codigo_error == CADENA_NULA)
    {
        printf("La cadena es nula\n");
    }
    else if (codigo_error == SIN_LUGAR_SUFICIENTE)
    {
        printf("No hay lugar suficiente para la operacion\n");
    }
    else if (codigo_error == CAPACIDAD_INCORRECTA)
    {
        printf("La capacidad no es la correcta (0 o negativa)\n");
    }
    else if (codigo_error == POSICION_INVALIDA)
    {
        printf("La posicion indicad no es correcta\n");
    }
    else if (codigo_error == CAPACIDAD_INSUFICIENTE)
    {
        printf("La capacidad en el arreglo no alcanza\n");
    }
    else
    {
        printf("Codigo de error '%d' desconocido!\n", codigo_error);
    }
}

/**
 * Comprueba si un arreglo es válido.
 *
 * Esta función verifica si un arreglo es válido según las siguientes
 * condiciones:
 * - El puntero al arreglo no es nulo.
 * - La capacidad del arreglo es mayor o igual a 1.
 * - Esta función no verifica que el largo de la cadena sea consistente o que la
 * misma contenga el terminador.
 *
 * @param capacidad La capacidad del arreglo.
 * @param arreglo   Un puntero al arreglo.
 *
 * @return Un código de salida que indica si el arreglo es válido o no.
 *         - Si el arreglo es nulo, devuelve CADENA_NULA.
 *         - Si la capacidad es menor que 1, devuelve CAPACIDAD_INCORRECTA.
 *         - Si el arreglo es válido, devuelve TODO_OK.
 *
 * @pre
 * - El puntero al arreglo puede ser nulo o apuntar a un arreglo válido.
 * - La capacidad debe ser un valor mayor o igual a 1.
 *
 * @post
 * - El arreglo no es modificado.
 * - La función devuelve uno de los siguientes códigos:
 *   - CADENA_NULA si el arreglo es nulo.
 *   - CAPACIDAD_INCORRECTA si la capacidad es menor que 1.
 *   - TODO_OK si el arreglo es válido.
 */
int es_valido(char arreglo[], int capacidad)
{
    int codigo_salida;

    if (arreglo == NULL)
    {
        codigo_salida = CADENA_NULA;
    }
    else if (capacidad < 1)
    {
        codigo_salida = CAPACIDAD_INCORRECTA;
    }
    else
    {
        codigo_salida = TODO_OK;
    }
    return codigo_salida;
}

/**
 * Convierte la letra en mayúsculas, solo si es una letra minúscula.
 *
 * @param letra El carácter a convertir.
 * @return La letra en mayúscula si es una letra minúscula, o la misma letra si
 * no lo es.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Si la entrada es una letra minúscula, la salida es la misma letra en
 * mayúscula. Si la entrada no es una letra minúscula, la salida es la misma
 * letra sin cambios.
 */
char a_mayuscula(char letra)
{
    if (es_minuscula(letra))
    {
        letra = letra - 32; // Reemplazar por ('a' - 'A') para la conversión.
    }
    return letra;
}

/**
 * Convierte la letra en minúsculas, solo si es una letra.
 *
 * @param letra El carácter a convertir.
 * @return La letra en minúscula si es una letra mayúscula, o la misma letra si
 * no lo es.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Si la entrada es una letra mayúscula, la salida es la misma letra en
 * minúscula. Si la entrada no es una letra mayúscula, la salida es la misma
 * letra sin cambios.
 */
char a_minuscula(char letra)
{
    if (es_mayuscula(letra))
    {
        letra = letra + 32; // Reemplazar por ('a' - 'A') para la conversión.
    }
    return letra;
}

/**
 * Verifica si un carácter es una vocal.
 *
 * @param letra El carácter a verificar.
 * @return true si es una vocal, false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Ninguna postcondición específica adicional a lo indicado en @returns.
 */
bool es_vocal(char letra)
{
    letra = a_minuscula(letra); // Convertir a minúscula antes de verificar.
    bool resultado = (letra == 'a' || letra == 'e' || letra == 'i' ||
                      letra == 'o' || letra == 'u');
    return resultado;
}

/**
 * Verifica si un carácter es una letra mayúscula.
 *
 * @param letra El carácter a verificar.
 * @return true si es una letra mayúscula, false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Ninguna postcondición específica adicional a lo indicado en @returns.
 */
bool es_mayuscula(char letra)
{
    return (letra >= 'A' && letra <= 'Z');
}

/**
 * Verifica si un carácter es un número.
 *
 * @param letra El carácter a verificar.
 * @return true si es un número(0-9), false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Ninguna postcondición específica adicional a lo indicado en @returns.
 */
bool es_numero(char letra)
{
    return (letra >= '0' && letra <= '9');
}

/**
 * Verifica si un carácter es una letra minúscula.
 *
 * @param letra El carácter a verificar.
 * @return true si es una letra minúscula, false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post Ninguna postcondición específica adicional a lo indicado en @returns.
 */
bool es_minuscula(char letra)
{
    return (letra >= 'a' && letra <= 'z');
}

/**
 * Verifica si un carácter es alfabético (letra mayúscula o minúscula).
 *
 * @param letra El carácter a verificar.
 * @return true si es alfabético, false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post La función devuelve true si la entrada es una letra mayúscula o
 * minúscula, y devuelve false en caso contrario.
 */
bool es_alfabetica(char letra)
{
    return (es_mayuscula(letra) || es_minuscula(letra));
}

/**
 * Verifica si un carácter es alfanumérico (letra o número).
 *
 * @param letra El carácter a verificar.
 * @return true si es alfanumérico, false de lo contrario.
 *
 * @pre Ninguna precondición específica.
 *
 * @post La función devuelve true si la entrada es una letra (mayúscula o
 * minúscula) o un número (0-9), y devuelve false en caso contrario.
 */
bool es_alfanumerico(char letra)
{
    return es_numero(letra) || es_alfabetica(letra);
}

/**
 * 2.1
 * Calcula la longitud de una cadena segura.
 *
 * @param cadena Arreglo de caracteres que representa la cadena.
 * @param capacidad Capacidad máxima del arreglo (incluyendo el carácter nulo).
 * @return La longitud de la cadena (sin incluir el carácter nulo) o un código
 * de error. ver @post
 *
 * @pre
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - El puntero 'cadena' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función devuelve la longitud de la cadena si es válida y no está vacía.
 * - Si el largo es igual a la capacidad, se devuelve CADENA_SIN_TERMINADOR.
 * - Aplican los mismos codigos de error que `es_valido`
 */
int largo_seguro(char cadena[], int capacidad)
{
    int longitud = es_valido(cadena, capacidad);
    if (longitud == TODO_OK)
    {
        longitud = 0;
        while ((cadena[longitud] != '\0') && (longitud <= capacidad))
        {
            longitud++;
        }
        if (longitud == capacidad)
        {
            longitud = CADENA_SIN_TERMINADOR;
        }
    }
    return longitud;
}

/**
 * 2.2
 * Copia una cadena segura en otra cadena segura y asegura que la cadena destino
 * tenga un carácter nulo al final.
 *
 * @param origen Arreglo de caracteres que representa la cadena de origen.
 * @param capacidad_origen Capacidad máxima del arreglo de origen (incluyendo el
 * carácter nulo).
 * @param destino Arreglo de caracteres que representa la cadena de destino.
 * @param capacidad_destino Capacidad máxima del arreglo de destino (incluyendo
 * el carácter nulo).
 * @return La longitud de la cadena copiada o un código de error:
 *         - Si la cadena de origen y destino son válidas y la copia se realizó
 * con éxito, se devuelve la longitud.
 *         - Si la capacidad de destino es insuficiente para la copia, se
 * devuelve CAPACIDAD_DESTINO_INSUFICIENTE.
 *
 * @pre
 * - La variable 'capacidad_origen' debe ser mayor o igual a 1.
 * - La variable 'capacidad_destino' debe ser mayor o igual a 1.
 * - El puntero 'origen' puede ser NULL o apuntar a un arreglo válido.
 * - El puntero 'destino' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función copia la cadena de origen en la cadena de destino si ambas son
 * válidas y la capacidad de destino es suficiente.
 * - La cadena de destino tendrá un carácter nulo al final para asegurar que sea
 * una cadena segura.
 * - La función devuelve la longitud de la cadena copiada si la copia se realiza
 * con éxito.
 * - Si la capacidad de destino es insuficiente para la copia, se devuelve
 * CAPACIDAD_INSUFICIENTE.
 */
int copiar(char origen[], int capacidad_origen, char destino[],
           int capacidad_destino)
{

    int longitud_destino = largo_seguro(destino, capacidad_destino);
    int longitud_origen = largo_seguro(origen, capacidad_origen);
    int estado_copia;
    int i;

    if ((longitud_origen > TODO_OK) && (longitud_destino > TODO_OK))
    {
        if (longitud_origen < longitud_destino)
        {
            for (i = 0; i < capacidad_destino - 1 && i < capacidad_origen &&
                        origen[i] != '\0';
                 i++)
            {
                destino[i] = origen[i];
            }

            destino[i] = '\0';
            estado_copia = i;
        }
        else
        {
            estado_copia = CAPACIDAD_INSUFICIENTE;
        }
    }
    else if (longitud_origen <= TODO_OK)
    {
        estado_copia = longitud_origen;
    }
    else
    {
        estado_copia = longitud_destino;
    }
    return estado_copia;
}

/**
 * 2.3
 * Inserta una cadena en otra después de la posición indicada de manera segura.
 *
 * @param cadena_destino Arreglo de caracteres que representa la cadena destino.
 * @param capacidad_destino Capacidad máxima del arreglo de destino (incluyendo
 * el carácter nulo).
 * @param posicion Posición en la cadena destino después de la cual se insertará
 * la cadena a_insertar.
 * @param a_insertar Arreglo de caracteres que representa la cadena a insertar.
 * @return La longitud de la cadena destino después de la inserción o un código
 * de error:
 *         - La longitud de la cadena destino después de la inserción si la
 * inserción se realiza con éxito.
 *         - Mensajes de error en caso de problemas, como cadena destino nula,
 * capacidad incorrecta, posición inválida, cadena a_insertar nula o capacidad
 * insuficiente.
 *
 * @pre
 * - La variable 'capacidad_destino' debe ser mayor o igual a 1.
 * - El puntero 'cadena_destino' puede ser NULL o apuntar a un arreglo válido.
 * - La variable 'posicion' debe estar en el rango de 0 a la longitud de la
 * cadena destino (inclusive).
 * - El puntero 'a_insertar' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función inserta la cadena a_insertar en la cadena destino después de la
 * posición indicada si ambas son válidas.
 * - La cadena destino tendrá un carácter nulo al final para asegurar que sea
 * una cadena segura.
 * - La función devuelve la longitud de la cadena destino después de la
 * inserción si la inserción se realiza con éxito.
 * - Mensajes de error en caso de problemas con las precondiciones incluyendo
 *      los devueltos por la funcion largo_seguro en ambas cadenas.
 */
int insertar_cadena(char destino[], int capacidad_destino, int posicion,
                    char origen[], int capacidad_origen)
{
    int longitud_destino = largo_seguro(destino, capacidad_destino);
    int longitud_origen = largo_seguro(origen, capacidad_origen);

    int espacio_disponible = capacidad_destino - longitud_destino;

    int codigo_salida = TODO_OK;

    if (longitud_destino <= TODO_OK)
    {
        codigo_salida = longitud_destino;
    }
    if (longitud_origen <= TODO_OK)
    {
        codigo_salida = longitud_origen;
    }
    if ((posicion < 0) || (posicion > longitud_destino))
    {
        codigo_salida = POSICION_INVALIDA;
    }
    if (longitud_origen > espacio_disponible)
    {
        codigo_salida = CAPACIDAD_INSUFICIENTE;
    }

    if (codigo_salida == TODO_OK)
    {
        for (int i = longitud_destino; i >= posicion; i--)
        {
            destino[i + longitud_origen] = destino[i];
        }
        for (int i = 0; i < longitud_origen; i++)
        {
            destino[posicion + i] = origen[i];
        }
        codigo_salida = largo_seguro(destino, capacidad_destino);
    }
    return codigo_salida;
}

/**
 * 2.4
 * Limpia una cadena de caracteres, eliminando los caracteres que no son
 * alfanuméricos (AZaz09), manteniendo el carácter nulo.
 *
 * @param capacidad Capacidad máxima de la cadena (incluyendo el carácter nulo).
 * @param cadena Arreglo de caracteres que representa la cadena a limpiar.
 * @return El largo de la cadena limpiada o un código de error correspondiente.
 *
 * @pre
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - El puntero 'cadena' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función elimina los caracteres no alfanuméricos (AZaz09) de la cadena
 *   manteniendo el carácter nulo al final.
 * - La función devuelve el largo de la cadena limpiada si la limpieza se
 *   realiza con éxito.
 * - Mensajes de error en caso de problemas con las precondiciones.
 */
int limpiadora(int capacidad, char cadena[])
{
    int estado_limpieza = largo_seguro(cadena, capacidad);
    int i = 0;
    int j = 0;
    if (estado_limpieza >= TODO_OK)
    {
        for (; cadena[i] != '\0'; i++)
        {
            if (es_alfanumerico(cadena[i]))
            {
                cadena[j] = cadena[i];
                j++;
            }
        }
        cadena[j] = '\0';
        estado_limpieza = j;
    }
    return estado_limpieza;
}

/**
 * Compara dos cadenas seguras (solo minúsculas) y determina su orden
 * alfabético.
 *
 * @param capacidad Capacidad máxima de la primera cadena (incluyendo el
 * carácter nulo).
 * @param cadena Arreglo de caracteres que representa la primera cadena.
 * @param capacidad_a_comparar Capacidad máxima de la segunda cadena (incluyendo
 * el carácter nulo).
 * @param a_comparar Arreglo de caracteres que representa la segunda cadena a
 * comparar.
 * @return El resultado de la comparación o un código de error correspondiente.
 *
 * @pre
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - La variable 'capacidad_a_comparar' debe ser mayor o igual a 1.
 * - Los punteros 'cadena' y 'a_comparar' pueden ser NULL o apuntar a arreglos
 * válidos.
 *
 * @post
 * - La función compara las dos cadenas alfabéticamente y devuelve el resultado
 *   según las condiciones especificadas.
 * - Mensajes de error en caso de problemas con las precondiciones.
 */
int comparacion(int capacidad, char cadena[], int capacidad_a_comparar,
                char a_comparar[])
{
    int largo_cadena = largo_seguro(cadena, capacidad);
    int largo_a_comparar = largo_seguro(a_comparar, capacidad_a_comparar);
    int resultado = 1;
    int i = 0;

    if (largo_cadena <= TODO_OK)
    {
        resultado = largo_cadena;
    }
    else if (largo_a_comparar <= TODO_OK)
    {
        resultado = largo_a_comparar;
    }
    else
    {
        while (cadena[i] != '\0' && a_comparar[i] != '\0' && resultado)
        {
            if (cadena[i] < a_comparar[i])
            {
                resultado = CADENA_IGUAL;
            }
            else if (cadena[i] > a_comparar[i])
            {
                resultado = CADENA_MAYOR;
            }
            i++;
        }

        if (cadena[i] == '\0' && a_comparar[i] == '\0')
        {
            resultado = CADENA_MENOR;
        }
        else if (cadena[i] == '\0')
        {
            resultado = CADENA_IGUAL;
        }
        else
        {
            resultado = CADENA_MAYOR;
        }
    }
    return resultado;
}

/**
 * Convierte una cadena a minúsculas modificando la cadena original.
 *
 * @param capacidad Capacidad máxima de la cadena (incluyendo el carácter nulo).
 * @param cadena Arreglo de caracteres que representa la cadena a convertir a
 * minúsculas.
 * @return void
 *
 * @pre
 * - La variable 'capacidad' debe ser mayor o igual a 1.
 * - El puntero 'cadena' puede ser NULL o apuntar a un arreglo válido.
 *
 * @post
 * - La función convierte todos los caracteres de la cadena a minúsculas.
 * - Mensajes de error en caso de problemas con las precondiciones.
 */
int a_minusculas(int capacidad, char cadena[])
{
    int largo_cadena = largo_seguro(cadena, capacidad);

    if (largo_cadena > TODO_OK)
    {
        for (int i = 0; i < largo_cadena; i++)
        {
            cadena[i] = a_minuscula(cadena[i]);
        }
        largo_cadena = TODO_OK;
    }
    return largo_cadena;
}

#define CADENA_BASE 100
#define CADENA_XL 100

int main()
{
    char cadena1[CADENA_BASE] = "Hola, Mundo!";
    char cadena2[CADENA_BASE] = "Hola!";
    char cadena3[CADENA_BASE] = "Programacion I";
    char cadena4[CADENA_BASE] = "Setescientas lineas!!";
    char cadena5[CADENA_BASE] = "H3LL0W0RLD!";
    char destino[CADENA_XL] =
        "--------------------------------------------------------------------";

    printf("cadena1: %s\n", cadena1);
    printf("cadena2: %s\n", cadena2);
    printf("cadena3: %s\n", cadena3);
    printf("cadena4: %s\n", cadena4);
    printf("cadena5: %s\n", cadena5);

    int len1 = largo_seguro(cadena1, CADENA_BASE);
    int len2 = largo_seguro(cadena2, CADENA_BASE);
    int len3 = largo_seguro(cadena3, CADENA_BASE);
    int len4 = largo_seguro(cadena4, CADENA_BASE);
    int len5 = largo_seguro(cadena5, CADENA_BASE);

    printf("Longitud de cadena1: %d\n", len1);
    printf("Longitud de cadena2: %d\n", len2);
    printf("Longitud de cadena3: %d\n", len3);
    printf("Longitud de cadena4: %d\n", len4);
    printf("Longitud de cadena5: %d\n", len5);

    copiar(cadena1, CADENA_BASE, destino, CADENA_XL);
    printf("Copia de cadena1: %s\n", destino);

    int resultado =
        insertar_cadena(destino, CADENA_XL, 5, cadena2, CADENA_BASE);
    if (resultado >= 0)
    {
        printf("Insercion exitosa: %s\n", destino);
    }
    else
    {
        imprime_mensaje_error(resultado);
    }

    limpiadora(CADENA_XL, destino);
    printf("Cadena limpiada: %s\n", destino);

    resultado = comparacion(CADENA_BASE, cadena3, CADENA_BASE, cadena4);
    if (resultado == CADENA_IGUAL)
    {
        printf("Son iguales\n");
    }
    else if (resultado == CADENA_MENOR)
    {
        printf("Primera cadena va antes que la segunda\n");
    }
    else if (resultado == CADENA_MAYOR)
    {
        printf("Primera cadena va después que la segunda\n");
    }
    else
    {
        imprime_mensaje_error(resultado);
    }

    a_minusculas(CADENA_BASE, cadena5);
    printf("Cadena en minusculas: %s\n", cadena5);

    return 0;
}