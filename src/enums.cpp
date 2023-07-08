#include "../include/enums.hpp"

std::string permissao_para_string(permissao p)
{
    switch (p)
    {
    case 0:
        return "Product Owner";
    case 1:
        return "Developer";
    case 2:
        return "Scrum Master";
    default:
        break;
    }
}

std::string prioridade_para_string(prioridade p)
{
    switch (p)
    {
    case 0:
        return "Baixa";
    case 1:
        return "Media";
    case 2:
        return "Alta";
    case 3:
        return "Urgente";
    default:
        break;
    }
}

std::string status_para_string(status_evento s)
{
    switch (s)
    {
    case 0:
        return "Analise";
    case 1:
        return "Andamento";
    case 2:
        return "Finalizado";
    default:
        break;
    }
}

std::string tipo_para_string(eventos_sprint e)
{
    switch (e)
    {
    case 0:
        return "Planning";
    case 1:
        return "Daily Scrum";
    case 2:
        return "Review";
    case 3:
        return "Retrospective";
    default:
        break;
    }
}