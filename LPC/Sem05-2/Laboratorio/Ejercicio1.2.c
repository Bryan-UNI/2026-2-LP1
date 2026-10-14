#include<stdio.h>
int main(){
    int n, contador = 0;
    do{
        printf("Ingrese un numero entero positivo(1 a 10000): ");
        scanf("%d", &n);
    } while (!(n>=1 && n<=10000));
    while(n != 1){
        if(n%2 == 0){
            n = n/2;
        } else {
            n = 3*n + 1;
        }
        contador++;
    }
    printf("La semilla es: %d\n", contador);
    
    return 0;
}