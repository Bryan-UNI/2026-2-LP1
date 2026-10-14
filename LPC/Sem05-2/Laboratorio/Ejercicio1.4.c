#include<stdio.h>
#include <stdbool.h>
int main(){
    int n, i = 1;
    printf("Ingresa n: ");
    scanf("%d", &n);
    bool  suma = true;

    while(i>0){
        if(suma){
            for(int j=1; j<=i; j++){
                printf("%d ", j);
            }
            printf("\n");
            i++;
            if(i>n){
                suma = false;
            }
        } else {
            i--;
            for(int j=1; j<=i; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
    }

    return 0;
}