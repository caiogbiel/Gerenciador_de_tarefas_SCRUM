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
    

public:
    Tarefa(const int& id, const std::string& descricao);
    std::string getDescricao() const;
    bool estaConcluida() const;
    void marcarComoConcluida();
    void marcarComoEmDesenvolvimento();
};

#endif
