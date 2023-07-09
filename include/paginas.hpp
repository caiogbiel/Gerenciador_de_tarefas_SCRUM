#include <iostream>
#include "../include/time.hpp"
#include "../include/gerenciador.hpp"
#include "../include/evento.hpp"
#include "../include/utilities.hpp"
#include "../include/enums.hpp"
#include <functional>
#define ESQ 0
#define CEN 1
#define DIR 2
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
    void inserir(int linha, string conteudo, int alinhar);
    void inserir_em(int linha, int coluna, string conteudo);
    template <typename T>
    void ler(string mensagem, int linha_dest, T &saida, int alinhar = ESQ);
    void imprimir();
};

// void titulo(string titulo, int colunas);
// void pagina(int linhas, int colunas);
void p_login();
void p_principal();
void p_time(scrum_team time);
void criarNovaTarefa();
void programa();