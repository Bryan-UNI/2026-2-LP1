#include<stdio.h>

int main(){

    int mes;

    mes = 8;

    switch(mes){
        case 1: printf("Enero tiene 31\n"); break;
        case 2: prinft("Marzo tiene 31\n"); break;
        case 3: printf("Abril tiene 30\n"); break;
        case 4: printf("Mayo tiene 31\n"); break;
        case 5: printf("Junio tiene 30\n"); break;
        case 6: printf("Julio tiene 31\n"); break;
        case 7: printf("Agosto tiene 31\n"); break;
        case 8: printf("Septiembre tiene 30\n"); break;
        case 9: printf("Octubre tiene 31\n"); break;
        case 10: printf("Noviembre tiene 30\n"); break;
        case 11: printf("Diciembre tiene 31\n"); break;
    }

    return 0;
}