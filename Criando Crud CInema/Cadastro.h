#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"


void cadastrarCliente(struct dadosClientes **clientes, int *numClientes) {
    printf("Cadastro de Cliente:\n");

    (*numClientes)++;
    *clientes = (struct dadosClientes *)realloc(*clientes, (*numClientes) * sizeof(struct dadosClientes));

    if (*clientes == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    (*clientes)[*numClientes - 1].codigo = *numClientes;
    printf("Nome: ");
    scanf("%s", (*clientes)[*numClientes - 1].nome);

    printf("Idade: ");
    scanf("%d", &(*clientes)[*numClientes - 1].idade);

    printf("Cliente cadastrado com sucesso!\n");
}

void cadastrarFilme(struct dadosFilmes **filmes, int *numFilmes) {
    printf("Cadastro de Filme:\n");

    (*numFilmes)++;
    *filmes = (struct dadosFilmes *)realloc(*filmes, (*numFilmes) * sizeof(struct dadosFilmes));

    if (*filmes == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    (*filmes)[*numFilmes - 1].id = *numFilmes;
    printf("Nome: ");
    scanf("%s", (*filmes)[*numFilmes - 1].nome);

    printf("Ano de Lancamento: ");
    scanf("%d", &(*filmes)[*numFilmes - 1].anoLanc);

    printf("Preco: ");
    scanf("%f", &(*filmes)[*numFilmes - 1].preco);

    printf("Filme cadastrado com sucesso!\n");
}
