#ifndef AGENDAMENTO_H_INCLUDED
#define AGENDAMENTO_H_INCLUDED
#include "pontoDeColeta.h"
#include "usuario.h"

class agendamento : public pontoDeColeta {
    private:
        static std::string hora, data, nomeDoador, nomeReceptor;
        static bool confirmaEncontro; //false o encontro ainda nao aconteceu, true ja aconteceu
    public:
        agendamento();
        std::string getNomeDoador();
        std::string getNomeReceptor();
        void setNomeDoador(std::string);
        void setNomeReceptor(std::string);
        bool getConfirmaEncontro();
        void setConfirmaEncontro(bool);
        void agendamentoCompleto();
        void setNumeroDoador(int);
        void setNumeroReceptor(int);
        int getNumeroDoador ();
        int getNumeroReceptor ();
        void agendar();
        std::string getHora();
        std::string getData();
        void setHora(std::string);
        void setData(std::string);
};


#endif // AGENDAMENTO_H_INCLUDED
