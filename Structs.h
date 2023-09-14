struct Funcionario {
    int ID;
    char Nome[50];
    int Turno;
    char Funcao[20];
};

struct BombaCombustivel{
    int ID;
    char Nome[50];
    int Combustivel;
};

struct Estoque{
    int ID;
    char Nome[50];
    int Qntd;
    float Preco;
};
struct Carrinho{
    int ID;
    char Cliente[50];
    char Nome[50];
    int Qntd;
    float Preco;
};
