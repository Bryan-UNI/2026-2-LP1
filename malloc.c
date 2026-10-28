#include<stdio.h>
#include<stdlib.h>

int main(){

    int *p = (int *) malloc(sizeof(int));

    if(p==NULL){
        printf("No hay memoria suficiente\n");
        return 1;
    }

    *p = 50;
    printf("El valor guardado en el Heap es: %d\n", *p);
    printf("Direccion asignada por malloc: %p\n", (void *)p);

    free(p);
    p = NULL;

    int n;
    printf("Ingrese el numero de elementos del arreglo: ");
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    if(v==NULL){
        printf("No hay memoria suficiente\n");
        return 1;
    }
    for(int i=0; i<n; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");
    free(v);
    v = NULL; 

    return 0;
}