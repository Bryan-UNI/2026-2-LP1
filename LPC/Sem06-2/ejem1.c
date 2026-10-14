#include<stdio.h>
// Parametro de paso por valor
void agregar_uno(int n){  // se crea una copia de la memoria de la variable
    n++;
    printf("Dentro de la funcion, el valor de n es %d\n", n);
}

// Parametro de paso por referencia
void agregar_uno2(int *n){
    (*n)++;
    pirntf("Dentro de la funcion, el valor de n es %d\n", *n);
}
int main(){

    int n = 5;
    printf("----------------Sin usar referencia----------------");
    printf("Antes de entrar a la funcion, el valor de n es %d\n", n);
    agregar_uno(n);
    printf("Despues de entrar a la funcion, el valor de n es %d\n", n);

    printf("----------------Usando referencia----------------");
    printf("Antes de entrar a la funcion, el valor de n es %d\n", n);
    agregar_uno(&n);
    printf("Despues de entrar a la funcion, el valor de n es %d\n", n);

    return 0;

}