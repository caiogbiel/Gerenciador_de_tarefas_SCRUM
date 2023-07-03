#include "../include/time.hpp"

membros::membros()
{
}

membros::~membros()
{
}

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

scrum_team::scrum_team()
{
}

scrum_team::~scrum_team()
{
}