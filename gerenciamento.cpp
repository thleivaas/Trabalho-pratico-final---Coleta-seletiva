#include "gerenciamento.h"
#include <list>
gerenciamento::gerenciamento(){
    this->cpf= "";
    this->nome= "";
    this->endereco= "";
    this->cnpj= "";
    this->tipoUsuario = false;
}
void gerenciamento::imprimeUsuarios(){
    std::list <usuario*>::iterator it;
    int j=0;
    std::cout << "\n=========================================================\n";
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        std::cout <<"\n Nome do usuario ("<<j+1<<"): " <<(*it)->getNome();
        /*std::cout <<"\n Nome do residuo: "<< (*it)->get_nome_residuo;
        std::cout <<"\n Peso/Volume do residuo: "<<(*it)->get_peso_residuo;*/
        std::cout <<"\n Tipo de usuario :";
        if((*it)->getTipoUsuario() == false)
            std::cout <<" Doador";
        else
            std::cout <<" Receptor";
        if((*it)->getPessoaEmpresa() == false)
            std::cout<<"\n Cpf do usuario ("<<j+1<<"): "<<(*it)->getCpf();
        else
            std::cout<<"\n Cnpj do usuario ("<<j+1<<"): "<<(*it)->getCnpj();
        std::cout<<"\n Endereco do usuario ("<<j+1<<"): "<<(*it)->getEndereco();
        j++;
        std::cout <<"\n";
    }
}

void gerenciamento::adicionaUsuario(){
    std::cout << "\n=========================================================\n";
    usuario *aux = new gerenciamento() ;
    char opcao, op;
    std::string auxs,auxe;
    std::cout << "\n Digite:\n (1) Se o usuario for um doador | (2) Se o usuario for um receptor\n : ";
    std::cin >> op;
    while(op != '1' && op != '2'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Opcao invalida, digite novamente :";
        std::cin >> op;
        }
    if(op == '1')
        aux->setTipoUsuario(false);
    else
        aux->setTipoUsuario(true);
    /*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n Digite o tipo do residuo de interesse: ";
    std::getline(std::cin, auxs);
    aux->set_nome_residuo(auxs);
    std::cout << "\n Digite o volume/peso do residuo(utilize L ou KG na frente para identificar): ";
    std::getline(std::cin, auxs);
    aux->set_peso_residuo(auxs);*/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n Digite o nome do usuario: ";
    std::getline(std::cin, auxs);
    aux->setNome(auxs);
    std::cout << "\n Digite (P) para digitar o cpf | Digite (E) para digitar o cnpj\n ";
    std::cin >> opcao;
    while (opcao != 'P' && opcao != 'p' && opcao != 'E' && opcao != 'e'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Opcao invalida, digite novamente :";
        std::cin >> opcao;
    }
    if (opcao == 'p' || opcao == 'P'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n Digite o cpf do usuario: ";
        std::getline(std::cin, auxs);
        aux->setCpf(auxs);
        aux->setPessoaEmpresa(false);
    }
    else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n Digite o cnpj do usuario: ";
        std::getline(std::cin, auxs);
        aux->setCnpj(auxs);
        aux->setPessoaEmpresa(true);
    }
    std::cout << "\n Digite o endereco do usuario: ";
    std::getline(std::cin, auxe);
    aux->setEndereco(auxe);
    listaUsuarios.push_back(aux);

}

void gerenciamento::modificaUsuario(){
    char opcao;
    char op;
    bool j = false;//vê se achou algum resultado compativel
    std::string aux, auxs, auxe;
    std::cout << "\n=========================================================\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << " Digite o nome do usuario que deseja modificar: ";
    std::getline(std::cin, aux);
    std::list <usuario*>::iterator it;
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        if(strcmp((*it)->getNome().c_str(), aux.c_str()) == 0){
            std::cout << "\n            <<<USUARIO ENCONTRADO!>>>     ";
            std::cout <<"\n Nome do usuario : "<<(*it)->getNome();
            std::cout <<"\n Tipo de usuario :";
            if((*it)->getTipoUsuario() == false)
                std::cout <<" Doador";
            else
                std::cout <<" Receptor";
            if((*it)->getPessoaEmpresa() == false)
                std::cout<<"\n Cpf do usuario : "<<(*it)->getCpf();
            else
                std::cout<<"\n Cnpj do usuario : "<<(*it)->getCnpj();
            std::cout<<"\n Endereco do usuario : "<<(*it)->getEndereco();
            std::cout<<"\n         <<<Modifique os dados do usuario>>>";
            std::cout << "\n Digite o novo nome do usuario: ";
            std::getline(std::cin, auxs);
            (*it)->setNome(auxs);
            std::cout << "\n Digite:\n (1) Se o usuario for um doador | (2) Se o usuario for um receptor\n : ";
            std::cin >> op;
            while(op != '1' && op != '2'){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Opcao invalida, digite novamente :";
                std::cin >> op;
                }
            if(op == '1')
                (*it)->setTipoUsuario(false);
            else
                (*it)->setTipoUsuario(true);
            std::cout << "\n Digite (P) para digitar o cpf | Digite (E) para digitar o cnpj\n ";
            std::cin >> opcao;
            while (opcao != 'P' && opcao != 'p' && opcao != 'E' && opcao != 'e'){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Opcao invalida, digite novamente :";
                std::cin >> opcao;
            }
            if (opcao == 'p' || opcao == 'P'){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n Digite o novo cpf do usuario: ";
                std::getline(std::cin, auxs);
                (*it)->setCpf(auxs);
                (*it)->setPessoaEmpresa(false);
            }
            else{
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n Digite o novo cnpj do usuario: ";
                std::getline(std::cin, auxs);
                (*it)->setCnpj(auxs);
                (*it)->setPessoaEmpresa(true);
            }
            std::cout << "\n Digite o novo endereco do usuario: ";
            std::getline(std::cin, auxs);
            (*it)->setEndereco(auxs);
            j= true;
        }
    }
    if(j==false){
        std::cout <<"\n              <<<USUARIO NAO ENCONTRADO!!!>>>";

    }
}

void gerenciamento::removeUsuario(){
    std::string aux;
    std::cout << "\n=========================================================\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << " Digite o nome do usuario que deseja remover: ";
    std::getline(std::cin, aux);
    int i=0;
    int j=0;
    std::list <usuario*>::iterator it;
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        if(strcmp((*it)->getNome().c_str(), aux.c_str()) == 0){
            listaUsuarios.remove(*it);
            std::cout << "\n                            <<<USUARIO REMOVIDO!!!>>";
            i++;
            break;
        }
        j++;
    }
    if(i == 0)
        std::cout <<"\n                            <<<USUARIO NAO ENCONTRADO!!!>>>";
}
