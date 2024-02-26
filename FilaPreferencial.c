#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int pref;
    void * next;
    void * prev;

} Node;

typedef struct
{
    Node * tail;
    int qnt;
} FilaPreferencial;

FilaPreferencial * createFilaPreferencial()
{
    FilaPreferencial  * lp = (FilaPreferencial *)malloc(sizeof(FilaPreferencial));
    if(lp == NULL) return NULL;

    lp->qnt = 0;
    lp->tail = NULL;
}

Node * createNode(int data, int pref)
{
    Node  * n = (Node *)malloc(sizeof(Node));
    if(n == NULL) return NULL;
    n->data = data;
    n->pref = pref;
    n->next = NULL;
    n->prev = NULL;
}

void addFila(FilaPreferencial  * lp, int data, int pref)
{
    if(lp== NULL ) return NULL;
    Node * newNode = createNode(data,pref);
    if(lp->qnt == 0)
    {
        lp->tail = newNode;
    }
    else
    {
        Node * currentNode = lp->tail;
        while (1)
        {
            printf("If: %d,%d\n",newNode->pref , currentNode->pref);
            if(newNode->pref < currentNode->pref)
            {
                Node * prevNode = currentNode->prev;
                if(prevNode !=NULL)
                {
                prevNode->next = newNode;
                newNode->prev = prevNode;
                }
                else
                {
                    lp->tail = newNode;
                }

                currentNode->prev = newNode;
                newNode->next = currentNode;
                break;
            }
            if(currentNode->next == NULL)
            {
                currentNode->next = newNode;
                break;
            }
            else
            {
                currentNode = currentNode->next;
                if(currentNode == NULL) break;
            }
        }
    }
    lp->qnt++;
}

void exibirFila(FilaPreferencial  * lp)
{
    Node * currentNode = lp->tail;
    int count = 1;
    do{
        currentNode = currentNode->next;
        count++;
    }while (currentNode != NULL);
}

void RotinaTestes(FilaPreferencial  * lp)
{
    addFila(lp, 1,2);
    addFila(lp, 1,3);
    addFila(lp, 1,1);
    addFila(lp, 2,1);
    addFila(lp, 1,4);
    exibirFila(lp);
}

int main() {
    FilaPreferencial  * lp = createFilaPreferencial();
    RotinaTestes(lp);
    return 0;
}

