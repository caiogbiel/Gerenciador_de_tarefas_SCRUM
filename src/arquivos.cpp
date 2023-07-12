#include "../include/time.hpp"
#include "../include/utilities.hpp"
#include "../include/arquivos.hpp"
#include <fstream>
#include <iostream>

// Leitura de scrum_team e membros apenas
template <typename T>
void lerLista(std::string nome_arquivo, adts::Lista<T> &lista)
{
    std::ifstream arquivo(nome_arquivo);
    std::cerr << "ABRINDO ARQUIVO " << nome_arquivo;
    if (arquivo)
    {
        T aux;
        while (arquivo.peek() != EOF)
        {
            arquivo >> aux;
            lista.push_back(aux);
        }
    }
    else
    {
        std::cerr << "Houve um problema ao abrir o arquivo para leitura\n";
    }
    std::cerr << "Saiu\n";
    arquivo.close();
    std::cerr << "Fechou";
}

template <typename T>
void guardarLista(std::string nome_arquivo, adts::Lista<T> lista)
{
    std::ofstream arquivo(nome_arquivo, std::ios::in | std::ios::trunc);
    std::cerr << "ABRINDO ARQUIVO " << nome_arquivo;

    if (arquivo.is_open())
    {
        int n_objetos = lista.size();

        for (int i = 0; i < n_objetos; ++i)
        {
            arquivo << lista[i];
            // arquivo.write((char *)&lista[i], sizeof(membros));
        }
    }
    else
    {
        std::cerr << "Houve um problema ao abrir o arquivo para escrita\n";
    }

    arquivo.close();
}