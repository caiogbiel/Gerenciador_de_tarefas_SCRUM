#ifndef LISTATAREFAS_HPP
#define LISTATAREFAS_HPP

#include <vector>
#include "Tarefas.hpp"
#include "./include/sprint.hpp"

class GerenciadorDeTarefas
{
private:
    std::vector<Evento> evento;
    sprint Sprint;

public:
    void adicionarEvento(Tarefa tarefa);
    void removerTarefa(Tarefa tarefa);
    void iniciarSprint(sprint Sprint);
    void finalizarSprint() const;
};

#endif
