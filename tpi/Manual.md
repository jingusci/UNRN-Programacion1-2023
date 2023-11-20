# Sudoku
## Trabajo Practico Integrador

### Información del juego
-   El juego tiene una "base de datos" de 10 sudokus resueltos almacenados.
-   El menu principal ofrece 4 opciones:
    *   Crear un juego nuevo
    *   Cargar un juego previamente guardado
    *   Guardar el juego actual
    *   Salir

    #### Crear un juego nuevo
    -   Elige un juego de los disponibles, ya sea de manera manual o aleatoria.
    -   Elige un nivel de dificultad. Mientras mas alto sea el valor, mayor cantidad 
        de elementos tendrá que completar el jugador.
    -   Crea el tablero de juego.

    #### Cargar el juego previamente guardado
    -   Es necesario que exista el archivo "sudoku_guardado.txt".
        -   No realiza la carga si no existe el archivo, informando el error.
    -   Actualiza el tablero de juego con los elementos del archivo.

    #### Guardar el juego actual
    -   Sobreescribe el contenido del archivo "sudoku_guardado.txt".
        -   Si todavia no se inició un juego, avisa el error y no actualiza el archivo.
---

### Jugando
-   El juego pedirá que se ingrese una jugada en orden fila-columna-valor.
    -   Se validará en todas las solicitudes que se ingresen valores válidos de números.
-   Si la jugada es válida, se actualizará en el tablero.
-   Si la jugada no es válida, el tablero no se actualizará y se informará el error.
-   El juego te permite volver al menu pricipal ingresando cero durante la solicitud de fila.
-   Luego de cada jugada se informarán cuántos valores faltan completar.
-   Si se completan todos los valores faltantes en el tablero, se mostrará un mensaje de felicitaciones por ganar el juego.


---

### Mejoras posibles
-   Incrementar la base de datos de sudokus.
-   Encriptar la base de datos para que el usuario no tenga informacion disponible sobre el sudoku que está resolviendo.
    -   Se podria usar un algoritmo de la consiga "espias"
-   Crear un contador de errores
    -   Terminar el juego si el usuario llega a un numero de errores
-   La pausa del final tiene el objetivo de "frenar" la consola para que no 
    se cierre automaticamente. 
    -   Se puede mejorar con la funcion getchar()
-   Hay variables `int` que pueden ser reemplazadas por variables booleanas
-   Hay variables `int` que pueden optimizarce con memoria dinamica
-   Todos los inputs por teclado son numericos.
    -   Se puede mejorar para que el juego no se detenga si el usuario ingresa por error un valor no numerico.
-   Crear un input del nombre del archivo del juego que se desea guardar o cargar.
    -   Con esto se permitirá almacenar mas de una partida.
---
<p style='text-align: right;'> Javier Ingusci </p>
<!-- ### Javier Ingusci. -->