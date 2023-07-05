#include <iostream>
#include "../include/time.hpp"
#include "../include/gerenciador.hpp"

using namespace std;

membros p_login()
{

    cout << "=====================================\n";
    cout << "Entre com seu usuário: ";

    string nome;
    cin >> nome;
    usuario.setNome(nome);

    cout << "(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
    cout << "Entre com sua função: ";

    int p;
    cin >> p;
    usuario.setNivelDePermissao(permissao(p));

    return usuario;
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
    if (usuario.getNivelDePermissao() == 0)
    {
        cout << "(escolher numero) - Finalizar Sprint\n";
    }
    // PERMISSAO DEVELOPER
    if (usuario.getNivelDePermissao() == 1)
    {
    }
    // PERMISSAO SCRUM MASTER
    if (usuario.getNivelDePermissao() == 2)
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
    if (usuario.getNivelDePermissao() == 0)
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
    if (usuario.getNivelDePermissao() == 1)
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
    if (usuario.getNivelDePermissao() == 2)
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
    if (usuario.getNivelDePermissao() == 2)
    {
        cout << "2 - Adicionar participante\n";
        cout << "3 - Remover participante\n";
    }
}