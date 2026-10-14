
#include<stdio.h>

int main(){

    int *ptr;  // se define ptr como puntero
               // es una variable que opera con direccion de memoria
               // inicialmente apunta a algun lugar de la memoria (tiene un lugar de memorias)
    
    int cantidad = 200;
    /* Regla: Si se crea el puntero se requiere inicializar antes de usar */
    ptr = NULL;  // NULL es cero, significa que no se apunta a nada, que no tiene memoria


    // ... despues de muchas lineas
    if(ptr == NULL){
        ptr = &cantidad;
        printf("Puntero incializado, su direccion es %p y su valor es %d\n" , ptr, *ptr);
    } else {
        printf("El puntero ya tiene memoria, no es necesario inicializar!\n");
    }
    return 0;
}