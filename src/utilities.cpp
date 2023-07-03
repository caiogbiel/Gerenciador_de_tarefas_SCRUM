#include "../include/utilities.hpp"

geren_tempo::tempo geren_tempo::operator+(geren_tempo::tempo &t, int dias)
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
geren_tempo::tempo geren_tempo::operator+(geren_tempo::tempo &t1, geren_tempo::tempo &t2)
{
    // date::sys_time<std::chrono::minutes>(date::sys_days(t2._ano_mes_dia) + date::sys_days(t2._ano_mes_dia));
}
// PENDENTE
geren_tempo::tempo geren_tempo::operator-(geren_tempo::tempo &t1, geren_tempo::tempo &t2)
{
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

geren_tempo::tempo geren_tempo::tempo::agora()
{
    geren_tempo::tempo temp;
    auto _agora = std::chrono::system_clock::now();
    temp._ano_mes_dia = date::year_month_day(floor<date::days>(_agora));

    // Código abaixo obtido desta thread: https://stackoverflow.com/questions/34528083/get-current-number-of-hours-and-minutes-using-chronotime-point
    auto now = date::floor<std::chrono::minutes>(_agora);
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
    _hora = std::chrono::hours(hora);
}
void geren_tempo::tempo::SetMinuto(int minuto)
{
    _minutos = std::chrono::minutes(minuto);
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
std::chrono::hours geren_tempo::tempo::GetHora()
{
    return _hora;
}
std::chrono::minutes geren_tempo::tempo::GetMinuto()
{
    return _minutos;
}