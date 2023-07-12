#include "../include/gerenciador.hpp"
#include "../include/enums.hpp"
#include "../include/evento.hpp"
#include "../include/paginas.hpp"
#include "../include/utilities.hpp"
#include <iostream>
#include <string>

using namespace geren_tempo;

/**
 * PRIMEIRA PAGINA(login)
 * opções: string-nome, permissao-funcao, sair
 * SEGUNDA PAGINA(gerenciador)
 * opções: tarefas(em ordem cronologinca), ver-tarefas finalizadas, criar
 * tarefa, iniciar tarefa, finalizar tarefa, ver time, ver tarefas do time, sair
 */

int main() {
  todos_membros = adts::Lista<membros>();
  todos_equipes = adts::Lista<scrum_team>();
  todos_eventos = adts::Lista<evento>();

  membros u("Luis", permissao::product_owner, tempo(2004, 8, 24));
  membros m1("Jonas", permissao::developer, tempo(2000, 10, 21));
  membros m2("Maria", permissao::product_owner, tempo(1993, 4, 24));
  membros m3("Carlos", permissao::scrum_master, tempo(1965, 7, 4));
  todos_membros.push_back(m1);
  todos_membros.push_back(m2);
  todos_membros.push_back(m3);
  todos_membros.push_back(u);

  adts::Lista<int> tm1(m1.GetId());
  adts::Lista<int> tm2(m2.GetId());

  tm2.push_back(u.GetId());

  scrum_team t1("Time 1", tm1);
  scrum_team t2("Time 2", tm2);
  todos_equipes.push_back(t1);
  todos_equipes.push_back(t2);

  adts::Lista<int> em1(m2.GetId());
  em1.push_back(u.GetId());

  em1.push_back(m1.GetId());
  em1.push_back(m3.GetId());

  evento e1("Daily 1", eventos_sprint::daily_scrum, em1, &t1,
            prioridade::media);
  todos_eventos.push_back(e1);

  tm1.print();
  tm2.print();
  em1.print();

  todos_equipes.print();
  todos_eventos.print();
  todos_membros.print();

  // cin.ignore();
  // cin.get();

  programa();
}