#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <iostream>
#include <string>
#include <ctime>
#include ".\enums.hpp"
#include ".\time.hpp"
#include ".\utilities.hpp"

class evento
{
private:
    std::string nome;
    eventos_sprint tipo;
    status_evento status;
    tm inicio;
    tm fim;
    adts::Lista<membros> participantes;
    scrum_team time;

public:
    evento(/* args */);
    ~evento();
    void iniciar();
    void encerrar();
    bool adicionarParticipantes(membros participante);
    bool removerParticipantes(membros participante);
    tm duracao();
    // fazer os gets e sets
};

#endif