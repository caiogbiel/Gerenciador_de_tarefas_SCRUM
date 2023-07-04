#include <iostream>
#include <string>
#include "../include/date.h"
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"

#include <chrono>

using namespace geren_tempo;

int main()
{
    adts::Lista<membros> oao;
    scrum_team time;
    evento a = evento("hola", daily_scrum, tempo::agora(), tempo::agora(), oao, time);
    std::cout << "fez o evento" << a.GetNome() << " " << a.GetTipo() << " " << a.GetInicio() << " " << a.GetFim() << " " << std::endl;
}