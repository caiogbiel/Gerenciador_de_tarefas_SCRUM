#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <chrono>
#include "./evento.hpp"
#include "./enums.hpp"
#include "./utilities.hpp"

class membros
{
private:
    int                         _id;
    std::string                 _nome;
    geren_tempo::tempo          _data_nascimento;
    std::string                 _email;
    std::chrono::hours          _horas_trabalhadas;
    permissao                   _nivel_permissao;
    adts::Lista<int>            _id_eventos;
    adts::Lista<int>            _id_equipes;

public:
    membros();
    membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento);
    membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento, std::string email, std::chrono::hours horas_trabalhadas, adts::Lista<int> eventos, adts::Lista<int> equipes);
    ~membros();
    bool operator==(const membros &b);

    // GETTERS
    int                         GetId();
    std::string                 GetNome();
    geren_tempo::tempo          GetData_nascimento();
    std::string                 GetEmail();
    std::chrono::hours          GetHorasTrabalhadas();
    permissao                   GetNivelDePermissao();
    adts::Lista<int>            GetEventos();
    adts::Lista<int>            GetEquipes();

    // SETTERS
    void                        SetNome(std::string nome);
    void                        SetData_nascimento(geren_tempo::tempo data_nascimento);
    void                        SetEmail(std::string email);
    void                        SetHorasTrabalhadas(std::chrono::hours horas_trabalhadas);
    void                        SetNivelDePermissao(permissao nivel);
    void                        SetEventos(adts::Lista<int> eventos);
    void                        SetEquipes(adts::Lista<int> equipes);
    void                        SetEquipes(int equipe);

    friend std::ostream &
    operator<<(std::ostream &o, const membros &m);
    friend std::istream &
    operator>>(std::istream &i, membros &m);
};

class scrum_team
{
private:
    int                         _id;
    std::string                 _nome;
    adts::Lista<int>            _id_participantes;
    adts::Lista<int>            _id_eventos;

public:
    scrum_team();
    scrum_team(std::string nome, adts::Lista<int> id_participantes);
    scrum_team(std::string nome, adts::Lista<int> id_participantes, adts::Lista<int> id_eventos);
    ~scrum_team();
    bool                        addParticipante(int id_membro);
    bool                        removeParticipante(int id_membro);

    // // GETTERS
    int                         GetId();
    std::string                 GetNome();
    adts::Lista<int>            GetParticipantes();
    adts::Lista<int>            GetEventos();

    // // SETTERS
    void                        SetNome(std::string nome);
    void                        SetEquipe(adts::Lista<int> id_equipe);
    void                        SetEventos(adts::Lista<int> id_eventos);

    friend std::ostream &
    operator<<(std::ostream &o, const scrum_team &t);
    friend std::istream &
    operator>>(std::istream &i, scrum_team &m);
};

adts::Lista<scrum_team> &transformarEquipe(adts::Lista<int> equipes);
adts::Lista<membros>    &transformarMembros(adts::Lista<int> membros);

#endif