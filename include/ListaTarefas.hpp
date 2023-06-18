#ifndef LISTATAREFAS_HPP
#define LISTATAREFAS_HPP

#include <vector>
#include "Tarefas.hpp"
#include "./include/sprint.hpp"

class ListaTarefas
{
private:
    std::vector<Tarefa> tarefas;
    sprint Sprint;

public:
    void adicionarTarefa(Tarefa tarefa);
    void removerTarefa(Tarefa tarefa);
    void iniciarSprint(sprint Sprint);
    void finalizarSprint() const;
};

#endif
