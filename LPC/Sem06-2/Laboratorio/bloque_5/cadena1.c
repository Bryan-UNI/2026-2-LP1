#include <stdio.h>
#include <string.h>
int main() {
 char cadena1[] = "Manzana";
 char cadena2[] = "Mandarina";
 char cadena3[] = "Manzana";
 // 1. Ejemplo con strcmp (Compara todo)
    if (strcmp(cadena1, cadena3) == 0) {
    printf("strcmp: cadena1 y cadena3 son iguales.\n");
    }
 
    if (strcmp(cadena1, cadena2) != 0) {
    printf("strcmp: cadena1 y cadena2 son diferentes.\n");
    }
 
    // 2. Ejemplo con strncmp (Compara solo los primeros 3 caracteres: "Man" vs "Man")
    if (strncmp(cadena1, cadena2, 3) == 0) {
    printf("strncmp: Los primeros 3 caracteres son iguales.\n");
    }
 
    return 0;
}
