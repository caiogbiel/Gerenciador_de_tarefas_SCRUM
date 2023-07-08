#include <iostream>
#include <string>
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"
#include "./paginas.cpp"

using namespace geren_tempo;

/**
 * PRIMEIRA PAGINA(login)
 * opções: string-nome, permissao-funcao, sair
 * SEGUNDA PAGINA(gerenciador)
 * opções: tarefas(em ordem cronologinca), ver-tarefas finalizadas, criar tarefa, iniciar tarefa, finalizar tarefa, ver time, ver tarefas do time, sair
 */

// int main()
// {
//     adts::Lista<membros> teste;

//     membros m1 = membros("Jonas", permissao::developer);
//     membros m2 = membros("Maria", permissao::product_owner);
//     membros m3 = membros("Carlos", permissao::scrum_master);

//     teste.push_back(m1);
//     teste.push_back(m2);
//     teste.push_back(m3);
//     scrum_team time;

//     evento a = evento("confraternização", eventos_sprint::daily_scrum, tempo::agora(), tempo::agora(), teste, time, prioridade::media);
//     std::cout << "Fez o evento: \nNome: " << a.GetNome() << "\nTipo: " << a.GetTipo() << "\nData de inicio: " << a.GetInicio() << "\nData final: " << a.GetFim() << "\nPrioridade: " << a.GetPrioridade() << std::endl;
//     std::cout << "===========================\n"
//               << "Membros: \n";
//     teste.print();
// }

int main()
{
    adts::Lista<membros> a = adts::Lista<membros>();
    membros m1 = membros("Jonas", permissao::developer, tempo(2000, 10, 21));
    membros m2 = membros("Maria", permissao::product_owner, tempo(1993, 4, 24));
    membros m3 = membros("Carlos", permissao::scrum_master, tempo(1965, 7, 4));
    a.push_back(m1);
    a.push_back(m2);
    a.push_back(m3);
    a.print();

    string nome = "Daily 3";
    eventos_sprint tipo = eventos_sprint::daily_scrum;
    tempo inicio = tempo::agora();
    tempo fim = inicio + 1;
    adts::Lista<evento> eventos = adts::Lista<evento>();
    scrum_team *time = new scrum_team(a, eventos);

    evento daily = evento(nome, tipo, inicio, fim, a, time, prioridade::media);
}