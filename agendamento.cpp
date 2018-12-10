#include "agendamento.h"
void agendamento::agendar(){
    agendamento aux;
    std::string hora, data;
    std::cout << "\n Digite a data do encontro (DD/MM, colocar o '/'): ";
    std::getline(std::cin, data);
    aux.setData(data);
    std::cout << "\n Digite a hora do encontro (HH:MM, colocar os 2 ponto ':'): ";
    std::getline(std::cin, hora);
    aux.setHora(hora);
    horaData.push_back(aux);

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

