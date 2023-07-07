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
    std::string _nome;
    geren_tempo::tempo _data_nascimento;
    std::string _email;
    std::chrono::hours _horas_trabalhadas;
    permissao _nivel_permissao;
    adts::Lista<eventos_sprint> _eventos;

public:
    membros() {}
    membros(std::string __nome, permissao __per, geren_tempo::tempo __data_nascimento) : _nome(__nome), _nivel_permissao(__per), _data_nascimento(__data_nascimento) {}
    membros(std::string __nome, permissao __per, geren_tempo::tempo __data_nascimento, std::string __email, std::chrono::hours __horas_trabalhadas) {}
    ~membros() {}
    bool operator==(const membros &b);

    // GETTERS
    std::string getNome();
    geren_tempo::tempo getData_nascimento();
    std::string getEmail();
    std::chrono::hours getHorasTrabalhadas();
    permissao getNivelDePermissao();
    //     adts::Lista<eventos_sprint> getEventos();

    // SETTERS
    void setNome(std::string _nome);
    void setData_nascimento(geren_tempo::tempo _data_nascimento);
    void setEmail(std::string _email);
    void setHorasTrabalhadas(std::chrono::hours _horas_trabalhadas);
    void setNivelDePermissao(permissao nivel);
    //     void setEventos(eventos_sprint _eventos);
    friend std::ostream &
    operator<<(std::ostream &o, const membros &m)
    {
        o << "_nome: " << m._nome << " - " << permissao_para_string(m._nivel_permissao);
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
    scrum_team(adts::Lista<membros> participantes, adts::Lista<eventos_sprint> _eventos) : _participantes(participantes), _eventos(_eventos) {}
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
    void setEquipe(membros equipe);
    void setQuantidade(int quantidade);
    void setEventos(eventos_sprint _eventos);
};
#endif
