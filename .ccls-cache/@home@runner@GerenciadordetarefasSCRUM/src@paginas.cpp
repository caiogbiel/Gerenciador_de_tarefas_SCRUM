#include "../include/paginas.hpp"
#include "../include/utilities.hpp"
#define LINHAS 20
#define COLUNAS 100

Pagina::Pagina(int linhas, int colunas, string titulo) {
  _colunas = colunas;
  _linhas = linhas;
  //================TITULO================//
#pragma region Titulo
  int titulo_t = titulo.size();
  _titulo.push_back(string());
  _titulo.push_back(string());
  _titulo.push_back(string());
  // Primeira barra
  for (int i = 1; i <= colunas; ++i) {
    _titulo[0].append("=");
  }

  if (colunas - titulo_t <= 0) {
    throw runtime_error("Tamanho não pode ser menor que o titulo");
  }

  // Barra contendo o titulo
  _titulo[1].append("|");
  if (colunas % 2 == 0) {
    _titulo[1].append(" ");
  }
  for (int i = 1; i <= (colunas - titulo_t) / 2 - 1; ++i) {
    _titulo[1].append(" ");
  }

  _titulo[1].append(titulo);

  for (int i = 1; i <= (colunas - titulo_t) / 2 - 1; ++i) {
    _titulo[1].append(" ");
  }
  _titulo[1].append("|");

  // Terceira barra
  _titulo[2] = _titulo[0];
#pragma endregion

  //================CONTEUDO================//
#pragma region Conteudo
  string s;
  for (int i = 1; i < linhas; ++i) {
    s.append("*");
    while (s.size() < colunas - 1) {
      s.append(" ");
    }
    s.append("*");
    _conteudo.push_front(s);
    s.clear();
  }
  for (int i = 1; i <= colunas; ++i) {
    s.append("=");
  }
  _conteudo[_conteudo.size() - 1] = s;
#pragma endregion
}

Pagina::~Pagina() {}

void Pagina::inserir_em(int linha, int coluna, string conteudo) {
  string s = _conteudo[linha - 1];
  int c_t = conteudo.size();

  s.replace(coluna, c_t, conteudo);
  _conteudo[linha - 1] = s;
}

