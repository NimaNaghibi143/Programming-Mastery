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
    const std::string& fromUnit,
    const std::string& toUnit
)
{
    double kelvin {1};

    if (fromUnit == "K")
        kelvin = value;
    else if (fromUnit == "C")
        kelvin = value + 273.15;
    else if (fromUnit == "F")
        kelvin = ((value - 32) / 1.8) + 273.15;
    else if (fromUnit == "R")
        kelvin = value / 1.8;
    else
        kelvin = value;

    if (toUnit == "K")
        return kelvin;
    else if (toUnit == "C")
        return kelvin - 273.15;
    else if (toUnit == "F")
        return ((kelvin - 273.15) * 1.8) + 32;
    else if (toUnit == "R")
        return kelvin * 1.8;
    else
        return kelvin;
}


double convertEnergy(
    double value,
    const std::string& fromUnit,
    const std::string& toUnit
)
{
    double joule {1};

    if (fromUnit == "J")
        joule = value;
    else if (fromUnit == "Cal")
        joule = value * 4.184;
    else if (fromUnit == "Btu")
        joule = value * 1055.06;
    else
        joule = value;

    if (toUnit == "J")
        return joule;
    else if (toUnit == "Cal")
        return joule / 4.184;
    else if (toUnit == "Btu")
        return joule / 1055.06;
    else
        return joule;
}