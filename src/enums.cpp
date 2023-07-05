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