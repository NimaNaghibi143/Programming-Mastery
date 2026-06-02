#include "converter.hpp"
#include "converter.cpp"
#include <iostream>

int main()
{
    int category    {1};
    int fromUnit    {1};
    int toUnit      {2};
    double value    {0};

    std::cout << "\n==== Welcome to the Unit Converter CLI tool! ====\n\n";
    std::cout << "Please select the conversion category:\n";
    std::cout << "1. Pressure\n";
    std::cout << "2. Temperature\n";
    std::cout << "3. Energy\n";

    std::cout << "Choice number: ";
    std::cin  >> category;

    choose_category:
    if (category == 1)
    {
        // Pressure conversion
        std::cout << "\nAvailable Pressure Units:\n";
        std::cout << "1. Pa\n";
        std::cout << "2. Bar\n";
        std::cout << "3. Atm\n";
        std::cout << "4. Psi\n";

        std::cout << "From unit: ";
        std::cin >> fromUnit;
        std::cout << "To unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::string fromUnitString {PressureUnit::toString(fromUnit)};
        std::string toUnitString {PressureUnit::toString(toUnit)};

        std::cout << "\nConverting value " << value << " from " << fromUnitString << " to " << toUnitString;

        double result =
            convertPressure(value,
                            fromUnitString,
                            toUnitString);

        std::cout << "\n" << value << " " << fromUnitString << " = " << result << " " << toUnitString << "\n";
    }

    else if (category == 2)
    {
        // Temperature conversion
        std::cout << "\nAvailable Temperature Units:\n";
        std::cout << "1. K\n";
        std::cout << "2. C\n";
        std::cout << "3. F\n";
        std::cout << "4. R\n";

        std::cout << "From unit: ";
        std::cin >> fromUnit;
        std::cout << "From unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::cout   << "\nConverting value " << value 
                    << " from " << TemperatureUnit::toString(fromUnit)
                    << " to " << TemperatureUnit::toString(toUnit);
    }

    else if (category == 3)
    {
        // Energy conversion
        std::cout << "\nAvailable Energy Units:\n";
        std::cout << "1. J\n";
        std::cout << "2. Cal\n";
        std::cout << "3. Btu\n";

        std::cout << "From unit: ";
        std::cin >> fromUnit;
        std::cout << "From unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::cout   << "\nConverting value " << value 
                    << " from " << EnergyUnit::toString(fromUnit)
                    << " to " << EnergyUnit::toString(toUnit) << "\n";
    }

    else
    {
        std::cout << "Please choose a number from the options above: \n";
        std::cin >> category;
        goto choose_category;
    }
    
    // Stop terminal windows to close after the job is done
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    std::cin.get();
    return 0;
}
