#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un pedido
struct pedido
{
    char nombre[50];
    char producto[50];
    int membresia;
};

// Estructura de un nodo
struct NODE
{
    struct pedido p;
    struct NODE *next;
};

// Funciones
void enqueue(struct NODE **front, struct NODE **rear, struct NODE nodo)
{
    // Crear nuevo nodo
    struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));
    
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
    if(queue_isempty(*front, *rear)) {
        // El nuevo nodo no tiene nodos al lado
        newNode->next = NULL;

        // front y rear apuntan al nuevo nodo
        *front = *rear = newNode;
        return;
    }

    // Insertar el nodo al final de la cola
    (*rear)->next = newNode;
    *rear = newNode;
}

struct NODE dequeue(struct NODE **front, struct NODE **rear)
{
    // Var local para almacenar los datos del nodo a eliminar
    struct NODE node;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return;

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
        *rear = NULL;

    // Eliminar el primer nodo
    free(temp);

    // Retornar datos del nodo eliminado
    return node;
}

int queue_isempty(struct NODE **front, struct NODE **rear)
{
    if(*front == NULL && *rear == NULL) {
        printf("\nQueue is empty\n");
        return 1;
    }
    return 0;
}

int queue_isfull(struct NODE **front, struct NODE **rear, int limit)
{
    // Variables locales
    int count = 0;
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return 0;

    // Recorrer cola y contar
    while(temp) {
        temp = temp->next;
        count++;
    }

    // Verificar si la lista esta llena
    if(count >= limit) {
        printf("\nQueue is full\n");
        return 1;
    }
    return 0;
}

int queue_size(struct NODE **front, struct NODE **rear)
{
    // Variables locales
    int count = 0;
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return 0;

    // Recorrer cola y contar
    while(temp) {
        temp = temp->next;
        count++;
    }

    return count;
}

struct NODE peek(struct NODE **front, struct NODE **rear)
{
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return;
    
    // Retornar primer elemento
    return *temp;
}

struct NODE rear(struct NODE **front, struct NODE **rear)
{
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return;

    // Recorrer cola
    while(temp) {
        temp = temp->next;
    }

    // Retornar ultimo elemento
    return *temp;
}

void print_queue(struct NODE **front, struct NODE **rear)
{
    struct NODE *temp = *front;

    // Verificar si la cola esta vacia
    if(queue_isempty(*front, *rear))
        return;
    
    // Imprimir lista
    while(temp) {
        fflush(stdin);
        printf("%s, ", temp->p.producto);
        printf("%s\n", temp->p.nombre);
        temp = temp->next;
    }
    printf("\n\n");
}
