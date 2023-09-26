#include "struct.h"

void cadastrarFilme(struct dadosFilmes **filmes, int *numFilmes) {
    system("cls");
    int opcao = 1;
    
    do{
        printf("====Cadastro de Filme====\n");
        (*numFilmes)++;
        *filmes = (struct dadosFilmes *)realloc(*filmes, (*numFilmes) * sizeof(struct dadosFilmes));

        if (*filmes == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }

        (*filmes)[*numFilmes - 1].id = *numFilmes;
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]s", (*filmes)[*numFilmes - 1].nome);

        printf("Ano de Lancamento: ");
        fflush(stdin);
        scanf("%d", &(*filmes)[*numFilmes - 1].anoLanc);

        printf("Preco: ");
        fflush(stdin);
        scanf("%f", &(*filmes)[*numFilmes - 1].preco);
        system("cls"); 
        printf("Filme cadastrado com sucesso!\n");

        printf("\nDeseja cadastrar outro filme? (1 - Sim / 0 - Nao): ");
        fflush(stdin);
        scanf("%d", &opcao);
        system("cls");
    }while(opcao == 1);
}

void cadastrarCliente(struct dadosClientes **clientes, int *numClientes) {
    system("cls");
    int opcao = 1;
    
    do{
        printf("====Cadastro de Cliente====\n");
        (*numClientes)++;
        *clientes = (struct dadosClientes *)realloc(*clientes, (*numClientes) * sizeof(struct dadosClientes));

        if (*clientes == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }

        (*clientes)[*numClientes - 1].codigo = *numClientes;
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]s", (*clientes)[*numClientes - 1].nome);
        
        printf("Idade: ");
        fflush(stdin);
        scanf("%d", &(*clientes)[*numClientes - 1].idade);
        system("cls");
        printf("Cliente cadastrado com sucesso!\n");

        printf("\nDeseja cadastrar outro cliente? (1 - Sim / 0 - Nao): ");
        fflush(stdin);
        scanf("%d", &opcao);    
        system("cls");    
    }while(opcao == 1);
}


