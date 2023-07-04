#include "../include/evento.hpp"
#include "../include/time.hpp"
#include "../include/utilities.hpp"

evento::evento(std::string _nome, eventos_sprint _tipo, geren_tempo::tempo _inicio, geren_tempo::tempo _fim, adts::Lista<membros> _part, scrum_team _time)
{
    this->nome = _nome;
    this->tipo = _tipo;
    this->status = analise;
    this->inicio = _inicio;
    this->fim = _fim;
    this->participantes = _part;
    this->time = _time;
}
evento::~evento()
{
    participantes.clear();
}
void evento::iniciar()
{
    this->status = andamento;
}
void evento::encerrar()
{
    this->status = finalizado;
}
bool evento::adicionarParticipantes(membros participante)
{
    // ordenar participantes
    // procurar se existe
    if (participantes.find(participante))
    {
        this->participantes.push_front(participante);
        return true;
    }
    return false;
}
bool evento::removerParticipantes(membros participante)
{
    // ordenar participantes
    // procurar se existe
    if (participantes.find(participante))
    {
        participantes.remove(participante);
        return true;
    }
    return false;
}
// AGUARDANDO IMPLEMENTAÇÂO DE OPERATOR-(TEMPO, TEMPO)
geren_tempo::tempo evento::duracao()
{
    // return inicio - fim;
    // date::days temp = date::floor<date::days>(date::sys_days(date::year_month_day(inicio.GetAno(), inicio.GetMes(), inicio.GetDia())));

    // fim -
    //     return inicio;
}

// GETTERS//

std::string evento::GetNome()
{
    return this->nome;
}
eventos_sprint evento::GetTipo()
{
    return this->tipo;
}
status_evento evento::GetStatus()
{
    return this->status;
}
prioridade evento::GetPrioridade()
{
    return this->prio;
}
geren_tempo::tempo evento::GetInicio()
{
    return this->inicio;
}
geren_tempo::tempo evento::GetFim()
{
    return this->fim;
}
adts::Lista<membros> const evento::GetParticipantes()
{
    return this->participantes;
}
scrum_team evento::GetTime()
{
    return this->time;
}

// SETTERS

void evento::SetNome(std::string nome)
{
    this->nome = nome;
}
void evento::SetTipo(eventos_sprint tipo)
{
    this->tipo = tipo;
}
void evento::SetStatus(status_evento status)
{
    this->status = status;
}
void evento::SetPrioridade(prioridade prio)
{
    this->prio = prio;
}
void evento::SetInicio(geren_tempo::tempo inicio)
{
    this->inicio = inicio;
}
void evento::SetFim(geren_tempo::tempo fim)
{
    this->fim = fim;
}
void evento::SetTime(scrum_team time)
{
    this->time = time;
}