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
    FILE *filmes = fopen("filmes.txt", "r");
    if (filmes == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct dadosFilmes dados;

    while (fscanf(filmes, "%d %30s %d %f", &dados.id, dados.nome, &dados.anoLanc, &dados.preco) == 4){
        printf("Id: %d\n", dados.id);
        printf("Nome: %s\n", dados.nome);
        printf("Ano de Lancamento: %d\n", dados.anoLanc);
        printf("Preco: %f\n", dados.preco);
    }
    fclose(filmes);
}

void listar_cliente(){
    FILE *clientes = fopen("clientes.txt", "r");
    if (clientes == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct dadosClientes dados;

    while (fscanf(clientes, "%d %30s %d", &dados.codigo, dados.nome, &dados.idade) == 3){
        printf("Id: %d\n", dados.codigo);
        printf("Nome: %s\n", dados.nome);
        printf("Idade: %d\n", dados.idade);
    }
    fclose(clientes);
}