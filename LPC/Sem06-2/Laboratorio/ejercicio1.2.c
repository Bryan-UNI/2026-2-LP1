#include<stdio.h>
#define  COLUMNAS 4

void mostrar_matriz(int mat[][COLUMNAS], int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<COLUMNAS; j++){
            printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }
}
void mostrar_traspuesta(int mat[][COLUMNAS], int filas){
    for(int i=0; i<COLUMNAS; i++){
        for(int j=0; j<filas; j++){
            printf("\t%d", mat[j][i]);
        }
        printf("\n");
    }
}

int main(){
    int filas = 3;
    int m[filas][COLUMNAS];
    for(int i=0; i<filas; i++){
        for(int j=0; j<COLUMNAS; j++){   
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    mostrar_matriz(m, filas);
    printf("\n");
    mostrar_traspuesta(m, filas);

    return 0;
}