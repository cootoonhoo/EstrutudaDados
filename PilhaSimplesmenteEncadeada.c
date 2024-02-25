#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node * prev;
} Node;

typedef struct
{
    Node * head;
    int qnt;
} Pilha;

Node * creatNode(int data)
{
    Node * n = (Node *)malloc(sizeof(Node));
    if(n == NULL) return n;
    n->data = data;
    n->prev = NULL;
}

Pilha * createPilha()
{
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    if(p == NULL) return p;
    p->qnt = 0;
    p->head = NULL;
}

int pop(Pilha * p)
{
    if(p == NULL) return NULL;
    int value = p->head->data;
    if(p->qnt == 0)
    {
        free(p->head);
        p->head = NULL;
    }
    else
    {
        Node * aux = p->head;
        p->head = p->head->prev;
        free(aux);
    }
    p->qnt--;
    return value;
}

int peak(Pilha *p)
{
    if(p == NULL) return NULL;
    return p->head->data;
}

void add(Pilha * p, int data)
{
    if(p == NULL) return;
    Node * newNode = creatNode(data);
    newNode->prev = p->head;
    p->head = newNode;
    p->qnt++;
}

int main() {
    Pilha * pilha = createPilha();
    add(pilha,10);
    add(pilha,11);
    add(pilha,12);
    add(pilha,13);
    add(pilha,14);
    printf("Qnt [%d] -> %d\n", pilha->qnt, pop(pilha));
    printf("Qnt [%d] -> %d\n", pilha->qnt, pop(pilha));
    printf("Qnt [%d] -> %d\n", pilha->qnt, pop(pilha));
    printf("Qnt [%d] -> %d\n", pilha->qnt, pop(pilha));
    printf("Qnt [%d] -> %d\n", pilha->qnt, pop(pilha));
    return 0;
}

