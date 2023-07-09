// #include <iostream>
// #include "../include/time.hpp"
#include "../include/paginas.hpp"
// #include "../include/gerenciador.hpp"
// #include "../include/evento.hpp"
// #include "../include/utilities.hpp"

// using namespace std;

Pagina::Pagina(int linhas, int colunas, string titulo)
{
    //================TITULO================//
#pragma region Titulo
    int titulo_t = titulo.size();
    _titulo.push_back(string());
    _titulo.push_back(string());
    _titulo.push_back(string());
    // Primeira barra
    for (int i = 1; i <= colunas; ++i)
    {
        _titulo[0].append("=");
    }

    if (colunas - titulo_t <= 0)
    {
        throw runtime_error("Tamanho não pode ser menor que o titulo");
    }

    // Barra contendo o titulo
    _titulo[1].append("|");
    if (colunas % 2 == 0)
    {
        _titulo[1].append(" ");
    }
    for (int i = 1; i <= (colunas - titulo_t) / 2 - 1; ++i)
    {
        _titulo[1].append(" ");
    }

    _titulo[1].append(titulo);

    for (int i = 1; i <= (colunas - titulo_t) / 2 - 1; ++i)
    {
        _titulo[1].append(" ");
    }
    _titulo[1].append("|");

    // Terceira barra
    _titulo[2] = _titulo[0];
#pragma endregion

    //================CONTEUDO================//
#pragma region Conteudo
    string s;
    for (int i = 1; i < linhas; ++i)
    {
        s.append("*");
        while (s.size() < colunas - 1)
        {
            s.append(" ");
        }
        s.append("*");
        _conteudo.push_front(s);
        s.clear();
    }
    for (int i = 1; i <= colunas; ++i)
    {
        s.append("=");
    }
    _conteudo[_conteudo.size() - 1] = s;
#pragma endregion
}

Pagina::~Pagina() {}

void Pagina::inserir(int linha, string conteudo, int flag)
{
    string s = _conteudo[linha - 1];
    int s_t = s.size();
    int c_t = conteudo.size();
    switch (flag)
    {
    case 0:
        s.replace(2, c_t, conteudo);
        break;
    case 1:
        s.replace(s_t / 2 - c_t / 2, c_t, conteudo);
        break;
    case 2:
        s.replace(s_t - c_t - 2, c_t, conteudo);
        break;

    default:
        break;
    }
    _conteudo[linha - 1] = s;
}

template <typename T>
void Pagina::ler(string mensagem, int linha, T &saida)
{
    // string s;

    // cout >> mensagem;
    // cin.getline(s, 256);

    // istringstream buffer(s);
}

void Pagina::imprimir()
{
    for (int i = 0; i < _titulo.size(); i++)
    {
        cout << _titulo[i] << "\n";
    }
    for (int i = 0; i < _conteudo.size(); i++)
    {
        cout << _conteudo[i] << "\n";
    }
}

void p_login()
{
    // titulo("LOGIN", t);
    // cout << "================LOGIN================\n";
    cout << "Entre com seu usuário: ";

    string nome;
    cin >> nome;
    usuario.SetNome(nome);

    cout << "\n(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
    cout << "Entre com sua função: ";

    int p;
    cin >> p;
    usuario.SetNivelDePermissao(permissao(p));
}

void p_principal()
{
    int opcao;
    cout << "\n===============TAREFAS===============\n";

    if (todos_eventos.size() == 0)
    {
        cout << "\n           Não há tarefas              \n";
    }
    else
    {
        for (int i = 0; i < todos_eventos.size(); ++i)
        {
            cout << todos_eventos[i] << '\n';
        }
    }

    // PERMISSAO GLOBAL
    cout << "\n1 - Ver tarefas finalizadas\n";
    cout << "2 - Criar nova tarefa\n";
    cout << "3 - Iniciar uma tarefa\n";
    cout << "4 - Finalizar uma tarefa\n";
    cout << "5 - Ver meu time\n";
    // PERMISSAO PRODUCT OWNER
    if (usuario.GetNivelDePermissao() == 0)
    {
        cout << "6 - Finalizar Sprint\n";
    }
    // PERMISSAO DEVELOPER
    if (usuario.GetNivelDePermissao() == 1)
    {
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        cout << "6 - Atribuir tarefa\n";
    }

    cout << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        break;
    case 2:
        // ainda em desenvolvimento
        //  //cria novo evento
        //  evento novaTarefa = criarNovaTarefa();
        // listaTarefas.push(novaTarefa);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }

    // PERMISSAO PRODUCT OWNER
    if (usuario.GetNivelDePermissao() == 0)
    {
        switch (opcao)
        {
        case 6:
            break;

        default:
            break;
        }
    }
    // PERMISSAO DEVELOPER
    if (usuario.GetNivelDePermissao() == 1)
    {
        switch (opcao)
        {
        case 6:
            break;

        default:
            break;
        }
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        switch (opcao)
        {
        case 6:
            break;

        default:
            break;
        }
    }
}

void p_time(scrum_team time)
{
    cout << "=====================================\n";
    /* Mostrar participantes do time */
    cout << "1 - Ver tarefas do time\n";

    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        cout << "2 - Adicionar participante\n";
        cout << "3 - Remover participante\n";
    }
}

// ainda em desenvolvimento de case 2
void criarNovaTarefa()
{
    string buffer;

    string nome;
    int tipo;
    adts::Lista<int> participantes;
    adts::Lista<int> participantes_id;
    int time_id;
    scrum_team time;
    int prio;

    cout << "Digite o nome da nova tarefa: ";
    cin >> nome;

    cout << "Digite o tipo da sprint (0 - planning, 1 - daily_scrum, 2 - review, 3 - retrospective): ";
    cin >> tipo;

    cout << "Digite a prioridade da tarefa (0 - Baixa, 1 - Media, 2 - Alta, 3 - Urgente): ";
    cin >> prio;

    cout << "Digite os ID's dos participantes (separe por espaço): ";
    getline(cin, buffer);

    // Armazena a entrada em um buffer para ler cada Id fornecido
    istringstream tmp(buffer);

    // Cria uma cópia de todos os membros contendo somente o Id deles
    for (int i = 0; i < todos_membros.size(); ++i)
    {
        participantes_id.push_back(todos_membros[i].GetId());
    }

    // Faz a leitura de cada Id no buffer e verifica se existe esse Id
    while (tmp)
    {
        int id;
        tmp >> id;
        if (participantes_id.find(id))
        {
            participantes.push_back(id);
        }
        else
        {
            cout << "Id: " << id << " nao encontrado na lista de membros.\n";
        }
    }

    cout << "Digite o ID da equipe: ";
    cin >> time_id;

    evento tarefa(nome, eventos_sprint(tipo), participantes, &time, prioridade(prio));
}

// int gerenciador::verTime(adts::Lista<scrum_team> &equipes)
// {
//     if (usuario.getNivelDePermissao() == 0)
//     {
//         string nome_time;
//         cout << "Qual dos seus times deseja ver?" cin >> nome_time;
//         equipe_usuario = equipes.getEquipe_usuario(nome_time);
//     }
//     equipe_usuario.GetParticipantes();
// }

void programa()
{
    // titulo("Teste", 100);
    // pagina(20, 100);
    system("cls");
    Pagina teste(20, 100, "TESTE");
    teste.inserir(2, "Ola mundo", 1);
    teste.imprimir();
    p_login();
    p_principal();
}