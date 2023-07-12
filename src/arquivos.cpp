#include "../include/time.hpp"
#include "../include/utilities.hpp"
#include "../include/arquivos.hpp"
#include <fstream>
#include <iostream>

// Leitura de scrum_team e membros apenas
void lerScrum(std::string nome_arquivo, adts::Lista<scrum_team> &lista)
{
    std::ifstream arquivo(nome_arquivo, std::ios::out);
    std::cerr << "ABRINDO ARQUIVO " << nome_arquivo;
    if (arquivo)
    {
        int n_objetos;
        arquivo.seekg(0, std::ios::end);
        n_objetos = arquivo.tellg() / sizeof(scrum_team);
        arquivo.seekg(0, std::ios::beg);

        for (int i = 0; i < n_objetos; ++i)
        {
            scrum_team aux;
            arquivo.read((char *)&aux, sizeof(scrum_team));

            lista.push_back(aux);
        }
    }
    else
    {
        std::cerr << "Houve um problema ao abrir o arquivo para leitura\n";
    }
    arquivo.close();
}

// Leitura de scrum_team e membros apenas
template <typename T>
void lerLista(std::string nome_arquivo, adts::Lista<T> &lista)
{
    std::ifstream arquivo(nome_arquivo);
    std::cerr << "ABRINDO ARQUIVO " << nome_arquivo;
    if (arquivo)
    {
        T aux;
        while (arquivo.good())
        {

            std::cerr << "entrou\n";
            // std::cerr << arquivo.tellg() << "\n";
            if (arquivo.eof())
                break;
            // std::cerr << arquivo.tellg() << "\n";
            arquivo >> aux;
            std::cout << aux << "\n";
            lista.push_back(aux);
            std::cerr << "cabou\n";
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

// Leitura de eventos apenas
void lerEventos(std::string nome_arquivo, adts::Lista<evento> &lista)
{
    std::ifstream arquivo(nome_arquivo, std::ios::binary | std::ios::out);
    std::cerr << "ABRINDO ARQUIVO " << nome_arquivo;
    if (arquivo)
    {
        int n_objetos;
        arquivo.seekg(0, std::ios::end);
        n_objetos = arquivo.tellg() / sizeof(evento);
        arquivo.seekg(0, std::ios::beg);

        for (int i = 0; i < n_objetos; ++i)
        {
            evento aux;
            arquivo.read((char *)&aux, sizeof(evento));
            lista.push_back(aux);
        }
    }
    else
    {
        std::cerr << "Houve um problema ao abrir o arquivo para leitura\n";
    }
    arquivo.close();
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