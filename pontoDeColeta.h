#ifndef PONTODECOLETA_H
#define PONTODECOLETA_H
#include "gerenciamento.h"
#include <iostream>

class pontoDeColeta : public gerenciamento{
    protected:
        static std::string enderecoDeEscolha;
    public:
        pontoDeColeta();
        std::string getEnderecoDeEscolha();
        void setEnderecoDeEscolha(std::string);
        void escolherEndereco();
        std::string enderecosDosUsuarios();
};

#endif
