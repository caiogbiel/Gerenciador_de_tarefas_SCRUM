#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include "./time.hpp"
#include "./utilities.hpp"
#include <fstream>
#include <iostream>
/**
*  Lê uma lista de itens presentes em um arquivo
*  @tparam T Tipo a ser lido, requer implementação do operator<<
*  @param nome_arquivo Caminho do arquivo
*  @param lista Lista que guardará os itens
*/
template <typename T>
void lerLista(std::string nome_arquivo, adts::Lista<T> &lista);

/**
*  Guarda uma lista de itens presentes em uma lista
*  @tparam T Tipo a ser lido, requer implementação do operator>>
*  @param nome_arquivo Caminho do arquivo
*  @param lista Lista que contém os itens
*/
template <typename T>
void guardarLista(std::string nome_arquivo, adts::Lista<T> lista);

#endif
