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
};

int main()
{
    DList<int> my_list = {2, 3, 4, 7, 19, 29};
    std::cout << my_list[2] << std::endl;
    my_list[2] = 10;
    std::cout << my_list[2] << std::endl;

}