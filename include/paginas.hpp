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
    void inserir_apos(int linha, string conteudo, int alinhar = -1);
    template <typename T>
    void ler_inserir(string mensagem, int linha_dest, T &saida, int alinhar = ESQ);
    template <typename T>
    void ler(string mensagem, T &saida);
    void separador(int linha);
    void esperar(int linha, string mensagem);
    void limpar_linha(int linha);
    void caixa(int x1, int y1, int x2, int y2);
    void imprimir();
};

void p_login();
void p_principal(bool &controlador);
void p_time();
void p_finalizadas();
void p_finalizarTarefa();

void criarNovaTarefa();
void programa();
