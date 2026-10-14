#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    int n;

    do{
        printf("Ingresa n(1 - 10): ");
        scanf("%d", &n);
    } while(!(n<=10 && n>=1));  
    getchar();

    
    char **lineas = (char **) malloc(n * sizeof(char *));
    if (lineas == NULL) {
        printf("Error: No se pudo asignar memoria para el arreglo de punteros.\n");
        return 1;
    }

    printf("\n--- INGRESO DE CADENAS ---\n");
    char buffer[BUFFER_SIZE];

    
    for (int i = 0; i < n; i++) {
        printf("Ingrese la cadena #%d: ", i + 1);
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }

            
            lineas[i] = (char *) malloc((len + 1) * sizeof(char));
            if (lineas[i] == NULL) {
                printf("Error de asignacion de memoria en cadena %d.\n", i);
                return 1;
            }

            
            strcpy(lineas[i], buffer);
        }
    }

    
    printf("\n=== RESULTADO (CADENAS EN EL HEAP) ===\n");
    for (int i = 0; i < n; i++) {
        printf("lineas[%d] = \"%s\" | Longitud: %zu | Dir. Memoria: %p\n",
               i, lineas[i], strlen(lineas[i]), (void *)lineas[i]);
    }

    
    for (int i = 0; i < n; i++) {
        free(lineas[i]);
        lineas[i] = NULL;
    }
    free(lineas);
    lineas = NULL;

    printf("\nMemoria liberada correctamente.\n");

    return 0;
}