#ifndef TAREFAS_HPP
#define TAREFAS_HPP

#include <string>

class Tarefa {
private:
    int id;
    std::string descricao;
    std::string status;
    std::string nivelPrioridade;

public:
    Tarefa(const int& id, const std::string& descricao);
    std::string getDescricao() const;
    bool estaConcluida() const;
    void marcarComoConcluida();
    void marcarComoEmDesenvolvimento();
};

#endif
