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

#endif