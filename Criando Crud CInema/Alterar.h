void atualizarFilme(struct dadosFilmes *filmes, int numFilmes) {
    system("cls");
    int id;
    printf("\nDigite o ID do filme que deseja atualizar: ");
    scanf("%d", &id);
    
    if (id >= 1 && id <= numFilmes) {
        
        printf("\nDigite o novo titulo do filme: ");
        fflush(stdin);
        scanf("%[^\n]", filmes[id - 1].nome);
        printf("Digite o novo ano de lancamento do filme: ");
        fflush(stdin);
        scanf("%d", &filmes[id - 1].anoLanc);
        printf("Digite o novo preco do filme: ");
        fflush(stdin);
        scanf("%f", &filmes[id - 1].preco);
        system("cls");
        printf("Filme atualizado com sucesso!\n");
    } else {
        system("cls");
        printf("ID de filme nao encontrado.\n");
    }
}

void atualizarCliente(struct dadosClientes *clientes, int numClientes) {
    system("cls");
    int id;
    printf("\nDigite o ID do cliente que deseja atualizar: ");
    scanf("%d", &id);
    
    if (id >= 1 && id <= numClientes) {

        printf("\nDigite o novo nome do cliente: ");
        fflush(stdin);
        scanf("%[^\n]", clientes[id - 1].nome);
        printf("Digite a nova idade do cliente: ");
        fflush(stdin);
        scanf("%d", &clientes[id - 1].idade);
        fflush(stdin);
        system("cls");
        printf("Cliente atualizado com sucesso!\n");
    } else {
        system("cls");
        printf("ID de cliente nao encontrado.\n");
    }
}
