#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void menu();

int main()
{
    // Variables locales
    struct NODE *front = NULL;
    struct NODE *tail = NULL;
    struct NODE nodo;
    int opcion = 0;

    printf("****Sistema de pedidos****\n");
    
    while(opcion != 7) {
        menu();        
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                fflush(stdin);
                printf("\nNombre del producto: ");
                scanf(" %[^\n]s", nodo.p.producto);
                fflush(stdin);
                printf("Nombre del cliente: ");
                scanf(" %[^\n]s", nodo.p.nombre);
                fflush(stdin);
                printf("Membresia (1/0): ");
                scanf("%d", &nodo.p.membresia);
                getchar();
                
                
                enqueue(&front, &tail, nodo);
                printf("\nCola de pedidos (producto, cliente, membresia): \n");
                print_queue(&front, &tail);
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;
            
            case 2:
                nodo = dequeue(&front, &tail);
                printf("\nPedido procesado (producto, cliente, membresia): \n");
                printf("%s, ", nodo.p.producto);
                printf("%s, ", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                print_queue(&front, &tail);
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;
                
            case 3:
                printf("\nCola actual: \n");
                print_queue(&front, &tail);
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;

            case 4:
                nodo = peek(&front, &tail);
                printf("\nPrimer pedido en cola: \n");
                printf("%s\n", nodo.p.producto);
                printf("%s\n", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;

            case 5:
                nodo = rear(&front, &tail);
                printf("\nUltimo pedido en cola: \n");
                printf("%s\n", nodo.p.producto);
                printf("%s\n", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;

            case 6:
                printf("\nNumero de pedidos: ");
                printf("%d", queue_size(&front, &tail));
                
                printf("\nPresione cualquier tecla para volver al menu");
                getchar();
                system("clear");
                
                break;

            case 7:
                break;
            
            default:
                printf("Opcion inexistente\n");
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("\nSeleccione una opcion:\n");
    printf("1. Registrar un pedido.\n");
    printf("2. Procesar un pedido.\n");
    printf("3. Desplegar cola de pedidos.\n");
    printf("4. Primer pedido en cola.\n");
    printf("5. Ultimo pedido en cola.\n");
    printf("6. Numero de pedidos.\n");
    printf("7. Salir\n");
}
