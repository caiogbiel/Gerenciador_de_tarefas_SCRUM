#include <iostream>
#include <vector>
#include "../include/time.hpp"
#include "../include/gerenciador.hpp"
#include "../include/evento.hpp"
#include "../include/utilities.hpp"
#define ESQ 1
#define DIR 2
#define CEN 3
using namespace std;

class Pagina
{
private:
    adts::Lista<string> _titulo;
    adts::Lista<string> _conteudo;
    int _linhas;
    int _colunas;

public:
    Pagina(int linhas, int colunas, string titulo);
    ~Pagina();
    // void titulo(string titulo, int colunas);
    void inserir(int linha, string conteudo, int flag);
    template <typename T>
    void ler(int linha, T &saida);
};

// void titulo(string titulo, int colunas);
// void pagina(int linhas, int colunas);
void p_login();
void p_principal();
void p_time(scrum_team time);
void criarNovaTarefa();
void programa();