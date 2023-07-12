#include "../include/evento.hpp"
#include "../include/time.hpp"
#include "../include/utilities.hpp"
#include "../include/gerenciador.hpp"

evento::~evento()
{
}

evento::evento()
{
    this->_id_participantes = adts::Lista<int>();
    this->_id = eventos_global_id;
    ++eventos_global_id;
}

evento::evento(std::string nome, eventos_sprint tipo, adts::Lista<int> id_part, int id_time, prioridade prio)
{
    this->_nome = nome;
    this->_tipo = tipo;
    this->_status = analise;
    this->_id_participantes = id_part;
    this->_id_time = id_time;
    this->_prio = prio;

    this->_id = eventos_global_id;
    ++eventos_global_id;
}

evento::evento(std::string nome, eventos_sprint tipo, geren_tempo::tempo inicio, geren_tempo::tempo fim, adts::Lista<int> id_part, int id_time, prioridade prio)
{
    this->_nome = nome;
    this->_tipo = tipo;
    this->_status = analise;
    this->_inicio = inicio;
    this->_fim = fim;
    this->_id_participantes = id_part;
    this->_id_time = id_time;
    this->_prio = prio;

    this->_id = eventos_global_id;
    ++eventos_global_id;
}
void evento::iniciar()
{
    this->_status = andamento;
    this->SetInicio(geren_tempo::tempo::agora());
}
void evento::encerrar()
{
    this->_status = finalizado;
    this->SetFim(geren_tempo::tempo::agora());
    /*
    Adicionar horas de duração do evento às horas trabalhadas de todos os participantes
    */
}
bool evento::adicionarParticipantes(int participante)
{
    if (_id_participantes.find(participante))
    {
        this->_id_participantes.push_front(participante);
        return true;
    }
    return false;
}
bool evento::removerParticipantes(int participante)
{
    if (_id_participantes.find(participante))
    {
        _id_participantes.remove(participante);
        return true;
    }
    return false;
}
// AGUARDANDO IMPLEMENTAÇÂO DE OPERATOR-(TEMPO, TEMPO)
geren_tempo::tempo evento::duracao()
{
    geren_tempo::tempo d;
    d.SetMinuto(_fim.GetMinuto().count() - _inicio.GetMinuto().count());
    d.SetHora(_fim.GetHora().count() - _inicio.GetHora().count());
    d.SetDia(unsigned(_fim.GetDia()) - unsigned(_inicio.GetDia()));
    d.SetMes(unsigned(_fim.GetMes()) - unsigned(_inicio.GetMes()));
    d.SetAno(int(_fim.GetAno()) - int(_inicio.GetAno()));

    return d;
}

// GETTERS//

int evento::GetId() const
{
    return _id;
}
std::string evento::GetNome() const
{
    return this->_nome;
}
eventos_sprint evento::GetTipo() const
{
    return this->_tipo;
}
status_evento evento::GetStatus() const
{
    return this->_status;
}
prioridade evento::GetPrioridade() const
{
    return this->_prio;
}
geren_tempo::tempo evento::GetInicio() const
{
    return this->_inicio;
}
geren_tempo::tempo evento::GetFim() const
{
    return this->_fim;
}
adts::Lista<int> const evento::GetParticipantes() const
{
    return this->_id_participantes;
}
int evento::GetTime() const
{
    return this->_id_time;
}

// SETTERS

void evento::SetNome(std::string nome)
{
    this->_nome = nome;
}
void evento::SetTipo(eventos_sprint tipo)
{
    this->_tipo = tipo;
}
void evento::SetStatus(status_evento status)
{
    this->_status = status;
}
// void evento::SetPrioridade(prioridade prio)
// {
//     this->_prio = prio;
// }
void evento::SetInicio(geren_tempo::tempo inicio)
{
    this->_inicio = inicio;
}
void evento::SetFim(geren_tempo::tempo fim)
{
    this->_fim = fim;
}
void evento::SetTime(int time)
{
    this->_id_time = time;
}

std::ostream &
operator<<(std::ostream &o, const evento &e)
{
    o << e._id << "," << e._nome << "," << e._tipo << "," << e._status << "," << e._prio << "," << e._inicio << "," << e._fim << "," << e._id_time << "[";

    if (e._id_participantes.size() > 0)
    {
        for (int i = 0; i < e._id_participantes.size(); ++i)
        {
            o << e._id_participantes[i] << ",";
        }
    }
    o << "]";
    o << ";";
    return o;
}

std::istream &operator>>(std::istream &i, evento &e)
{
    char temp[512];
    std::string token;
    i.getline(temp, 512, ';');

    std::stringstream buffer(temp);
    std::stringstream auxbuffer;

    std::getline(buffer, token, ',');
    e._id = std::stoi(token);

    std::getline(buffer, token, ',');
    e._nome = token;

    std::getline(buffer, token, ',');
    e._tipo = eventos_sprint(std::stoi(token));

    std::getline(buffer, token, ',');
    e._status = status_evento(std::stoi(token));

    std::getline(buffer, token, ',');
    e._prio = prioridade(std::stoi(token));

    std::getline(buffer, token, ',');
    auxbuffer << token;
    auxbuffer >> e._inicio;

    auxbuffer.str(std::string());
    auxbuffer.clear();

    std::getline(buffer, token, ',');
    auxbuffer << token;
    auxbuffer >> e._fim;

    auxbuffer.str(std::string());
    auxbuffer.clear();

    std::getline(buffer, token, '[');
    e._id_time = std::stoi(token);

    std::getline(buffer, token, ']');
    auxbuffer << token;

    while (std::getline(auxbuffer, token, ',').good())
    {
        e._id_participantes.push_front(std::stoi(token));
    }
    return i;
}

adts::Lista<evento> &transformarEventos(adts::Lista<int> eventos)
{
    adts::Lista<evento> *lista = new adts::Lista<evento>();
    int ev_t = eventos.size();
    int to_t = todos_eventos.size();

    for (int i = 0; i < ev_t; ++i)
    {
        for (int j = 0; j < to_t; ++i)
        {
            if (eventos[i] == todos_eventos[j].GetId())
            {
                lista->push_front(todos_eventos[j]);
            }
        }
    }
    return *lista;
}