
/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
 */
int largo_seguro(char cadena[], int capacidad)
{
   int largo = 0;

   while (cadena[largo] != '\0' && largo < capacidad)
   {
      largo++;
   }

   if (largo == capacidad)
   {
      largo = CADENA_SIN_TERMINADOR;
   }

   return largo;
}

/**
 * La funcion copia una cadena en otra.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
 */
int copiar_cadenas(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);

   if (largo_origen == CADENA_SIN_TERMINADOR)
   {
      resultado = CADENA_SIN_TERMINADOR;
   }
   else if (largo_origen >= capacidad_destino)
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else
   {
      for (int i = 0; i < (largo_origen + 1); i++)
      {
         cadena_destino[i] = cadena_origen[i];
      }
      resultado = largo_seguro(cadena_destino, capacidad_destino);
   }

   return resultado;
}

/**
 * La funcion inserta una cadena en otra.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
 */
int insertar_cadena(char cadena_origen[], char cadena_destino[], int capacidad_origen, int capacidad_destino, int posicion)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);
   int largo_destino = largo_seguro(cadena_destino, capacidad_destino);

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

/*
   Esta funcion solicita y retorna un numero entero.
   @return entero (int)
*/
int solicitar_entero()
{
   int numero;
   printf("Ingrese un numero entero: ");
   scanf("%d", &numero);
   return numero;
}

int limpiar_cadena(char cadena_origen[], char cadena_limpia[], int capacidad_origen, int capacidad_limpia)
{
   int resultado;
   int largo_origen = largo_seguro(cadena_origen, capacidad_origen);

   if (largo_origen > capacidad_limpia)
   {
      resultado = DESTINO_MENOR_ORIGEN;
   }
   else
   {
      int j = 0;
      for (int i = 0; i <= largo_origen; i++)
      {
         if ((cadena_origen[i] >= '0' && cadena_origen[i] <= '9') ||
             (cadena_origen[i] >= 'A' && cadena_origen[i] <= 'Z') ||
             (cadena_origen[i] >= 'a' && cadena_origen[i] <= 'z') ||
             (cadena_origen[i] == '\0'))
         {
            cadena_limpia[j] = cadena_origen[i];
            j++;
         }
      }
      resultado = largo_seguro(cadena_limpia, capacidad_limpia);
   }
   return resultado;
}

int comparar_cadena(char cadena_1[], char cadena_2[], int capacidad_1, int capacidad_2)
{
   int resultado = 0;
   int largo_origen = largo_seguro(cadena_1, capacidad_1);
   for (int i = 0; i <= largo_origen; i++)
   {
      if (cadena_1[i] > cadena_2[i])
      {
         resultado = 1;
         break;
      }
      else if (cadena_1[i] < cadena_2[i])
      {
         resultado = -1;
         break;
      }
   }
   return resultado;
}

void convertir_a_minusculas(char cadena[], int capacidad)
{
   int resultado = 0;
   int distancia = 32; // distancia entre la "A" y la "a" en ASCII

   int largo_cadena = largo_seguro(cadena, capacidad);

   for (int i = 0; i < largo_cadena; i++)
   {
      if (cadena[i] >= 'A' && cadena[i] <= 'Z')
      {
         cadena[i] = cadena[i] + distancia;
      }
   }
}

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

int muestra_arreglo(int capacidad, char arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error.

   printf("[ ");
   for (int i = 0; i < capacidad; i++)
   {
      printf("%c ", arreglo[i]);
   }
   printf("]\n");
   return flag_error;
}

/*
Esta funcion recibe un arreglo y su capacidad, y solicita valores para completarlo.
@param1 capacidad (int)
@param2 arreglo[] (Char)
@return flag_error (int)
Precondiciones
   Un entero positivo (capacidad) y un arreglo.
Postcondiciones
   Arreglo cargado, flag con el resultado de la carga
*/
int cargar_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error.

   printf("Se solicitaran %d valores para cargar el arreglo\n", capacidad);
   for (int i = 0; i < capacidad; i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ", i);
      scanf("%d", &arreglo[i]);
   }
   return flag_error;
}