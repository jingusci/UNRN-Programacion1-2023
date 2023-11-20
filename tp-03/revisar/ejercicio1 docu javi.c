

/*
Esta funcion recibe un arreglo y su capacidad, y solicita valores para completarlo.
@param1 capacidad (int)
@param2 arreglo[] (int)
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

   printf("Se solicitaran %d valores para cargar el arreglo\n",capacidad);
   for (int i = 0; i<capacidad;i++)
   {
      printf("Ingrese el valor numero %i para el arreglo: ",i);
      scanf("%d", &arreglo[i]);
   }
   return flag_error;
}

/*
Esta funcion recibe un arreglo y su capacidad, y muestra por pantalla sus valores.
@param1 capacidad (int)
@param2 arreglo[] (int)
@return flag_error (int)
Precondiciones 
   Un entero positivo (capacidad) y un arreglo ya cargado.
Postcondiciones 
   -
*/
int muestra_arreglo(int capacidad, int arreglo[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error. 

   printf("[ ");
   for (int i = 0; i<capacidad;i++)
   {
      printf("%d ", arreglo[i]);
   }
   printf("]");
   return flag_error;
}

/*
Esta funcion recibe tres arreglos y sus capacidades, y carga el tercero con los dos primeros.
@param1 capacidad (int)
@param2 arreglo[] (int)
@param3 capacidad (int)
@param4 arreglo[] (int)
@param5 capacidad (int)
@param6 arreglo[] (int)
@return flag_error (int)
Precondiciones 
   Tres enteros positivos (capacidades), dos arreglos ya cargados, un arreglo vacio.
   capacidad del tercer arreglo igual a la suma de los otros 2.
Postcondiciones 
   tercer arreglo cargado
*/
int unir_arreglos(int capacidad_1, int arreglo_1[], int capacidad_2, int arreglo_2[], int arreglo_unido[])
{
   int flag_error = 0;
   // ver si hay que hacer un if que levante el flag de error. 

   int i = 0;
   for (int j=0;j<capacidad_1;j++)
   {
      arreglo_unido[i] = arreglo_1[j];
      i++;
   }
   for (int j=0;j<capacidad_2;j++)
   {
      arreglo_unido[i] = arreglo_2[j];
      i++;
   }
   return flag_error;
}


/*
Esta funcion recibe un arreglo y su capacidad, calcula el promedio de sus valores.
@param1 capacidad (int)
@param2 arreglo[] (int)
@return promedio (int)
Precondiciones 
   Un entero positivo (capacidad) y un arreglo ya cargado.
Postcondiciones 
   Valor del promedio
*/
float calc_promedio(int capacidad, int arreglo[])
{
   float suma = 0;
   float promedio;
   for (int i = 0;i<capacidad;i++)
   {
      suma += arreglo[i];
   }
   promedio = suma/capacidad;
   return promedio;
}


/*
Esta funcion recibe un arreglo y su capacidad, encuentra el valor minimo de los
valores del arreglo.
@param1 capacidad (int)
@param2 arreglo[] (int)
@return minimo (int)
Precondiciones 
   Un entero positivo (capacidad) y un arreglo ya cargado.
Postcondiciones 
   Valor minimo
*/
int minimo_de_arreglo(int capacidad, int arreglo[])
{
   int minimo;

   for (int i=0;i<capacidad;i++)
   {
      if (i==0)
      {
         minimo = arreglo[i];
      }
      else if (arreglo[i]<minimo)
      {
         minimo = arreglo[i];
      }
   }
   return minimo;
}

/*
Esta funcion recibe un arreglo y su capacidad, y encuentra la posicion del valor maximo.
@param1 capacidad (int)
@param2 arreglo[] (int)
@return minimo (int)
Precondiciones 
   Un entero positivo (capacidad) y un arreglo ya cargado.
Postcondiciones 
   Valor minimo
*/
int posicion_del_max(int capacidad, int arreglo[])
{
   int max,pos_max;

   for (int i=0;i<capacidad;i++)
   {
      if (i==0)
      {
         max = arreglo[i];
         pos_max = i;
      }
      else if (arreglo[i]>max)
      {
         max = arreglo[i];
         pos_max = i;
      }
   }
   return pos_max;
}

/**
 * Esta funcion recibe un arreglo y su capacidad, y ordena sus valores de menoar a mayor.
 * @param capacidad (int)
 * @param arreglo[] (int)
 * @return minimo (int)
 * Precondiciones 
 *    Un entero positivo (capacidad) y un arreglo ya cargado.
 * Postcondiciones 
 *    Valor minimo
*/
void ordenar_arreglo(int capacidad, int arreglo[])
{
   int temp;
   for (int i=0; i<capacidad;i++)
   {
      for (int j=(i+1); j<capacidad;j++)
      {
         if (arreglo[j]<arreglo[i])
         {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
         }
      }
   }
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
