#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "./evento.hpp"
#include "./time.hpp"
#include "./utilities.hpp"

static membros usuario;

static int membros_global_id = 0;
static int equipes_global_id = 0;
static int eventos_global_id = 0;

static adts::Lista<membros> todos_membros = adts::Lista<membros>();
static adts::Lista<scrum_team> todos_equipes = adts::Lista<scrum_team>();
static adts::Lista<evento> todos_eventos = adts::Lista<evento>();

// static sprint sprint_atual;

#endif