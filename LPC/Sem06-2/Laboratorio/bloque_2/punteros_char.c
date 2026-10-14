#include<stdio.h>

int main(){

    char *s = "Hola, mundo";
    char *p = s; 
    while(*p != '\0'){
        putchar(*p);
        p++;
    }
    printf("\n");
    size_t len1 = 0;
    p = s;
    while(*p != '\0'){
        len1++;
        p++;
    }
    printf("%zu\n", len1);

    //s[0] = 'h';
    printf("\n");



    char s2[] = "Hola, mundo";
    p = s2;
    while(*p != '\0'){
        putchar(*p);
        p++;
    }
    printf("\n");
    len1 = 0;
    p = s2;
    while(*p != '\0'){
        len1++;
        p++;
    }
    printf("%zu\n", len1);

    s2[0] = 'h';
    p = s2;
    while(*p != '\0'){
        putchar(*p);
        p++;
    }
    printf("\n");

    return 0;
}