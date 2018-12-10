#include "gerenciamento.h"
#include <list>
gerenciamento::gerenciamento(){
    this->cpf= "";
    this->nome= "";
    this->endereco= "";
    this->cnpj= "";
    this->tipoUsuario = false;
    this->nome_residuo = "";
    this->peso_residuo = "";
    this->solidoLiquido = false;
}


void gerenciamento::adicionaUsuario(){
    std::cout<<"\n===========================================================================================\n";
    std::cout << "                                  <<<CADASTRO DE USUARIO>>>";
    std::cout<<"\n===========================================================================================\n";
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

    aux->set_nome_residuo(tipoResiduo()); //chama a funcao tipoResiduo para dar o nome do residuo
    aux->set_peso_residuo(setPesoResiduo()); //chama a funcao getPesoResiduo para pegar o peso do residuo
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << " Digite o nome do usuario: ";
    std::getline(std::cin, auxs);
    aux->setNome(auxs);
    std::cout << " Digite (P) para digitar o cpf | Digite (E) para digitar o cnpj\n: ";
    std::cin >> opcao;
    while (opcao != 'P' && opcao != 'p' && opcao != 'E' && opcao != 'e'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Opcao invalida, digite novamente :";
        std::cin >> opcao;
    }
    if (opcao == 'p' || opcao == 'P'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Digite o cpf do usuario: ";
        std::getline(std::cin, auxs);
        aux->setCpf(auxs);
        aux->setPessoaEmpresa(false);
    }
    else{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Digite o cnpj do usuario: ";
        std::getline(std::cin, auxs);
        aux->setCnpj(auxs);
        aux->setPessoaEmpresa(true);
    }
    std::cout << " Digite o endereco do usuario: ";
    std::getline(std::cin, auxe);
    aux->setEndereco(auxe);
    listaUsuarios.push_back(aux);

}

void gerenciamento::modificaUsuario(){
    char opcao;
    char op;
    bool j = false;//vê se achou algum resultado compativel
    std::string aux, auxs, auxe;
    std::cout<<"\n===========================================================================================\n";
    std::cout << "                                   <<<MODIFICACAO DE USUARIO>>>";
    std::cout<<"\n===========================================================================================\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << " Digite o nome do usuario que deseja modificar: ";
    std::getline(std::cin, aux);
    std::list <usuario*>::iterator it;
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        if(strcmp((*it)->getNome().c_str(), aux.c_str()) == 0){
            std::cout << "\n            <<<USUARIO ENCONTRADO!>>>     ";
            std::cout << "\n Nome do usuario: "<<(*it)->getNome();
            std::cout << "\n Tipo de usuario:";
            if((*it)->getTipoUsuario() == false)
                std::cout <<" Doador";
            else
                std::cout <<" Receptor";
            std::cout << "\n Tipo de residuo: "<<(*it)->get_nome_residuo();
            std::cout << "\n Peso/Volume do residuo: "<<(*it)->getPesoResiduo();
            if((*it)->getPessoaEmpresa() == false)
                std::cout<<"\n Cpf do usuario : "<<(*it)->getCpf();
            else
                std::cout<<"\n Cnpj do usuario : "<<(*it)->getCnpj();
            std::cout<<"\n Endereco do usuario : "<<(*it)->getEndereco();
            std::cout<<"\n         <<<Modifique os dados do usuario>>>";
            std::cout << "\n Digite o novo nome do usuario: ";
            std::getline(std::cin, auxs);
            (*it)->setNome(auxs);
            (*it)->set_nome_residuo(tipoResiduo()); //chama a funcao tipoResiduo para dar o nome do residuo
            (*it)->set_peso_residuo(setPesoResiduo()); //chama a funcao getPesoResiduo para pegar o peso do residuo
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
    std::cout<<"\n===========================================================================================\n";
    std::cout << "                                      <<<REMOCAO DE USUARIO>>>";
    std::cout<<"\n===========================================================================================\n";
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

std::string gerenciamento::tipoResiduo(){
    std::string aux;
    char op;
    std::cout << " Escolha o tipo de residuo: \n"<< " (1) Solido | (2)  Liquido \n: ";
    std::cin >> op;
    while(op != '1' && op != '2'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Opcao invalida, tente novamente: ";
        std::cin >> op;
    }
    if(op == '1'){
        this->solidoLiquido = false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Escolha o tipo de residuo solido: \n (1) Papel | (2) Plastico | (3) Vidro | (4) Metal \n: ";
        std::cin >> op;
        while(op != '1' && op != '2' && op != '3' && op != '4'){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Opcao invalida, tente novamente: ";
                std::cin >> op;
        }
        if(op == '1')
            aux = "Papel";
        else if(op == '2')
            aux = "Plastico";
        else if(op == '3')
            aux = "Vidro";
        else
            aux = "Metal";
    }
    else{
        this->solidoLiquido = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Escolha o tipo de residuo liquido: \n (1) Organico | (2) Quimico \n: ";
        std::cin >> op;
        while(op != '1' && op != '2'){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << " Opcao invalida, tente novamente: ";
                std::cin >> op;
        }
        if(op == '1')
            aux = "Liquido Organico";
        else
            aux = "Liquido Quimico";
    }
    return aux;
}

std::string gerenciamento::setPesoResiduo(){
    std::string aux, result;
    if(this->solidoLiquido == false){
        std::cout << " Digite o peso do residuo em kg (Ex: 2; 0,5; 6): ";
        std::cin >> aux;
        result = aux + "KG";
    }
    else{
        std::cout << " Digite o volume do residuo em litros (Ex: 2; 0,5; 6): ";
        std::cin >> aux;
        result = aux + "L";
    }
    return result;
}
