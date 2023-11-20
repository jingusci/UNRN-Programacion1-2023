#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char cadena[] = "121A"; // Declara una matriz de caracteres, no un puntero
    int largo_cadena = strlen(cadena);
    printf(" -> %s <- \n", cadena);
    cadena[2] = 'X'; // Modifica el carácter en la posición 2
    printf(" -> %s <- \n", cadena);

    return 0;
}
