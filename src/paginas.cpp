#include "../include/paginas.hpp"
#define LINHAS 20
#define COLUNAS 100

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

void Pagina::inserir_em(int linha, int coluna, string conteudo)
{
    string s = _conteudo[linha - 1];
    int c_t = conteudo.size();

    s.replace(coluna, c_t, conteudo);
    _conteudo[linha - 1] = s;
}

// Preset: ESQ = esquerda, CEN = centro, DIR = direita
void Pagina::inserir(int linha, string conteudo, int preset)
{
    string s = _conteudo[linha - 1];
    int s_t = s.size();
    int c_t = conteudo.size();
    switch (preset)
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
void Pagina::ler(string mensagem, int linha, T &saida, int alinhar)
{
    string s;
    string b;
    int n;

    s.append(mensagem);
    s.append(" ");

    cout << mensagem;

    if (typeid(T).name() == typeid(int).name() || typeid(T).name() == typeid(string).name())
    {
        getline(cin, b);
        istringstream buffer(b);
        s.append(b);
        buffer >> saida;
    }

    if (typeid(T).name() == typeid(permissao).name())
    {
        cin >> n;
        string b = permissao_para_string(permissao(n));
        s.append(b);
        saida = permissao(n);
    }

    inserir(linha, s, alinhar);
}

void Pagina::imprimir()
{
    system("cls");

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
    Pagina login(LINHAS, COLUNAS, "LOGIN");
    string nome;
    permissao perm;

    login.imprimir();
    login.ler("Entre com seu usuario: ", 2, nome, CEN);
    login.imprimir();
    cout << "\n(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
    login.ler("Entre com sua funcao: ", 3, perm, CEN);
    login.imprimir();

    usuario.SetNome(nome);
    usuario.SetNivelDePermissao(permissao(perm));
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
    // Pagina teste(LINHAS, COLUNAS, "TESTE");
    // teste.inserir(2, "Ola mundo", CEN);
    // teste.imprimir();

    // int x;
    // teste.ler("Insira um numero: ", 2, x);
    // teste.imprimir();

    p_login();
    p_principal();
}