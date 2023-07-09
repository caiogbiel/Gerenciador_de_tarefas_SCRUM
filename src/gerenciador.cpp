#include <iostream>
#include <string>
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"
#include "../include/paginas.hpp"

using namespace geren_tempo;

/**
 * PRIMEIRA PAGINA(login)
 * opções: string-nome, permissao-funcao, sair
 * SEGUNDA PAGINA(gerenciador)
 * opções: tarefas(em ordem cronologinca), ver-tarefas finalizadas, criar tarefa, iniciar tarefa, finalizar tarefa, ver time, ver tarefas do time, sair
 */

int main()
{
    membros m1("Jonas", permissao::developer, tempo(2000, 10, 21));
    membros m2("Maria", permissao::product_owner, tempo(1993, 4, 24));
    membros m3("Carlos", permissao::scrum_master, tempo(1965, 7, 4));
    todos_membros.push_back(m1);
    todos_membros.push_back(m2);
    todos_membros.push_back(m3);

    // cout << "TODOS OS MEMBROS\n";
    // todos_membros.print();

    // for (int i = 0; i < 3; ++i)
    // {
    //     cout << todos_membros[i] << "\n";
    // }

    // string nome = "Daily 3";
    // eventos_sprint tipo = eventos_sprint::daily_scrum;
    // tempo inicio = tempo::agora();
    // tempo fim = inicio + 1;

    // adts::Lista<int> membros_id;
    // adts::Lista<int> eventos_id;

    // // PEGANDO APENAS OS IDS DOS MEMBROS
    // for (int i = 0; i < todos_membros.size(); ++i)
    // {
    //     membros_id.push_back(todos_membros[i].GetId());
    // }

    // // PEGANDO APENAS OS IDS DOS MEMBROS
    // for (int i = 0; i < todos_eventos.size(); ++i)
    // {
    //     eventos_id.push_back(todos_eventos[i].GetId());
    // }

    // membros_id.print();
    // eventos_id.print();

    // scrum_team *time = new scrum_team(membros_id, eventos_id);

    // cout << "\nTIME - EVENTOS\n";
    // time->getEventos().print();
    // cout << "\nTIME - PARTICIPANTES\n";
    // time->getParticipantes().print();

    // evento daily = evento(nome, tipo, inicio, fim, a, time, prioridade::media);

    // cout << "EVENTO - PARTICIPANTES\n";
    // daily.GetParticipantes();

    programa();
}