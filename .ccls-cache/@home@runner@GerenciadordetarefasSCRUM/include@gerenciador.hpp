#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP
#include "./evento.hpp"
#include "./time.hpp"
#include "./utilities.hpp"

#define ARQUIVO_M "./files/mem.txt"
#define ARQUIVO_S "./files/scr.txt"
#define ARQUIVO_E "./files/eve.txt"

extern membros usuario;

extern int membros_global_id;
extern int equipes_global_id;
extern int eventos_global_id;

extern adts::Lista<membros> todos_membros;
extern adts::Lista<scrum_team> todos_equipes;
extern adts::Lista<evento> todos_eventos;

// sprint sprint_atual;

#endif