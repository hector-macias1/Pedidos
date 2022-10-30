#ifndef COLAS_H
#define COLAS_H

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
    struct NODE *sig, *prev;
};

// Prototipos
void enqueue(struct NODE **front, struct NODE **rear, struct NODE nodo);
struct NODE dequeue(struct NODE **front, struct NODE **rear);
int queue_isempty(struct NODE **front, struct NODE **rear);
int queue_isfull(struct NODE **front, struct NODE **rear, int limit);
int queue_size(struct NODE **front, struct NODE **rear);
struct NODE peek(struct NODE **front, struct NODE **rear);
struct NODE rear(struct NODE **front, struct NODE **rear);
void print_queue(struct NODE **front, struct NODE **rear);

#endif