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
    printf("Informe o Turno de Trabalho:");
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
            printf("Informe o Turno de Trabalho:");
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

void CadastrarProduto(int *contadorestoque, struct Estoque *estoque){

    if(*contadorestoque>1){
        estoque = (struct Estoque*) realloc (estoque,*contadorestoque * sizeof(struct Estoque));  
    }
    
   
    estoque[*contadorestoque].ID = *contadorestoque + 1;
   
    //Nome  
    printf("Digite o nome do estoque: ");
    fflush(stdin);
    gets(estoque[*contadorestoque].Nome);       
    fflush(stdin);
    //Qntd
    printf("Informe a quantidade do produto:");
    scanf("%i",&estoque[*contadorestoque].Qntd);
    fflush(stdin);
    //Preco
    printf("Informe o preco do produto:\n(ex: 1.99)");
    scanf("%f",&estoque[*contadorestoque].Preco);
    
     
      

}

void ExibirProduto(int *contadorestoque, struct Estoque *estoque){
    if((*contadorestoque)==0){
        printf("\n============================================\n");
        printf("NAO TEM PRODUTOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    for (int i = 0; i < (*contadorestoque); i++){
        printf("\nIndice: %d\n",estoque[i].ID);
        printf("Nome: %s\n",estoque[i].Nome);
        printf("Quantidade: %i\n",estoque[i].Qntd);
        printf("Preco: R$ %.2f\n",estoque[i].Preco);
    }
    
}

void EditarProduto(int *contadorestoque, struct Estoque *estoque){
    if((*contadorestoque)==0){
        printf("\n============================================\n");
        printf("NAO TEM PRODUTOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    int indiceTroca = 0;
    // exibe todos que tem ate o momento
    for (int i = 0; i < (*contadorestoque); i++){
        printf("\nIndice: %d\n",estoque[i].ID);
        printf("Nome: %s\n",estoque[i].Nome);
        printf("Quantidade: %i\n",estoque[i].Qntd);
        printf("Preco: R$ %.2f\n",estoque[i].Preco);
    }
    //pede qual quer alterar
    printf("\ninforme qual o indice do estoque que deseja editar: ");
    scanf("%d",&indiceTroca);
    for(int i = 0; i < (*contadorestoque); i++){
        if (estoque[i].ID == indiceTroca){
            printf("\nIndice: %d\n",estoque[indiceTroca-1].ID);
            printf("Nome: %s\n",estoque[indiceTroca-1].Nome);
            printf("Quantidade: %i\n",estoque[indiceTroca-1].Qntd);
            printf("Preco: R$ %.2f\n",estoque[indiceTroca-1].Preco);

            //Nome  
            printf("\nDigite o nome do estoque: ");
            fflush(stdin);
            gets(estoque[indiceTroca-1].Nome);       
            
            //Qntd
            printf("Informe a quantidade do produto:");
            scanf("%i",&estoque[indiceTroca-1].Qntd);
            
            //Preco
            printf("Informe o preco do produto: \n(ex: 1.99)");
            scanf("%f",&estoque[indiceTroca-1].Preco);
            
             
        
        }
    }
    printf("Alteracao realizada.\n");
}

void DeletarProduto(int *contadorestoque, struct Estoque *estoque){
    if((*contadorestoque)==0){
        printf("\n============================================\n");
        printf("NAO TEM PRODUTOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    //exibir
    for (int i = 0; i < (*contadorestoque); i++){
        printf("\nIndice: %d\n",estoque[i].ID);
        printf("Nome: %s\n",estoque[i].Nome);
        printf("Quantidade: %i\n",estoque[i].Qntd);
        printf("Preco: R$ %.2f\n",estoque[i].Preco);
    }
    int indiceDelete;

    printf("\ninforme qual o indice do estoque que deseja excluir: ");
    scanf("%d",&indiceDelete);
    for(int i = 0; i < (*contadorestoque); i++){
        if (estoque[i].ID == indiceDelete){
            
            estoque[i]= estoque[*contadorestoque-1];
            estoque[i].ID = i+1;
            
            // tirar 1 do contador
            (*contadorestoque)--;
            
            //caso delete e so tenha 1 cadastrado
            if (*contadorestoque==0){
              //n faz nada se não buga  
            }
            else{
                estoque = (struct Estoque*) realloc (estoque,*contadorestoque * sizeof(struct Estoque));
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
    printf("Digite o nome do Bomba: ");
    fflush(stdin);
    gets(BombaCombustivel[*contadorBombaCombustivel].Nome);       
    
    //Combustivel
    printf("\nCombustivel: \n1 - Gasolina: R$ 5.00\n2 - Gasolina Aditivada: R$ 5.30\n3 - Alcool: R$ 3.70\n4 - Diesel: R$ 6.18\n");
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

void AdicionarCarrinho(int *contadorestoque, struct Estoque *estoque, float *valorFinal, struct Estoque *carrinho, int *contadorCarrinho){
    int indiceProduto, qntcompra, continuar;
    if((*contadorestoque)==0){
        printf("\n============================================\n");
        printf("NAO TEM PRODUTOS CADASTRADOS NO MOMENTO\n");
        printf("============================================\n");
        return;
    }
    do{
        if(*contadorCarrinho>1){
            carrinho = (struct Estoque*) realloc (carrinho,*contadorCarrinho * sizeof(struct Estoque));  
        }
        for (int i = 0; i < (*contadorestoque); i++){
            printf("\nIndice: %d\n",estoque[i].ID);
            printf("Nome: %s\n",estoque[i].Nome);
            printf("Quantidade: %i\n",estoque[i].Qntd);
            printf("Preco: R$ %.2f\n",estoque[i].Preco);
        }
        printf("\nInforme o Indice do Produto que deseja adicionar ao carrinho: ");
        scanf("%i",&indiceProduto);
        printf("\nInforme a Quantidade do Produto que voce deseja comprar: ");
        scanf("%i",&qntcompra);
        for(int i = 0; i < (*contadorestoque); i++){
            if (estoque[i].ID == indiceProduto){
                if (estoque[indiceProduto-1].Qntd>=qntcompra){
                    // *contadorCarrinho = (*contadorCarrinho) + 1;
                    // carrinho[(*contadorCarrinho)-1].ID = (*contadorCarrinho);
                    // // carrinho[(*contadorCarrinho)-1].Nome = estoque[indiceProduto-1].Nome;
                    // carrinho[(*contadorCarrinho)-1].Qntd = qntcompra;
                    // carrinho[(*contadorCarrinho)-1].Preco = estoque[indiceProduto-1].Preco*qntcompra;

                    
                    *valorFinal = (*valorFinal)+(estoque[indiceProduto-1].Preco*qntcompra);
                    estoque[indiceProduto-1].Qntd = estoque[indiceProduto-1].Qntd - qntcompra;
                }
                else{
                    printf("\nSem itens suficientes do produto no estoque\n");
                }       
            }
        }  
        printf("\nDeseja Continuar?\n");
        printf("============================================\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        printf("============================================\n");
        scanf("%d",&continuar);
    }while(continuar!=2);
}

void Abastecer(float *valorFinal){
    int combustivelUsado=0;
    float litros=0;
    const float valorGasolina=5.0,valorGasolinaAditivada=5.30,valorAlcool=3.70,valorDiesel=6.18;
    printf("\nCombustivel: \n1 - Gasolina: R$ 5.00\n2 - Gasolina Aditivada: R$ 5.30\n3 - Alcool: R$ 3.70\n4 - Diesel: R$ 6.18\n");
    printf("Informe o combustivel utilizado: ");
    scanf("%d",&combustivelUsado);
    printf("Informe a quantidade de litros abastecido: ");
    scanf("%f",&litros);
    if (combustivelUsado==1){
        *valorFinal=(*valorFinal)+(litros*valorGasolina);    
        
    }
    if (combustivelUsado==2){

        *valorFinal=(*valorFinal)+(litros*valorGasolinaAditivada);    
    }
    if (combustivelUsado==3){

        *valorFinal=(*valorFinal)+(litros*valorAlcool);    
    }
    if (combustivelUsado==4){
        *valorFinal=(*valorFinal)+(litros*valorDiesel);    

    }
    if (combustivelUsado!=1 && combustivelUsado!=2 && combustivelUsado!=3 && combustivelUsado != 4){
        printf("Combustivel nao encontrado\n");
    }
} 

void FinalizarCompra(float *valorfinal){
    printf("\nVALOR TOTAL A PAGAR: R$ %.2f\n",(*valorfinal));
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

void MenuProdutos(int *escolha){
    printf("\nMENU PRODUTOS\n");
    printf("============================================\n");
    printf("1 - Estoque\n");
    printf("2 - Venda\n");
    printf("0 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}

void MenuEstoque(int *escolha){
    printf("\nMENU ESTOQUE\n");
    printf("============================================\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Editar Produtos\n");
    printf("3 - Exibir Produtos\n");
    printf("4 - Deletar Produto\n");
    printf("5 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}

void MenuVendas(int *escolha){
    printf("\nMENU VENDAS\n");
    printf("============================================\n");
    printf("1 - Adicionar ao Carrinho\n");
    // printf("2 - Editar Carrinho\n");
    // printf("3 - Exibir Carrinho\n");
    printf("2 - Abastecer\n");
    printf("3 - Finalizar Compra\n");
    printf("4 - Voltar\n");
    printf("============================================\n");
    printf("Escolha uma das alternativas acima: ");
    scanf("%i", escolha);
}
// void ExibirCarrinho(float *valorFinal, struct Estoque *carrinho, int *contadorCarrinho){
//     if((*contadorCarrinho)==0){
//         printf("\n============================================\n");
//         printf("NAO TEM PRODUTOS CADASTRADOS NO MOMENTO\n");
//         printf("============================================\n");
//         return;
//     } 
//     *valorFinal=0;     
//     for (int i = 0; i < (*contadorCarrinho); i++){
//         printf("\nIndice: %d\n",carrinho[i].ID);
//         printf("Nome: %s\n",carrinho[i].Nome);
//         printf("Quantidade: %i\n",carrinho[i].Qntd);
//         printf("Preco: R$ %.2f\n",carrinho[i].Preco);
//         *valorFinal= (*valorFinal)+ (carrinho[i].Preco*carrinho[i].Qntd);
//     }
//     printf("\nValor total: %.2f",(*valorFinal));    
    
// }