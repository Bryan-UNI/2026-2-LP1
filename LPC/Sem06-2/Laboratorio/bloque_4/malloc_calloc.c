#include<stdio.h>
#include<stdlib.h>
void imprimir(const int *arr){
    for(int i=0; i<10; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main(){
    
    int *arr1 = (int *) malloc(10 * sizeof(int));
    int *arr2 = (int *) calloc(10, sizeof(int));

    imprimir(arr1);
    imprimir(arr2);

    for(int i=0; i<10; i++){
        arr1[i] = i*i;
        arr2[i] = i*i;
    }

    printf("Tras llenar con cuadrados:\n"); 
    imprimir(arr1);
    imprimir(arr2);

    free(arr1);
    arr1 = NULL;
    
    free(arr2);
    arr2 = NULL;

    printf("Variante:\n");
    int *ptr = (int *)malloc(0);
    printf("Direccion: %p\n", ptr);
    free(ptr);
    ptr = NULL;
    
    return 0;
}