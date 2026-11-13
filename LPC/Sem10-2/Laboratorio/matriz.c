#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int fila;
    int col;
    double valor;
} ElementoEsparso;

void generar_matriz_esparsa(const char *archivo, int filas, int columnas, float densidad) {
    
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        printf("Error al crear el archivo.\n"); 
        return;
    }

    int total_celdas = filas * columnas;
    int numero_elementos = (int)(total_celdas * densidad);

    fprintf(f, "%d %d %d\n", filas, columnas, numero_elementos);

    for (int k = 0; k < numero_elementos; k++) {
        int i = rand() % filas;
        int j = rand() % columnas;
        float valor = 1.0f + ((float)rand() / (float)RAND_MAX) * 9.0f;

        // generamos un numero de entre 1 y 10 (en float)
        fprintf(f, "%d %d %.2f\n", i, j, valor);
    }
    fclose(f);
}

void txt_a_binario(const char *archivo, const char *archivo_bin) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo de texto.\n");
        return;
    }

    FILE *f_bin = fopen(archivo_bin, "wb");
    if (f_bin == NULL) {
        printf("Error al crear el archivo binario.\n");
        fclose(f);
        return;
    }

    int filas, columnas, numero_elementos;
    if (fscanf(f, "%d %d %d", &filas, &columnas, &numero_elementos) == 3) {
        fwrite(&filas, sizeof(int), 1, f_bin);
        fwrite(&columnas, sizeof(int), 1, f_bin);
    }

    ElementoEsparso elem;

    while (fscanf(f, "%d %d %lf", &elem.fila, &elem.col, &elem.valor) == 3) {
        fwrite(&elem, sizeof(ElementoEsparso), 1, f_bin);
    }

    fclose(f);
    fclose(f_bin);
}

int comparar_elementos(const void *a, const void *b) {
    const ElementoEsparso *e1 = (const ElementoEsparso *)a;
    const ElementoEsparso *e2 = (const ElementoEsparso *)b;

    if (e1->fila != e2->fila)
        return e1->fila - e2->fila;
    return e1->col - e2->col;
}


void multiplicar_y_consolidar_binario(void) {
    FILE *fa = fopen("matriz_a.bin", "rb");
    FILE *fb = fopen("matriz_b.bin", "rb");
    FILE *f_acumulado = fopen("acumulado.bin", "wb");

    if (fa == NULL || fb == NULL || f_acumulado == NULL) {
        printf("Error al abrir archivos binarios en la multiplicacion.\n");
        return;
    }

    int filas_a, columnas_a, filas_b, columnas_b;
    fread(&filas_a, sizeof(int), 1, fa);
    fread(&columnas_a, sizeof(int), 1, fa);
    fread(&filas_b, sizeof(int), 1, fb);
    fread(&columnas_b, sizeof(int), 1, fb);

    
    fwrite(&filas_a, sizeof(int), 1, f_acumulado);
    fwrite(&columnas_b, sizeof(int), 1, f_acumulado);

    ElementoEsparso elem_a, elem_b, prod;
    int total_parciales = 0;

    while (fread(&elem_a, sizeof(ElementoEsparso), 1, fa) == 1) {
        fseek(fb, sizeof(int) * 2, SEEK_SET);

        while (fread(&elem_b, sizeof(ElementoEsparso), 1, fb) == 1) {
            if (elem_a.col == elem_b.fila) {
                prod.fila = elem_a.fila;
                prod.col = elem_b.col;
                prod.valor = elem_a.valor * elem_b.valor;

                fwrite(&prod, sizeof(ElementoEsparso), 1, f_acumulado);
                total_parciales++;
            }
        }
    }
    fclose(fa);
    fclose(fb);
    fclose(f_acumulado);

    FILE *f_read_acum = fopen("acumulado.bin", "rb");
    if (f_read_acum == NULL) {
        printf("Error al abrir acumulado.bin para lectura.\n");
        return;
    }

    int M, P;
    fread(&M, sizeof(int), 1, f_read_acum);
    fread(&P, sizeof(int), 1, f_read_acum);

    ElementoEsparso *buffer = (ElementoEsparso *)malloc(total_parciales * sizeof(ElementoEsparso));
    if (buffer == NULL && total_parciales > 0) {
        printf("Error al asignar memoria para consolidacion.\n");
        fclose(f_read_acum);
        return;
    }

    fread(buffer, sizeof(ElementoEsparso), total_parciales, f_read_acum);
    fclose(f_read_acum);

    qsort(buffer, total_parciales, sizeof(ElementoEsparso), comparar_elementos);

    FILE *f_res_bin = fopen("matriz_resultado.bin", "wb");
    fwrite(&M, sizeof(int), 1, f_res_bin);
    fwrite(&P, sizeof(int), 1, f_res_bin);

    if (total_parciales > 0) {
        ElementoEsparso actual = buffer[0];

        for (int i = 1; i < total_parciales; i++) {
            if (buffer[i].fila == actual.fila && buffer[i].col == actual.col) {
                actual.valor += buffer[i].valor; // Sumar valores en la misma celda
            } else {
                fwrite(&actual, sizeof(ElementoEsparso), 1, f_res_bin);
                actual = buffer[i];
            }
        }
        fwrite(&actual, sizeof(ElementoEsparso), 1, f_res_bin);
    }

    free(buffer);
    fclose(f_res_bin);
}

void binario_a_txt_resultado(const char *archivo_bin, const char *archivo_txt) {
    FILE *f_bin = fopen(archivo_bin, "rb");
    if (f_bin == NULL) {
        printf("Error al abrir el archivo binario resultado.\n");
        return;
    }

    FILE *f = fopen(archivo_txt, "w");
    if (f == NULL) {
        printf("Error al crear el archivo de texto resultado.\n");
        fclose(f_bin);
        return;
    }

    int M, P;
    fread(&M, sizeof(int), 1, f_bin);
    fread(&P, sizeof(int), 1, f_bin);

    fprintf(f, "%d %d\n", M, P);

    ElementoEsparso elem;
    while (fread(&elem, sizeof(ElementoEsparso), 1, f_bin) == 1) {
        fprintf(f, "%d %d %.2f\n", elem.fila, elem.col, elem.valor);
    }

    fclose(f_bin);
    fclose(f);
}

int main(void) {
    srand((unsigned int)time(NULL));

    int M = 1000;
    int N = 1000;
    int P = 1000;
    float densidad = 0.05f;
    
    generar_matriz_esparsa("matriz_a.txt", M, N, densidad);
    generar_matriz_esparsa("matriz_b.txt", N, P, densidad);

    txt_a_binario("matriz_a.txt", "matriz_a.bin");
    txt_a_binario("matriz_b.txt", "matriz_b.bin");

    multiplicar_y_consolidar_binario();

    binario_a_txt_resultado("matriz_resultado.bin", "matriz_axb.txt");

    return 0;
}