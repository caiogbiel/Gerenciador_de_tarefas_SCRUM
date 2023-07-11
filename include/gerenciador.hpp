#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP
#include "./evento.hpp"
#include "./time.hpp"
#include "./utilities.hpp"

#define ARQUIVO_M "./files/mem.txt"
#define ARQUIVO_S "./files/scr.txt"
#define ARQUIVO_E "./files/eve.txt"

static membros usuario;

static int membros_global_id;
static int equipes_global_id;
static int eventos_global_id;

static adts::Lista<membros> todos_membros;
static adts::Lista<scrum_team> todos_equipes;
static adts::Lista<evento> todos_eventos;

// static sprint sprint_atual;

#endif