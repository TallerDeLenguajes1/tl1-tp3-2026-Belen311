#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir"
};

void cargarDatos(struct Cliente *cli, int cant, char *TiposProductos[]);

void mostrarDatos(struct Cliente *cli, int cant);

float calcularCostoTotal(float precioUnitario, int cant);

void liberarMemoria(struct Cliente *cli, int cant);

int main(){
    int cant;
    float precioTotal;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    printf("Ingresar la cantidad de clientes: ");
    scanf("%d", &cant);
    struct Cliente *cli = (struct Cliente *)malloc(cant * sizeof(struct Cliente));
    cargarDatos(cli, cant, TiposProductos);
    mostrarDatos(cli, cant);
    liberarMemoria(cli, cant);
    return 0;
}

void cargarDatos(struct Cliente *cli, int cant, char *TiposProductos[]){
    char *nombre = (char *)malloc(TAM * sizeof(char));
    int letras = 0, indice = 0;
    srand(time(NULL));

    for (int i = 0; i < cant; i++)
    {
        cli[i].ClienteID = i + 1;
        //nombre del cliente
        printf("\n");
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(nombre);
        letras = strlen(nombre);
        cli[i].NombreCliente = (char *)malloc(letras + 1 * sizeof(char));
        strcpy(cli[i].NombreCliente, nombre);
        //fin pasaje de nombre
        cli[i].CantidadProductosAPedir = 1 + rand() % 5;
        cli[i].Productos = (struct Producto *)malloc(cli[i].CantidadProductosAPedir * sizeof(struct Producto));
        //struct productos
        for (int j = 0; j< cli[i].CantidadProductosAPedir; j++)
        {
            cli[i].Productos[j].ProductoID = j + 1;
            cli[i].Productos[j].Cantidad = 1 + rand() % 10;
            //asignar memoria a tipo de producto
            indice = rand() % 5;
            letras = strlen(TiposProductos[indice]);
            cli[i].Productos[j].TipoProducto = (char *)malloc(letras + 1 * sizeof(char));
            strcpy(cli[i].Productos[j].TipoProducto, TiposProductos[indice]);
            cli[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
        }
    }
}

void mostrarDatos(struct Cliente *cli, int cant){
    float precioTotal, precioUnitario, sum;
    int cantProductos;
    for (int i = 0; i < cant; i++)
    {
        sum = 0;
        printf("\n");
        printf("Numero de cliente: %d", cli[i].ClienteID);
        printf("\n");
        printf("Nombre del cliente: ");
        puts(cli[i].NombreCliente);
        printf("Cantidad de productos: %d", cli[i].CantidadProductosAPedir);
        printf("\n");
        for (int j = 0; j < cli[i].CantidadProductosAPedir; j++)
        {
            printf("\n");
            printf("Numero de producto: %d", cli[i].Productos[j].ProductoID);
            printf("\n");
            printf("Cantidad: %d", cli[i].Productos[j].Cantidad);
            printf("\n");
            printf("Tipo de producto: ");
            puts(cli[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f", cli[i].Productos[j].PrecioUnitario);
            printf("\n");
            cantProductos = cli[i].Productos[j].Cantidad;
            precioUnitario = cli[i].Productos[j].PrecioUnitario;
            precioTotal = calcularCostoTotal(precioUnitario, cantProductos);
            sum += calcularCostoTotal(precioUnitario, cantProductos);
            printf("Precio total: %.2f", precioTotal);
            printf("\n");
        }
        printf("Total a pagar: %.2f", sum);
        printf("\n");
    }
    
}

float calcularCostoTotal(float precioUnitario, int cant){
float precioTotal;
    precioTotal = precioUnitario * cant;
return precioTotal;
}

void liberarMemoria(struct Cliente *cli, int cant){
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j< cli[i].CantidadProductosAPedir; j++)
        {
            free(cli[i].Productos[j].TipoProducto);
        }
        free(cli[i].NombreCliente);
        free(cli[i].Productos);
    }
    free(cli);
}