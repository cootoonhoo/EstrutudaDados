#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    void * next;
    void * prev;
} Node;

typedef struct
{
    Node * head;
    Node * tail;
    int qnt;
} Lista;

Lista * createLista()
{
    Lista * p = (Lista *)malloc(sizeof(Lista));
    if (p == NULL) return NULL;
    p->head = NULL;
    p->tail = NULL;
    p->qnt = 0;
    return p;
}

Node * createNode(int data)
{
    Node * n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void push(Lista * lst, int data)
{
    if(lst == NULL) return;
    Node * newNode = createNode(data);
    if(lst->qnt == 0)
    {
        lst->head = newNode;
        lst->tail = newNode;
        lst->qnt += 1;
        return;
    }
    else
    {
        lst->head->next = newNode;
        newNode->prev = lst->head;
        lst->head = newNode;
         lst->qnt += 1;
    }
}

int pop(Lista * lst)
{
    if(lst->qnt == 0) return NULL;
    int data = lst->head->data;
    if(lst->qnt == 1)
    {
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        
    }
    else
    {
        Node * p = lst->head;
        lst->head = lst->head->prev;
        lst->head->next = NULL;
        free(p);
    }
    lst->qnt--;
    return data;
}

int peak(Lista * lst)
{
    if(lst == NULL || lst->qnt == 0) return NULL;
    return lst->head->data;
}

int main() {
    Lista *p = createLista();
    push(p, 10);
    printf("peak : %d\n", peak(p));
    push(p,15);
    printf("peak : %d\n", peak(p));
    printf("pop : %d\n", pop(p));
    printf("peak : %d\n", peak(p));
    return 0;
}

