#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Cadastro.h"
#include "Comprar.h"
#include "struct.h"




int main() {
    struct dadosFilmes *filmes = NULL;
    struct dadosClientes *clientes = NULL;
    int numFilmes = 0;
    int numClientes = 0;
    int opcao;
    system("cls");
    do {
        
        printf("\n===============Menu=============\n");
        printf(" |1. Cadastrar Filme              |\n");
        printf(" |2. Cadastrar Cliente            |\n");
        printf(" |3. Listar Filmes                |\n");
        printf(" |4. Listar Clientes              |\n");
        printf(" |5. Vender ingresso              |\n");
        printf(" |0. Sair                         |\n");
        printf("  ========Escolha uma opcao=======\n ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            system("cls");
                cadastrarFilme(&filmes, &numFilmes);
                break;
            case 2:
                system("cls");
                cadastrarCliente(&clientes, &numClientes);
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("cls");
                comprar(clientes, numClientes,filmes, numFilmes);
                break;
            case 0:
                system("cls");
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);


    free(filmes);
    free(clientes);

    return 0;
}
