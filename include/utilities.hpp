/**
 * Muitas classes aqui são templates, portanto, por praticidade, serão implementadas neste arquivo mesmo
 */
#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <iostream>
#include <iomanip>
#include <chrono>
#include "./date.h"
// #include "./time.hpp"

namespace adts
{
#ifndef ADTS_HPP
#define ADTS_HPP
#pragma region Nodes
    template <typename U>
    struct Duo_Node
    {
        U value;
        Duo_Node<U> *previous;
        Duo_Node<U> *next;

        Duo_Node() : value()
        {
            previous = nullptr;
            next = nullptr;
        }
        Duo_Node(U value)
        {
            this->value = value;
            previous = nullptr;
            next = nullptr;
        }
        ~Duo_Node()
        {
            previous = nullptr;
            next = nullptr;
        }
    };

    template <typename U>
    struct Uni_Node
    {
        U value;
        Uni_Node<U> *next;
        Uni_Node()
        {
            next = nullptr;
        }
        Uni_Node(U value)
        {
            this->value = value;
            next = nullptr;
        }
        ~Uni_Node()
        {
            next = nullptr;
        }
    };
#pragma endregion Nodes

#pragma region List
    // front = inicio | back = fim
    template <typename T>
    class Lista
    {
    private:
        Duo_Node<T> *start;

    public:
        Lista()
        {
            start = nullptr;
        }
        Lista(T initial)
        {
            start = new Duo_Node<T>;
            start->value = initial;
            start->next = nullptr;
            start->previous = nullptr;
        }
        ~Lista()
        {
            clear();
        }
        void push_front(T value)
        {
            Duo_Node<T> *new_node = new Duo_Node<T>();
            if (new_node)
            {
                new_node->next = start;
                new_node->previous = nullptr;
                new_node->value = value;

                if (start)
                {
                    start->previous = new_node;
                }
                start = new_node;
                return;
            }
            std::cerr << "Memoria insuficiente para inclusao de um novo valor\n";
        }
        void push_back(T value)
        {
            Duo_Node<T> *new_node = new Duo_Node<T>();
            if (new_node)
            {
                new_node->value = value;

                if (start)
                {
                    Duo_Node<T> *temp = start;
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                    new_node->previous = temp;
                }
                else
                {
                    start = new_node;
                }
                return;
            }
            std::cerr << "Memoria insuficiente para inclusao de um novo valor\n";
        }
        void pop_front()
        {
            if (start)
            {
                Duo_Node<T> *aux = start->next;
                delete start;
                start = aux;
            }
        }
        void pop_back()
        {
            if (!start)
            {
                return;
            }

            if (!start->next)
            {
                delete start;
                start = nullptr;
                return;
            }

            Duo_Node<T> *aux = start;

            while (aux->next)
            {
                if (!aux->next->next)
                {
                    delete aux->next;
                    aux->next = nullptr;
                    return;
                }
                aux = aux->next;
            }
        }
        bool remove(T value)
        {
            Duo_Node<T> *aux = start;
            while (aux)
            {
                if (aux->value == value)
                {
                    if (aux->previous)
                    {
                        aux->previous->next = aux->next;
                    }
                    else
                    {
                        start = aux->next;
                    }
                    if (aux->next)
                    {
                        aux->next->previous = aux->previous;
                    }
                    delete aux;
                    aux = nullptr;
                    return true;
                }
                aux = aux->next;
            }
            return false;
        }
        void clear()
        {
            while (start)
            {
                pop_back();
            }
        }
        int size()
        {
            Duo_Node<T> *aux = start;
            int count = 0;

            if (aux)
            {
                count++;
                while (aux->next != nullptr)
                {
                    count++;
                    aux = aux->next;
                }
            }
            return count;
        }
        bool find(T value)
        {
            Duo_Node<T> *aux = start;
            if (aux)
            {
                while (aux->next)
                {
                    if (aux->value == value)
                    {
                        return true;
                    }
                    aux = aux->next;
                }
            }
            return false;
        }
        void print()
        {
            Duo_Node<T> *temp = start;
            while (temp != nullptr)
            {
                std::cout << temp->value << "\n";
                temp = temp->next;
            }
        }

        // Duo_Node<T> *GetStart() const
        // {
        //     return start;
        // }

        // friend membros scrum_team::operator[](int indice)
        // {
        //     if (indice >= 0 && indice < _quantidade)
        //     {
        //         int current = 0;
        //         Duo_Node<membros> *aux = _participantes.getStart();
        //         while (aux != nullptr)
        //         {
        //             if (indice == current)
        //             {
        //                 return aux->value;
        //             }
        //             aux = aux->next;
        //             current++;
        //         }
        //     }
        //     throw std::runtime_error("Indice nao foi encontrado");
        // }
    };
#pragma endregion

#pragma region Queue
    template <typename T>
    class Queue
    {
    private:
        int _size = 0;
        Uni_Node<T> *_first = nullptr;
        Uni_Node<T> *_last = nullptr;

