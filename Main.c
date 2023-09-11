#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"


int main(){
    int escolha=0, contFunci=0, continuar=0, contBombaCombustivel = 0;
    // struct Funcionario funcionario;
    struct Funcionario *funcionario;
    funcionario = (struct Funcionario*) malloc (1 * sizeof(struct Funcionario));
    if (funcionario==NULL){
        exit(1);
    }
    struct BombaCombustivel *BombaCombustivel;
    BombaCombustivel = (struct BombaCombustivel*) malloc (1 * sizeof(struct BombaCombustivel));
    if (BombaCombustivel==NULL){
        exit(1);
    }
    
    MenuPrincipal(&escolha);
    do{
        if (escolha==1){
            do{
                //Funcionario
                MenuFuncionarios(&escolha);
                if (escolha==1){
                    do{
                        CadastrarFuncionario(&contFunci,funcionario);
                        contFunci++;
                        Continuar(&continuar);
                    } while (continuar==1);
                }
                if (escolha==2){
                    EditarFuncionario(&contFunci,funcionario);
                }
                
                if (escolha==3){
                    ExibirFuncionario(&contFunci,funcionario);
                }
                if (escolha==4){
                    DeletarFuncionario(&contFunci,funcionario);
                }
                
            } while (escolha!=5);
        }
        if (escolha == 3){
            //Combustivel
            do{
                MenuBombaCombustivel(&escolha);
                if (escolha==1){
                    do{
                        CadastrarBombaCombustivel(&contBombaCombustivel,BombaCombustivel);
                        contBombaCombustivel++;
                        Continuar(&continuar);
                    } while (continuar==1);
                }
                if (escolha==2){
                    EditarBombaCombustivel(&contBombaCombustivel,BombaCombustivel);
                }               
                if (escolha==3){
                    ExibirBombaCombustivel(&contBombaCombustivel,BombaCombustivel);
                }
                if (escolha==4){
                    DeletarBombaCombustivel(&contBombaCombustivel,BombaCombustivel);
                }             
            } while (escolha!=5);
        }
        if (escolha != 4){
            MenuPrincipal(&escolha);
        }
        
    } while (escolha!=4);

    free(funcionario);
}
