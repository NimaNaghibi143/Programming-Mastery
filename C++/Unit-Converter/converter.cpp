#include "converter.hpp"
#include <iostream>

// Using const so they remain unchainged
// Using & to use the values themselves and not a copy of them
double convertPressure(
    double value,
    const std::string& fromUnit,
    const std::string& toUnit
)
{
    double pascal {1};

    if (fromUnit == "Pa")
        pascal = value;
    else if (fromUnit == "Bar")
        pascal = value * 100000.00;
    else if (fromUnit == "Atm")
        pascal = value * 101325.00;
    else if (fromUnit == "Psi")
        pascal = value * 6894.76;
    else
        pascal = value;

    if (toUnit == "Pa")
        return pascal;
    else if (toUnit == "Bar")
        return pascal / 100000.0;
    else if (toUnit == "Atm")
        return pascal / 101325.0;
    else if (toUnit == "Psi")
        return pascal / 6894.76;
    else
        return pascal;
}


double convertTemperature(
    double value,
    const std::string& from,
    const std::string& to
)
{
    // Implement temperature conversion
    return 0;
}


double convertEnergy(
    double value,
    const std::string& from,
    const std::string& to
)
{
    // Implement energy conversion
    return 0;
}