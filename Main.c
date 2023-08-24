#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"


int main(){
    int escolha=0, contFunci=0, continuar=0;
    // struct Funcionario funcionario;
    struct Funcionario *funcionario;
    funcionario = (struct Funcionario*) malloc (contFunci * sizeof(struct Funcionario));
    if (funcionario==NULL){
        exit(1);
    }
    
    MenuPrincipal(&escolha);
    do{
        if (escolha==1){
            do{
                MenuFuncionarios(&escolha);
                if (escolha==1){
                    do{
                        CadastrarFuncionario(&contFunci,funcionario);
                        contFunci++;
                        Continuar(&continuar);
                    } while (continuar==1);
                }
                if (escolha==3)
                {
                    ExibirFuncionario(&contFunci,funcionario);
                }
                
            } while (escolha!=5);

        }
        if (escolha != 4){
            MenuPrincipal(&escolha);
        }
        
    } while (escolha!=4);

    free(funcionario);
}
