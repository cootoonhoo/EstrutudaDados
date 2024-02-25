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
    int qnt;
} ListaCircular;


ListaCircular * createListaCircular()
{
    ListaCircular * lc = (ListaCircular *)malloc(sizeof(ListaCircular));
    if(lc == NULL) return lc;
    lc->head = NULL;
    lc->qnt = 0;
    return lc;
}

Node * createNode(int data)
{
    Node * n = (Node *)malloc(sizeof(Node));
    if(n == NULL) return n;
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void add(ListaCircular * lc, int data)
{
    if(lc == NULL) return NULL;
    Node * newNode = createNode(data);
    if(lc->qnt == 0)
    {
        lc->head = newNode;
        lc->head->prev = newNode;
        lc->head->next = newNode;
    }
    else
    {
        Node * nextNode = lc->head->next;

        newNode->next = lc->head->next; // Passo 1
        newNode->prev = lc->head->prev; // Passo 2

        nextNode->prev = newNode;
        lc->head->next = newNode;
        lc->head = newNode;
    }
    lc->qnt++;
}

int peak(ListaCircular * lc)
{
    if(lc->qnt == 0 || lc == NULL) return NULL;
    return lc->head->data;
}

int pop(ListaCircular * lc)
{
    if(lc->qnt == 0 || lc == NULL) return NULL;
    int value = lc->head->data;
    if(lc->qnt == 1)
    {
        free(lc->head);
        lc->head = NULL;
    }
    else
    {
        Node * prevNode = lc->head->prev;
        Node * nextNode = lc->head->next;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        lc->head = nextNode;
    }
    lc->qnt--;
    return value;
}

int main() {
    ListaCircular * list = createListaCircular();
    add(list, 1);
    printf("peak -> %d \n",peak(list));
    add(list, 2);
    add(list, 3);
    printf("peak -> %d \n",peak(list));
    printf("pop -> %d \n",pop(list));
    printf("peak -> %d \n",peak(list));
    return 0;
}

