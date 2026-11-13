/*
char arr
*/


#include<stdio.h>

int main(){
    int matriz[2][3] = {
                        {10, 20, 30},
                        {40, 50, 60}
                        };
    int (*ptr)[3] = matriz; // (*ptr))[3]arreglo de 3 punteros, apuntando a matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(ptr + i) + j)); // aprovechando la aritmética de punteros
        }
        printf("\n");
    }

    return 0;
    // hacer desde 2.3 (recorrer una matriz usando un puntero doble int**). llamar al .c como ejercicio6.1
}