#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pilha[50];
    int qnt;
} PilhaOperacoes;


PilhaOperacoes * construtorPilha()
{
    PilhaOperacoes * pilha = (PilhaOperacoes *)malloc(sizeof(PilhaOperacoes));
    pilha->qnt = 0;
    return pilha;
}

void freePilha(PilhaOperacoes * p)
{
    free(p->pilha);
    free(p);
}

void push(PilhaOperacoes *p, char * dado)
{
    int valor = atoi(dado);
    int pos = p->qnt;
    if(valor != 0)
    {
        p->pilha[pos] = valor;
        p->qnt += 1;
        return;
    }
    if(p->qnt <=1) return;

    int valorOp = p->pilha[pos-1];
    if(dado[0] == '+')
    {
        for(int i = pos-2; i >= 0; i--)
            valorOp += p->pilha[i];
    }
    else if(dado[0] == '-')
    {
        for(int i = p->qnt-2; i >= 0; i--)
            valorOp -= p->pilha[i];
    }
    else if(dado[0] == '*')
    {
        for(int i = p->qnt-2; i >= 0; i--)
            valorOp *= p->pilha[i];
    }
    else if(dado[0] == '/')
    {
        for(int i = p->qnt-2; i >= 0; i--)
               valorOp /= p->pilha[i];
        
    }
    else
        return;
    p->pilha[0] = valorOp;
    p->qnt = 1;
}

int main() {
    PilhaOperacoes * pilha = construtorPilha();
    free(pilha);

    push(pilha, "42");
    push(pilha, "41");
    push(pilha, "40");
    push(pilha, "+");
    printf("%d\n",pilha->pilha[0]);
    push(pilha, "*");
    printf("%d\n",pilha->pilha[0]); // Aqui deve retornar o mesmo valor
    push(pilha, "2");
    push(pilha, "2");
    push(pilha, "*");
    printf("%d\n",pilha->pilha[0]); // Aqui deve quadruplicar o valor anterior
    push(pilha, "500");
    push(pilha, "-");
    printf("%d\n",pilha->pilha[0]);
    push(pilha, "16");
    push(pilha, "/");
    printf("%d\n",pilha->pilha[0]);
    
    return 0;
}

