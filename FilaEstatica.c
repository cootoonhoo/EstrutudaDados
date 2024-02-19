#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct 
{
	int * pFila;
	int * headFila;
	int posFila;
	int posHead;
} FilaController;

int * gerarFila()
{
	int * pFila = (int *)malloc(MAX_LENGTH * sizeof(int));
	return pFila;
}

FilaController * gerarControladorFila()
{
	FilaController * pController = (FilaController *) malloc(sizeof(FilaController));
	pController->pFila = gerarFila();
	pController->headFila = NULL;
	pController->posFila = 0;
	pController->posHead = 0;
	return pController;
}

void apagarFila(FilaController * pFilaController)
{
	free(pFilaController->pFila);
	free(pFilaController->headFila);
	free(pFilaController);
}

	int adicionarFila(FilaController * pFilaControler, int dado)
	{
		int posFila = pFilaControler->posFila;
		if(pFilaControler->pFila == NULL) return 0;
		if(posFila == 0)
		{
			pFilaControler->pFila[posFila] = dado;
			pFilaControler->headFila = &pFilaControler->pFila[posFila];
			pFilaControler->posFila++;
		}
		else if(posFila < 50)
		{
			if(pFilaControler->headFila == &pFilaControler->pFila[posFila])
			{
				pFilaControler->headFila = &pFilaControler->pFila[posFila+1];
				pFilaControler->posHead = posFila+1;
			}
			pFilaControler->pFila[posFila] = dado;
			pFilaControler->posFila++;
		}
		else
		{	
			pFilaControler->headFila = &pFilaControler->pFila[1];
			pFilaControler->posHead = 1;
			pFilaControler->pFila[0] = dado;	
			pFilaControler->posFila = 1;
		}
		return 1;
	}

	int peakFila(FilaController * pFilaControler)
	{
		if(pFilaControler->headFila != NULL)
			return *pFilaControler->headFila;
		return -1;
	}

	int popFila(FilaController * pFilaControler)
	{
		if(pFilaControler->posFila != 0)
		{
			int value = pFilaControler->pFila[pFilaControler->posHead];
			pFilaControler->pFila[pFilaControler->posHead] = NULL;
			if(pFilaControler->posHead == 49)
			{
				pFilaControler->headFila = &pFilaControler->pFila[0];
				pFilaControler->posHead = 0;
			}
			else
			{
				pFilaControler->headFila = &pFilaControler->pFila[pFilaControler->posHead+1];
				pFilaControler->posHead++;
			}
			return value;
		}
		return -1;
	}

void PrintarFila(FilaController * fila)
{
	printf("Fila : [");
	for(int i = 0; i < MAX_LENGTH; i++)
	{
		if(i == 0) printf(" ");
		printf("%d", fila->pFila[i]);
		if(i != MAX_LENGTH-1) printf(",");

	}
	printf(" ]\n");
}

int main() {
	FilaController * fila = gerarControladorFila();
	if(fila == NULL)
	{
		printf("Nao foi possivel alocar a fila\n");
		return -1;
	}
	// Populando fila normamlente
	for(int i = 0; i < MAX_LENGTH; i++)
	{
		adicionarFila(fila, i+1);
	}
	PrintarFila(fila);

	printf("\nPeakFila : %d\n", peakFila(fila));
	printf("PopFila : %d\n", popFila(fila));
	printf("[Pos pop] PeakFila : %d\n\n", peakFila(fila));



	// Populando fila novamente
	for(int i = 0; i < MAX_LENGTH/2; i++)
	{
		adicionarFila(fila, i%2 == 0? (i+1)*20 : (i+1)*30);
	}
	PrintarFila(fila);
	for(int i = 0; i < MAX_LENGTH/4; i++)
	{
		popFila(fila);
	}
	printf("\n[Pos multipop] PeakFila : %d\n\n", peakFila(fila));
	PrintarFila(fila);

	return 0;
}

