#include "converter.hpp"
#include <iostream>


int main()
{
    int category {1};
    std::cout << "\n==== Welcome to the Unit Converter CLI tool! ====\n\n";
    std::cout << "Please select the convertion category:\n";
    std::cout << "1. Pressure\n";
    std::cout << "2. Temperature\n";
    std::cout << "3. Energy\n";

    std::cout << "Choice number: ";
    std::cin  >> category;

    return 0;
}
