#ifndef GERENCIAMENTO_H_INCLUDED
#define GERENCIAMENTO_H_INCLUDED

#include "usuario.h"

class gerenciamento : public usuario {
    public:
        gerenciamento();
        //void imprimeUsuarios();
        void adicionaUsuario();
        void removeUsuario();
        void modificaUsuario();
        std::string tipoResiduo();
        std::string setPesoResiduo();
};


#endif // GERENCIAMENTO_H_INCLUDED
