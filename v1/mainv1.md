#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

int main() {
    int escolha = 0, contFunci = 0, continuar = 0;
    struct Funcionario *funcionarios = NULL;
    
    do {
        MenuPrincipal(&escolha);
        
        if (escolha == 1) {
            do {
                MenuFuncionarios(&escolha);
                if (escolha == 1) {
                    do{
                        CadastrarFuncionario(&contFunci, &funcionarios);
                        Continuar(&continuar);
                    } while (continuar==1);
                }
                else if (escolha == 3) {
                    ExibirFuncionarios(contFunci, funcionarios);
                }
            } while (escolha != 5);
        }

        // ...
        
    } while (escolha != 4);
    
    // Liberar memória alocada
    free(funcionarios);
    
    return 0;
}
