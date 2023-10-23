#include <iostream>
#include <utility>
#include "include/DList.h"

struct GeometricShape
{
    std::string name;
    float area;
    float perimeter;

    GeometricShape(std::string name, float area, float perimeter)
    {
        this->name = std::move(name);
        this->area = area;
        this->perimeter = perimeter;
    }

    [[nodiscard]] std::string GetName() const
    {
        return this->name;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const GeometricShape& shape) {
        outputStream << shape.name;
        //outputStream << "Geometric Shape {name: " << shape.name << ", area: " << shape.area << ", perimeter: " << shape.perimeter << "}";
        return outputStream;
    }
};


int main()
{
    GeometricShape square("Square", 10, 20);
    GeometricShape triangle("Triangle", 8, 16);
    GeometricShape pentagon("Pentagon", 91, 12);

    DList<GeometricShape> shapeList = {square, triangle, pentagon};

    GeometricShape triangle2("Triangle 2", 10, 129);

    shapeList.Append(triangle2);
    shapeList.Print();

    shapeList.RemoveByIndex(2);
    shapeList.Print();

    std::cout << shapeList[1] << std::endl;
    GeometricShape hexagon("Hexagon", 12, 123);

    shapeList[1] = hexagon;
    std::cout << shapeList[1] << std::endl;
}