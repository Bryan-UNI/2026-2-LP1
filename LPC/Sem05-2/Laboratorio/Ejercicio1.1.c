#include<stdio.h>
int main(){
    int n, cifra;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    while(n/10 != 0){
        int suma = 0;
        while(n>0){
            cifra = n%10;
            suma = suma + cifra;
            n = n/10;
        }
        n = suma;

    }
    printf("Raiz digital: %d\n", n);
    return 0;
}