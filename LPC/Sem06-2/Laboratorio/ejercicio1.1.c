#include<stdio.h>

void mostrar_array(int arr[], int n){
    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int calcular_suma(int arr[], int n){
    int suma = 0;
    for(int i=0; i<n; i++){
        suma += arr[i]; 
    }
    return suma;
}

double calcular_promedio(int arr[], int n){
    return ( (double)calcular_suma(arr, n)/(double)n);
}

void invertir_array(int arr[], int n){
    int aux = 0, j = n-1;
    for(int i=0; i<=n/2 - 1; i++){
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        j--;
    }
    mostrar_array(arr, n);
}
int main(){
    int n = 10, datos[n];
    printf("Ingrese 10 enteros:\n");
    for(int i=0; i<n; i++){
        printf("datos[%d]: ", i);
        scanf("%d", &datos[i]);
    }
    printf("Suma: %d\n", calcular_suma(datos, n));
    printf("Promedio: %lf\n", calcular_promedio(datos, n));

    int minimo = datos[0], maximo = 0, num_pares = 0, num_impares = 0, ind_max = 0, ind_min = 0;
    for(int i=0; i<n; i++){
        if(minimo>datos[i]){
            minimo = datos[i];
            ind_min = i;
        }
        if(maximo<datos[i]){
            maximo = datos[i];
            ind_max = i;
        }
        if(datos[i]%2 == 0 && datos[i] != 0){
            num_pares++;
        } else {
            num_impares++;
        }
    }
    printf("Minimo: %d (indice %d)\n", minimo, ind_min);
    printf("Maximo: %d (indice %d)\n", maximo, ind_max);
    printf("Pares: %d\n", num_pares);
    printf("Impares: %d\n", num_impares);
    printf("Original: ");
    mostrar_array(datos, n);
    printf("Invertido: ");
    invertir_array(datos, n);

    return 0;
}