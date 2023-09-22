#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Cadastro.h"
#include "Consulta.h"



int main () {
    int option = 0;
    int menuLoop = 0;
 do{
    system("cls");
    printf("\n=============== Menu ==================\n");
    printf("|  [1] - Cadastrar                      |\n");
    printf("|  [2] - Listar filmes/clientes         |\n");
    printf("|  [3] - Listar todos os clientes       |\n");
    printf("|  [4] - Alterar cadastros              |\n");
    printf("|  [5] - Excluir                        |\n");
    printf("|  [6] - Limpar a Tela                  |\n");
    printf("|  [7] - Sair do Programa               |\n");
    printf("=========================================\n");
    printf("Digite a opcao desejada: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option){
        case 1:
            system("cls");
            Cadastrar();
            break;
        
        case 2:
            system("cls");
            Listar();            
            break;
        
        
      
    }

 }while (menuLoop == 0);
}