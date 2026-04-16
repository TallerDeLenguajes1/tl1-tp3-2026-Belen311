#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50

void mostrarPersonas(char *v[], int cant);

void liberarMemoria(char *v[], int cant);

int main(){
    int cant = 5, letra = 0;
    char *v[cant], nombre[TAM], *pNombre;
    
    for (int i = 0; i < cant; i++){
        printf("\n");
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(nombre);
        
        letra = strlen(nombre);
        pNombre = (char *)malloc((letra + 1) * sizeof(char));
        strcpy(pNombre, nombre);
        v[i] = pNombre;
    }
    
    mostrarPersonas(v, cant);
    liberarMemoria(v, cant);
    return 0;
}

void mostrarPersonas(char *v[], int cant){
    for (int i = 0; i < cant; i++){
        printf("\n");
        puts(v[i]);
        printf("\n");
    }
}

void liberarMemoria(char *v[], int cant){
    for (int i = 0; i < cant; i++){
        free(v[i]);
    }
    free(v);
}