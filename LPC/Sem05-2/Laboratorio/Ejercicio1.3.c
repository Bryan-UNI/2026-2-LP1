#include<stdio.h>
int main(){
    double tolerancia = 1e-6, i = 1, suma = 0, temp = 1;
    while(temp > tolerancia){
        if((int)i%2 == 0){
            suma = suma - 1.0/i;
        } else {
            suma  = suma + 1.0/i;
        }
        temp = 0.693147 - suma;
        if(temp<0){
            temp = -temp;
        }
        i++;
    }
    printf("Resultado: %lf", suma);

    return 0;
}