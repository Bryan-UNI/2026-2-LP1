#include<stdio.h>
int main(){
    
    //Solucion esperada
    int n = 4728;
    printf("Miles:    %d\n", n / 1000);
    printf("Centenas: %d\n", (n / 100) % 10);
    printf("Decenas:  %d\n", (n / 10) % 10);
    printf("Unidades: %\n", n % 10);

}