#include "../include/arquivos.hpp"
#include "./arquivos.cpp"
#include "../include/gerenciador.hpp"
#include "../include/enums.hpp"
#include "../include/evento.hpp"
#include "../include/paginas.hpp"
#include "../include/utilities.hpp"
#include <iostream>
#include <string>

using namespace geren_tempo;

membros usuario = membros();

int membros_global_id = 0;
int equipes_global_id = 0;
int eventos_global_id = 0;

adts::Lista<membros> todos_membros = adts::Lista<membros>();
adts::Lista<scrum_team> todos_equipes = adts::Lista<scrum_team>();
adts::Lista<evento> todos_eventos = adts::Lista<evento>();

// Sempre que adicionar uma entidade, deve adicionar as relações dela (as listas de ID);
// Por tanto, prefira utilizar os construtores completos;

int main()
{
  // membros u("Luis", permissao::product_owner, geren_tempo::tempo(2004, 8, 24));
  // membros m1("Jonas", permissao::developer, geren_tempo::tempo(2000, 10, 21));
  // membros m2("Maria", permissao::product_owner,
  //            geren_tempo::tempo(1993, 4, 24));
  // membros m3("Carlos", permissao::scrum_master, geren_tempo::tempo(1965, 7, 4));
  // todos_membros.push_back(m1);
  // todos_membros.push_back(m2);
  // todos_membros.push_back(m3);
  // todos_membros.push_back(u);

  // adts::Lista<int> tm1(m1.GetId()); // Lista de membros do time 1
  // adts::Lista<int> tm2(m2.GetId()); // Lista de membros do time 2
  // tm2.push_back(u.GetId());

  // scrum_team t1("Time 1", tm1);
  // scrum_team t2("Time 2", tm2);
  // todos_equipes.push_back(t1);
  // todos_equipes.push_back(t2);

  // u.SetEquipes(adts::Lista<int>(t2.GetId()));

  // adts::Lista<int> em1(m2.GetId());
  // em1.push_back(u.GetId());
  // em1.push_back(m3.GetId());

  // evento e1("Daily 1", eventos_sprint::daily_scrum, em1, t1.GetId(),
  //           prioridade::media);
  // todos_eventos.push_back(e1);
  // u.SetEventos(adts::Lista<int>(e1.GetId()));
  // m2.SetEventos(adts::Lista<int>(e1.GetId()));
  // m3.SetEventos(adts::Lista<int>(e1.GetId()));
  /*
    Situação:
    Existem 4 membros,
    Jonas faz parte do time 1
    Maria faz parte do time 2
    Todos menos Jonas fazem parte do evento daily
  */

  todos_equipes.print();
  todos_membros.print();
  todos_eventos.print();

  // evento teste;
  // cout << "Entre com o evento: \n";
  // cin >> teste;
  // cout << teste;

  // membros mem;
  // cout << "\nEntre com o membro: \n";
  // cin >> mem;
  // cout << mem;

  // scrum_team tim;
  // cout << "\nEntre com o time: \n";
  // cin >> tim;
  // cout << tim;

  // cin.ignore();
  // cin.get();

  // todos_membros = adts::Lista<membros>();
  // todos_equipes = adts::Lista<scrum_team>();
  // todos_eventos = adts::Lista<evento>();

  lerLista<membros>(ARQUIVO_M, todos_membros);
  lerLista<scrum_team>(ARQUIVO_S, todos_equipes);
  lerLista<evento>(ARQUIVO_E, todos_eventos);

  todos_equipes.print();
  todos_membros.print();
  todos_eventos.print();

  cin.ignore();
  cin.get();

  programa();

  guardarLista(ARQUIVO_M, todos_membros);
  guardarLista(ARQUIVO_S, todos_equipes);
  guardarLista(ARQUIVO_E, todos_eventos);
}