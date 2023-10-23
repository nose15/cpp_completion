#include "../include/DList.h"


// Plik źródłowy zawierający implementację klasy DList, której przeznaczenie jest opisane w jej pliku nagłówkowym DList.h

// dzięki zastosowaniu std::initializer_list, listę można inicjalizować w podobny sposób jak tablicę, dzięki czemu praca
// z nią jest prosta i intuicyjna
template<typename T>
DList<T>::DList(std::initializer_list<T> initializerList)
{
    bool firstSet = false;
    Node<T> * prev_pointer = nullptr;

    this->list_size = initializerList.size();

    for (const T& value : initializerList)
    {
        auto* node = new Node<T>(value, prev_pointer, nullptr);

        if (firstSet)
        {
            prev_pointer->setNextPtr(node);
        }
        else
        {
            this->startNode = node;
            firstSet = true;
        }

        prev_pointer = node;
        this->endNode = node;
    }
}

// Poniższe dwie funkcje zawierają nadpisanie operatora []
// Pozwala to na odwoływanie się do elementów listy, w taki sam sposób jak do elementów tablicy

// ta funkcja jest używana tylko do odczytu
template<typename T>
T DList<T>::operator[](size_t index) const
{
    Node<T> * result = GetElementByIndex(index);
    return result->GetValue();
}

// ta funkcja zwraca odwołanie do wartości, więc może być używana do modyfikacji danej pozycji
template<typename T>
T& DList<T>::operator[](size_t index)
{
    Node<T> * result = GetElementByIndex(index);
    return result->GetValue();
}

// Funkcja append dodaje nowy element na końcu listy
template<typename T>
Node<T> * DList<T>::Append(T val)
{
    // tworzymy nowy węzeł z podaną wartością
    auto * newNode = new Node<T>(val, endNode, nullptr);

    // do dotychczasowego węzła końcowego dodajemy wskaźnik do nowego węzła
    endNode->setNextPtr(newNode);

    // ustawiamy nowy węzeł jako nowy węzeł końcowy
    endNode = newNode;
    list_size++;

    // zwracamy nowy węzeł
    return endNode;
}


// Ta funkcja pozwala na usunięcie elementu według jego wartości
// Działa tylko dla podstawowych typów (bool, int, char, itp...)
template<typename T>
Node<T> * DList<T>::RemoveByValue(T val)
{
    // ustawiamy zmienną current_node, która będzie zawierać węzeł, który obecnie sprawdzamy
    Node<T> * current_node = startNode;

    // iterujemy po wszystkich węzłach z wyłączeniem pierwszego i ostatniego
    while (current_node != endNode)
    {
        if (current_node->GetValue() == val)
        {
            return RemoveElement(current_node);
        }
        current_node = current_node->next_node();
    }

    // w wypadku, gdy żaden węzeł nie miał poszukiwanej wartości, zwracamy wskaźnik do 0
    return nullptr;
}

// Ta funkcja pozwala na usunięcie elementu znajdującego się na danym indeksie listy
template<typename T>
Node<T> * DList<T>::RemoveByIndex(int index)
{
    Node<T> * currentNode = GetElementByIndex(index);
    Node<T> * node = RemoveElement(currentNode);

    return node;
}

// Funkcja zwracająca ilość elementów listy
template<typename T>
size_t DList<T>::GetSize() const
{
    this->list_size;
}

// Funkcja pozwalająca szybko znaleźć element listy
template<typename T>
Node<T> * DList<T>::GetElementByIndex(int index)
{
    // najpierw wykluczamy przypadki skrajne oraz przypadek, gdzie podany indeks nie znajduje się w liście
    if (index == 0) return startNode;
    if (index == list_size - 1) return endNode;
    if (index < 0 || index > (list_size - 1)) return nullptr;

    Node<T> * currentNode;

    // teraz sprawdzamy czy szybciej będzie iterować od początku czy od końca
    if (index > (list_size - 1) - index)
    // iteracja od końca
    {
        currentNode = endNode;

        for (int i = list_size - 1; i > index; --i)
        {
            currentNode = currentNode->prev_node();
        }

        return currentNode;
    }

    // iteracja od początku
    currentNode = startNode;

    for (int i = 0; i < index; ++i)
    {
        currentNode = currentNode->next_node();
    }

    return currentNode;
}

template<typename T>
Node<T> * DList<T>::RemoveElement(Node<T> * node)
{
    // na górze od razu wykluczamy przypadki, gdy podany index to pierwszy lub ostatni element listy
    // robimy tak dlatego że usuwanie skrajnych elementów listy różni się od usuwania zwykłych tym,
    // że tutaj nie łączymy sąsiadujących elementów ze sobą, oraz musimy przypisać nowy węzeł startowy lub końcowy
    if (node == startNode)
    {
        Node<T> * nextNode = startNode->next_node();
        nextNode->setPrevPtr(nullptr);
        startNode = nextNode;

        list_size--;
        delete node;
        return startNode;
    }
    else if (node == endNode)
    {
        Node<T> * prevNode = endNode->prev_node();
        prevNode->setNextPtr(nullptr);
        endNode = prevNode;

        list_size--;
        delete node;
        return endNode;
    }

    // jeśli index nie jest skrajny
    // odczytujemy wskaźniki do sąsiednich węzłów podangego węzła
    Node<T> * prevNode = node->prev_node();
    Node<T> * nextNode = node->next_node();

    // łączymy ze sobą te węzły
    prevNode->setNextPtr(nextNode);
    nextNode->setPrevPtr(prevNode);

    // odłączamy od nich usuwany węzeł
    node->setPrevPtr(nullptr);
    node->setNextPtr(nullptr);

    // zmniejszamy rozmiar listy oraz usuwamy podany węzeł z pamięci
    list_size--;
    delete node;
    return nextNode;
}


// Funkcja pozwalająca na wyświetlenie całej listy na ekranie w stylu listy z Pythona
// Min. do tej funkcji było potrzebne nadpisanie operatora << w strukturze GeometricShape
template<typename T>
void DList<T>::Print() const
{
    Node<T> * current_node = startNode;
    std::cout << "[";
    while (true) {
        std::cout << current_node->GetValue();
        current_node = current_node->next_node();

        if (current_node != nullptr)
        {
            std::cout << ", ";
            continue;
        }
        break;
    }
    std::cout << "]" << std::endl;
}
