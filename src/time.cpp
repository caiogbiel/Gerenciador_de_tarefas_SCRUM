#include "../include/time.hpp"
#includde "../include/utilities.hpp"

bool membros::operator==(const membros &b)
{
    bool is_equal = true;
    is_equal &= this->nome == b.nome;
    is_equal &= this->email == b.email;
    is_equal &= this->dataDeNascimento.tm_year == b.dataDeNascimento.tm_year;
    is_equal &= this->dataDeNascimento.tm_mday == b.dataDeNascimento.tm_mday;
    is_equal &= this->dataDeNascimento.tm_mon == b.dataDeNascimento.tm_mon;
    return is_equal;
}
// GETTERS

permissao membros::getNivelDePermissao()
{
    return this->nivel_de_permissao;
}

// SETTERS

void membros::setNome(std::string nome)
{
    this->nome = nome;
}
void membros::setNivelDePermissao(permissao nivel_de_Permissao)
{
    this->nivel_de_permissao = nivel_de_Permissao;
}

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
membros scrum_team::operator[](int indice)
{
    if(indice >= 0 && indice < quantidade)
    {
        int current = 0;
        if(indice == 0)
        {
        return participante.start;
        }

    }
    throw std::runtime_error("Indice nao foi encontrado");
}
