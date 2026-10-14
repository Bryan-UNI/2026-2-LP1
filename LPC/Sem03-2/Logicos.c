#include<stdio.h>
int main(){
    int a = 5, b = 0;

    // En C cualquier valor != es "verdadero"
    if(a) printf("a=%d es verdadero\n", a);
    if(!b) printf("b=%d es falso, !b = %d\n", b, !b);

    // Resultado de una comparacion es 0 o 1
    printf("5 > 3 = %d\n", 5 > 3);
    printf("5 == 5  = %d\n", 5 == 5);

    // Cortocircuito: // y && no evaluan lo innecesario
    int x = 0;
    if(b != 0 && a / b > 1) {
        printf("No se ejecuta\n");
    } else {
        printf("Cortocurcuito evito division por cero\n");
    }

    // Precedencia: && tiene mayor precedencia que //
    int r = 1 || 0 && 0;   // 1 // (0 && 0) = 1
    printf("1 || 0 && 0 = %d\n", r);

    return 0;
}