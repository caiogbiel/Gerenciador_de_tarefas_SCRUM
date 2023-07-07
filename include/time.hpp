#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
// #include <chrono>
// #include "./evento.hpp"
#include "./enums.hpp"
#include "./utilities.hpp"

class membros
{
private:
    std::string nome;
    geren_tempo::tempo data_nascimento;
    std::string email;
    std::chrono::hours HorasTrabalhadas;
    permissao nivel_de_permissao;
    adts::Lista<eventos_sprint> eventos;

public:
    membros() {}
    membros(std::string _nome, permissao _per, geren_tempo::tempo _data_nascimento) : nome(_nome), nivel_de_permissao(_per), data_nascimento(_data_nascimento) {}
    ~membros() {}
    bool operator==(const membros &b);

    //     // GETTERS
    //     std::string getNome();
    //     geren_tempo::tempo getData_nascimento();
    //     std::string getEmail();
    //     geren_tempo::tempo getHorasTrabalhadas();
    permissao getNivelDePermissao();
    //     adts::Lista<eventos_sprint> getEventos();

    //     // SETTERS
    void setNome(std::string nome);
    //     void setData_nascimento(tm data_nascimento);
    //     void setEmail(std::string email);
    //     void setHorasTrabalhadas(tm HorasTrabalhadas);
    void setNivelDePermissao(permissao nivel);
    //     void setEventos(eventos_sprint eventos);
    friend std::ostream &
    operator<<(std::ostream &o, const membros &m)
    {
        o << "Nome: " << m.nome << " - " << permissao_para_string(m.nivel_de_permissao);
        return o;
    }
};

class scrum_team
{
private:
    adts::Lista<membros> _participantes;
    int _quantidade;
    adts::Lista<eventos_sprint> _eventos;

public:
    scrum_team() {}
    scrum_team(adts::Lista<membros> participantes, adts::Lista<eventos_sprint> eventos) : _participantes(participantes), _eventos(eventos) {}
    ~scrum_team(){};
    bool addParticipante(membros novoMembro);
    bool removeParticipante(membros membros);
    membros operator[](int indice);
    // membros &operator[](int indice) const;

    // // GETTERS
    adts::Lista<membros> getParticipantes();
    int getQuantidade();
    adts::Lista<eventos_sprint> getEventos();

    // // SETTERS
    // void setEquipe(membros equipe);
    // void setQuantidade(int quantidade);
    // void setEventos(eventos_sprint eventos);
};
#endif
