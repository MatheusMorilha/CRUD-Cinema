// Vitor Grupo 02 ficou com a parte de Excluir.

#include "struct.h"

void excluirFilme(struct dadosFilmes **filmes, int *numFilmes) {
    system("cls");
    int id;
    system("cls");
    printf("\nDigite o ID do filme que deseja excluir: ");
    scanf("%d", &id);
    
    if (id >= 1 && id <= *numFilmes) {
        for (int j = id - 1; j < (*numFilmes) - 1; j++) {
            strcpy((*filmes)[j].nome, (*filmes)[j + 1].nome);
            (*filmes)[j].anoLanc = (*filmes)[j + 1].anoLanc;
            (*filmes)[j].preco = (*filmes)[j + 1].preco;
        }
        (*numFilmes)--;
        *filmes = (struct dadosFilmes *)realloc(*filmes, (*numFilmes) * sizeof(struct dadosFilmes));
        system("cls");
        printf("\nFilme excluido com sucesso!\n");
    } else {
        system("cls");
        printf("ID de filme nao encontrado.\n");
    }
}

void excluirCliente(struct dadosClientes **clientes, int *numClientes) {
    system("cls");
    int id;
    printf("\nDigite o ID do cliente que deseja excluir: ");
    scanf("%d", &id);
    
    if (id >= 1 && id <= *numClientes) {
        for (int j = id - 1; j < (*numClientes) - 1; j++) {
            strcpy((*clientes)[j].nome, (*clientes)[j + 1].nome);
            (*clientes)[j].idade = (*clientes)[j + 1].idade;
        }
        (*numClientes)--;
        *clientes = (struct dadosClientes *)realloc(*clientes, (*numClientes) * sizeof(struct dadosClientes));
        system("cls");
        printf("Cliente excluido com sucesso!\n");
    } else {
        system("cls");
        printf("ID de cliente nao encontrado.\n");
    }
}