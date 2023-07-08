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
    std::string _nome;
    geren_tempo::tempo _data_nascimento;
    std::string _email;
    std::chrono::hours _horas_trabalhadas;
    permissao _nivel_permissao;
    adts::Lista<evento> _eventos;

public:
    membros() {}
    membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento) : _nome(nome), _nivel_permissao(per), _data_nascimento(data_nascimento) {}
    membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento, std::string email, std::chrono::hours horas_trabalhadas, adts::Lista<evento> eventos) : _nome(nome), _nivel_permissao(per), _data_nascimento(data_nascimento), _email(email), _horas_trabalhadas(horas_trabalhadas), _eventos(eventos) {}
    ~membros() { std::cout << "deletando membro " << this << '\n'; }
    bool operator==(const membros &b);

    // GETTERS
    std::string getNome();
    geren_tempo::tempo getData_nascimento();
    std::string getEmail();
    std::chrono::hours getHorasTrabalhadas();
    permissao getNivelDePermissao();
    adts::Lista<evento> getEventos();

    // SETTERS
    void setNome(std::string _nome);
    void setData_nascimento(geren_tempo::tempo _data_nascimento);
    void setEmail(std::string _email);
    void setHorasTrabalhadas(std::chrono::hours _horas_trabalhadas);
    void setNivelDePermissao(permissao nivel);
    void setEventos(adts::Lista<evento> _eventos);
    friend std::ostream &
    operator<<(std::ostream &o, const membros &m)
    {
        o << "Nome: " << m._nome << " - " << permissao_para_string(m._nivel_permissao);
        return o;
    }
};

class scrum_team
{
private:
    adts::Lista<membros> _participantes;
    int _quantidade;
    adts::Lista<evento> _eventos;

public:
    scrum_team() {}
    scrum_team(adts::Lista<membros> participantes, adts::Lista<evento> _eventos) : _participantes(participantes), _eventos(_eventos) {}
    ~scrum_team() { std::cout << "deletando time" << this << '\n'; };
    bool addParticipante(membros novoMembro);
    bool removeParticipante(membros membros);
    // membros operator[](int indice);
    // membros &operator[](int indice) const;

    // // GETTERS
    adts::Lista<membros> getParticipantes();
    int getQuantidade();
    adts::Lista<evento> getEventos();

    // // SETTERS
    void setEquipe(membros equipe);
    void setQuantidade(int quantidade);
    void setEventos(evento _eventos);
};
#endif