#include <iostream>
#include <string>
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"

using namespace geren_tempo;

/**
 * PRIMEIRA PAGINA(login)
 * opções: string-nome, permissao-funcao, sair
 * SEGUNDA PAGINA(gerenciador)
 * opções: tarefas(em ordem cronologinca), ver-tarefas finalizadas, criar tarefa, iniciar tarefa, finalizar tarefa, ver time, ver tarefas do time, sair
 */

adts::Lista<membros> teste;

membros m1 = membros("Jonas", permissao::developer);
membros m2 = membros("Maria", permissao::product_owner);
membros m3 = membros("Carlos", permissao::scrum_master);

int main()
{
    teste.push_back(m1);
    teste.push_back(m2);
    teste.push_back(m3);
    scrum_team time;

    evento a = evento("confraternização", eventos_sprint::daily_scrum, tempo::agora(), tempo::agora(), teste, time, prioridade::media);
    std::cout << "Fez o evento: \nNome: " << a.GetNome() << "\nTipo: " << a.GetTipo() << "\nData de inicio: " << a.GetInicio() << "\nData final: " << a.GetFim() << "\nPrioridade: " << a.GetPrioridade() << std::endl;
    std::cout << "===========================\n"
              << "Membros: \n";
    teste.print();
}