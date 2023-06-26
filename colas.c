#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pedido
struct pedido
{
    char nombre[50];
    char producto[50];
    int membresia;
};

// Nodo
struct NODE
{
    struct pedido p;
    struct NODE *next;
};

void enqueue(struct NODE **front, struct NODE **tail, struct NODE nodo)
{
    // Crear nuevo nodo
    struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));
    
    // Nodos auxiliares
    struct NODE *temp;
    
    // Verificar si hay memoria disponible
    if (!newNode) {
        printf("\nMemory Error\n");
        return;
    }

    // Insertar datos en el nodo
    strcpy(newNode->p.producto, nodo.p.producto);
    strcpy(newNode->p.nombre, nodo.p.nombre);
    newNode->p.membresia = nodo.p.membresia;

    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail)) {
        // El nuevo nodo no tiene nodos al lado
        newNode->next = NULL;

        // front y rear apuntan al nuevo nodo
        *front = *tail = newNode;
        return;
    }
    
    // Verificar si el nodo tiene prioridad sobre el primero
    if((*front)->p.membresia != 1 && nodo.p.membresia != (*front)->p.membresia) {
        newNode->next = *front;
        *front = newNode;
        return;
    }
    
    //Verificar la prioridad del nodo
    if(nodo.p.membresia == 1) {
        temp = *front;
        while(temp->next != NULL && temp->next->p.membresia != 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
    
    // Insertar el nodo al final de la cola
    (*tail)->next = newNode;
    *tail = newNode;
}

struct NODE dequeue(struct NODE **front, struct NODE **tail)
{
    // Var local para almacenar los datos del nodo a eliminar
    struct NODE node;

    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail))
        return node;

    // Crear un nodo temporal
    struct NODE *temp;

    // Iniciar temp en front
    temp = *front;

    // Insertar datos de temp en variable local
    strcpy(node.p.producto, temp->p.producto);
    strcpy(node.p.nombre, temp->p.nombre);
    node.p.membresia = temp->p.membresia;

    // front ahora apunta al segundo nodo de la cola
    *front = (*front)->next;

    // Si frente apunta a nulo, tambien rear (cola vacia).
    if(*front == NULL)
        *tail = NULL;

    // Eliminar el primer nodo
    free(temp);

    // Retornar datos del nodo eliminado
    return node;
}

int queue_isempty(struct NODE **front, struct NODE **tail)
{
    if(*front == NULL && *tail == NULL) {
        printf("\nQueue is empty\n");
        return 1;
    }
    return 0;
}

int queue_size(struct NODE **front, struct NODE **tail)
{
    // Variables locales
    int count = 0;
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail))
        return 0;

    // Recorrer cola y contar
    while(temp) {
        temp = temp->next;
        count++;
    }

    return count;
}

struct NODE peek(struct NODE **front, struct NODE **tail)
{
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail))
        return *temp;
    
    // Retornar primer elemento
    return *temp;
}

struct NODE rear(struct NODE **front, struct NODE **tail)
{
    struct NODE *temp = *tail;
    
    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail))
        return *temp;

    // Retornar ultimo elemento
    return *temp;
}

void print_queue(struct NODE **front, struct NODE **tail)
{
    int i = 0;
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(front, tail))
        return;
    
    // Imprimir lista
    while(temp) {
        i++;
        fflush(stdin);
        printf("\nPedido %d: %s, ", i, temp->p.producto);
        printf("%s, ", temp->p.nombre);
        printf("%d", temp->p.membresia);
        temp = temp->next;
    }
    printf("\n\n");
}
