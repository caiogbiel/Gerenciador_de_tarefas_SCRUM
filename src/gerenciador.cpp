#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "../include/date.h"
#include "../include/evento.hpp"
#include "../include/enums.hpp"
#include "../include/utilities.hpp"

using namespace date;
using namespace std::chrono;

int main()
{
    std::cout << "PROGRAMA INICIOU\n";

    geren_time::tempo inicio = geren_time::tempo::agora();
    geren_time::tempo fim = inicio + 2;

    std::cout << "VAI CRIAR EVENTO\n";
    std::cout << inicio << "\n"
              << fim << "\n"
              << std::endl;

    std::cout << "CRIOU EVENTO\n";
    std::cout << "PROGRAMA TERMINOU\n";
}