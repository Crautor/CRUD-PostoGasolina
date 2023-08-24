#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>

void CadastrarFuncionario(int *contadorFuncionario, struct Funcionario *funcionario){
  
   if (*contadorFuncionario>1)
   {
    funcionario = (struct Funcionario*) realloc (funcionario,*contadorFuncionario * sizeof(struct Funcionario));
    
   }
   
    funcionario[*contadorFuncionario].ID = *contadorFuncionario + 1;
   
    //Nome  
    printf("Digite o nome do Funcionario: ");
    fflush(stdin);
    gets(funcionario[*contadorFuncionario].Nome);       
    
    //Turno
    printf("TURNOS: \n1 - Matutino\n2 - Vespertino\n3 - Noturno\n");
    printf("informe o Turno de Trabalho:");
    scanf("%i",&funcionario[*contadorFuncionario].Turno);
    
    //Função
    printf("Informe a funcao do funcionario:");
    fflush(stdin);
    gets(funcionario[*contadorFuncionario].Funcao); 
      

}

void ExibirFuncionario(int *contadorFuncionario, struct Funcionario *funcionario){
    for (int i = 0; i < (*contadorFuncionario); i++){
        printf("\nIndice: %d\n",funcionario[i].ID);
        printf("Nome: %s\n",funcionario[i].Nome);
        if (funcionario[i].Turno==1){
            printf("Turno: Matutino\n");
        }
        if (funcionario[i].Turno==2){
            printf("Turno: Vespertino\n");
        }
        if (funcionario[i].Turno==3){
            printf("Turno: Noturno\n");
        }
        if (funcionario[i].Turno!=1 && funcionario[i].Turno!=2 && funcionario[i].Turno!=3){
            printf("Turno: Nao encontrado\n");
        }
        printf("Funcao: %s\n",funcionario[i].Funcao);
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