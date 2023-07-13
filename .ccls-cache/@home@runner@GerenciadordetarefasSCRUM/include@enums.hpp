#ifndef ENUMS_HPP
#define ENUMS_HPP
#include <iostream>

/// Contém definição das prioridades das tarefas
enum prioridade
{
    baixa,
    media,
    alta,
    urgente
};

/// Contém definição dos tipos de tarefas existentes
enum eventos_sprint
{
    planning,
    daily_scrum,
    review,
    retrospective
};

/// Contém definição do status das tarefas
enum status_evento
{
    analise,
    andamento,
    finalizado
};

/// Contém definição dos niveis de permissão de um usuário
enum permissao
{
    product_owner,
    developer,
    scrum_master
};

/**  Transforma uma variáveis do tipo permissão em string
*    @param[in] p permissão
*    @return string 
*/   
std::string permissao_para_string(permissao p);

/**  Transforma uma variáveis do tipo prioridade em string
*    @param[in] p Prioridade
*    @return string 
*/   
std::string prioridade_para_string(prioridade p);

/**  Transforma uma variáveis do tipo status_evento em string
*    @param[in] s Status_evento
*    @return string 
*/   
std::string status_para_string(status_evento s);

/**  Transforma uma variáveis do tipo eventos_sprint em string
*    @param[in] e Eventos_sprint
*    @return string 
*/   
std::string tipo_para_string(eventos_sprint e);

std::istream &operator>>(std::istream &i, permissao &p);
#endif
