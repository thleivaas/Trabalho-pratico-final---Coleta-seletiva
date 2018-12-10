#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>
#include <iostream>
#include <list>
#include <limits>
#include <cstring>
class usuario{
    protected:
        std::string cpf, nome, endereco, cnpj, nome_residuo, peso_residuo;
        bool tipoUsuario, pessoaEmpresa, solidoLiquido;//false para solido e true para liquido; //tipo usuario se for false é doador e se for true é receptor, se pessoaEmpresa for false é uma pessoa e se for true é uma emrpesa;
    public:
        static std::list <usuario*> listaUsuarios;
        bool operator == (const usuario& s) const { return nome == s.nome; }
        bool operator != (const usuario& s) const { return !operator==(s); }
        std::string getNome();
        std::string getCpf();
        std::string getCnpj();
        std::string getEndereco();
        bool getPessoaEmpresa();
        bool getTipoUsuario();
        void setNome(std::string );
        void setCpf(std::string);
        void setCnpj(std::string);
        void setEndereco(std::string);
        void setPessoaEmpresa(bool);
        void setTipoUsuario(bool);
        std::string get_nome_residuo();
        std::string getPesoResiduo();
        void set_nome_residuo(std::string);
        void set_peso_residuo(std::string);
        void formaDeArmazenamento();
        void imprimeUsuarios();
};

#endif // USUARIO_H_INCLUDED
