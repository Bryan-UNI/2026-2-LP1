#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    char *msj  = "Bienvenidos a la Escuela de Ingenieria de Software - UNI";
    char *c = msj;
    p = (int *)malloc(sizeof(int)*5); // malloc devuelve una region de memoria
                                      // de tamaño 5 veces de un entero
    for(size_t i=0; i < 5; i++){      // muestra la basura de la memoria
        printf("En la direccion %p esta el valor %d\n", (p+i), *(p+i));
    }

    int cuenta = 0;
    printf("Impremiendo la cadena:\n");   // poniendo "x" en vez de "c" se mira en hexadecimal
    while(*c != 0){           // mientras el caracter sea diferente de fin de cadena
        printf("%x", *c);     // Mostrar el caracter que esta en la memoria
        c++;   // se aumenta la direccion del puntero
        if(cuenta %16);
    }


    free(p);
    return 0;
}