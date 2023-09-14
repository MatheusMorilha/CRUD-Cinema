#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"

void Cadastrar();
void cadastrar_Filme();
void cadastrar_Cliente();

void Cadastrar(){
    int cadastrar;

    printf("\n=========== Cadastrar =============\n");
    printf("|  [1] - Cadastrar Filme            |\n");
    printf("|  [2] - Cadastrar Cliente          |\n");
    printf("|  [3] - Voltar Menu Principal      |\n");
    printf("====================================\n");
    printf("Digite a opcao desejada: ");
    fflush(stdin);
    scanf("%d", &cadastrar);

    switch (cadastrar)
    {
    case 1:
        cadastrar_Filme();
        break;
    
    case 2:
        cadastrar_Cliente();
        break;
    default:
        break;
    }
}

void cadastrar_Filme () {
    printf("\n\n----Cadastro Filmes---\n");
    int tamanhoMaxFilme = 1;
    int tamanhoAtualFilme = 0;

    struct dadosFilmes *filmes = (struct dadosFilmes *) malloc (tamanhoMaxFilme * sizeof(struct dadosFilmes));

    if(filmes == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    FILE *arquivo = fopen("filmes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }


    while(1){
        filmes[tamanhoAtualFilme].id = tamanhoAtualFilme;
        getchar();
        printf("Nome: ");
        gets(filmes[tamanhoAtualFilme].nome);

        printf("Ano Lancamento: ");
        scanf("%i", &filmes[tamanhoAtualFilme].anoLanc);

        printf("Preco: ");
        scanf("%f", &filmes[tamanhoAtualFilme].preco);

        fprintf(arquivo, "Id: %i\nNome: %s\nAno Lancamento: %d\nPreco: %.2f\n\n",filmes[tamanhoAtualFilme].id, filmes[tamanhoAtualFilme].nome, filmes[tamanhoAtualFilme].anoLanc, filmes[tamanhoAtualFilme].preco);

        tamanhoAtualFilme++;

        if (tamanhoAtualFilme >= tamanhoMaxFilme) {
            
            tamanhoMaxFilme *= 2;
            filmes = (struct dadosFilmes *)realloc(filmes, tamanhoMaxFilme * sizeof(struct dadosFilmes));

            if (filmes == NULL) {
                printf("Erro na alocacao de memoria.\n");
                fclose(arquivo); 
                return;
            }
        }

        printf("\nDeseja cadastrar outro filme? (1 - Sim / 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 0) {
            break;
        }
    }
        fclose(arquivo);
        free(filmes);
        
}

void cadastrar_Cliente () {
    printf("\n\n----Cadastro Clientes---\n");
    int tamanhoMaxCliente = 1;
    int tamanhoAtualCliente = 0;

    struct dadosClientes *clientes = (struct dadosClientes *) malloc (tamanhoMaxCliente * sizeof(struct dadosClientes));

    if(clientes == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }



    while(1){
        clientes[tamanhoAtualCliente].codigo = tamanhoAtualCliente;
        getchar();
        printf("Nome: ");
        gets(clientes[tamanhoAtualCliente].nome);

        printf("Idade: ");
        scanf("%i", &clientes[tamanhoAtualCliente].idade);

        fprintf(arquivo,"Codigo: %i\nNome: %s\nIdade: %d\n\n", clientes[tamanhoAtualCliente].codigo, clientes[tamanhoAtualCliente].nome, clientes[tamanhoAtualCliente].idade);

        tamanhoAtualCliente++;

        if (tamanhoAtualCliente >= tamanhoMaxCliente) {
            // Alocar mais memória usando realloc se necessário
            tamanhoMaxCliente *= 2;
            clientes = (struct dadosClientes *)realloc(clientes, tamanhoMaxCliente * sizeof(struct dadosClientes));

            if (clientes == NULL) {
                printf("Erro na alocacao de memoria.\n");
                fclose(arquivo); // Certifique-se de fechar o arquivo antes de sair
                return;
            }
        }

        printf("\nDeseja cadastrar outro cliente? (1 - Sim / 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 0) {
            break;
        }
    }
        fclose(arquivo);
        free(clientes);
}




