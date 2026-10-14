#include<stdio.h>
#include<string.h>
typedef char cadena[20];

void quitar_salto(cadena a){   // para quitar el \n que se guarda al final de las cadenasa
    size_t len = strlen(a);
    if(len>0 && a[len-1]=='\n'){
        a[len-1]='\0';
    }
}
int main(){
    
    cadena nombre;
    cadena apellido;
    int x;
    printf("Ingrese los nombres: ");
    fgets(nombre, 20, stdin);
    quitar_salto(nombre);
    //printf("ingrese x: ");
    //scanf("%d", &x);
    //getchar();
    printf("Ingresa los apellidos: ");
    fgets(apellido, 20, stdin);
    quitar_salto(apellido);


    printf("nombre: %s\n", nombre);
    printf("apellido: %s\n", apellido);

    return 0;
}