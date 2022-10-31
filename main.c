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
    //int limit;
    
    while(opcion != 7) {
        menu();        
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                fflush(stdin);
                printf("\nIngrese producto: ");
                scanf("%s", nodo.p.producto);
                fflush(stdin);
                printf("Ingrese nombre: ");
                scanf("%s", nodo.p.nombre);
                fflush(stdin);
                printf("Membresia (1/0): ");
                scanf("%d", &nodo.p.membresia);
                getchar();
                
                
                enqueue(&front, &tail, nodo);
                printf("\nCola de pedidos: \n");
                print_queue(&front, &tail);
                break;
            
            case 2:
                nodo = dequeue(&front, &tail);
                printf("\nPedido culminado: \n");
                printf("%s\n", nodo.p.producto);
                printf("%s\n", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                print_queue(&front, &tail);
                break;
                
            case 3:
                printf("\nCola actual: \n");
                print_queue(&front, &tail);
                break;

            case 4:
                nodo = peek(&front, &tail);
                printf("\nPrimer pedido en cola: \n");
                printf("%s\n", nodo.p.producto);
                printf("%s\n", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                break;

            case 5:
                nodo = rear(&front, &tail);
                printf("\nUltimo pedido en cola: \n");
                printf("%s\n", nodo.p.producto);
                printf("%s\n", nodo.p.nombre);
                printf("%d\n\n", nodo.p.membresia);
                break;

            case 6:
                printf("\nNumero de pedidos: ");
                printf("%d", queue_size(&front, &tail));
                break;
            
            default:
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("\nSeleccione una opcion\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. print queue\n");
    printf("4. peek\n");
    printf("5. rear\n");
    printf("6. queue size\n");
    printf("7. Exit\n");
}
