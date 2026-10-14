#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    int n;

    do{
        printf("Ingresa n (1 - 10): ");
        scanf("%d", &n);
    } while(!(n<=10 && n>=1));  
    getchar();

    printf("n: %d", n);

    return 0;
}