#include "pontoDeColeta.h"
std::string pontoDeColeta::enderecoDeEscolha;
pontoDeColeta::pontoDeColeta(){
}

std::string pontoDeColeta::enderecosDosUsuarios(){
    std::list <usuario*>::iterator it;
    std::string endereco;
    int op;
    int i=1;
    int j=0;
    std::cout << " Escolha o numero (indicado na frente do usuario e endereco) desejado: \n";
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        std::cout <<"\n Nome do usuario ("<<j+1<<"): "<<(*it)->getNome();
        std::cout <<"\n Tipo de usuario : ";
        if((*it)->getTipoUsuario() == false)
            std::cout <<"Doador";
        else
            std::cout <<"Receptor";
        if((*it)->getPessoaEmpresa() == false)
        std::cout<<"\n Endereco do usuario ("<<j+1<<"): "<<(*it)->getEndereco();
        j++;
        std::cout <<"\n";
    }
    std::cout << ": ";
    std::cin >> op;
    while(op > j+1 || op<1){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout <<" Opcao invalida, tente novamente: ";
        std::cin >> op;
    }
    for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
        if(i == op){
            endereco = (*it)->getEndereco();
        }
        i++;
    }
    return endereco;
 }

void pontoDeColeta::escolherEndereco(){
    pontoDeColeta *aux = new pontoDeColeta() ;
    std::string auxs;
    char opcao;
    int op;
    std::cout<<"\n===========================================================================================\n";
    std::cout << "                                        <<<PONTO DE COLETA>>>";
    std::cout<<"\n===========================================================================================\n";
    std::cout << " Digite a opcao desejada para determinar o endereco do ponto de coleta:";
    std::cout << "\n (D) Digitar endereco combinado | (U) Usar endereco de um usuario \n ";
    std::cin >> opcao;

    while (opcao != 'D' && opcao != 'd' && opcao != 'U' && opcao != 'u'){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n Opcao invalida, tente novamente: ";
        std::cin >> opcao;
    }

    if(opcao == 'D' || opcao == 'd'){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n Digite o endereco combinado: ";
    std::getline(std::cin, auxs);
    aux->setEnderecoDeEscolha(auxs);
    }
    else{
        aux->setEnderecoDeEscolha(enderecosDosUsuarios());
    }
    std::cout <<"\n O endereco escolhido foi: "<< aux->getEnderecoDeEscolha();

}
std::string pontoDeColeta::getEnderecoDeEscolha(){
    return this->enderecoDeEscolha;
}
void pontoDeColeta::setEnderecoDeEscolha(std::string endereco){
    this->enderecoDeEscolha=endereco;
}
