#ifndef EVENTO_HPP
#define EVENTO_HPP
#include <iostream>
#include <string>
#include "./enums.hpp"
#include "./utilities.hpp"

class membros;

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
    int                         _id_time;

public:
    evento();
    evento(std::string nome, eventos_sprint tipo, adts::Lista<int> part, int id_time, prioridade prio);
    evento(std::string nome, eventos_sprint tipo, geren_tempo::tempo inicio, geren_tempo::tempo fim, adts::Lista<int> part, int id_time, prioridade prio);
    ~evento();
    void                        iniciar();
    void                        encerrar();
    bool                        adicionarParticipantes(int participante);
    bool                        removerParticipantes(int participante);
    geren_tempo::tempo          duracao();
    // GETTERS
    int                         GetId() const;
    std::string                 GetNome() const;
    eventos_sprint              GetTipo() const;
    status_evento               GetStatus() const;
    prioridade                  GetPrioridade() const;
    geren_tempo::tempo          GetInicio() const;
    geren_tempo::tempo          GetFim() const;
    adts::Lista<int> const      GetParticipantes() const;
    int                         GetTime() const;
    // SETTERS
    void                        SetNome(std::string nome);
    void                        SetTipo(eventos_sprint tipo);
    void                        SetStatus(status_evento status);
    void                        SetInicio(geren_tempo::tempo inicio);
    void                        SetFim(geren_tempo::tempo fim);
    void                        SetTime(int time);

    friend std::ostream &operator<<(std::ostream &o, const evento &e);
    friend std::istream &operator>>(std::istream &i, evento &e);
};

adts::Lista<evento> &transformarEventos(adts::Lista<int> eventos);

#endif