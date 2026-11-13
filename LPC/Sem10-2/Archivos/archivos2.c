#include<stdio.h>

int main() {
    FILE *archivo;
    int caracter;    
    archivo = fopen("datos.txt", "r");

    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leyendo de caracter a caracter
    while((caracter = fgetc(archivo)) != EOF){
        putchar(caracter);
    }

    fclose(archivo);

    return 0;
}