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
void enqueue(struct NODE **front, struct NODE **tail, struct NODE nodo);
struct NODE dequeue(struct NODE **front, struct NODE **tail);
int queue_isempty(struct NODE **front, struct NODE **tail);
int queue_size(struct NODE **front, struct NODE **tail);
struct NODE peek(struct NODE **front, struct NODE **tail);
struct NODE rear(struct NODE **front, struct NODE **tail);
void print_queue(struct NODE **front, struct NODE **tail);

#endif