#include<stdio.h>
#include<stdlib.h>

void dividir(int a, int b, int *cociente, int *resto){
    if(b!=0){
        *cociente = a/b;
        *resto = a%b;
    }
}

void reservar_entero(int **pp, int valor){
    *pp = (int *) malloc(sizeof(int));
    if(*pp != NULL){
        **pp = valor;
    }
}

int main(){
    int a = 10;
    int *p = &a;
    int **pp = &p;

    printf("a =     %d,    *p =    %d,    **p =   %d\n", a, *p, **pp);
    printf("&a =   %p,    &p =   %p,    &*pp =   %p\n", (void *)&a, (void *)p, (void *)*pp);
    printf("&p =   %p,    &pp =   %p\n", (void *)&p, (void *)pp);


    **pp = 12;
    printf(" a =    %d\n", a);
    int cociente, resto;
    dividir(17, 5, &cociente, &resto);
    printf("Cociente:   %d\n", cociente);
    printf("resto:   %d\n", resto);
    
    reservar_entero(&p, 13);
    printf("*p =    %d\n", *p);
    free(p);
    p = NULL;

    return 0;
}