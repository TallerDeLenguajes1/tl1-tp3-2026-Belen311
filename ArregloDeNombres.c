#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50

int buscarPalabra(char *v[], int cant);

void mostrarPersonas(char *v[], int cant);

void buscarPorID(char *v[], int cant);

void liberarMemoria(char *v[], int cant);

int main(){
    int cant = 5, letra = 0, resultado;
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
    resultado = buscarPalabra(v, cant);

    printf("\nResultado %d", resultado);

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

void buscarPorID(char *v[], int cant){
    int id, busqueda = 0;
    
    printf("Ingrese una id: ");
    scanf("%d", &id);

    while (id < 0)
    {
        printf("Ingrese una id valida: ");
        scanf("%d", &id);
    }

    for (int i = 0; i < cant; i++)
    {
        if (id == i){
            busqueda++;
        }
    }

    if (busqueda != 0)
    {
        puts(v[id]);
    } else {
        printf("No se encontro valor buscado");
    }
    
}

void liberarMemoria(char *v[], int cant){
    for (int i = 0; i < cant; i++){
        free(v[i]);
    }
    free(v);
}

int buscarPalabra(char *v[], int cant){
    char buscar[TAM], *resultado;
    printf("Ingrese el nombre a buscar: ");
    gets(buscar);

    for (int i = 0; i < cant; i++)
    {
        resultado = strstr(v[i], buscar);
        if (resultado != NULL)
        {
            printf("Nombre encontrado %s", resultado);
            return 1;
        } else {
            return -1;
        }
    }
}