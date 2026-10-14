#include<stdio.h>

int main(){
    int x = 42;
    int *p = &x;
    int **pp = &p;
    printf("Valor de    x:   %d\n", x);
    printf("Valor de   *p:   %d\n", *p);
    printf("Valor de **pp:   %d\n", **pp);

    printf("Direccion de x:        %p\n", &x);
    printf("Valor de   *p:         %d\n", p);
    printf("Direccion de p:       %p\n", &p);
    printf("Direccion de pp:     %p\n", &pp);

    *p = 12;
    printf("Valor de    x:   %d\n", x);
    **pp = 24;
    printf("Valor de    x:   %d\n", x);

    printf("Direccion guardada en *p:        %p\n", (void *)p);
    printf("Direccion guardada en *pp:       %p\n", (void *)pp);
    
    return 0;
}