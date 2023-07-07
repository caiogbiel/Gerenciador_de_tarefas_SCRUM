#include "../include/time.hpp"
#include "../include/utilities.hpp"

#pragma region Membros
bool membros::operator==(const membros &b)
{
    bool is_equal = true;
    is_equal &= this->_nome == b._nome;
    is_equal &= this->_email == b._email;
    is_equal &= this->_data_nascimento == b._data_nascimento;
    return is_equal;
}
// GETTERS

std::string membros::getNome()
{
    return this->_nome;
}
geren_tempo::tempo membros::getData_nascimento()
{
    return this->_data_nascimento;
}
std::string membros::getEmail()
{
    return this->_email;
}
std::chrono::hours membros::getHorasTrabalhadas()
{
    return this->_horas_trabalhadas;
}
permissao membros::getNivelDePermissao()
{
    return this->_nivel_permissao;
}

// SETTERS

void membros::setNome(std::string nome)
{
    this->_nome = nome;
}

void membros::setData_nascimento(geren_tempo::tempo data_nascimento)
{
    this->_data_nascimento = data_nascimento;
}
void membros::setEmail(std::string email)
{
    this->_email = email;
}
void membros::setHorasTrabalhadas(std::chrono::hours HorasTrabalhadas)
{
    this->_horas_trabalhadas = HorasTrabalhadas;
}

void membros::setNivelDePermissao(permissao nivel_de_Permissao)
{
    this->_nivel_permissao = nivel_de_Permissao;
}
#pragma endregion
#pragma region SCRUM_MASTER
bool scrum_team::addParticipante(membros novoMembro)
{
    if (!_participantes.find(novoMembro))
    {
        this->_participantes.push_front(novoMembro);
        return true;
    }
    return false;
}

bool scrum_team::removeParticipante(membros participante)
{
    if (_participantes.find(participante))
    {
        _participantes.remove(participante);
        return true;
    }
    return false;
}

// GETTERS
adts::Lista<membros> scrum_team::getParticipantes()
{
    return _participantes;
}
int scrum_team::getQuantidade()
{
    return _quantidade;
}
adts::Lista<eventos_sprint> scrum_team::getEventos()
{
    return _eventos;
}
// SETTERS
void scrum_team::setEquipe(membros participantes)
{
    this->_participantes = participantes;
}
void scrum_team::setQuantidade(int quantidade)
{
    this->_quantidade = quantidade;
}
void scrum_team::setEventos(eventos_sprint eventos)
{
    this->_eventos = eventos;
}

#pragma endregion
