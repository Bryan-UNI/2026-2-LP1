#include<stdio.h>

int main(){
    int v[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int *p = v;
    printf("*p:       %d\n", *p);
    printf("*(p+1):   %d\n", *(p+1));
    printf("*(p+7):   %d\n", *(p+7));

    printf("p[3]:     %d\n", p[3]);
    printf("[3]p:     %d\n", 3[p]);
    printf("La diferencia (p+5) - p:    %lld\n", (p+5) - p);

    printf("El tamanio de un int es:    %zu\n", sizeof(int));

    printf("Recorrido del arreglo:\n");
    int suma = 0;
    for(int i=0; i<8; i++){
        printf("v[%d]=   %d\n", i, *(p+i));
        suma += *(p+i);
    }

    printf("Suma:   %d\n", suma);

    printf("Recorrido invertido del arreglo:\n");
    int *p_rev = &v[7];
    for(int i=0; i<8; i++){
        printf("v[%d]=   %d\n", 7-i, *(p_rev));
        p_rev--;
    }

    return 0;

    // gcc -Wall -Wextra -std=c11 -g aritmetica.c -o aritmetica.exe
}