// Preset: ESQ = esquerda, CEN = centro, DIR = direita
void Pagina::inserir(int linha, string conteudo, int preset) {
  string s = _conteudo[linha - 1];
  int s_t = s.size();
  int c_t = conteudo.size();
  switch (preset) {
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

void Pagina::inserir_apos(int linha, string conteudo, int alinhar) {
  string s = _conteudo[linha - 1];
  string aux(s);

  aux.replace(0, 1, " ");
  aux.replace(aux.size() - 1, 1, " ");

  aux.replace(aux.find_last_not_of(' ') + 1, conteudo.size(), conteudo);

  if (alinhar < 0) {
    aux.replace(0, 1, "*");
    aux.replace(aux.size() - 1, 1, "*");
    _conteudo[linha - 1] = aux;
  } else {
    istringstream buffer(aux);

    aux.clear();

    while (buffer >> s)
      ;
    { aux.append(s); }

    inserir(linha, aux, alinhar);
  }
}

void Pagina::ler(string mensagem, std::string &saida) {
  cout << mensagem;
  std::getline(cin, saida);
}

void Pagina::ler(string mensagem, int &saida) {
  cout << mensagem;
  cin >> saida;
}

void Pagina::ler(string mensagem, permissao &saida) {
  cout << mensagem;
  int x;
  cin >> x;
  saida = permissao(x);
}

void Pagina::ler(string mensagem, prioridade &saida) {
  cout << mensagem;
  int x;
  cin >> x;
  saida = prioridade(x);
}

void Pagina::ler(string mensagem, eventos_sprint &saida) {
  cout << mensagem;
  int x;
  cin >> x;
  saida = eventos_sprint(x);
}

void Pagina::ler(string mensagem, status_evento &saida) {
  cout << mensagem;
  int x;
  cin >> x;
  saida = status_evento(x);
}

void Pagina::ler(string mensagem, evento &saida) {
  cout << mensagem;
  cin >> saida;
}

template <typename T>
void Pagina::ler_inserir(string mensagem, int linha, T &saida, int alinhar) {
  cin.clear();
  string s;
  string b;
  int n;

  s.append(mensagem);
  s.append(" ");

  cout << mensagem;

  if (typeid(T).name() == typeid(int).name() ||
      typeid(T).name() == typeid(string).name()) {
    getline(cin, b);
    istringstream buffer(b);
    s.append(b);
    buffer >> saida;
  }

  if (typeid(T).name() == typeid(permissao).name()) {
    cin >> n;
    string b = permissao_para_string(permissao(n));
    s.append(b);
    saida = permissao(n);
  }

  inserir(linha, s, alinhar);
}

void Pagina::imprimir() {
  cout << "\033[2J\033[1;1H";

  for (int i = 0; i < _titulo.size(); i++) {
    cout << _titulo[i] << "\n";
  }
  for (int i = 0; i < _conteudo.size(); i++) {
    cout << _conteudo[i] << "\n";
  }
}

void Pagina::separador(int linha) {
  string s;

  s.append("*");
  for (int i = 1; i < _colunas - 1; ++i) {
    s.append("=");
  }
  s.append("*");

  _conteudo[linha - 1] = s;
}

void Pagina::esperar(int linha, string mensagem) {
  inserir(linha, "Pressione qualquer tecla para " + mensagem, CEN);
  imprimir();
  cin.ignore();
  cin.get();
}

void Pagina::limpar_linha(int linha) {
  string s;
  s.append("*");
  for (int i = 1; i < _colunas; ++i) {
    s.append("=");
  }
  s.append("*");
  _conteudo[linha - 1] = s;
}

void Pagina::caixa(int x1, int y1, int x2, int y2) {
  y2++;

  for (int i = x1 + 1; i < x2; ++i) {
    inserir_em(y1, i, "_");
  }
  for (int i = y1 + 1; i < y2; i++) {
    inserir_em(i, x1, "|");
  }
  for (int i = x1 + 1; i < x2; ++i) {
    inserir_em(y2 - 1, i, "_");
  }
  for (int i = y1 + 1; i < y2; i++) {
    inserir_em(i, x2, "|");
  }
}

void p_login() {
#if 0 // temporario
    membros u("Luis", permissao::product_owner, geren_tempo::tempo(2004, 8, 24));
    membros m1("Jonas", permissao::developer, geren_tempo::tempo(2000, 10, 21));
    membros m2("Maria", permissao::product_owner, geren_tempo::tempo(1993, 4, 24));
    membros m3("Carlos", permissao::scrum_master, geren_tempo::tempo(1965, 7, 4));
    todos_membros.push_back(m1);
    todos_membros.push_back(m2);
    todos_membros.push_back(m3);
    todos_membros.push_back(u);

    adts::Lista<int> tm1(m1.GetId());
    adts::Lista<int> tm2(m2.GetId());

    tm2.push_back(u.GetId());

    scrum_team t1("Time 1", tm1);
    scrum_team t2("Time 2", tm2);
    todos_equipes.push_back(t1);
    todos_equipes.push_back(t2);

    adts::Lista<int> em1(m2.GetId());
    em1.push_back(u.GetId());

    em1.push_back(m1.GetId());
    em1.push_back(m3.GetId());

    evento e1("Daily 1", eventos_sprint::daily_scrum, em1, t1.GetId(), prioridade::media);
    todos_eventos.push_back(e1);
    u.SetEventos(adts::Lista<int>(e1.GetId()));
    /*
      Situação:
      Existem 4 membros,
      Jonas faz parte do time 1
      Maria faz parte do time 2
      Todos menos Jonas fazem parte do evento daily
    */

#endif

  Pagina login(LINHAS, COLUNAS, "LOGIN");
  string nome;
  permissao perm;

  login.caixa(COLUNAS / 3, 1, (COLUNAS / 3) * 2, LINHAS / 2 + 1);
  login.inserir_em(3, COLUNAS / 3 + 1, "Usuario: ");
  login.inserir_em(7, COLUNAS / 3 + 1, "Funcao: ");
  login.caixa(COLUNAS / 3 + 1, 4, (COLUNAS / 3) * 2 - 1, 6);
  login.caixa(COLUNAS / 3 + 1, 8, (COLUNAS / 3) * 2 - 1, 10);

  login.imprimir();

  login.ler("Entre com seu usuario: ", nome);
  login.imprimir();

  login.inserir_em(5, COLUNAS / 3 + 2, " " + nome);
  // login.inserir_apos(2, " " + nome);
  login.imprimir();

  cout << "\n(0 - Product Owner) (1 - Desenvolvedor) (2 - Scrum Master)\n";
  login.ler("Entre com sua funcao: ", perm);

  login.inserir_em(9, COLUNAS / 3 + 2, " " + permissao_para_string(perm));

  // login.inserir_apos(3, " " + permissao_para_string(perm));

  for (int i = 0; i < todos_membros.size(); ++i) {
    if (todos_membros[i].GetNome() == nome) {
      usuario = todos_membros[i];
      login.inserir(LINHAS - 6, "Bem vindo de volta " + nome, CEN);
      login.esperar(LINHAS - 4, "continuar");

      return;
    }
  }

  // FAZER CADASTRO//

  usuario.SetNome(nome);
  usuario.SetNivelDePermissao(perm);

  login.inserir(LINHAS - 6, "Bem vindo " + nome, CEN);
  login.esperar(LINHAS - 4, "continuar");
}

void p_debug() {
  Pagina debug(LINHAS + 5, COLUNAS, "TELA DE DEBUG");
  int l = 1;
  int k = 0;
  stringstream buffer;

  debug.inserir(l, "membros", CEN);
  for (int i = 0; i < todos_membros.size(); ++i) {
    buffer << todos_membros[i];
    cout << todos_membros[i] << '\n';
    debug.inserir(l + k + 1, buffer.str(), CEN);
    debug.imprimir();
    buffer.str(std::string());
    buffer.clear();
    k++;
  }
  for (int i = 0; i < todos_equipes.size(); ++i) {
    buffer << todos_equipes[i];
    cout << todos_equipes[i] << '\n';
    debug.inserir(l + k + 1, buffer.str(), CEN);
    debug.imprimir();
    buffer.str(std::string());
    buffer.clear();
    k++;
  }
  debug.inserir(l, "eventos", CEN);
  for (int i = 0; i < todos_eventos.size(); ++i) {
    buffer << todos_eventos[i];
    cout << todos_equipes[i] << '\n';
    debug.inserir(l + k + 1, buffer.str(), CEN);
    debug.imprimir();
    buffer.str(std::string());
    buffer.clear();
    k++;
  }
  debug.esperar(LINHAS + 4, "voltar");
}

void p_principal(bool &controlador) {
  Pagina principal(LINHAS + 7, COLUNAS, "MENU PRINCIPAL");
  principal.inserir(1, "-Suas tarefas-", CEN);
  int opcao;

  /*SUBSTITUIR todos_eventos POR LISTA DO USUÁRIO*/

  if (usuario.GetEventos().size() == 0) {
    // stringstream buffer;
    // buffer << usuario;
    principal.inserir(3, "Nao existem tarefas pendentes", CEN);

    /*
                     _____
                         /
                        /
                       /
                      /____
                ___
                  /
          _      /__
          /_
    z
    Colocar isso aqui depois
    */
  } else {
    stringstream buffer;
    for (int i = 0; i < 10 && i < todos_eventos.size(); ++i) {
      buffer << usuario.GetEventos()[i];
      principal.inserir(3 + i, buffer.str(), ESQ);
      buffer.str(std::string());
      buffer.clear();
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
  if (usuario.GetNivelDePermissao() == 0) {
    //principal.inserir(24, "6 - Finalizar Sprint", ESQ);
  }
  // PERMISSAO DEVELOPER
  if (usuario.GetNivelDePermissao() == 1) {
  }
  // PERMISSAO SCRUM MASTER
  if (usuario.GetNivelDePermissao() == 2) {
    principal.inserir(24, "6 - Atribuir tarefa", ESQ);
    principal.inserir(25, "7 - Desatribuir tarefa", ESQ);
  }
  principal.imprimir();

  principal.ler("Selecione uma opção: ", opcao);

  switch (opcao) {
  case -1:
    p_debug();
    break;
  case 0:
    controlador = false;
    return;
    break;
  case 1:
    p_finalizadas();
    break;
  case 2:
    // ainda em desenvolvimento
    p_criarNovaTarefa();
    break;
  case 3:
    p_iniciarTarefa();
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
  if (usuario.GetNivelDePermissao() == 0) {
    if (opcao == 6) {
    }
  }
  // PERMISSAO DEVELOPER
  if (usuario.GetNivelDePermissao() == 1) {
  }
  // PERMISSAO SCRUM MASTER
  if (usuario.GetNivelDePermissao() == 2) {
    if (opcao == 6) {
      atribuirTarefa();
    }
    if( opcao == 7){
      desatribuirTarefa();
    }
  }
}

void p_finalizadas() {
  Pagina finalizadas(LINHAS + 4, COLUNAS, "FINALIZAR TAREFA");
  std::string nomeTarefa;

  finalizadas.inserir(1, "-Tarefas finalizadas-", CEN);
  finalizadas.separador(LINHAS - 4);
  finalizadas.imprimir();

  // Fazer checar apenas as tarefas finalizadas
  if (todos_eventos.size() == 0) {
    finalizadas.inserir(3, "Nao existem tarefas encerradas", CEN);
    finalizadas.esperar(LINHAS, "voltar");
    return;
  } else {
    stringstream buffer;
    // string s;
    for (int i = 0; i < 10 && i < todos_eventos.size(); ++i) {
      if (todos_eventos[i].GetStatus() == finalizado) {
        buffer << todos_eventos[i];
        finalizadas.inserir(3 + i, buffer.str(), ESQ);
        buffer.str(std::string());
        buffer.clear();
      }
    }
  }
  finalizadas.esperar(LINHAS, "voltar");
  finalizadas.imprimir();
}

// ainda em desenvolvimento de case 2
void p_criarNovaTarefa() {
  Pagina criarNovaTarefa(LINHAS + 4, COLUNAS, "CRIAR NOVA TAREFA");
  evento novaTarefa;
  int n = 0;

  int aux;
  std::string nome;
  int id_participantes;
  membros *participante = nullptr;
  scrum_team *time = nullptr;
  int id_time;

  criarNovaTarefa.ler("Digite o nome da tarefa: ", nome);
  novaTarefa.SetNome(nome);
  criarNovaTarefa.ler(
      "Digite a prioridade da tarefa 0: Baixa, 1 Media, 2: Alta, 3: Urgente: ",
      aux);
  novaTarefa.SetPrioridade(prioridade(aux));
  criarNovaTarefa.ler("Digite o tipo da tarefa 0: Planning, 1 Daily Scrum, 2: "
                      "Review, 3: Retrospective: ",
                      aux);
  novaTarefa.SetTipo(eventos_sprint(aux));
  criarNovaTarefa.ler("Digite o id do time da tarefa: ", id_time);

  for (int i = 0; i < todos_equipes.size(); ++i) {
    if (todos_equipes[i].GetId() == id_time) {
      time = &todos_equipes[i];
      break;
    }
  }
  if (time == nullptr) {
    criarNovaTarefa.inserir(3, "Time nao existe", CEN);
    criarNovaTarefa.esperar(LINHAS, "voltar");
  } else {
    novaTarefa.SetTime(time->GetId());
  }
  while (n != -1) {
    criarNovaTarefa.ler("Digite o id dos participantes da tarefa: ",
                        id_participantes);
    for (int i = 0; i < todos_membros.size(); ++i) {
      if (todos_membros[i].GetId() == id_participantes) {
        participante = &todos_membros[i];
        break;
      }
    }
    if (participante == nullptr) {
      criarNovaTarefa.inserir(3, "Participante nao existe", CEN);
      criarNovaTarefa.esperar(LINHAS, "voltar");
    } else {
      novaTarefa.adicionarParticipantes(participante->GetId());
    }
    criarNovaTarefa.ler(
        "Se nao deseja adicionar outro participante aperte -1: ", n);
    criarNovaTarefa.esperar(LINHAS, "voltar");
  }
  criarNovaTarefa.esperar(10, "confirmar");
  /* pedir para confirmar */
  std::string conf;
  criarNovaTarefa.ler("Criar tarefa?(s/n)", conf);
  if (conf.front() == 's' || conf.front() == 'S') {
    todos_eventos.push_back(novaTarefa);
    // usuario.AddEvento(novaTarefa.GetId());
    criarNovaTarefa.limpar_linha(18);
    criarNovaTarefa.inserir(19, "Tarefa criada com sucesso", CEN);
  } else {
    criarNovaTarefa.esperar(10, "nao confirmou");
    p_finalizarTarefa();
  }
}

// TROCAR PARA TAREFAS DO USUÁRIO
void p_iniciarTarefa() {
  Pagina iniciar(LINHAS + 4, COLUNAS, "INICIAR TAREFA");
  int id_tarefa;

  iniciar.inserir(1, "-Tarefas a iniciar-", CEN);
  iniciar.separador(LINHAS - 4);
  iniciar.imprimir();

  if (todos_eventos.size() == 0) {
    iniciar.inserir(3, "Nao existem tarefas para iniciar", CEN);
    iniciar.esperar(LINHAS, "voltar");
    iniciar.imprimir();
    return;
  } else {
    stringstream buffer;
    for (int i = 0; i < 10 && i < todos_eventos.size(); ++i) {
      if (todos_eventos[i].GetStatus() == analise) {
        buffer << todos_eventos[i];
        iniciar.inserir(3 + i, buffer.str(), ESQ);
        buffer.str(std::string());
        buffer.clear();
      }
    }
  }

  iniciar.imprimir();

  iniciar.inserir(18, "Tarefa selecionada: ", ESQ);

  iniciar.ler("Digite o ID da tarefa que deseja iniciar: ", id_tarefa);
  iniciar.inserir_apos(18, " " + std::to_string(id_tarefa));
  iniciar.imprimir();

  evento *tarefa = nullptr;

  for (int i = 0; i < todos_eventos.size(); ++i) {
    if (todos_eventos[i].GetId() == id_tarefa) {
      tarefa = &todos_eventos[i];
      break;
    }
  }

  if (tarefa != nullptr) {
    if (tarefa->GetStatus() == andamento) {
      iniciar.inserir(19, "A tarefa já está em andamento", ESQ);
      iniciar.esperar(18, "voltar");
      return;
    } else {
      std::string conf;
      iniciar.ler("Deseja iniciar a tarefa?(s/n)", conf);
      if (conf.front() == 's' || conf.front() == 'S') {
        tarefa->iniciar();
        // iniciar.limpar_linha(18);
        iniciar.inserir(19, "Tarefa inicializada com sucesso", CEN);
        iniciar.esperar(18, "voltar");
      } else {
        iniciar.esperar(18, "voltar");
        return;
      }
    }
  } else {
    iniciar.inserir(19, "Tarefa nao encontrada", CEN);
  }
  iniciar.esperar(18, "voltar");
}
// case 4
void p_finalizarTarefa() {
  Pagina finalizar(LINHAS + 4, COLUNAS, "FINALIZAR TAREFA");
  int id_tarefa;

  finalizar.inserir(1, "-Tarefas a finalizar-", CEN);
  finalizar.separador(LINHAS - 4);
  finalizar.imprimir();

  // adts::Lista<evento> lista = transformarEventos(usuario.GetEventos());

  if (todos_eventos.size() == 0) {
    finalizar.inserir(3, "Nao existem tarefas para encerrar", CEN);
    finalizar.esperar(LINHAS, "voltar");
    finalizar.imprimir();
    return;
  } else {
    stringstream buffer;
    for (int i = 0; i < 10 && i < todos_eventos.size(); ++i) {
      if (todos_eventos[i].GetStatus() == andamento) {
        buffer << todos_eventos[i];
        finalizar.inserir(3 + i, buffer.str(), ESQ);
        buffer.clear();
      }
    }
  }

  finalizar.imprimir();

  finalizar.inserir(18, "Tarefa selecionada: ", ESQ);

  finalizar.ler("Digite o ID da tarefa que deseja finalizar: ", id_tarefa);
  finalizar.inserir_apos(18, " " + std::to_string(id_tarefa));
  finalizar.imprimir();

  evento *tarefa = nullptr;

  for (int i = 0; i < todos_eventos.size(); ++i) {
    if (todos_eventos[i].GetId() == id_tarefa) {
      tarefa = &todos_eventos[i];
      break;
    }
  }

  if (tarefa != nullptr) {
    finalizar.esperar(10, "Entrou");
    if (tarefa->GetStatus() == finalizado) {
      finalizar.esperar(10, "finalizado");
      finalizar.inserir(19, "A tarefa já está finalizada", ESQ);
    } else {
      finalizar.esperar(10, "confirmar");
      /* pedir para confirmar */
      std::string conf;
      finalizar.ler("Deseja finalizar a tarefa?(s/n)", conf);
      if (conf.front() == 's' || conf.front() == 'S') {
        tarefa->encerrar();
        finalizar.limpar_linha(18);
        finalizar.inserir(19, "Tarefa finalizada com sucesso", CEN);
      } else {
        finalizar.esperar(10, "nao confirmou");
        p_finalizarTarefa();
      }
    }
  } else {
    finalizar.inserir(19, "Tarefa nao encontrada", CEN);
  }
  finalizar.imprimir();
  finalizar.esperar(18, "voltar");
}

void p_time() {
  Pagina equipe(LINHAS, COLUNAS, "EQUIPE");

  adts::Lista<int> equipe_lista_id = usuario.GetEquipes();
  adts::Lista<scrum_team> equipe_lista = transformarEquipe(equipe_lista_id);
  scrum_team equipe_selec;

  equipe.separador(LINHAS - 6);

  if (equipe_lista.size() > 1) {
    int tam = equipe_lista.size();
    equipe.inserir(1, "-Selecione uma equipe-", CEN);

    stringstream buffer;
    for (int i = 0; i < 10 && i < tam; ++i) {
      buffer << equipe_lista[i];
      equipe.inserir(3 + i, buffer.str(), ESQ);
    }
    equipe.inserir(LINHAS - 3, "Time selecionado: ", ESQ);
    equipe.imprimir();
    string s;
    equipe.ler("Insira o nome ou ID da equipe", s);

    for (int i = 0; i < equipe_lista.size(); ++i) {
      if (equipe_lista[i].GetNome() == s ||
          equipe_lista[i].GetId() == stoi(s)) {
        equipe_selec = equipe_lista[i];
        break;
      }
    }
  } else if (equipe_lista.size() == 0) {
    equipe.inserir(5, "Voce nao faz parte de nenhum time", CEN);
    equipe.esperar(LINHAS - 4, "voltar");
  }

  /* Mostrar participantes do time */
  cout << "1 - Ver tarefas do time\n";

  // PERMISSAO SCRUM MASTER
  if (usuario.GetNivelDePermissao() == 2) {
    cout << "2 - Adicionar participante\n";
    cout << "3 - Remover participante\n";
  }
}

void verTime() {
  cout << "=====================================\n";
  cout << "Membros da equipe:\n";

  for (int i = 0; i < todos_membros.size(); ++i) {
    cout << "ID: " << todos_membros[i].GetId()
         << ", Nome: " << todos_membros[i].GetNome() << "\n";
  }

  cout << "=====================================\n";
}

// case 6 scrum_master
void atribuirTarefa() {
  Pagina atribuir(LINHAS + 4, COLUNAS, "ATRIBUIR TAREFA");
  int id_tarefa;
  int id_participante;

  atribuir.inserir(1, "-Atribuir Tarefa-", CEN);
  atribuir.separador(LINHAS - 4);
  atribuir.imprimir();

  atribuir.ler("Digite o ID da tarefa que deseja atribuir: ", id_tarefa);
  atribuir.ler("Digite o ID do participante a quem deseja atribuir a tarefa: ",
               id_participante);

  // Verificar se a tarefa existe
  bool tarefaEncontrada = false;
  evento *tarefa = nullptr;
  for (int i = 0; i < todos_eventos.size(); ++i) {
    if (todos_eventos[i].GetId() == id_tarefa) {
      tarefa = &todos_eventos[i];
      tarefaEncontrada = true;
      break;
    }
  }

  // Verificar se o participante existe
  bool participanteEncontrado = false;
  membros *participante = nullptr;
  for (int i = 0; i < todos_membros.size(); ++i) {
    if (todos_membros[i].GetId() == id_participante) {
      participante = &todos_membros[i];
      participanteEncontrado = true;
      break;
    }
  }

  // Atribuir a tarefa ao participante
  if (tarefaEncontrada && participanteEncontrado) {
    tarefa->adicionarParticipantes(participante->GetId());
    atribuir.inserir(3, "Tarefa atribuída com sucesso!", CEN);
  } else {
    atribuir.inserir(3, "Tarefa ou participante não encontrado.", CEN);
  }
  atribuir.esperar(LINHAS, "voltar");
  atribuir.imprimir();
}

// case 7 scrum_master
void desatribuirTarefa()
{
  Pagina desatribuir(LINHAS + 4, COLUNAS, "REMOVER PARTICIPANTE");
  int id_tarefa;
  int id_participante;

  desatribuir.inserir(1, "-Remover Participante-", CEN);
  desatribuir.separador(LINHAS - 4);
  desatribuir.imprimir();

  desatribuir.ler("Digite o ID da tarefa da qual deseja remover o participante: ", id_tarefa);
  desatribuir.ler("Digite o ID do participante que deseja remover da tarefa: ", id_participante);

  //verifica se a tarefa existe
  bool TarefaEncontrada = false;
  evento* tarefa = nullptr;
    for(int i = 0; i < todos_eventos.size(); ++i){
      if(todos_eventos[i].GetId() == id_tarefa){
        tarefa = &todos_eventos[i];
        TarefaEncontrada = true;
        break;
      }
    }

  //verifica se existe usuario
  bool participanteEncontrado = false;
  membros* participante = nullptr;
    for(int i = 0; i < todos_membros.size(); ++i){
      if(todos_membros[i].GetId() == id_participante){
        participante = &todos_membros[i];
        participanteEncontrado = true;
        break;
      }
    }

  //desatribui a tarefa caso o participante esteja associado a ela
  if(TarefaEncontrada && participanteEncontrado) {
    bool participanteRemovido = tarefa->removerParticipantes(participante->GetId());
    if(participanteRemovido){
      desatribuir.inserir(3, "Participante removido da tarefa", CEN);
    }
    else {
      desatribuir.inserir(3, "Participante nao esta atribuido a tarefa", CEN);
    }
  }
  else{
    desatribuir.inserir(3, "Participante ou tarefa nao encontrado.", CEN);
  }
  desatribuir.esperar(LINHAS, "voltar");
  desatribuir.imprimir();
}

void programa() {
  bool controle = true;
  p_login();
  while (controle) {
    p_principal(controle);
  }
}