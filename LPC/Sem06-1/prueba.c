#include<stdio.h>
int main(){
    int n;
    printf("Ingrese el tamanio del arreglo: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}