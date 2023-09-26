// Willian Grupo 02 ficou com a parte de alterar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void alterar_Filme();
void alterar_Cliente();
void lerArquivo(const char *lista);
int buscar_ID(const char *lista, int id);

int AlterarDados()
{
    system("cls");
    int menuAlterar; // SubMenu do alterar

    do
    {
        printf("\n=========== Menu Alterar =============\n");
        printf("|  [1] - Alterar Filme                 |\n");
        printf("|  [2] - Listar Filmes                 |\n");
        printf("|  [3] - Alterar Cliente               |\n");
        printf("|  [4] - Listar Clientes               |\n");
        printf("|  [5] - Voltar Menu Principal         |\n");
        printf("========================================\n");
        printf("Digite a opcao desejada: ");
        fflush(stdin);

        scanf("%d", &menuAlterar);

        switch (menuAlterar)
        {
        case 1:
            alterar_Filme();
            break;

        case 2:
            system("cls");
            printf("\n\nLista Atualizada Filmes: \n");
            lerArquivo("filmes.txt");
            break;

        case 3:
            alterar_Cliente();
            break;

        case 4:
            system("cls");
            printf("\n\nLista Atualizada Clientes: \n");
            lerArquivo("clientes.txt");
            break;

        case 5:
            printf("Voltando ao menu principal...\n");
            // Adicione opção para voltar ao menu principal
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
        fflush(stdin);
    } while (menuAlterar != 5);

    return 0;
}

// Função para fazer a leitura todos os dados de um arquivo de texto
void lerArquivo(const char *lista)
{
    FILE *arquivo = fopen(lista, "r");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }
    printf("\nRelatorio Acima, use o scroll!\n\n");

    fclose(arquivo);
}

// Função para buscar um ID em um arquivo e mostrar os dados para alterar mostrando o antes da alteração.
int buscar_ID(const char *lista, int id)
{
    FILE *arquivo = fopen(lista, "r");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }

    char linha[1000];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int idLido;
        if (sscanf(linha, "id : %d", &idLido) == 1 && idLido == id)
        {
            printf("\nDados antes da alteracao:\n");
            printf("%s", linha); // Mostrar os dados antes da alteração

            for (int i = 1; i < 3; i++)
            {
                if (fgets(linha, sizeof(linha), arquivo) != NULL)
                {
                    printf("%s", linha); // Mostrar a linha
                }
            }

            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado)
    {
        printf("Erro: Cliente com ID %d não encontrado no arquivo.\n", id);
    }

    return encontrado;
}
// Função faz a alteração conforme o id do filme
void alterar_Filme()
{
    int id;
    printf("Digite o ID do filme que deseja alterar: ");
    scanf("%d", &id);

    if (!buscar_ID("filmes.txt", id))
    {
        printf("Filme com ID %d nao encontrado.\n", id);
        return;
    }

    printf("\n\n----Alterar Filme----\n");

    FILE *file = fopen("filmes.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[1000];
    int encontrou = 0;
    long int posicaoAtual;

    while (fgets(linha, sizeof(linha), file) != NULL)
    {
        if (encontrou)
        {
            break; // Já encontrou os dados do filme, pode sair do loop
        }

        int idLido;
        if (sscanf(linha, "id : %d", &idLido) == 1 && idLido == id)
        {
            encontrou = 1;
            posicaoAtual = ftell(file);
        }
    }

    if (!encontrou)
    {
        printf("Erro: Filme com ID %d nao encontrado no arquivo.\n", id);
        fclose(file);
        return;
    }

    fseek(file, posicaoAtual, SEEK_SET);

    struct dadosFilmes *filme = (struct dadosFilmes *)malloc(sizeof(struct dadosFilmes));
    if (filme == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        fclose(file);
        return;
    }

    getchar(); // Limpar o buffer do teclado

    printf("Digite o novo nome do filme: ");
    fgets(filme->nome, sizeof(filme->nome), stdin);
    filme->nome[strcspn(filme->nome, "\n")] = '\0';

    printf("Digite o novo ano de lancamento: ");
    scanf("%d", &filme->anoLanc);

    printf("Digite o novo preco: ");
    scanf("%f", &filme->preco);

    fprintf(file, "Nome do filme: %s\n", filme->nome);
    fprintf(file, "Ano de lancamento: %d\n", filme->anoLanc);
    fprintf(file, "Preco: %.2f\n", filme->preco);

    printf("\nDados do filme atualizados com sucesso!\n");
    fclose(file);
    free(filme);
}

void alterar_Cliente()
{
    int id;
    printf("Digite o ID do cliente que deseja alterar: ");
    scanf("%d", &id);

    if (!buscar_ID("clientes.txt", id))
    {
        printf("Cliente com ID %d não encontrado.\n", id);
        return;
    }

    printf("\n\n----Alterar Cliente----\n");

    FILE *file = fopen("clientes.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[1000];
    int encontrou = 0;
    long int posicaoAtual;

    while (fgets(linha, sizeof(linha), file) != NULL)
    {
        if (encontrou)
        {
            break; // Já encontrou os dados do cliente, pode sair do loop
        }

        int idLido;
        if (sscanf(linha, "id : %d", &idLido) == 1 && idLido == id)
        {
            encontrou = 1;
            posicaoAtual = ftell(file);
        }
    }

    if (!encontrou)
    {
        printf("Erro: Cliente com ID %d nao encontrado no arquivo.\n", id);
        fclose(file);
        return;
    }

    fseek(file, posicaoAtual, SEEK_SET);

    char nomeCliente[100];
    int idade;

    printf("Digite o novo nome do cliente: ");
    getchar();
    fgets(nomeCliente, sizeof(nomeCliente), stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

    printf("Digite a nova idade do cliente: ");
    scanf("%d", &idade);

    fprintf(file, "Nome do cliente: %s\n", nomeCliente);
    fprintf(file, "Idade do cliente: %d\n", idade);

    printf("\nDados do cliente atualizados com sucesso!\n");
    fclose(file);
}
