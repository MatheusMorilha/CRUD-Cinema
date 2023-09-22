#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"
#include "Cadastro.h"

void Listar();
void listar_filme();
void listar_cliente();

void Listar(){
    int listar;

    printf("\n=========== Listar =============\n");
    printf("|  [1] - Listar Filme            |\n");
    printf("|  [2] - Listar Cliente          |\n");
    printf("|  [3] - Voltar Menu Principa    |\n");
    printf("==================================\n");
    printf("Digite a opcao desejada: ");
    fflush(stdin);
    scanf("%d", &listar);

    switch (listar)
    {
    case 1:
        listar_filme();
        break;
    
    case 2:
        listar_cliente();
        break;
    default:
        break;
    }
}

void listar_filme(){
    // FILE *filmes = fopen("filmes.txt", "r");
    // if (filmes == NULL)
    // {
    //     printf("Erro ao abrir o arquivo.\n");
    //     return;
    // }

    for(int i = 0; i < *tamanhoMaxFilme; i++){
        printf("Id: %i\n", dadosFilmes[i].id)
        printf("Nome: %s\n", dadosFilmes[i].nome);
        printf("Ano de Lancamento: %i\n", dadosFilmes[i].anoLanc);
        printf("Preco: %.2f\n", dadosFilmes[i].preco);
    }

    
}

void listar_cliente(){}