#include "agendamento.h"
std::string agendamento::hora;
std::string agendamento::data;
std::string agendamento::nomeDoador;
std::string agendamento::nomeReceptor;
bool agendamento::confirmaEncontro;

agendamento::agendamento(){
}

void agendamento::agendar(){
    std::list <usuario*>::iterator it;
    bool pegou = false;
    agendamento aux;
    std::string residuo, auxs;
    std::cout<<"\n===========================================================================================\n";
    std::cout << "                                           <<<AGENDAMENTO>>>";
    std::cout<<"\n===========================================================================================\n";
    std::cout << "\n Digite: \n (0) Para verificar agendamento | (1) Para agendar | (2) Confirmar a realizacao do encontro\n: ";
    std::cin >> auxs;
    while(auxs != "0" && auxs != "1" && auxs != "2"){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcao invalida, tente novamente: ";
        std::cin >> auxs;

    }
    if(auxs == "0")
        aux.agendamentoCompleto();
    else if(auxs == "2"){
        std::cout << "\n O encontro foi realizado com sucesso!";
        aux.setConfirmaEncontro(true);
    }
    else{
        residuo = tipoResiduo();
        //mostra os nomes dos doadores do residuo
        aux.setConfirmaEncontro(false);
        std::cout << "\n Doadores do residuo("<<residuo<<"): \n";
        for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
            if((*it)->getTipoUsuario() == false){
                if((*it)->get_nome_residuo() == residuo){
                    std::cout <<"\n Nome do usuario: "<<(*it)->getNome();
                    std::cout <<"\n Tipo de usuario : ";
                    if((*it)->getTipoUsuario() == false)
                        std::cout <<"Doador";
                    else
                        std::cout <<"Receptor";
                    if((*it)->getPessoaEmpresa() == false)
                    std::cout<<"\n Endereco do usuario: "<<(*it)->getEndereco();
                    std::cout <<"\n";

                    }
            }
        }
        //pega e testa para ver se bate com o tipo de residuo e o tipo de usuario (doador ou receptor)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n Digite o nome do doador que deseja agendar com o receptor: ";
        std::getline(std::cin, auxs);
        do{
            for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
                if((*it)->getTipoUsuario() == false){
                    if((*it)->get_nome_residuo() == residuo){
                            if((*it)->getNome() == auxs){
                                pegou = true;
                                aux.setNomeDoador(auxs);
                            }
                    }
                }
            }
            if(pegou == false){
                std::cout << "\n Nome de usuario nao bate com o tipo de residuo ou usuario nao e doador, tente novamente ou digite 0 para sair: ";
                std::getline(std::cin, auxs);
                if(auxs == "0"){
                    break;
                }
            }
        }while(pegou == false);
        pegou = false;
        //mostra os nomes dos receptores do residuo
        std::cout << "\n Receptores do residuo("<<residuo<<"): \n";
        for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
            if((*it)->getTipoUsuario() == true){
                if((*it)->get_nome_residuo() == residuo){
                    std::cout <<"\n Nome do usuario: "<<(*it)->getNome();
                    std::cout <<"\n Tipo de usuario: ";
                    if((*it)->getTipoUsuario() == false)
                        std::cout <<"Doador";
                    else
                        std::cout <<"Receptor";
                    if((*it)->getPessoaEmpresa() == false)
                    std::cout<<"\n Endereco do usuario: "<<(*it)->getEndereco();
                    std::cout <<"\n";

                    }
            }
        }
        //pega o nome e testa para ver se bate com o residuo e o tipo de usuario (doador ou receptor)
        std::cout << "\n Digite o nome do receptor que deseja agendar com o doador: ";
        std::getline(std::cin, auxs);
        do{
            for(it = listaUsuarios.begin(); it!= listaUsuarios.end(); it++){
                if((*it)->getTipoUsuario() == true){
                    if((*it)->get_nome_residuo() == residuo){
                            if((*it)->getNome() == auxs){
                                aux.setNomeReceptor(auxs);
                                pegou = true;
                            }
                    }
                }
            }
            if(pegou == false){
                std::cout << "\n Nome de usuario nao bate com o tipo de residuo ou usuario nao e receptor, tente novamente ou digite 0 para sair: ";
                std::getline(std::cin, auxs);
                if(auxs == "0"){
                    break;
                }
            }
        }while(pegou == false);
        std::string hora, data;
        std::cout << "\n Digite o data do encontro (ex: 26/04): ";
        std::getline(std::cin, data);
        aux.setData(data);
        std::cout << "\n Digite a hora do encontro (ex: 12:30): ";
        std::getline(std::cin, hora);
        aux.setHora(hora);
        aux.agendamentoCompleto();
    }
}
void agendamento::agendamentoCompleto(){
    int i = 0;
    agendamento aux;
    std::list <usuario*>::iterator it;
    std::cout << "\n O encontro no dia "<<aux.getData()<<" as "<<aux.getHora();
    std::cout << "\n Entre o doador: "<<aux.getNomeDoador();
    std::cout << "\n E o receptor: "<<aux.getNomeReceptor();
    std::cout << "\n No endereco do ponto de coleta: "<<aux.getEnderecoDeEscolha();
    if(aux.getConfirmaEncontro() == true)
        std::cout << "\n Foi realizado com sucesso!";
    else
        std::cout << "\n Ainda nao foi realizado!";
}

std::string agendamento::getHora(){
    return this->hora;
}


std::string agendamento::getData(){
    return this->data;
}


void agendamento::setHora(std::string hora){
    this->hora = hora;
}


void agendamento::setData(std::string data){
    this->data= data;
}

bool agendamento::getConfirmaEncontro(){
    return confirmaEncontro;
}
void agendamento::setConfirmaEncontro(bool confirma){
    confirmaEncontro = confirma;
}
std::string agendamento::getNomeDoador(){
    return nomeDoador;
}
std::string agendamento::getNomeReceptor(){
    return nomeReceptor;
}
void agendamento::setNomeDoador(std::string nome){
    nomeDoador = nome;
}
void agendamento::setNomeReceptor(std::string nome){
    nomeReceptor = nome;
}
