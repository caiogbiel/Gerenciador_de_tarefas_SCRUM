#include <iostream>
#include <string>
#include <ctime>
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"

int main()
{
    time_t inicio = time(NULL);
    tm *inicio_tm;
    inicio_tm = localtime(&inicio);
    tm fim;
    fim.tm_hour = inicio_tm->tm_hour + 2;
    adts::Lista<membros> lista;
    scrum_team team;

    evento teste = evento("Planejamento", planning, *inicio_tm, fim, lista, team);
}