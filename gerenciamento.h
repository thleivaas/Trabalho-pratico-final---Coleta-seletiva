#ifndef GERENCIAMENTO_H_INCLUDED
#define GERENCIAMENTO_H_INCLUDED

#include "usuario.h"

class gerenciamento : public usuario {
    public:
        gerenciamento();
        void imprimeUsuarios();
        void adicionaUsuario();
        void removeUsuario();
        void modificaUsuario();
};


#endif // GERENCIAMENTO_H_INCLUDED
