void listar_filme(struct dadosFilmes *filmes, int numFilmes){
    while(1){
        if(filmes == NULL){
            printf("Ainda nao foi cadastrado nenhum filme!\n");
        }else{
            printf("---Filmes---\n");
            for(int i = 0; i < numFilmes; i++){
                printf("Id: %i\n", i+1);
                printf("Nome: %s\n", filmes[i].nome);
                printf("Idade: %i\n", filmes[i].anoLanc);
                printf("Idade: %.2f\n\n", filmes[i].preco);
            }
        }
        printf("Digite 0 para voltar para o menu principal: ");
        int zero;
        scanf("%d", &zero);
        if (zero == 0){
            break;
        }
    }
}    


void listar_cliente(struct dadosClientes *clientes, int numClientes){
    while (1){
        if(clientes == NULL){
            printf("Ainda nao foi cadastrado nenhum cliente!\n");
        }else{
            printf("---Clientes---\n");
            for(int i = 0; i < numClientes; i++){
                printf("Id: %i\n", i+1);
                printf("Nome: %s\n", clientes[i].nome);
                printf("Idade: %i\n\n", clientes[i].idade);
            }
        }
        printf("Digite 0 para voltar para o menu principal: ");
        int zero;
        scanf("%d", &zero);
        if (zero == 0){
            break;
        }
    }
}
