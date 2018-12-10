#ifndef AGENDAMENTO_H_INCLUDED
#define AGENDAMENTO_H_INCLUDED
#include "pontoDeColeta.h"
#include "usuario.h"

class agendamento : public pontoDeColeta {
    private:
        std::string hora, data;
        std::list <agendamento> horaData;
    public:
        void agendar();
        std::string getHora();
        std::string getData();
        void setHora(std::string);
        void setData(std::string);
};


#endif // AGENDAMENTO_H_INCLUDED
