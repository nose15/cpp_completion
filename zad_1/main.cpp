#include <iostream>
#include "include/DList.h"

struct GeometricShape
{
    GeometricShape(std::string name, float area, float perimeter)
    {
        this->name = std::move(name);
        this->area = area;
        this->perimeter = perimeter;
    }

    std::string GetName() const
    {
        return this->name;
    }

    // Metoda nadpisująca operator << Umożliwia określenie strumienia wyjścia podczas używania tej struktury w funkcji cout
    // Atrybut friend daje tej metodzie dostęp do prywatnych zmiennych struktury GeometricShape
    friend std::ostream& operator<<(std::ostream& outputStream, const GeometricShape& shape) {
        outputStream << shape.name;

        // Na górze krótsza wersja strumienia wyjścia, na dole dłuższa

        //outputStream << "Geometric Shape {name: " << shape.name << ", area: " << shape.area << ", perimeter: " << shape.perimeter << "}";
        return outputStream;
    }

private:
    std::string name;
    float area;
    float perimeter;
};


int main()
{
    // Krótka demonstracja działania programu

    // Tworzymy 3 instancje struktury GeometricShape, podając nazwę, pole oraz obwód
    GeometricShape square("Square", 10, 20);
    GeometricShape triangle("Triangle", 8, 16);
    GeometricShape pentagon("Pentagon", 91, 12);

    // Tworzymy listę zawierającą wcześniej stworzone struktury
    DList<GeometricShape> shapeList = {square, triangle, pentagon};

    GeometricShape triangle2("Triangle 2", 10, 129);

    // Za pomocą metody Append dodajemy wyżej stworzoną instancję do listy
    shapeList.Append(triangle2);
    shapeList.Print();

    // Za pomocą metody RemoveByIndex usuwamy element znajdujący się na podanym indeksie
    shapeList.RemoveByIndex(2);
    shapeList.Print();

    // Można odwołać się do elementów listy tak jak do elementów tablicy czyli tablica[index]
    std::cout << shapeList[1] << std::endl;

    // Do elementu na 1 indeksie wstawiamy nową instancję GeometricShape
    GeometricShape hexagon("Hexagon", 12, 123);
    shapeList[1] = hexagon;

    std::cout << shapeList[1] << std::endl;
}