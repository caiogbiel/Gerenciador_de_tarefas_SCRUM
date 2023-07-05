#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <iostream>
#include <string>
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
    geren_tempo::tempo inicio;
    geren_tempo::tempo fim;
    adts::Lista<membros> participantes;
    scrum_team time;

public:
    evento(std::string _nome, eventos_sprint _tipo, geren_tempo::tempo _inicio, geren_tempo::tempo _fim, adts::Lista<membros> _part, scrum_team _time, prioridade _prio);
    ~evento();
    void iniciar();
    void encerrar();
    bool adicionarParticipantes(membros participante);
    bool removerParticipantes(membros participante);
    geren_tempo::tempo duracao();
    // GETTERS
    std::string GetNome();
    eventos_sprint GetTipo();
    status_evento GetStatus();
    prioridade GetPrioridade();
    geren_tempo::tempo GetInicio();
    geren_tempo::tempo GetFim();
    adts::Lista<membros> const GetParticipantes();
    scrum_team GetTime();
    // SETTERS
    void SetNome(std::string nome);
    void SetTipo(eventos_sprint tipo);
    void SetStatus(status_evento status);
    // void SetPrioridade(prioridade prioridade);
    void SetInicio(geren_tempo::tempo inicio);
    void SetFim(geren_tempo::tempo fim);
    void SetTime(scrum_team time);
};

#endif