#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <iostream>
#include <string>
#include <ctime>
#include "./enums.hpp"
#include "./time.hpp"
#include "./utilities.hpp"

class evento
{
private:
    std::string nome;
    eventos_sprint tipo;
    status_evento status;
    prioridade prio;
    tm inicio;
    tm fim;
    adts::Lista<membros> participantes;
    scrum_team time;

public:
    evento(std::string _nome, eventos_sprint _tipo, tm _inicio, tm _fim, adts::Lista<membros> _part, scrum_team _time);
    ~evento();
    void iniciar();
    void encerrar();
    bool adicionarParticipantes(membros participante);
    bool removerParticipantes(membros participante);
    tm duracao();
    // GETTERS
    std::string GetNome();
    eventos_sprint GetTipo();
    status_evento GetStatus();
    prioridade GetPrioridade();
    tm GetInicio();
    tm GetFim();
    adts::Lista<membros> const GetParticipantes();
    scrum_team GetTime();
    // SETTERS
    void SetNome(std::string nome);
    void SetTipo(eventos_sprint tipo);
    void SetStatus(status_evento status);
    void SetPrioridade(prioridade prioridade);
    void SetInicio(tm inicio);
    void SetFim(tm fim);
    void SetTime(scrum_team time);
};

#endif