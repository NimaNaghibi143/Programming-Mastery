#include "converter.hpp"
#include "converter.cpp"
#include <iostream>

int main()
{
    int category    {1};
    int fromUnit    {1};
    int toUnit      {2};
    double value    {0};

    choose_category:
    std::cout << "\n==== Welcome to the Unit Converter CLI tool! ====\n\n";
    std::cout << "Please select the conversion category:\n";
    std::cout << "1. Pressure\n";
    std::cout << "2. Temperature\n";
    std::cout << "3. Energy\n";

    while (true) {
        std::cout << "\nCategory number: ";
        std::cin >> category;
        
        // Check if input failed (not an int)
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number (1, 2, or 3).\n";
            std::cin.clear();  // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Remove invalid input
        } 
        // Check if category is within valid range
        else if (category >= 1 && category <= 3) {
            break;  // Valid input, exit the loop
        } 
        else {
            std::cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }

    if (category == 1)
    {
        // Pressure conversion
        std::cout << "\nAvailable Pressure Units:\n";
        std::cout << "1. Pa\n";
        std::cout << "2. Bar\n";
        std::cout << "3. Atm\n";
        std::cout << "4. Psi\n";

        std::cout << "\nFrom unit: ";
        std::cin >> fromUnit;
        std::cout << "To unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::string fromUnitString {PressureUnit::toString(fromUnit)};
        std::string toUnitString {PressureUnit::toString(toUnit)};

        std::cout << "\nConverting value " << value << " from " << fromUnitString << " to " << toUnitString << " ...";

        double result =
            convertPressure(value,
                            fromUnitString,
                            toUnitString);

        std::cout << "\n\nConversion result:";
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

        std::cout << "\nFrom unit: ";
        std::cin >> fromUnit;
        std::cout << "To unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::string fromUnitString {TemperatureUnit::toString(fromUnit)};
        std::string toUnitString {TemperatureUnit::toString(toUnit)};

        std::cout << "\nConverting value " << value << " from " << fromUnitString << " to " << toUnitString << " ...";

        double result =
            convertTemperature(value,
                            fromUnitString,
                            toUnitString);

        std::cout << "\n\nConversion result:";
        std::cout << "\n" << value << " " << fromUnitString << " = " << result << " " << toUnitString << "\n";
    }

    else if (category == 3)
    {
        // Energy conversion
        std::cout << "\nAvailable Energy Units:\n";
        std::cout << "1. J\n";
        std::cout << "2. Cal\n";
        std::cout << "3. Btu\n";

        std::cout << "\nFrom unit: ";
        std::cin >> fromUnit;
        std::cout << "To unit: ";
        std::cin >> toUnit;
        std::cout << "Value: ";
        std::cin >> value;

        std::string fromUnitString {EnergyUnit::toString(fromUnit)};
        std::string toUnitString {EnergyUnit::toString(toUnit)};

        std::cout << "\nConverting value " << value << " from " << fromUnitString << " to " << toUnitString << " ...";

        double result =
            convertEnergy(value,
                            fromUnitString,
                            toUnitString);
        
        std::cout << "\n\nConversion result:";
        std::cout << "\n" << value << " " << fromUnitString << " = " << result << " " << toUnitString << "\n";
    }
    
    // Stop terminal windows to close after the job is done
    std::cout << "\nPress Enter to convert again. Close terminal to exit.";
    std::cin.get();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    goto choose_category;
    return 0;
}
