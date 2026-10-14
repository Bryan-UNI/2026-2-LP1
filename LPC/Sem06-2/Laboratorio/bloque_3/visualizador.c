#include<stdio.h>

int main(){

    int v[5] = {1, 2, 3, 4, 5};
    for(int i=0; i<5; i++){
        printf("v[%d] = %d @ 0x%08X %p\n", i, v[i], v[i], (void *)&v[i]);
    }

    unsigned char *p = (unsigned char *)&v;
    for(size_t i=0; i<sizeof(int); i++){
        printf("%02x ", *(p + i));
    }
    printf("\n");

    double d = 3.14;
    p = (unsigned char *)&d;
    for(size_t i=0; i<sizeof(double); i++){
        printf("%02x ", *(p + i));
    }
    printf("\n");
    return 0;
}