#ifndef ENUMS_HPP
#define ENUMS_HPP
#include <iostream>

enum prioridade
{
    baixa,
    media,
    alta,
    urgente
};

enum eventos_sprint
{
    planning,
    daily_scrum,
    review,
    retrospective
};

enum status_evento
{
    analise,
    andamento,
    finalizado
};

enum permissao
{
    product_owner,
    developer,
    scrum_master
};

std::string permissao_para_string(permissao p);
std::string prioridade_para_string(prioridade p);
std::string status_para_string(status_evento s);
std::string tipo_para_string(eventos_sprint e);

#endif