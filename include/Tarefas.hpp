#ifndef TAREFAS_HPP
#define TAREFAS_HPP

#include <string>

class Evento {
private:
    std::string nome;
    Eventos_sprint tipo;
    Status_Evento status;
    tm inicio;
    tm fim;
    std::vector<Membros> participantes;
    ScrumTeam time;  

public:
    void inciar();
    void encerrar();
    void adicionarParticipantes(Membros participante)
};

#endif
