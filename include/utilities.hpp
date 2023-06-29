/**
 * Muitas classes aqui são templates, portanto, por praticidade, serão implementadas neste arquivo mesmo
 */

namespace adts
{
#ifndef ADTS_HPP
#define ADTS_HPP
#include <iostream>
#pragma region Nodes
    template <typename U>
    struct Duo_Node
    {
        U value;
        Duo_Node<U> *previous;
        Duo_Node<U> *next;
        Duo_Node()
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
            Duo_Node<T> *new_node = new Duo_Node<T>;
            if (new_node)
            {
                new_node->next = start;
                new_node->previous = nullptr;
                new_node->value = value;

                start->previous = new_node;
                start = new_node;
                return;
            }
            std::cerr << "Memoria insuficiente para inclusao de um novo valor\n";
        }
        void push_back(T value)
        {
            Duo_Node<T> *new_node = new Duo_Node<T>;
            if (new_node)
            {
                new_node->next = nullptr;
                new_node->previous = nullptr;
                new_node->value = value;

                Duo_Node<T> *temp = start;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                new_node->previous = temp;
                temp->next = new_node;
                return;
            }
            std::cerr << "Memoria insuficiente para inclusao de um novo valor\n";
        }
        void pop_front()
        {
            Duo_Node<T> *aux = start->next;
            delete start;
            start = aux;
        }
        void pop_back()
        {
            Duo_Node<T> *aux = start;

            if (!start)
            {
                return;
            }

            while (aux->next != nullptr)
            {
                if (aux->next->next == nullptr)
                    break;
                aux = aux->next;
            }
            delete aux->next;
            aux->next = nullptr;
        }
        void clear()
        {
            int count = size();
            for (int i = 1; i <= count; i++)
            {
                pop_front();
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
        void print()
        {
            Duo_Node<T> *temp = start;
            while (temp != nullptr)
            {
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
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
                cout << aux->value << " ";
                aux = aux->next;
            }
            cout << "\n";
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
