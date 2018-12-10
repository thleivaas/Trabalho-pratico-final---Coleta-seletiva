#include <iostream>
#include "gerenciamento.h"
#include "usuario.h"
#include "pontoDeColeta.h"
void menu(gerenciamento *Lista, pontoDeColeta endereco){
    int op;
    std::cout <<"\n =================================================================\n"<<"                               <<<MENU>>>\n";
    std::cout<< " (1) Adicionar usuario | (2) Imprimir usuarios | (3) Modificar usuario \n (4) Remover usuario | (5) Escolher ponto de coleta \n Escolha uma opcao (0 para sair): ";
    std::cin >> op;
    do{
        switch (op){
            case 0:

                break;
            case 1:
                Lista->adicionaUsuario();
                break;
            case 2:
                Lista->imprimeUsuarios();
                break;
            case 3:
                Lista->modificaUsuario();
                break;
            case 4:
                Lista->removeUsuario();
                break;
            case 5:
                endereco.escolherEndereco();
                break;
            default:
                std::cout << "\n Opcao invalida, tente novamente: ";
                break;
        }
        std::cout <<"\n =================================================================\n"<<"                               <<<MENU>>>\n";
        std::cout<< " (1) Adicionar usuario | (2) Imprimir usuarios | (3) Modificar usuario \n (4) Remover usuario | (5) Escolher ponto de coleta \n Escolha uma opcao (0 para sair): ";
        std::cin >> op;
    }while (op != 0);
}
int main()
{
    gerenciamento* Lista = new gerenciamento();
    pontoDeColeta endereco;
    menu(Lista, endereco);
    return 0;
}