    public:
        Queue() {}
        Queue(T value)
        {
            _first = new Uni_Node<T>(value);
            _last = _first;
            _size++;
        }
        int size() { return _size; }
        void print()
        {
            Uni_Node<T> *aux = _first;
            while (aux != nullptr)
            {
                std::cout << aux->value << " ";
                aux = aux->next;
            }
            std::cout << "\n";
        }
        const T &front() const { return _first->value; }
        const T &back() const { return _last->value; }
        bool empty() const { return (_first == nullptr) ? true : false; }
        void push(T value)
        {
            Uni_Node<T> *new_node = new Uni_Node<T>(value);

            if (empty())
            {
                _first = new_node;
                _last = _first;
            }
            else
            {
                _last->next = new_node;
                _last = new_node;
            }
            _size++;
        }
        void pop()
        {
            if (empty())
            {
                std::cerr << "Fila ja esta vazia\n";
                return;
            }
            if (_first->next == nullptr)
            {
                delete _first;
                _first = nullptr;
                _size--;
                return;
            }
            Uni_Node<T> *aux = _first->next;

            delete _first;
            _first = nullptr;

            _first = aux;
            _size--;
        }
    };
#pragma endregion

#endif
} // namespace adts (abstract data types)

namespace sorters
{
#ifndef SORTERS_HPP
#define SORTERS_HPP
    // selection sort
    template <typename T>
    void selectionSort(T arr[], int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int minIndex = i;

            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                std::swap(arr[i], arr[minIndex]);
            }
        }
    }

    // quick sort
    template <typename T>
    int partition(T arr[], int low, int high)
    {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    template <typename T>
    void quickSort(T arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // merge sort
    template <typename T>
    void mergeSort(T arr[], int start, int end)
    {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        int left = start, right = mid + 1;
        T temp[end - start + 1];
        int index = 0;

        while (left <= mid && right <= end)
        {
            if (arr[left] <= arr[right])
                temp[index++] = arr[left++];
            else
                temp[index++] = arr[right++];
        }

        while (left <= mid)
            temp[index++] = arr[left++];

        while (right <= end)
            temp[index++] = arr[right++];

        for (int i = start; i <= end; i++)
            arr[i] = temp[i - start];
    }
#endif
} // namespace sorters

namespace searchers
{
#ifndef SEARCHERS_HPP
#define SEARCHERS_HPP
    template <typename T>
    T *binary_search(T *&vector, int start, int end, T value)
    {
        int mid = (end + start) / 2;

        if (end - start == 0 && vector[end] != value)
        {
            return nullptr;
        }

        if (vector[mid] < value)
        {
            return binary_search(vector, mid + 1, end, value);
        }
        if (vector[mid] > value)
        {
            return binary_search(vector, start, mid - 1, value);
        }

        return &vector[mid];
    }
#endif
} // namespace searchers

namespace geren_tempo
{
#ifndef GEREN_TEMPO
#define GEREN_TEMPO
    /**
     * @brief Representa uma data, com ano, mes, dia, hora e minuto. Requer "date.h"
     *
     */
    class tempo
    {
    private:
        date::year_month_day _ano_mes_dia;
        std::chrono::hours _hora;
        std::chrono::minutes _minutos;

    public:
        tempo() : _ano_mes_dia(date::year(1900), date::month(1), date::day(1)), _hora(0), _minutos(0) {}
        tempo(int ano, int mes, int dia) : _ano_mes_dia(date::year(ano), date::month(mes), date::day(dia)), _hora(0), _minutos(0) {}
        tempo(int ano, int mes, int dia, int hora, int minuto) : _ano_mes_dia(date::year(ano), date::month(mes), date::day(dia)), _hora(hora), _minutos(minuto) {}
        friend tempo operator+(tempo &t, int dias);
        friend tempo operator-(tempo &t, int dias);
        // friend tempo operator+(tempo &t1, tempo &t2);
        // friend tempo operator-(tempo &t1, tempo &t2);
        tempo &operator+=(int dias);
        tempo &operator-=(int dias);
        bool operator==(const tempo &t);
        static tempo agora(int fuso_horario = 0);
        void SetAno(int ano);
        void SetMes(int mes);
        void SetDia(int dia);
        void SetHora(int hora);
        void SetMinuto(int minuto);
        date::year GetAno();
        date::month GetMes();
        date::day GetDia();
        std::chrono::hours GetHora();
        std::chrono::minutes GetMinuto();
        friend std::ostream &
        operator<<(std::ostream &o, const tempo &t)
        {
            o << t._ano_mes_dia.day() << "/" << t._ano_mes_dia.month() << "/" << t._ano_mes_dia.year() << " " << std::setw(2) << std::setfill('0') << t._hora.count() << ":" << std::setw(2) << std::setfill('0') << t._minutos.count();
            return o;
        }
    };
#endif
}
#endif