#include <iostream>
#include "gerenciamento.h"
#include "usuario.h"
#include "pontoDeColeta.h"
#include "agendamento.h"
void menu(gerenciamento *Lista, agendamento agenda){
    int op;
    std::cout<<"\n===========================================================================================\n"<<"                                              <<<MENU>>>";
    std::cout<<"\n===========================================================================================\n";
    std::cout<< "\n (1) Adicionar usuario | (2) Imprimir usuarios | (3) Modificar usuario \n (4) Remover usuario | (5) Escolher ponto de coleta | (6) Agendar coleta | (7) Formas de armazenamento\n Escolha uma opcao (0 para sair): ";
    std::cin >> op;
    while (op != 0){
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
                agenda.escolherEndereco();
                break;
            case 6:
                agenda.agendar();
                break;
            case 7:
                Lista->formaDeArmazenamento();
                break;
            default:
                std::cout << "\n Opcao invalida, tente novamente: ";
                break;
        }
        std::cout<<"\n===========================================================================================\n"<<"                                              <<<MENU>>>";
        std::cout<<"\n===========================================================================================\n";
        std::cout<< "\n (1) Adicionar usuario | (2) Imprimir usuarios | (3) Modificar usuario \n (4) Remover usuario | (5) Escolher ponto de coleta | (6) Agendar coleta | (7) Formas de armazenamento\n Escolha uma opcao (0 para sair): ";
        std::cin >> op;
    }
}
int main()
{
    gerenciamento* Lista = new gerenciamento();
    agendamento agenda;
    menu(Lista, agenda);
    return 0;
}
