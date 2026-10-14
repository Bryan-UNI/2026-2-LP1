/*
#include <stdio.h>
int contador = 0; // VARIABLE GLOBAL
void incrementar_local(void) {
    int contador = 0; // LOCAL — oculta la global
    contador++;
    printf("local contador = %d\n", contador);
}
int main(void) {
    incrementar_local();
    incrementar_local();
    incrementar_local();
    printf("global contador = %d\n", contador);

    return 0;
}
*/

#include <stdio.h>
int contador = 0; // VARIABLE GLOBAL
void incrementar_global(void) {
 contador++; // modifica la GLOBAL
}
int main(void) {
    incrementar_global();
    incrementar_global();
    incrementar_global();
    printf("global contador = %d\n", contador);
    return 0;
}

