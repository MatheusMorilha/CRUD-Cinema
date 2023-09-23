void listar_filme(){
    while(1){

        FILE *filmes = fopen("filmes.txt", "r");
        if (filmes == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return;
        }else{
            int vazio = fgetc(filmes);
            if(vazio == EOF){
                printf("Ainda nao foi cadastrado nenhum filme\n");
            }else{
                fseek(filmes, 0, SEEK_SET);
                char linhaf[100];
                while(fgets(linhaf, sizeof(linhaf), filmes)){
                    printf("%s", linhaf);
                }
            }
            fclose(filmes);
        }

        printf("\nDigite 0 para voltar para o menu principal: ");
        int zero;
        scanf("%d", &zero);
        if (zero == 0) {
            break;
        }
    }
}    


void listar_cliente(){
    while (1){

        FILE *clientes = fopen("clientes.txt", "r");
        if (clientes == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return;
        }else{
            int vazio = fgetc(clientes);
            if(vazio == EOF){
                printf("Ainda nao foi cadastrado nenhum cliente\n");
            }else{
                fseek(clientes, 0, SEEK_SET);
                char linhac[100];
                while (fgets(linhac, sizeof(linhac), clientes)){
                    printf("%s", linhac);
                }
            }
            fclose(clientes);
        }

        printf("\nDigite 0 para voltar para o menu principal: ");
        int zero;
        scanf("%d", &zero);
        if (zero == 0) {
            break;
        }
    }
    

}

void Listar(){
    int opc;

    printf("\n=========== Listar ===============\n");
    printf("|  [1] - Listar Filme            |\n");
    printf("|  [2] - Listar Cliente          |\n");
    printf("|  [0] - Voltar Menu Principal   |\n");
    printf("==================================\n");
    printf("Digite a opcao desejada: ");
    fflush(stdin);
    scanf("%d", &opc);

    switch (opc){
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