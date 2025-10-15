#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 1000

typedef unsigned short us;



typedef struct tipoNoFila{
    int dado;
    struct tipoNoFila *proximo;
} tipoNoFila;

typedef struct tipoFila{
    tipoNoFila *inicio;
    tipoNoFila *fim;
} tipoFila;


typedef struct tipoNoPilha{
    int dado;
    struct tipoNoPilha *proximo;
} tipoNoPilha;

typedef struct tipoPilha{
    tipoNoPilha *topo;
} tipoPilha;


typedef struct tipoFilaPrioridade{
    int dado;
    int prioridade;
} tipoFilaPrioridade;

typedef struct _tipoFilaPrioridade{
    int qtd;
    struct tipoFilaPrioridade dados[MAXSIZE];
} _tipoFilaPrioridade;


void inicializaFila(tipoFila *);
void inserirFila(tipoFila *, int);
int frenteFila(tipoFila *);
void removerFila(tipoFila *);


void inicializaPilha(tipoPilha *);
void inserirPilha(tipoPilha *, int);
void removerPilha(tipoPilha *);
int topoPilha(tipoPilha *);


_tipoFilaPrioridade* criarFilaPrioridade();
void inserirFilaPrioridade(_tipoFilaPrioridade *, int, int );
void removerFilaPrioridade(_tipoFilaPrioridade *);
int frenteFilaPrioridade(_tipoFilaPrioridade *);
void balancearRemocao(_tipoFilaPrioridade *, int);
void balancearInsercao(_tipoFilaPrioridade *, int);

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int x, comando, i;
        _Bool fila, pilha, fila_prioridade;
        _tipoFilaPrioridade *fila_prioridade_ = criarFilaPrioridade();
        tipoFila fila_;
        tipoPilha pilha_;

        inicializaFila(&fila_);
        inicializaPilha(&pilha_);

        fila = pilha = fila_prioridade = true;
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &comando, &x);
            if (comando == 1)
            {
                inserirFilaPrioridade(fila_prioridade_, x, x);
                inserirPilha(&pilha_, x);
                inserirFila(&fila_, x);
            }
            else
            {
                if (topoPilha(&pilha_) != x)
                    pilha = false;
                else
                    removerPilha(&pilha_);
                
                if (frenteFila(&fila_) != x)
                    fila = false;
                else
                    removerFila(&fila_);

                if (frenteFilaPrioridade(fila_prioridade_) != x)
                    fila_prioridade = false;
                else
                    removerFilaPrioridade(fila_prioridade_);
            }
        }
        if (!pilha && !fila && !fila_prioridade)
            printf("impossible\n");
        else if (pilha && fila_prioridade)
            printf("not sure\n");
        else if (pilha && fila)
            printf("not sure\n");
        else if (fila_prioridade && fila)
            printf("not sure\n");
        else if (fila_prioridade)
            printf("priority queue\n");
        else if (fila)
            printf("queue\n");
        else if (pilha)
            printf("stack\n");
    }
    return 0;
}

void inicializaFila(tipoFila *fila)
{
    fila->inicio = fila->fim = NULL;
}

void inserirFila(tipoFila *fila, int x)
{
    tipoNoFila *auxiliar;
    auxiliar = (tipoNoFila *) malloc(sizeof(tipoNoFila));
    if (!auxiliar)
        exit(1);
    if (fila->inicio)
    {
        fila->fim->proximo = auxiliar;
        auxiliar->proximo = NULL;
    }
    else
        fila->inicio = auxiliar;
    fila->fim = auxiliar;
    auxiliar->dado = x;
}

void removerFila(tipoFila *fila)
{
    tipoNoFila *auxiliar;
    if (fila->inicio)
    {
        if (fila->inicio->proximo)
        {
            auxiliar = fila->inicio;
            fila->inicio = fila->inicio->proximo;
            free(auxiliar);
            return;
        }
        else
        {
            auxiliar = fila->inicio;
            fila->inicio = fila->fim = NULL;
            free(auxiliar);
            return;
        }
    }
    else
        return;
}

int frenteFila(tipoFila *fila)
{
    return fila->inicio->dado;
}

void inicializaPilha(tipoPilha *pilha)
{
    pilha->topo = NULL;
}

int topoPilha(tipoPilha *pilha)
{
    return pilha->topo->dado;
}

void removerPilha(tipoPilha *pilha)
{
    tipoNoPilha *auxiliar;
    auxiliar = pilha->topo;
    if (auxiliar)
    {
        pilha->topo = auxiliar->proximo;
        free(auxiliar);
    }
}

void inserirPilha(tipoPilha *pilha, int x)
{
    tipoNoPilha *auxiliar;
    auxiliar = (tipoNoPilha *) malloc(sizeof(tipoNoPilha));
    if (!auxiliar)
        exit(1);
    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
    auxiliar->dado = x;
}

void inserirFilaPrioridade(_tipoFilaPrioridade *filaP, int prioridade, int id)
{
    if (filaP == NULL)
        exit(1);
    if (filaP->qtd == MAXSIZE)
        exit(1);
    filaP->dados[filaP->qtd].dado = id;
    filaP->dados[filaP->qtd].prioridade = prioridade;
    balancearInsercao(filaP, filaP->qtd);
    ++filaP->qtd;
}

void balancearInsercao(_tipoFilaPrioridade *filaP, int filho)
{
    int pai;
    tipoFilaPrioridade tmp;
    pai = (filho - 1) / 2;
    while ((filho > 0) && (filaP->dados[pai].prioridade <= filaP->dados[filho].prioridade))
    {
        tmp = filaP->dados[filho];
        filaP->dados[filho] = filaP->dados[pai];
        filaP->dados[pai] = tmp;
        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int frenteFilaPrioridade(_tipoFilaPrioridade *filaP)
{
    if (filaP == NULL || filaP->qtd == 0)
        return 0;
    return filaP->dados[0].dado;
}

_tipoFilaPrioridade* criarFilaPrioridade()
{
    _tipoFilaPrioridade *filaP;
    filaP = (_tipoFilaPrioridade *) malloc(sizeof(_tipoFilaPrioridade));
    if (filaP)
        filaP->qtd = 0;
    return filaP;
}

void removerFilaPrioridade(_tipoFilaPrioridade *filaP)
{
    if (filaP == NULL)
        exit(1);
    if (filaP->qtd == 0)
        exit(1);
    --filaP->qtd;
    filaP->dados[0] = filaP->dados[filaP->qtd];
    balancearRemocao(filaP, 0);
}

void balancearRemocao(_tipoFilaPrioridade *filaP, int pai)
{
    int filho;
    tipoFilaPrioridade tmp;
    filho = 2 * pai + 1;
    while (filho < filaP->qtd)
    {
        if (filho < filaP->qtd - 1)
            if (filaP->dados[filho].prioridade < filaP->dados[filho + 1].prioridade)
                ++filho;
        if (filaP->dados[pai].prioridade >= filaP->dados[filho].prioridade)
            break;
        tmp = filaP->dados[pai];
        filaP->dados[pai] = filaP->dados[filho];
        filaP->dados[filho] = tmp;
        pai = filho;
        filho = 2 * pai + 1;
    }
}
