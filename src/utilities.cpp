#include "../include/utilities.hpp"
using namespace std::chrono;

geren_tempo::tempo
geren_tempo::operator+(geren_tempo::tempo &t, int dias)
{
    auto data = date::year_month_day(date::sys_days(t._ano_mes_dia) + date::days(dias));
    tempo novo_tempo = tempo(int(data.year()), unsigned(data.month()), unsigned(data.day()), t.GetHora().count(), t.GetMinuto().count());
    return novo_tempo;
}

geren_tempo::tempo geren_tempo::operator-(geren_tempo::tempo &t, int dias)
{
    auto data = date::year_month_day(date::sys_days(t._ano_mes_dia) - date::days(dias));
    tempo novo_tempo = tempo(int(data.year()), unsigned(data.month()), unsigned(data.day()), t.GetHora().count(), t.GetMinuto().count());
    return novo_tempo;
}

// PENDENTE
// geren_tempo::tempo geren_tempo::operator+(geren_tempo::tempo &t1, geren_tempo::tempo &t2)
// {
//     // date::sys_time<minutes>(date::sys_days(t2._ano_mes_dia) + date::sys_days(t2._ano_mes_dia));
//     int novo_ano = int(t1.GetAno()) + int(t2.GetAno());

//     date::year_month_day novo = date::year_month_day();
// }
// // PENDENTE
// geren_tempo::tempo geren_tempo::operator-(geren_tempo::tempo &t1, geren_tempo::tempo &t2)
// {
//     int novo_ano = int(t1.GetAno()) - int(t2.GetAno());
//     unsigned novo_mes = unsigned(t1.GetMes()) - unsigned(t2.GetMes());
//     unsigned novo_dia = unsigned(t1.GetDia()) - unsigned(t2.GetDia());
//     int nova_hora = t1.GetHora().count() - t2.GetHora().count();
//     int novo_minuto = t1.GetMinuto().count() - t2.GetMinuto().count();

//     //data_em_segundos = (hora1 * 60) + (hora2 * 60) + minuto1 + minuto2

//     unsigned long long data_em_segundos = (31536000 * int(t1.GetAno())) - (31536000 * int(t2.GetAno())) + (t1.GetMes()) + (86400 * unsigned(t1.GetDia())) - (86400 * unsigned(t1.GetDia())) +;

//     geren_tempo::tempo novo = geren_tempo::tempo(0,0,0);
//     if(novo_ano < 0) {
//         return novo;
//     }
//     if (novo_minuto < 0)
//     {
//         novo.SetMinuto((60 - novo_minuto) + t1.GetMinuto().count());
//         nova_hora--;
//     }
//     if(nova_hora < 0){
//         novo.SetHora((24 - nova_hora) + t1.GetHora().count());
//         novo_dia--;
//     }
//     auto temp = date::year_month_day(novo_ano, novo_mes, novo_dia);
// }
bool geren_tempo::tempo::operator==(const tempo &t)
{
    bool is_equal = true;
    is_equal &= (this->GetAno() == t._ano_mes_dia.year());
    is_equal &= (this->GetMes() == t._ano_mes_dia.month());
    is_equal &= (this->GetDia() == t._ano_mes_dia.day());
    is_equal &= (this->GetHora() == t._hora);
    is_equal &= (this->GetMinuto() == t._minutos);
    return is_equal;
}

geren_tempo::tempo &geren_tempo::tempo::operator+=(int dias)
{
    *this = *this + dias;
    return *this;
}

geren_tempo::tempo &geren_tempo::tempo::operator-=(int dias)
{
    *this = *this - dias;
    return *this;
}

geren_tempo::tempo geren_tempo::tempo::agora(int fuso_horario)
{
    // ACHAR UMA MANEIRA DE SUBTRAIR FUSO HORARIO
    geren_tempo::tempo temp;
    auto _agora = system_clock::now();
    temp._ano_mes_dia = date::year_month_day(floor<date::days>(_agora));

    // Código abaixo obtido desta thread: https://stackoverflow.com/questions/34528083/get-current-number-of-hours-and-minutes-using-chronotime-point
    auto now = date::floor<minutes>(_agora);
    auto dp = date::floor<date::days>(now);
    auto time = date::make_time(now - dp);
    temp._hora = time.hours();
    temp._minutos = time.minutes();

    return temp;
}

void geren_tempo::tempo::SetAno(int ano)
{

    _ano_mes_dia = date::year_month_day(date::year(ano), _ano_mes_dia.month(), _ano_mes_dia.day());
}
void geren_tempo::tempo::SetMes(int mes)
{
    _ano_mes_dia = date::year_month_day(_ano_mes_dia.year(), date::month(mes), _ano_mes_dia.day());
}
void geren_tempo::tempo::SetDia(int dia)
{
    _ano_mes_dia = date::year_month_day(_ano_mes_dia.year(), _ano_mes_dia.month(), date::day(dia));
}
void geren_tempo::tempo::SetHora(int hora)
{
    _hora = hours(hora);
}
void geren_tempo::tempo::SetMinuto(int minuto)
{
    _minutos = minutes(minuto);
}

date::year geren_tempo::tempo::GetAno()
{
    return _ano_mes_dia.year();
}
date::month geren_tempo::tempo::GetMes()
{
    return _ano_mes_dia.month();
}
date::day geren_tempo::tempo::GetDia()
{
    return _ano_mes_dia.day();
}
hours geren_tempo::tempo::GetHora()
{
    return _hora;
}
minutes geren_tempo::tempo::GetMinuto()
{
    return _minutos;
}