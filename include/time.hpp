#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <ctime>
// #include "./evento.hpp"
#include "./enums.hpp"
#include "./utilities.hpp"

class membros
{
private:
    std::string nome;
    tm dataDeNascimento;
    std::string email;
    tm HorasTrabalhadas;
    permissao nivelDePermissao;
    adts::Lista<eventos_sprint> eventos;

public:
    membros();
    ~membros();
    bool operator==(const membros &b);

    //     // GETTERS
    //     std::string getNome();
    //     tm getDataDeNascimento();
    //     std::string getEmail();
    //     tm getHorasTrabalhadas();
    //     permissao getNivelDePermissao();
    //     adts::Lista<eventos_sprint> getEventos();

    //     // SETTERS
    //     void setNome(std::string nome);
    //     void setDataDeNascimento(tm dataDeNascimento);
    //     void setEmail(std::string email);
    //     void setHorasTrabalhadas(tm HorasTrabalhadas);
    //     void setNivelDePermissao(permissao nivelDePermissao);
    //     void setEventos(eventos_sprint eventos);
};

class scrum_team
{
private:
    adts::Lista<membros> participantes;
    int quantidade;
    adts::Lista<eventos_sprint> eventos;

public:
    scrum_team();
    ~scrum_team();

     void addParticipante==(membros membros);
    // void removeParticipante(membros membros);
    // membros operator[](int indice);
    // membros &operator[](int indice) const;

    // // GETTERS
    // adts::Lista<membros> getParticipantes();
    // int getQuantidade();
    // adts::Lista<eventos_sprint> getEventos();

    // // SETTERS
    // void setEquipe(membros equipe);
    // void setQuantidade(int quantidade);
    // void setEventos(eventos_sprint eventos);
};
#endif
