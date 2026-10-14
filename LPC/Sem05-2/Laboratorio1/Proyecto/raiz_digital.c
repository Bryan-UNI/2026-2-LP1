#include<stdio.h>
#include "raiz_digital.h"
#include<stdio.h>

int suma_digitos(int n){
    int suma = 0;
    while(n>0){
        suma += n%10;
        n /= 10;
    }
    return suma;
}


int raiz_digital(int n){
    imprimir_traza(n);
    while(n>=10){
        n = suma_digitos(n);
        imprimir_traza(n);
    }
    return n;
}


void imprimir_traza(int n){
    if(n>=10){
        printf("%d -> ", n);
    } else {
        printf("%d\n", n);
    }
}
