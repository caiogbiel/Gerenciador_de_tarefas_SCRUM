#include "../include/time.hpp"
#include "../include/utilities.hpp"
#include "../include/gerenciador.hpp"

#pragma region Membros
membros::membros()
{
    this->_id = membros_global_id;
    ++membros_global_id;
}
membros::membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento)
{
    this->_nome = nome;
    this->_nivel_permissao = per;
    this->_data_nascimento = data_nascimento;

    this->_id = membros_global_id;
    ++membros_global_id;
}
membros::membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento, std::string email, std::chrono::hours horas_trabalhadas, adts::Lista<int> eventos, adts::Lista<int> equipes)
{
    this->_nome = nome;
    this->_nivel_permissao = per;
    this->_data_nascimento = data_nascimento;
    this->_email = email;
    this->_horas_trabalhadas = horas_trabalhadas;
    this->_id_eventos = eventos;
    this->_id_equipes = equipes;

    this->_id = membros_global_id;
    ++membros_global_id;
}
membros::~membros()
{
}

bool membros::operator==(const membros &b)
{
    bool is_equal = true;
    is_equal &= this->_nome == b._nome;
    is_equal &= this->_email == b._email;
    is_equal &= this->_data_nascimento == b._data_nascimento;
    return is_equal;
}
// GETTERS
int membros::GetId()
{
    return _id;
}
std::string membros::GetNome()
{
    return this->_nome;
}
geren_tempo::tempo membros::GetData_nascimento()
{
    return this->_data_nascimento;
}
std::string membros::GetEmail()
{
    return this->_email;
}
std::chrono::hours membros::GetHorasTrabalhadas()
{
    return this->_horas_trabalhadas;
}
permissao membros::GetNivelDePermissao()
{
    return this->_nivel_permissao;
}
adts::Lista<int> membros::GetEventos()
{
    return this->_id_eventos;
}
adts::Lista<int> membros::GetEquipes()
{
    return this->_id_equipes;
}

// SETTERS

void membros::SetNome(std::string nome)
{
    this->_nome = nome;
}

void membros::SetData_nascimento(geren_tempo::tempo data_nascimento)
{
    this->_data_nascimento = data_nascimento;
}
void membros::SetEmail(std::string email)
{
    this->_email = email;
}
void membros::SetHorasTrabalhadas(std::chrono::hours HorasTrabalhadas)
{
    this->_horas_trabalhadas = HorasTrabalhadas;
}

void membros::SetNivelDePermissao(permissao nivel_de_Permissao)
{
    this->_nivel_permissao = nivel_de_Permissao;
}
void membros::SetEventos(adts::Lista<int> eventos)
{
    this->_id_eventos = eventos;
}
void membros::SetEquipes(adts::Lista<int> equipes)
{
    this->_id_equipes = equipes;
}
#pragma endregion
#pragma region SCRUM_MASTER

scrum_team::scrum_team()
{
    this->_id = equipes_global_id;
    ++equipes_global_id;
}
scrum_team::scrum_team(std::string nome, adts::Lista<int> participantes, adts::Lista<int> eventos)
{
    _id_participantes = participantes;
    _id_eventos = eventos;
    this->_id = equipes_global_id;
    ++equipes_global_id;
}
scrum_team::~scrum_team()
{
}
bool scrum_team::addParticipante(int membro)
{
    if (!_id_participantes.find(membro))
    {
        this->_id_participantes.push_front(membro);
        return true;
    }
    return false;
}

bool scrum_team::removeParticipante(int participante)
{
    if (_id_participantes.find(participante))
    {
        _id_participantes.remove(participante);
        return true;
    }
    return false;
}

// GETTERS
int scrum_team::GetId()
{
    return _id;
}
std::string scrum_team::GetNome()
{
    return this->_nome;
}
adts::Lista<int> scrum_team::GetParticipantes()
{
    return _id_participantes;
}
adts::Lista<int> scrum_team::GetEventos()
{
    return _id_eventos;
}
// SETTERS
void membros::SetNome(std::string nome)
{
    this->_nome = nome;
}
void scrum_team::SetEquipe(adts::Lista<int> participantes)
{
    this->_id_participantes = participantes;
}

void scrum_team::SetEventos(adts::Lista<int> eventos)
{
    this->_id_eventos = eventos;
}

adts::Lista<scrum_team> &transformarEquipe(adts::Lista<int> equipes)
{
    adts::Lista<scrum_team> *lista = new adts::Lista<scrum_team>();
    int ev_t = equipes.size();
    int to_t = todos_equipes.size();

    for (int i = 0; i < ev_t; ++i)
    {
        for (int j = 0; j < to_t; ++i)
        {
            if (equipes[i] == todos_equipes[j].GetId())
            {
                lista->push_front(todos_equipes[j]);
            }
        }
    }
    return *lista;
}
adts::Lista<membros> &transformarMembros(adts::Lista<int> membros_id)
{
    adts::Lista<membros> *lista = new adts::Lista<membros>();
    int ev_t = membros_id.size();
    int to_t = todos_membros.size();

    for (int i = 0; i < ev_t; ++i)
    {
        for (int j = 0; j < to_t; ++i)
        {
            if (membros_id[i] == todos_membros[j].GetId())
            {
                lista->push_front(todos_membros[j]);
            }
        }
    }
    return *lista;
}

#pragma endregion
