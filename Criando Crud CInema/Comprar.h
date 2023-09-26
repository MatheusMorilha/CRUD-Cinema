// João Grupo 02 ficou com a parte de Comprar.

#include "struct.h"

void comprar(struct dadosClientes *clientes, int numClientes,struct dadosFilmes *filmes, int numFilmes) {
    int i,op1,op2,ver=1;
    float valor;
    char op3;
    
    if(clientes==NULL || filmes == NULL){
        printf("Falta dados no banco para prosseguir\n");
        return;
    }

    while(ver==1){
    ver=1;
    printf("====Escolha o Cliente====\n");
    for(i = 0; i < numClientes; i++) {
        printf("%i -- Nome: %s\n",i+1 ,clientes[i].nome);
        printf("\n");
    }

    printf(">> ");
    scanf("%i",&op1);
    op1--;

    if(numClientes>op1){
    ver=0;
    }
    }

    
    ver=1;
    while(ver==1){
    ver=1;
    printf("\n====Escolha o Filme====\n");
    for(i = 0; i < numFilmes; i++) {
        printf("%i -- Nome: %s\n",i+1 ,filmes[i].nome);
        printf("\n");
    }
    printf(">> ");
    scanf("%i",&op2);
    op2--;

    if(numFilmes > op2){
    ver=0;
        }
    }

    valor = filmes[op2].preco;

    printf("\nTem direito a meia entrada? se tiver escreva: S \n");
    printf(">> ");
    scanf("%s",&op3);

    if(op3=='s' || op3=='S'){
        valor=valor/2;
    }

    FILE *arquivo; 

    arquivo = fopen(clientes[op1].nome, "w");

     if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }


    fprintf(arquivo, " ===============================\n");
    fprintf(arquivo, "|\n");
    fprintf(arquivo, "| Filme: %s\n",filmes[op2].nome);
    fprintf(arquivo, "| Preco: $%.2f\n",valor);
    fprintf(arquivo, "|\n");
    fprintf(arquivo, " ===============================\n");

    
    fclose(arquivo);
    system("cls");
    printf("Ingresso impresso com sucesso\n");
}

