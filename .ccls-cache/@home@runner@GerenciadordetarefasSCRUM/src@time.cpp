#include "../include/time.hpp"
#include "../include/utilities.hpp"
#include "../include/gerenciador.hpp"

#pragma region Membros
membros::membros()
{
    this->_id_equipes = adts::Lista<int>();
    this->_id_eventos = adts::Lista<int>();
    this->_horas_trabalhadas = std::chrono::hours(0);
    this->_id = membros_global_id;
    ++membros_global_id;
}
membros::membros(std::string nome, permissao per, geren_tempo::tempo data_nascimento)
{
    this->_nome = nome;
    this->_nivel_permissao = per;
    this->_data_nascimento = data_nascimento;
    this->_id_equipes = adts::Lista<int>();
    this->_id_eventos = adts::Lista<int>();
    this->_horas_trabalhadas = std::chrono::hours(0);

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

void membros::AddEquipe(int equipe)
{
    if (!this->_id_equipes.find(equipe))
        this->_id_equipes.push_front(equipe);
}

void membros::AddEvento(int evento)
{
    if (!this->_id_eventos.find(evento))
        this->_id_eventos.push_front(evento);
}

std::ostream &
operator<<(std::ostream &o, const membros &m)
{
    o << m._id << "," << m._nome << "," << m._data_nascimento << "," << m._email << "," << m._horas_trabalhadas.count() << "," << m._nivel_permissao
      << "[";
    if (m._id_equipes.size() > 0)
    {
        for (int i = 0; i < m._id_equipes.size(); ++i)
        {
            o << m._id_equipes[i] << ",";
        }
    }
    o << "]";
    o << "[";
    if (m._id_eventos.size() > 0)
    {
        for (int i = 0; i < m._id_eventos.size(); ++i)
        {
            o << m._id_eventos[i] << ",";
        }
    }
    o << "]";
    o << ";";
    return o;
}

std::istream &
operator>>(std::istream &i, membros &m)
{
    char temp[512];
    std::string token;
    i.getline(temp, 512, ';');

    std::stringstream buffer(temp);
    std::stringstream auxbuffer;

    std::getline(buffer, token, ',');
    m._id = std::stoi(token);
    std::getline(buffer, token, ',');
    m._nome = token;
    std::getline(buffer, token, ',');
    auxbuffer << token;
    auxbuffer >> m._data_nascimento;

    auxbuffer.str(std::string());
    auxbuffer.clear();

    std::getline(buffer, token, ',');
    m._email = token;
    std::getline(buffer, token, ',');
    m._horas_trabalhadas = std::chrono::hours(std::stoi(token));
    std::getline(buffer, token, '[');
    m._nivel_permissao = permissao(std::stoi(token));

    std::getline(buffer, token, ']');
    auxbuffer << token;
    while (std::getline(auxbuffer, token, ',').good())
    {
        m._id_equipes.push_front(std::stoi(token));
    }

    auxbuffer.str(std::string());
    auxbuffer.clear();

    buffer.ignore(1);
    std::getline(buffer, token, ']');
    auxbuffer << token;
    while (std::getline(auxbuffer, token, ',').good())
    {
        m._id_eventos.push_front(std::stoi(token));
    }

    return i;
}

#pragma endregion
#pragma region SCRUM_MASTER

scrum_team::~scrum_team()
{
}
scrum_team::scrum_team()
{
    this->_id_eventos = adts::Lista<int>();
    this->_id_participantes = adts::Lista<int>();
    this->_id = equipes_global_id;
    ++equipes_global_id;
}

scrum_team::scrum_team(std::string nome, adts::Lista<int> id_participantes)
{
    this->_nome = nome;
    this->_id_participantes = id_participantes;
    this->_id_eventos = adts::Lista<int>();
    this->_id = equipes_global_id;
    ++equipes_global_id;
}

scrum_team::scrum_team(std::string nome, adts::Lista<int> participantes, adts::Lista<int> eventos)
{
    this->_nome = nome;
    this->_id_participantes = participantes;
    this->_id_eventos = eventos;
    this->_id = equipes_global_id;
    ++equipes_global_id;
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

void scrum_team::AddEvento(int evento)
{
    if (!this->_id_eventos.find(evento))
        this->_id_eventos.push_front(evento);
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
void scrum_team::SetNome(std::string nome)
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

std::ostream &
operator<<(std::ostream &o, const scrum_team &t)
{
    o << t._id << "," << t._nome << ","
      << "[";
    if (t._id_participantes.size() > 0)
    {
        for (int i = 0; i < t._id_participantes.size(); ++i)
        {
            o << t._id_participantes[i] << ",";
        }
    }
    o << "]";
    o << "[";
    if (t._id_eventos.size() > 0)
    {
        for (int i = 0; i < t._id_eventos.size(); ++i)
        {
            o << t._id_eventos[i] << ",";
        }
    }
    o << "]";
    o << ";";
    return o;
}

std::istream &
operator>>(std::istream &i, scrum_team &t)
{
    char temp[512];
    std::string token;
    i.getline(temp, 512, ';');

    std::stringstream buffer(temp);
    std::stringstream auxbuffer;

    std::getline(buffer, token, ',');
    t._id = std::stoi(token);
    std::getline(buffer, token, ',');
    t._nome = token;

    buffer.ignore(1);
    std::getline(buffer, token, ']');
    auxbuffer << token;
    while (std::getline(auxbuffer, token, ',').good())
    {
        t._id_participantes.push_front(std::stoi(token));
    }

    auxbuffer.str(std::string());
    auxbuffer.clear();

    buffer.ignore(1);
    std::getline(buffer, token, ']');
    auxbuffer << token;
    while (std::getline(auxbuffer, token, ',').good())
    {
        t._id_eventos.push_front(std::stoi(token));
    }
    return i;
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
