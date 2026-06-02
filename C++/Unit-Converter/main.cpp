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

    choose_category:
    if (category == 1)
    {
        // Pressure convertion
    }

    else if (category == 2)
    {
        // Temperature convertion
    }

    else if (category == 3)
    {
        // Energy convertion
    }

    else
    {
        std::cout << "Please choose a number from the options above: ";
        std::cin >> category;
        goto choose_category;
    }
    

    return 0;
}
