#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include "./time.hpp"
#include "./utilities.hpp"
#include <fstream>
#include <iostream>

template <typename T>
void lerLista(std::string nome_arquivo, adts::Lista<T> &lista);

template <typename T>
void guardarLista(std::string nome_arquivo, adts::Lista<T> lista);

// void lerScrum(std::string nome_arquivo, adts::Lista<scrum_team> &lista);

// // Leitura de scrum_team e membros apenas
// void lerMembros(std::string nome_arquivo, adts::Lista<membros> &lista);

// // Leitura de eventos apenas
// void lerEventos(std::string nome_arquivo, adts::Lista<evento> &lista);

// void guardarMembros(std::string nome_arquivo, adts::Lista<membros> lista);
#endif