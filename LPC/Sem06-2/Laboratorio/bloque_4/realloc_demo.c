#include<stdio.h>
#include<stdlib.h>
int main(){
    int capacidad = 2;
    int size = 0;
    int contador = 0;
    int *arr = (int *) calloc(2, sizeof(int));
    if(arr == NULL){
        return 1;
    }
    int num;
    while(scanf("%d", &num) == 1 && num != -1){
        if(size == capacidad){
            int n_capacidad = capacidad * 2;

            int *tmp = (int *) realloc(arr, n_capacidad * sizeof(int));
            if(tmp == NULL){
                return 1;
            }
            arr = tmp;
            capacidad = n_capacidad;
            contador++;
        }
        arr[size] = num;
        size++;
    }
    
    printf("\nElementos: %d\n", size);
    printf("Capacidad final: %d\n", capacidad);
    printf("Realloc llamados: %d\n", contador);

    printf("Contenido: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    
    return 0;
}