#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <iostream>
#include <string>
#include "./enums.hpp"
#include "./utilities.hpp"

class membros;
class scrum_team;

class sprint
{
};

class evento
{
private:
    int                         _id;
    std::string                 _nome;
    eventos_sprint              _tipo;
    status_evento               _status;
    prioridade                  _prio;
    geren_tempo::tempo          _inicio;
    geren_tempo::tempo          _fim;
    adts::Lista<int>            _id_participantes;
    scrum_team                  *_time;

public:
    evento();
    evento(std::string nome, eventos_sprint tipo, adts::Lista<int> part, scrum_team *time, prioridade prio);
    evento(std::string nome, eventos_sprint tipo, geren_tempo::tempo inicio, geren_tempo::tempo fim, adts::Lista<int> part, scrum_team *time, prioridade prio);
    ~evento();
    void                        iniciar();
    void                        encerrar();
    bool                        adicionarParticipantes(int participante);
    bool                        removerParticipantes(int participante);
    geren_tempo::tempo          duracao();
    // GETTERS
    int                         GetId();
    std::string                 GetNome();
    eventos_sprint              GetTipo();
    status_evento               GetStatus();
    prioridade                  GetPrioridade();
    geren_tempo::tempo          GetInicio();
    geren_tempo::tempo          GetFim();
    adts::Lista<int> const      GetParticipantes();
    scrum_team                  GetTime();
    // SETTERS
    void                        SetNome(std::string nome);
    void                        SetTipo(eventos_sprint tipo);
    void                        SetStatus(status_evento status);
    void                        SetInicio(geren_tempo::tempo inicio);
    void                        SetFim(geren_tempo::tempo fim);
    void                        SetTime(scrum_team time);
    void                        SetPrioridade(prioridade prio);

    friend std::ostream &
    operator<<(std::ostream &o, const evento &e)
    {
        o << "ID: " << e._id << " - Nome: " << e._nome << ", Tipo: " << tipo_para_string(e._tipo) << ", Prioridade: " << prioridade_para_string(e._prio) << ", Status: " << status_para_string(e._status);
        return o;
    }
};

adts::Lista<evento> &transformarEventos(adts::Lista<int> eventos);

#endif