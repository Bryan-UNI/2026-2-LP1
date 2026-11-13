#include<stdio.h>
// recorriendo la memoria de numeros char a char
int main(){
    // long long ocupa 8 bytes
    long long numeros[5] = {10, 20, 30, 40, 50};
    char *ptr;
    ptr = (char *)numeros;
    for(int i = 0; i < 5; i++){
        printf("Valor %ld, direccion %c\n", *(ptr + i), (ptr + i));
    }
    return 0;
}