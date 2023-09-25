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
            main();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

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
    return encontrado;
}

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

    printf("\n\n----Alterar Filmes---\n");
    int tamanhoMaxFilme = 10; // Alocar espaço para 10 filmes inicialmente
    int tamanhoAtualFilme = 0;

    struct dadosFilmes *filmes = (struct dadosFilmes *)malloc(tamanhoMaxFilme * sizeof(struct dadosFilmes));

    if (filmes == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    FILE *arquivo = fopen("filmes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        free(filmes);
        return;
    }

    FILE *novoArquivo = fopen("temp_filmes.txt", "w");
    if (novoArquivo == NULL)
    {
        printf("Erro ao criar o novo arquivo.\n");
        free(filmes);
        fclose(arquivo);
        return;
    }

    while (1)
    {
        if (tamanhoAtualFilme >= tamanhoMaxFilme)
        {
            tamanhoMaxFilme *= 2;
            struct dadosFilmes *temp = (struct dadosFilmes *)realloc(filmes, tamanhoMaxFilme * sizeof(struct dadosFilmes));

            if (temp == NULL)
            {
                printf("Erro na alocação de memória.\n");
                fclose(arquivo);
                fclose(novoArquivo);
                remove("temp_filmes.txt"); // Excluir o arquivo temporário em caso de erro
                return;
            }

            filmes = temp;
        }

        filmes[tamanhoAtualFilme].id = tamanhoAtualFilme;
        getchar();
        printf("Nome: ");
        fgets(filmes[tamanhoAtualFilme].nome, sizeof(filmes[tamanhoAtualFilme].nome), stdin);

        printf("Ano Lancamento: ");
        scanf("%d", &filmes[tamanhoAtualFilme].anoLanc);

        printf("Preco: ");
        scanf("%f", &filmes[tamanhoAtualFilme].preco);

        fprintf(novoArquivo, "Id: %d\nNome: %s\nAno Lancamento: %d\nPreco: %.2f\n\n", filmes[tamanhoAtualFilme].id, filmes[tamanhoAtualFilme].nome, filmes[tamanhoAtualFilme].anoLanc, filmes[tamanhoAtualFilme].preco);

        tamanhoAtualFilme++;

        printf("\nDeseja Alterar outro filme? (1 - Sim / 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 0)
        {
            break;
        }
    }

    // Verifique se a alocação de memória após o loop foi bem-sucedida
    if (filmes == NULL)
    {
        printf("Erro na alocação de memória após o loop.\n");
        fclose(arquivo);
        fclose(novoArquivo);
        remove("temp_filmes.txt"); // Excluir o arquivo temporário em caso de erro
        return;
    }

    // Copiar o conteúdo restante do arquivo original para o novo arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        fprintf(novoArquivo, "%s", linha);
    }

    fclose(arquivo);
    fclose(novoArquivo);

    // Renomear o arquivo temporário para o arquivo original
    remove("filmes.txt");
    rename("temp_filmes.txt", "filmes.txt");

    free(filmes);
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

    printf("\n\n----Alterar Clientes---\n");
    int tamanhoMaxCliente = 1;
    int tamanhoAtualCliente = 0;

    struct dadosClientes *clientes = (struct dadosClientes *)malloc(tamanhoMaxCliente * sizeof(struct dadosClientes));

    if (clientes == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        free(clientes);
        return;
    }

    FILE *novoArquivo = fopen("temp_clientes.txt", "w");
    if (novoArquivo == NULL)
    {
        printf("Erro ao criar o novo arquivo.\n");
        free(clientes);
        fclose(arquivo);
        return;
    }

    while (1)
    {
        clientes[tamanhoAtualCliente].codigo = tamanhoAtualCliente;
        getchar();
        printf("Nome: ");
        fgets(clientes[tamanhoAtualCliente].nome, sizeof(clientes[tamanhoAtualCliente].nome), stdin);

        printf("Idade: ");
        scanf("%d", &clientes[tamanhoAtualCliente].idade);

        fprintf(novoArquivo, "Codigo: %d\nNome: %s\nIdade: %d\n\n", clientes[tamanhoAtualCliente].codigo, clientes[tamanhoAtualCliente].nome, clientes[tamanhoAtualCliente].idade);

        tamanhoAtualCliente++;

        if (tamanhoAtualCliente >= tamanhoMaxCliente)
        {
            tamanhoMaxCliente *= 2;
            clientes = (struct dadosClientes *)realloc(clientes, tamanhoMaxCliente * sizeof(struct dadosClientes));

            if (clientes == NULL)
            {
                printf("Erro na alocacao de memoria.\n");
                fclose(arquivo);
                fclose(novoArquivo);
                remove("temp_clientes.txt"); // Excluir o arquivo temporário em caso de erro
                return;
            }
        }

        printf("Alterado com Sucesso");

        printf("\nDeseja alterar outro cliente? (1 - Sim / 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 0)
        {
            break;
        }
    }

    // Copiar o conteúdo restante do arquivo original para o novo arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        fprintf(novoArquivo, "%s", linha);
    }

    fclose(arquivo);
    fclose(novoArquivo);

    // Renomear o arquivo temporário para o arquivo original
    remove("clientes.txt");
    rename("temp_clientes.txt", "clientes.txt");

    free(clientes);
}