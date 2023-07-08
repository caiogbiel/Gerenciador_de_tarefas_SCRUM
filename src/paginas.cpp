#include <iostream>
#include <vector>
#include "../include/time.hpp"
#include "../include/gerenciador.hpp"
#include "../include/evento.hpp"

using namespace std;

void programa()
{
    p_login();
    p_principal();
}

void p_login()
{

    cout << "=====================================\n";
    cout << "Entre com seu usuário: ";

    string nome;
    cin >> nome;
    usuario.SetNome(nome);

    cout << "(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
    cout << "Entre com sua função: ";

    int p;
    cin >> p;
    usuario.SetNivelDePermissao(permissao(p));
}

void p_principal()
{
    int opcao;
    cout << "=====================================\n";

    /* mostrar as tarefas do usuario aqui */

    // PERMISSAO GLOBAL
    cout << "1 - Ver tarefas finalizadas\n";
    cout << "2 - Criar nova tarefa\n";
    cout << "3 - Iniciar uma tarefa\n";
    cout << "4 - Finalizar uma tarefa\n";
    cout << "5 - Ver meu time\n";
    // PERMISSAO PRODUCT OWNER
    if (usuario.GetNivelDePermissao() == 0)
    {
        cout << "(escolher numero) - Finalizar Sprint\n";
    }
    // PERMISSAO DEVELOPER
    if (usuario.GetNivelDePermissao() == 1)
    {
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.GetNivelDePermissao() == 2)
    {
        cout << "(escolher numero) - Atribuir tarefa\n";
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
