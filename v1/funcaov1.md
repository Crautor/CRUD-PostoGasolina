#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>


void CadastrarFuncionario(int *contadorFuncionario, struct Funcionario **funcionarios) {
    (*contadorFuncionario)++;
    
    *funcionarios = realloc(*funcionarios, (*contadorFuncionario) * sizeof(struct Funcionario));
    if (*funcionarios == NULL) {
        // Lida com erro de alocação de memória
        exit(1);
    }
    
    struct Funcionario *novoFuncionario = &(*funcionarios)[*contadorFuncionario - 1];
    
    novoFuncionario->ID = *contadorFuncionario;
   
    // Nome
    printf("Digite o nome do Funcionario: ");
    fflush(stdin);
    fgets(novoFuncionario->Nome, sizeof(novoFuncionario->Nome), stdin);
    novoFuncionario->Nome[strcspn(novoFuncionario->Nome, "\n")] = '\0';
    
    // Turno
    printf("TURNOS: \n1 - Matutino\n2 - Vespertino\n3 - Noturno\n");
    printf("Informe o Turno de Trabalho: ");
    scanf("%d", &novoFuncionario->Turno);
    
    // Função
    printf("Informe a funcao do funcionario: ");
    fflush(stdin);
    fgets(novoFuncionario->Funcao, sizeof(novoFuncionario->Funcao), stdin);
    novoFuncionario->Funcao[strcspn(novoFuncionario->Funcao, "\n")] = '\0';
}

void ExibirFuncionarios(int contadorFuncionario, struct Funcionario *funcionarios) {
    for (int i = 0; i < contadorFuncionario; i++) {
        printf("\nIndice: %d\n", funcionarios[i].ID);
        printf("Nome: %s\n", funcionarios[i].Nome);
        if (funcionarios[i].Turno == 1){
            printf("Turno: Matutino\n");
        }
        if (funcionarios[i].Turno == 2){
            printf("Turno: Vespertino\n");
        }
        if (funcionarios[i].Turno == 3){
            printf("Turno: Noturno\n");
        }
        else{
            printf("Turno: Nao Encontrado\n");
        }
        
        printf("Funcao: %s\n", funcionarios[i].Funcao);
    }
}


void Continuar(int *continuar){
    printf("\nDeseja Continuar?\n");
    printf("============================================\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("============================================\n");
    scanf("%d",continuar);
}

void MenuPrincipal(int *escolha){
    printf("\nMENU\n");
    printf("============================================\n");
    printf("1 - Funcionario\n");
    printf("2 - Produtos\n");
    printf("3 - Bombas de Combustivel\n");
    printf("4 - Sair\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}

void MenuFuncionarios(int *escolha){
    printf("\nMENU FUNCIONARIOS\n");
    printf("============================================\n");
    printf("1 - Cadastrar Funcionario\n");
    printf("2 - Editar Funcionarios\n");
    printf("3 - Exibir Funcionarios Cadastrados\n");
    printf("4 - Deletar Funcionario \n");
    printf("5 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}