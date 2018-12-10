#include "usuario.h"

std::string usuario::getNome(){
    return this->nome;
}

std::string usuario::getCpf(){
    return this->cpf;
}

std::string usuario::getCnpj(){
    return this->cnpj;
}

std::string usuario::getEndereco(){
    return this->endereco;
}
bool usuario::getPessoaEmpresa(){
    return this->pessoaEmpresa;
}

bool usuario::getTipoUsuario(){
    return this->tipoUsuario;
}

void usuario::setNome(std::string nome){
    this->nome = nome;
}

void usuario::setCpf(std::string cpf){
    this->cpf = cpf;
}

void usuario::setCnpj(std::string cnpj){
    this->cnpj = cnpj;
}

void usuario::setEndereco(std::string endereco){
    this->endereco = endereco;
}

void usuario::setPessoaEmpresa(bool pessoaEmpresa){
    this->pessoaEmpresa = pessoaEmpresa;
}

void usuario::setTipoUsuario(bool tipoUsuario){
    this->tipoUsuario = tipoUsuario;
}

/*void usuario::set_nome_residuo(std::string nome){
    this->nome_residuo = nome;
}
void usuario::set_peso_residuo(std::string peso ){
    this->peso_residuo = peso;
}

std::string usuario::get_nome_residuo(){
	return this->nome_residuo;
}

std::string usuario::get_peso_residuo(){
	return this->peso_residuo;
}
void usuario::formaDeArmazenamento(){
		std::cout<<"Armazenamento do Papel: "<<std::endl<<"Os residuos compostos de papel devem ser armazenados em ambiente seco, fora do alcance de animais"<<std::endl;
		std::cout<<"Armazenamento do Plastico: "<<std::endl<<"Os residuos compostos de plastico devem ser lavados, secos e em seguida armazenados de forma conjunta, fora do alcance de criancas e animais"<<std::endl;2
		std::cout<<"Armazenamento do vidro: "<<std::endl<<"Os residuos compostos de vidro devem ser lavados, e em seguida armazenados fora do alcance de criancas e animais, em recipientes resistentes (garrafas pet, cestas, etc), para facilitar o manuseio dos mesmos durante a coleta"<<std::endl;
		std::cout<<"Armazenamento do metal: "<<std::endl<<"Os residuos compostos de metal devem ser limpos, e em seguida armazenados fora do alcançe de criancas e animais, em ambiente seco"<<std::endl;
		std::cout<<"Armazenamento de residuos organicos liquidos: "<<std::endl<<"Devem ser armazenados em recipientes fechados, previamente limpos, em ambiente seco, fora do alcance de criancas e animais"<<std::endl;
		std::cout<<"Armazenamento de residuos quimicos liquidos: "<<std::endl<<"Devem ser armazenados em recipientes fechados, previamente limpos, em ambiente seco, fora do alcance de criancas e animais"<<std::endl;
}
*/
