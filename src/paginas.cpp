#include "../include/paginas.hpp"
#define LINHAS 20
#define COLUNAS 100

Pagina::Pagina(int linhas, int colunas, string titulo)
{
    _colunas = colunas;
    _linhas = linhas;
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

void Pagina::inserir_apos(int linha, string conteudo, int alinhar)
{
    string s = _conteudo[linha - 1];
    string aux(s);

    aux.replace(0, 1, " ");
    aux.replace(aux.size() - 1, 1, " ");

    aux.replace(aux.find_last_not_of(' ') + 1, conteudo.size(), conteudo);

    if (alinhar < 0)
    {
        aux.replace(0, 1, "*");
        aux.replace(aux.size() - 1, 1, "*");
        _conteudo[linha - 1] = aux;
    }
    else
    {
        istringstream buffer(aux);

        aux.clear();

        while (buffer >> s)
            ;
        {
            aux.append(s);
        }

        inserir(linha, aux, alinhar);
    }
}

template <typename T>
void Pagina::ler(string mensagem, T &saida)
{
    cin.clear();
    string b;
    int n;

    cout << mensagem;

    if (typeid(T).name() == typeid(int).name() || typeid(T).name() == typeid(string).name())
    {
        cin >> saida;
    }

    if (typeid(T).name() == typeid(permissao).name())
    {
        cin >> n;
        string b = permissao_para_string(permissao(n));
        saida = permissao(n);
    }
}

template <typename T>
void Pagina::ler_inserir(string mensagem, int linha, T &saida, int alinhar)
{
    cin.clear();
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

void Pagina::separador(int linha)
{
    string s;

    s.append("*");
    for (int i = 1; i < _colunas - 1; ++i)
    {
        s.append("=");
    }
    s.append("*");

    _conteudo[linha - 1] = s;
}

void Pagina::esperar(int linha, string mensagem)
{
    inserir(linha, "Pressione qualquer tecla para " + mensagem, CEN);
    imprimir();
    cin.ignore();
    cin.get();
}

void p_login()
{
    Pagina login(LINHAS, COLUNAS, "LOGIN");
    string nome;
    permissao perm;

    login.inserir(2, "Usuario: ", CEN);
    login.inserir(3, "Funcao: ", CEN);
    login.imprimir();

    login.ler("Entre com seu usuario: ", nome);
    login.imprimir();

    login.inserir_apos(2, " " + nome);
    login.imprimir();

    cout << "\n(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
    login.ler("Entre com sua funcao: ", perm);

    login.inserir_apos(3, " " + permissao_para_string(perm));

    login.inserir(LINHAS - 6, "Bem vindo " + nome, CEN);
    login.esperar(LINHAS - 4, "continuar");

    usuario.SetNome(nome);
    usuario.SetNivelDePermissao(permissao(perm));
}

void p_principal(bool &controlador)
{
    Pagina principal(LINHAS + 7, COLUNAS, "MENU PRINCIPAL");
    principal.inserir(1, "-Suas tarefas-", CEN);
    int opcao;

    /*SUBSTITUIR todos_eventos POR LISTA DO USUÁRIO*/

    if (todos_eventos.size() == 0)
    {
        principal.inserir(3, "Nao existem tarefas pendentes", CEN);
    }
    else
    {
        stringstream buffer;
        string s;
        for (int i = 0; i < 10 && i < todos_eventos.size(); ++i)
        {
            buffer << todos_eventos[i];
            buffer >> s;
            principal.inserir(3 + i, s, ESQ);
        }
    }

    principal.separador(LINHAS - 4);

    principal.inserir(18, "0 - Sair", ESQ);
    principal.inserir(19, "1 - Ver tarefas finalizadas", ESQ);
    principal.inserir(20, "2 - Criar nova tarefa", ESQ);
    principal.inserir(21, "3 - Iniciar uma tarefa", ESQ);
    principal.inserir(22, "4 - Finalizar uma tarefa", ESQ);
    principal.inserir(23, "5 - Ver meu time", ESQ);
    // PERMISSAO PRODUCT OWNER
    if (usuario.GetNivelDePermissao() == 0)
    {
        principal.inserir(23, "6 - Finalizar Sprint", ESQ);
    }
    // PERMISSAO DEVELOPER
    if (usuario.GetNivelDePermissao() == 1)
    {
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        principal.inserir(23, "6 - Atribuir tarefa", ESQ);
    }
    principal.imprimir();

    principal.ler("Selecione uma opção: ", opcao);

    switch (opcao)
    {
    case 0:
        controlador = false;
        return;
        break;
    case 1:
        p_finalizadas();
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
        p_finalizarTarefa();
        break;
    case 5:
        p_time();
        break;
    default:
        break;
    }

    // PERMISSAO PRODUCT OWNER
    if (usuario.GetNivelDePermissao() == 0)
    {
        if (opcao == 6)
        {
        }
    }
    // PERMISSAO DEVELOPER
    if (usuario.GetNivelDePermissao() == 1)
    {
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        if (opcao == 6)
        {
        }
    }
}

void p_finalizadas()
{
    Pagina finalizadas(LINHAS + 4, COLUNAS, "FINALIZAR TAREFA");
    std::string nomeTarefa;

    finalizadas.inserir(1, "-Tarefas finalizadas-", CEN);
    finalizadas.separador(LINHAS - 4);
    finalizadas.imprimir();

    if (todos_eventos.size() == 0)
    {
        string trash;
        finalizadas.inserir(3, "Nao existem tarefas encerradas", CEN);
        finalizadas.inserir(LINHAS, "Pressione qualquer tecla para voltar", CEN);
        finalizadas.imprimir();
        cin.ignore();
        cin.get();
        return;
    }
    else
    {
        stringstream buffer;
        string s;
        for (int i = 0; i < 10 && i < todos_eventos.size(); ++i)
        {
            if (todos_eventos[i].GetStatus() == finalizado)
            {
                buffer << todos_eventos[i];
                buffer >> s;
                finalizadas.inserir(3 + i, s, ESQ);
            }
        }
    }

    finalizadas.imprimir();
}

void p_finalizarTarefa()
{
    Pagina finalizar(LINHAS + 4, COLUNAS, "FINALIZAR TAREFA");
    std::string nomeTarefa;

    finalizar.inserir(1, "-Tarefas a finalizar-", CEN);
    finalizar.separador(LINHAS - 4);
    finalizar.imprimir();

    if (todos_eventos.size() == 0)
    {
        string trash;
        finalizar.inserir(3, "Nao existem tarefas para encerrar", CEN);
        finalizar.esperar(LINHAS, "voltar");
        finalizar.imprimir();
        return;
    }
    else
    {
        stringstream buffer;
        string s;
        for (int i = 0; i < 10 && i < todos_eventos.size(); ++i)
        {
            if (todos_eventos[i].GetStatus() != finalizado)
            {
                buffer << todos_eventos[i];
                buffer >> s;
                finalizar.inserir(3 + i, s, ESQ);
            }
        }
    }

    finalizar.imprimir();

    finalizar.inserir(18, "Tarefa selecionada: ", ESQ);

    finalizar.ler("Digite o nome ou ID da tarefa que deseja finalizar: ", nomeTarefa);
    finalizar.inserir_apos(18, " " + nomeTarefa);
    finalizar.imprimir();

    evento *tarefa = nullptr;

    for (int i = 0; i < todos_eventos.size(); ++i)
    {
        if (todos_eventos[i].GetNome() == nomeTarefa || todos_eventos[i].GetId() == stoi(nomeTarefa))
        {
            tarefa = &todos_eventos[i];
            break;
        }
    }

    if (tarefa != nullptr)
    {
        if (tarefa->GetStatus() == finalizado)
        {
            finalizar.inserir(19, "A tarefa já está finalizada", ESQ);
        }
        else
        {
            /* pedir para confirmar */
            tarefa->encerrar();
            finalizar.inserir(19, "Tarefa finalizada com sucesso", ESQ);
        }
    }
    else
    {
        finalizar.inserir(19, "Tarefa nao encontrada", ESQ);
    }
    finalizar.imprimir();
}

void p_time()
{
    Pagina equipe(LINHAS, COLUNAS, "EQUIPE");

    adts::Lista<int> equipe_lista_id = usuario.GetEquipes();
    adts::Lista<scrum_team> equipe_lista = transformarEquipe(equipe_lista_id);
    scrum_team equipe_selec;

    equipe.separador(LINHAS - 6);

    if (equipe_lista.size() > 1)
    {
        int tam = equipe_lista.size();
        equipe.inserir(1, "-Selecione uma equipe-", CEN);
        stringstream buffer;
        string s;

        for (int i = 0; i < 10 && i < tam; ++i)
        {
            buffer << equipe_lista[i];
            buffer >> s;
            equipe.inserir(3 + i, s, ESQ);
        }
        equipe.inserir(LINHAS - 3, "Time selecionado: ", ESQ);
        equipe.imprimir();
        equipe.ler("Insira o nome ou ID da equipe", s);

        for (int i = 0; i < equipe_lista.size(); ++i)
        {
            if (equipe_lista[i].GetNome() == s || equipe_lista[i].GetId() == stoi(s))
            {
                equipe_selec = equipe_lista[i];
                break;
            }
        }
    }
    else if (equipe_lista.size() == 0)
    {
        equipe.inserir(5, "Voce nao faz parte de nenhum time", CEN);
        equipe.esperar(LINHAS - 4, "voltar");
    }

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

void verTime()
{
    cout << "=====================================\n";
    cout << "Membros da equipe:\n";

    for (int i = 0; i < todos_membros.size(); ++i)
    {
        cout << "ID: " << todos_membros[i].GetId()
             << ", Nome: " << todos_membros[i].GetNome() << "\n";
    }

    cout << "=====================================\n";
}

void programa()
{
    bool controle = true;
    p_login();
    while (controle)
    {
        p_principal(controle);
    }
}