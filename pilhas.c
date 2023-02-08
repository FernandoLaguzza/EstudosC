#include <stdio.h>
#include <stdlib.h>

typedef struct st_pilha
{
    int valor;
    struct st_pilha *prox;
}pilha;

pilha* empilhar(pilha *topo, int num)
{
    pilha *novo = malloc(sizeof(pilha));

    if(novo)
    {
        novo->valor = num;
        novo->prox = topo;
        return novo;
    }
    else
        printf("Erro ao alocar memoria\n");
    return NULL;
}

pilha* desempilhar(pilha **topo) //ponteiro para ponteiro poque topo é um ponteiro para o topo da pilha. Desempilhar aponta para o ponteiro *topo.
{
    pilha *remover = NULL;

    if(*topo)
    {
        remover = *topo;
        *topo = remover->prox;
        free(remover);
    }
    else
        printf("Pilha vazia.\n");
    return remover;
}

void imprimir(pilha *topo)
{
    printf("\n\t---Pilha---\n");
    while(topo)
    {
        printf("\t%d\n", topo->valor);
        topo = topo->prox;
    }

}

int main()
{
    int opcao = 0, valor = 0, tamanho = 0;
    pilha *topo = NULL;

    do
    {
        printf("\n-- Selecione uma opcao --\n");
        printf("\n 1 - empilhar\n 2 - desempilhar\n 3 - tamanho da pilha\n 4 - imprimir pilha\n 5 - sair\n\n");
        scanf("%i", &opcao); // Escolha de opcao
        getchar(); //limpa Buffer

        switch(opcao)
        {
            case 1:
                printf("\nInsira um valor: ");
                scanf("%d", &valor);
                topo = empilhar(topo, valor);
                tamanho++;
                break;
            case 2:
                desempilhar(&topo);
                tamanho--;
                break;
            case 3:
                printf("\n A pilha tem %i elementos \n", tamanho);
                break;
            case 4:
                imprimir(topo);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("\nOpcao invalida\n");
        }
    }while(opcao != 5);

    return 0;
}
