#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>

void CadastrarFuncionario(int *contadorFuncionario, struct Funcionario *funcionario){

    if(*contadorFuncionario>1){
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
    if((*contadorFuncionario)==0){
        printf("\n============================================\n");
        printf("NAO TEM FUNCIONARIOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
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

void EditarFuncionario(int *contadorFuncionario, struct Funcionario *funcionario){
    if((*contadorFuncionario)==0){
        printf("\n============================================\n");
        printf("NAO TEM FUNCIONARIOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    int indiceTroca = 0;
    // exibe todos que tem ate o momento
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
    //pede qual quer alterar
    printf("\ninforme qual o indice do funcionario que deseja editar: ");
    scanf("%d",&indiceTroca);
    for(int i = 0; i < (*contadorFuncionario); i++){
        if (funcionario[i].ID == indiceTroca){
            printf("\nIndice: %d\n",funcionario[indiceTroca-1].ID);
            printf("Nome: %s\n",funcionario[indiceTroca-1].Nome);
            if (funcionario[indiceTroca-1].Turno==1){
                printf("Turno: Matutino\n");
            }
            if (funcionario[indiceTroca-1].Turno==2){
                printf("Turno: Vespertino\n");
            }
            if (funcionario[indiceTroca-1].Turno==3){
                printf("Turno: Noturno\n");
            }
            if (funcionario[indiceTroca-1].Turno!=1 && funcionario[indiceTroca-1].Turno!=2 && funcionario[indiceTroca-1].Turno!=3){
                printf("Turno: Nao encontrado\n");
            }
            printf("Funcao: %s\n",funcionario[i].Funcao);

            //Nome  
            printf("\nDigite o nome do Funcionario: ");
            fflush(stdin);
            gets(funcionario[indiceTroca-1].Nome);       
            
            //Turno
            printf("TURNOS: \n1 - Matutino\n2 - Vespertino\n3 - Noturno\n");
            printf("informe o Turno de Trabalho:");
            scanf("%i",&funcionario[indiceTroca-1].Turno);
            
            //Função
            printf("Informe a funcao do funcionario:");
            fflush(stdin);
            gets(funcionario[indiceTroca-1].Funcao); 
        
        }
    }
    printf("Alteracao realizada.\n");
}

void DeletarFuncionario(int *contadorFuncionario, struct Funcionario *funcionario){
    if((*contadorFuncionario)==0){
        printf("\n============================================\n");
        printf("NAO TEM FUNCIONARIOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    //exibir
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
    int indiceDelete;

    printf("\ninforme qual o indice do funcionario que deseja excluir: ");
    scanf("%d",&indiceDelete);
    for(int i = 0; i < (*contadorFuncionario); i++){
        if (funcionario[i].ID == indiceDelete){
            
            funcionario[i]= funcionario[*contadorFuncionario-1];
            funcionario[i].ID = i+1;
            
            // tirar 1 do contador
            (*contadorFuncionario)--;
            
            //caso delete e so tenha 1 cadastrado
            if (*contadorFuncionario==0){
              //n faz nada se não buga  
            }
            else{
                funcionario = (struct Funcionario*) realloc (funcionario,*contadorFuncionario * sizeof(struct Funcionario));
            }

            
        }
    }
}

//BombaCombustivel
void CadastrarBombaCombustivel(int *contadorBombaCombustivel, struct BombaCombustivel *BombaCombustivel){

    if(*contadorBombaCombustivel>1){
        BombaCombustivel = (struct BombaCombustivel*) realloc (BombaCombustivel,*contadorBombaCombustivel * sizeof(struct BombaCombustivel));  
    }
    
   
    BombaCombustivel[*contadorBombaCombustivel].ID = *contadorBombaCombustivel + 1;
   
    //Nome  
    printf("Digite o nome do Funcionario: ");
    fflush(stdin);
    gets(BombaCombustivel[*contadorBombaCombustivel].Nome);       
    
    //Combustivel
    printf("Combustivel: \n1 - Gasolina\n2 - Gasolina Aditivada\n3 - Alcool\n4 - Diesel\n");
    printf("Informe o tipo de combustivel:");
    scanf("%i",&BombaCombustivel[*contadorBombaCombustivel].Combustivel);  

}

void ExibirBombaCombustivel(int *contadorBombaCombustivel, struct BombaCombustivel *BombaCombustivel){
    if((*contadorBombaCombustivel)==0){
        printf("\n============================================\n");
        printf("NAO TEM BOMBAS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    for (int i = 0; i < (*contadorBombaCombustivel); i++){
        printf("\nIndice: %d\n",BombaCombustivel[i].ID);
        printf("Nome: %s\n",BombaCombustivel[i].Nome);
        if (BombaCombustivel[i].Combustivel==1){
            printf("Combustivel: Gasolina\n");
        }
        if (BombaCombustivel[i].Combustivel==2){
            printf("Combustivel: Gasolina Aditivada\n");
        }
        if (BombaCombustivel[i].Combustivel==3){
            printf("Combustivel: Alcool\n");
        }
        if (BombaCombustivel[i].Combustivel==4){
            printf("Combustivel: Diesel\n");
        }
        if (BombaCombustivel[i].Combustivel!=1 && BombaCombustivel[i].Combustivel!=2 && BombaCombustivel[i].Combustivel!=3 && BombaCombustivel[i].Combustivel != 4){
            printf("Combustivel: Nao encontrado\n");
        }
    }
    
}

void EditarBombaCombustivel(int *contadorBombaCombustivel, struct BombaCombustivel *BombaCombustivel){
    if((*contadorBombaCombustivel)==0){
        printf("\n============================================\n");
        printf("NAO TEM BOMBAS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    int indiceTroca = 0;
    // exibe todos que tem ate o momento
    for (int i = 0; i < (*contadorBombaCombustivel); i++){
        printf("\nIndice: %d\n",BombaCombustivel[i].ID);
        printf("Nome: %s\n",BombaCombustivel[i].Nome);
        if (BombaCombustivel[i].Combustivel==1){
            printf("Combustivel: Gasolina\n");
        }
        if (BombaCombustivel[i].Combustivel==2){
            printf("Combustivel: Gasolina Aditivada\n");
        }
        if (BombaCombustivel[i].Combustivel==3){
            printf("Combustivel: Alcool\n");
        }
        if (BombaCombustivel[i].Combustivel==4){
            printf("Combustivel: Diesel\n");
        }
        if (BombaCombustivel[i].Combustivel!=1 && BombaCombustivel[i].Combustivel!=2 && BombaCombustivel[i].Combustivel!=3 && BombaCombustivel[i].Combustivel != 4){
            printf("Combustivel: Nao encontrado\n");
        }
    }
    //pede qual quer alterar
    printf("\ninforme qual o indice do BombaCombustivel que deseja editar: ");
    scanf("%d",&indiceTroca);
    for(int i = 0; i < (*contadorBombaCombustivel); i++){
        if (BombaCombustivel[i].ID == indiceTroca){
            printf("\nIndice: %d\n",BombaCombustivel[indiceTroca-1].ID);
            printf("Nome: %s\n",BombaCombustivel[indiceTroca-1].Nome);
            if (BombaCombustivel[i].Combustivel==1){
            printf("Combustivel: Gasolina\n");
            }
            if (BombaCombustivel[i].Combustivel==2){
                printf("Combustivel: Gasolina Aditivada\n");
            }
            if (BombaCombustivel[i].Combustivel==3){
                printf("Combustivel: Alcool\n");
            }
            if (BombaCombustivel[i].Combustivel==4){
                printf("Combustivel: Diesel\n");
            }
            if (BombaCombustivel[i].Combustivel!=1 && BombaCombustivel[i].Combustivel!=2 && BombaCombustivel[i].Combustivel!=3 && BombaCombustivel[i].Combustivel != 4){
                printf("Combustivel: Nao encontrado\n");
            }

            //Nome  
            printf("\nDigite o nome do BombaCombustivel: ");
            fflush(stdin);
            gets(BombaCombustivel[indiceTroca-1].Nome);       
            
            //Combustivel
            printf("Combustivel: \n1 - Gasolina\n2 - Gasolina Aditivada\n3 - Alcool\n4 - Diesel\n");
            printf("Informe o tipo de combustivel:");
            scanf("%i",&BombaCombustivel[indiceTroca-1].Combustivel);          
        }
    }
    printf("Alteracao realizada.\n");
}

void DeletarBombaCombustivel(int *contadorBombaCombustivel, struct BombaCombustivel *BombaCombustivel){
    if((*contadorBombaCombustivel)==0){
        printf("\n============================================\n");
        printf("NAO TEM BOMBAS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    //exibir
    for (int i = 0; i < (*contadorBombaCombustivel); i++){
        printf("\nIndice: %d\n",BombaCombustivel[i].ID);
        printf("Nome: %s\n",BombaCombustivel[i].Nome);
        if (BombaCombustivel[i].Combustivel==1){
            printf("Combustivel: Gasolina\n");
        }
        if (BombaCombustivel[i].Combustivel==2){
            printf("Combustivel: Gasolina Aditivada\n");
        }
        if (BombaCombustivel[i].Combustivel==3){
            printf("Combustivel: Alcool\n");
        }
        if (BombaCombustivel[i].Combustivel==4){
            printf("Combustivel: Diesel\n");
        }
        if (BombaCombustivel[i].Combustivel!=1 && BombaCombustivel[i].Combustivel!=2 && BombaCombustivel[i].Combustivel!=3 && BombaCombustivel[i].Combustivel != 4){
            printf("Combustivel: Nao encontrado\n");
        }
    }
    int indiceDelete;

    printf("\ninforme qual o indice do BombaCombustivel que deseja excluir: ");
    scanf("%d",&indiceDelete);
    for(int i = 0; i < (*contadorBombaCombustivel); i++){
        if (BombaCombustivel[i].ID == indiceDelete){
            
            BombaCombustivel[i]= BombaCombustivel[*contadorBombaCombustivel-1];
            BombaCombustivel[i].ID = i+1;
            
            // tirar 1 do contador
            (*contadorBombaCombustivel)--;
            
            //caso delete e so tenha 1 cadastrado
            if (*contadorBombaCombustivel==0){
              //n faz nada se não buga  
            }
            else{
                BombaCombustivel = (struct BombaCombustivel*) realloc (BombaCombustivel,*contadorBombaCombustivel * sizeof(struct BombaCombustivel));
            }

            
        }
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
    printf("1 - Funcionarios\n");
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

void MenuBombaCombustivel(int *escolha){
    printf("\nMENU BOMBA DE COMBUSTIVEL\n");
    printf("============================================\n");
    printf("1 - Cadastrar Bomba\n");
    printf("2 - Editar Bombas\n");
    printf("3 - Exibir Bombas Cadastrados\n");
    printf("4 - Deletar Bomba \n");
    printf("5 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}