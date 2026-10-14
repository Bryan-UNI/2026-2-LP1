#include<stdio.h>
int main(){
    int a = 7, b = 2;
    printf("7 / 2  = %d (division entera)\n", a / b);
    printf("7 %% 2  = %d (modulo)\n, a % b");
    printf("7 / 2.0  = %.2f (promocion a double)\n", a / 2.0);
    printf("(flaot)7/2 = %.2f\n", (float)a / b);

    //Modulo con negativos: C truca hacia cero.
    printf("-7 %% 2 = %f\n", -7 % 2);
    printf("7 %% -2 = %d\n", 7 % -2);

    printf("\n");
    //Asignacion compuesta
    int x = 10;
    x += 5; printf("x += 5 -> %d\n", x);
    x -= 3; printf("x -= 3 -> %d\n", x);
    x *= 2; printf("x *= 2 -> %d\n", x);
    x /= 4; printf("x /= 4 -> %d\n", x);
    x %= 4; printf("x %%= 4 -> %d\n", x);

    return 0;
}