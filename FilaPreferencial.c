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

int popFila(FilaPreferencial  * lp)
{
    if(lp == NULL || lp->qnt == 0) return NULL;
    
    int value = lp->tail->data;
    Node * auxNode = lp->tail;
    
    if(lp->qnt == 1)
    {
        lp->tail = NULL;
    }
    else
    {
        lp->tail = auxNode->next;
        lp->tail->prev = NULL;
    }
    
    free(auxNode);
    lp->qnt--;
    return value;
}

int peakFila(FilaPreferencial  * lp)
{
    if(lp == NULL || lp->qnt == 0) return NULL;
    return lp->tail->data;
}

void excluirFila(FilaPreferencial  * lp)
{
    Node * currentNode = lp->tail;
    do{
        Node * aux = currentNode;
        currentNode = currentNode->next;
        free(aux);
    }while (currentNode != NULL);
    free(lp);
}

void exibirFila(FilaPreferencial  * lp)
{
    Node * currentNode = lp->tail;
    int count = 1;
    printf("Ordem da fila: \n");
    do{
        printf("%d - Pref: %d, Val: %d\n", count, currentNode->pref, currentNode->data);
        currentNode = currentNode->next;
        count++;
    }while (currentNode != NULL);
}

void RotinaTestes()
{
    printf("=== ROTINA DE TESTES ===\n\n");
    FilaPreferencial * lp = createFilaPreferencial();
    printf("--- TESTE 1 : Instanciacao da lista -> ");
    if(lp == NULL)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");

    addFila(lp, 1,2);
    printf("--- TESTE 2 : Add simples -> ");
    if(lp ->tail->data != 1 || lp->qnt != 1)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");

    addFila(lp, 1,3);
    printf("--- TESTE 3 : Add sem alterar o head -> ");
    if(lp ->tail->data != 1 || lp->qnt != 2)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");
    
    addFila(lp, 10,1);
    printf("--- TESTE 4 : Add alterarando o head -> ");
    if(lp ->tail->data != 10 || lp->qnt != 3)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");

    printf("--- TESTE 5 : PopFila -> ");
    int aux = popFila(lp);
    if(lp ->tail->data != 1 || lp->qnt != 2 || aux != 10)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");

     printf("--- TESTE 6 : PeakFila -> ");
    aux = peakFila(lp);
    if(lp ->tail->data != 1 || lp->qnt != 2 || aux != 1)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");
    
    printf("--- TESTE 7 : Limpando a fila com pop -> ");
    aux = popFila(lp);
    aux = popFila(lp);
    aux = popFila(lp);
    if(lp ->tail != NULL || lp->qnt != 0 || aux != NULL)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");

    printf("--- TESTE 8 : Add pos limpeza -> ");
    addFila(lp, 1,1);
    if(lp ->tail->data != 1 || lp->qnt != 1)
    {
        printf("FAIL\n");
        return;
    }
    else
        printf("Ok!\n");
    printf("\n=== TESTES CONCLUIDOS COM SUCESSO! ===\n\n");
    system("pause");
    excluirFila(lp);
}

int main() {
    RotinaTestes();
    FilaPreferencial * fp = createFilaPreferencial();;
    int InputMenu = 0;
    do
    {
        printf("== MENU ==\n");
        printf("1 - Adicionar novo elemento na fila\n");
        printf("2 - Proximo da fila\n");
        printf("3 - Sair\n");
        printf("\nSelecione uma opcao: ");
        scanf(" %d", &InputMenu);

        int val = 0;
        int pref = 0;
        switch (InputMenu)
        {
        case 1:
            printf("Digite o valor da informacao: ");
            scanf(" %d", &val);
            printf("Digite a preferecia da informacao: ");
            scanf(" %d", &pref);
            addFila(fp,val,pref);
            break;
        case 2:
            val = popFila(fp);
            if(val == NULL)
                printf("Nao foi possivel encontrar um proximo da fila\n");
            else
                printf("Proximo da fila : %d\n", val);
            break;
        default:
            break;
        }
    }while (InputMenu != 3);
    

    return 0;
}

