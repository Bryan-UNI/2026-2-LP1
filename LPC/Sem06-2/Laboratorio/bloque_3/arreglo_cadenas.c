#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    int n;
    do{
        printf("Ingrese la cantidad de cadenas(1-10): ");
        scanf("%d", &n);
    } while(!(n>=1 && n<=10));

    getchar();

    char **lineas = (char **) malloc(n * sizeof(char *));

    if(lineas == NULL){
        printf("No se pudo asignar memorias para el arreglo de punteros\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    for(int i=0; i<n; i++){
        printf("Ingrese la cadena %d: ", i+1);
        fgets(buffer, BUFFER_SIZE, stdin);

        size_t len = strlen(buffer)
        if(len>0 && buffer[len-1] == '\n'){
            buffer[len-1] = '\0';
            len--;
        }

        lineas[i] = (char *) malloc((len + 1) * sizeof(char));
        if(lineas[i] != NULL){
            strcpy(lineas[i], buffer);
        }
    }
    printf("Resultado:\n");
    for(int i=0; i<n; i++){
        printf("lineas[%d] @ %p -> %s (len = %zu)", i, (void *)lineas[i], lineas[i], strlen(lineas[i])); 
    }

    for(int i=0; i<n; i++){
        free(lineas[i]);
        lineas[i] = NULL;
    }
    free(lineas);
    lineas = NULL;

    return 0;
}